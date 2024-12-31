#include "ros/ros.h"
#include "test/piece.h"
#include "test/next_piece.h"
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include "test/SYS/Some_define.hpp"
#include "test/PTC/MyList.hpp"
#include "test/PTC/MyTopic.hpp"
#include "test/SYS/MyROS.hpp"

typedef unsigned short u16;
typedef int i32;

std::map<u16, test::piece> piece_map;
test::piece piece_date;
test::next_piece next_piece_date;

MYLIST mylist;

class TicTacToe {
public:
    int board[3][3]; // 3x3的棋盘，0代表空，1代表白棋，2代表黑棋

    TicTacToe() {
        resetBoard();
    }

    void resetBoard() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = 0;
            }
        }
    }

    bool checkWin(int player) {
        for (int i = 0; i < 3; i++) {
            if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
                (board[0][i] == player && board[1][i] == player && board[2][i] == player) ||
                (board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
                (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
                return true;
            }
        }
        return false;
    }

    bool checkFull() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == 0) {
                    return false;
                }
            }
        }
        return true;
    }

    std::pair<int, int> findBestMove(int machinePlayer) {
        int bestScore = -1000;
        std::pair<int, int> bestMove = {-1, -1};

        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) {
                if (board[row][col] == 0) {
                    board[row][col] = machinePlayer;
                    int score = minimax(machinePlayer, false, 0);
                    board[row][col] = 0;
                    if (score > bestScore) {
                        bestScore = score;
                        bestMove = {row, col};
                    }
                }
            }
        }

        return bestMove;
    }

    int minimax(int player, bool isMaximizing, int depth) {
        int opponent = 3 - player;
        if (checkWin(player)) {
            return 10 - depth;
        } else if (checkWin(opponent)) {
            return depth - 10;
        }

        if (checkFull()) {
            return 0;
        }

        int bestScore = isMaximizing ? -1000 : 1000;
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) {
                if (board[row][col] == 0) {
                    board[row][col] = isMaximizing ? player : opponent;
                    int currentScore = minimax(player, !isMaximizing, depth + 1);
                    board[row][col] = 0;
                    bestScore = isMaximizing ? std::max(bestScore, currentScore) : std::min(bestScore, currentScore);
                }
            }
        }
        return bestScore;
    }

    void printBoard() {
        std::cout << "Current board status:" << std::endl;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                std::cout << (board[i][j] == 0 ? ". " : (board[i][j] == 1 ? "O " : "X "));
            }
            std::cout << std::endl;
        }
    }

    void updateBoardFromStatus(const int grid_status[3][3]) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = grid_status[i][j];
            }
        }
    }
};

int grid_status[3][3] = {0};

void UpdateGridStatus() {
    for (const auto& entry : piece_map) {
        int id = entry.first;
        int status = entry.second.status;
        
        int row = (id - 1) / 3;
        int col = (id - 1) % 3;
        
        grid_status[row][col] = status;
    }
}

void Get_Piece(const test::piece::ConstPtr &msg) 
{
    piece_date = *msg;
    piece_map[piece_date.id] = piece_date;
    UpdateGridStatus();
}

int getBestMove(TicTacToe& game, int grid_status[3][3], int machinePlayer) {
    game.updateBoardFromStatus(grid_status);
    std::pair<int, int> bestMove = game.findBestMove(machinePlayer);
    return bestMove.first * 3 + bestMove.second + 1;  // 将二维坐标转换为1-9的数字
}

int main(int argc, char **argv) 
{
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "ai_tictactoe");
    ros::NodeHandle nh;
    TicTacToe game;

    ros::Subscriber sub = nh.subscribe("get_piece", 1000, Get_Piece);
    MYTOPIC send_next_piece("next_piece", 10);

    while (ros::ok()) 
    {
        if (1 != mylist.Get<i32>("auto") || 1 != mylist.Get<i32>("ai_start")) continue;

        if (1 == mylist.Get<i32>("getpc")) {
            for (u8 i = 0; i < 50; i++) {
                UpdateGridStatus();
                ros::WallDuration(0.05).sleep();
                ros::spinOnce();
            }
            mylist.Send<i32>("getpc", 0);
        }

        int black_count = 0;
        int white_count = 0;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (grid_status[i][j] == 1) white_count++;
                if (grid_status[i][j] == 2) black_count++;
            }
        }

        int nextMove = -1;
        if (0 == mylist.Get<i32>("black")) {
            if (black_count == white_count) {
                nextMove = getBestMove(game, grid_status, 2);  // 机器下黑棋
            }
        } else {
            if (black_count > white_count) {
                nextMove = getBestMove(game, grid_status, 1);  // 机器下白棋
            }
        }

        if (nextMove != -1) {
            ROS_INFO("机器下一步最佳位置: %d", nextMove);

            next_piece_date.next = nextMove;
            send_next_piece.Send<test::next_piece>(next_piece_date);

            int row = (nextMove - 1) / 3;
            int col = (nextMove - 1) % 3;
            game.board[row][col] = (0 == mylist.Get<i32>("black")) ? 2 : 1; // 更新棋盘状态

            if (game.checkWin((0 == mylist.Get<i32>("black")) ? 2 : 1)) {
                ROS_INFO("机器胜利");
                break;
            } else if (game.checkFull()) {
                ROS_INFO("平局");
                break;
            }
        }

        game.printBoard();

        ros::Duration(0.1).sleep();
    }

    return 0;
}
