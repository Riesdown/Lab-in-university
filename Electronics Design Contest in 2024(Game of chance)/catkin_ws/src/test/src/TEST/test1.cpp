#include "ros/ros.h"
#include "test/piece.h"
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
/**********  1  ***************/
#include "test/SYS/Some_define.hpp"
#include "test/PTC/MyList.hpp"
#include "test/PTC/MyTopic.hpp"
/**********  2  ***************/
#include "test/SYS/MyROS.hpp"



typedef unsigned short u16;
typedef int i32;

std::map<u16, test::piece> piece_map;
std::map<int, std::vector<int>> piece_status_buffer;
std::map<int, int> piece_status_count;
test::piece piece_date;

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

    std::pair<int, int> findBestMove(int machinePlayer) {
        int bestScore = -1000;
        std::pair<int, int> bestMove = {-1, -1};

        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) {
                if (board[row][col] == 0) {
                    board[row][col] = machinePlayer;
                    int score = minimax(machinePlayer, false);
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

    int minimax(int player, bool isMaximizing) {
        int opponent = 3 - player;
        if (checkWin(player)) {
            return 10;
        } else if (checkWin(opponent)) {
            return -10;
        }

        int bestScore = isMaximizing ? -1000 : 1000;
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) {
                if (board[row][col] == 0) {
                    board[row][col] = isMaximizing ? player : opponent;
                    int currentScore = minimax(player, !isMaximizing);
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

    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            ROS_INFO("Grid [%d][%d] = %d", row, col, grid_status[row][col]);
        }
    }
}

void Get_Piece(const test::piece::ConstPtr &msg) {
    test::piece piece_date = *msg;

    auto it = piece_map.find(piece_date.id);
    if (it != piece_map.end()) {
        piece_map[piece_date.id] = piece_date;
    } else {
        piece_map[piece_date.id] = piece_date;
    }

    piece_status_buffer[piece_date.id].push_back(piece_date.status);
    piece_status_count[piece_date.id]++;

    if (piece_status_count[piece_date.id] >= 10) {
        int sum_status = 0;
        for (int status : piece_status_buffer[piece_date.id]) {
            sum_status += status;
        }

        int average_status = sum_status / 10;

        piece_status_buffer[piece_date.id].clear();
        piece_status_count[piece_date.id] = 0;

        piece_date.status = average_status;
        piece_map[piece_date.id] = piece_date;

        UpdateGridStatus();

        ROS_INFO("ID: %d, Old Status: %d, New Status: %d, Real-time Status: %d", 
                piece_date.id, piece_date.status, piece_date.status, piece_date.status);
    }
}

int getBestMove(TicTacToe& game, int grid_status[3][3], int machinePlayer) {
    game.updateBoardFromStatus(grid_status);
    std::pair<int, int> bestMove = game.findBestMove(machinePlayer);
    return bestMove.first * 3 + bestMove.second + 1;  // 将二维坐标转换为1-9的数字
}


 MYLIST mylist;


int main(int argc, char **argv) 
{
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "ai_tictactoe");
    ros::NodeHandle nh;
    TicTacToe game;

    ros::Subscriber sub = nh.subscribe("get_piece", 1000, Get_Piece);

    while (ros::ok()) 
    {
        if (1 != mylist.Get<i32>("auto") || 1 != mylist.Get<i32>("ai_start")) continue;
        
        ros::spinOnce();
        UpdateGridStatus();

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
        }
        game.printBoard();

        ros::Duration(0.1).sleep();
    }

    return 0;
}
