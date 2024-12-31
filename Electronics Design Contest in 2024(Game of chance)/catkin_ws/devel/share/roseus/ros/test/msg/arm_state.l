;; Auto-generated. Do not edit!


(when (boundp 'test::arm_state)
  (if (not (find-package "TEST"))
    (make-package "TEST"))
  (shadow 'arm_state (find-package "TEST")))
(unless (find-package "TEST::ARM_STATE")
  (make-package "TEST::ARM_STATE"))

(in-package "ROS")
;;//! \htmlinclude arm_state.msg.html


(defclass test::arm_state
  :super ros::object
  :slots (_chess_aim_x _chess_aim_y ))

(defmethod test::arm_state
  (:init
   (&key
    ((:chess_aim_x __chess_aim_x) 0.0)
    ((:chess_aim_y __chess_aim_y) 0.0)
    )
   (send-super :init)
   (setq _chess_aim_x (float __chess_aim_x))
   (setq _chess_aim_y (float __chess_aim_y))
   self)
  (:chess_aim_x
   (&optional __chess_aim_x)
   (if __chess_aim_x (setq _chess_aim_x __chess_aim_x)) _chess_aim_x)
  (:chess_aim_y
   (&optional __chess_aim_y)
   (if __chess_aim_y (setq _chess_aim_y __chess_aim_y)) _chess_aim_y)
  (:serialization-length
   ()
   (+
    ;; float32 _chess_aim_x
    4
    ;; float32 _chess_aim_y
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _chess_aim_x
       (sys::poke _chess_aim_x (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _chess_aim_y
       (sys::poke _chess_aim_y (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _chess_aim_x
     (setq _chess_aim_x (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _chess_aim_y
     (setq _chess_aim_y (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get test::arm_state :md5sum-) "021ae4e1499fe0af22a25b5797cdfc12")
(setf (get test::arm_state :datatype-) "test/arm_state")
(setf (get test::arm_state :definition-)
      "float32 chess_aim_x     # 棋子目的位置x
float32 chess_aim_y     # 棋子目的位置y





")



(provide :test/arm_state "021ae4e1499fe0af22a25b5797cdfc12")


