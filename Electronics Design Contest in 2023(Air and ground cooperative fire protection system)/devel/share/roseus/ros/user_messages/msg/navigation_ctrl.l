;; Auto-generated. Do not edit!


(when (boundp 'user_messages::navigation_ctrl)
  (if (not (find-package "USER_MESSAGES"))
    (make-package "USER_MESSAGES"))
  (shadow 'navigation_ctrl (find-package "USER_MESSAGES")))
(unless (find-package "USER_MESSAGES::NAVIGATION_CTRL")
  (make-package "USER_MESSAGES::NAVIGATION_CTRL"))

(in-package "ROS")
;;//! \htmlinclude navigation_ctrl.msg.html


(intern "*BODY_FRAME*" (find-package "USER_MESSAGES::NAVIGATION_CTRL"))
(shadow '*BODY_FRAME* (find-package "USER_MESSAGES::NAVIGATION_CTRL"))
(defconstant user_messages::navigation_ctrl::*BODY_FRAME* 0)
(intern "*MAP_FRAME*" (find-package "USER_MESSAGES::NAVIGATION_CTRL"))
(shadow '*MAP_FRAME* (find-package "USER_MESSAGES::NAVIGATION_CTRL"))
(defconstant user_messages::navigation_ctrl::*MAP_FRAME* 1)
(intern "*RELATIVE_MODE*" (find-package "USER_MESSAGES::NAVIGATION_CTRL"))
(shadow '*RELATIVE_MODE* (find-package "USER_MESSAGES::NAVIGATION_CTRL"))
(defconstant user_messages::navigation_ctrl::*RELATIVE_MODE* 0)
(intern "*GLOBAL_MODE*" (find-package "USER_MESSAGES::NAVIGATION_CTRL"))
(shadow '*GLOBAL_MODE* (find-package "USER_MESSAGES::NAVIGATION_CTRL"))
(defconstant user_messages::navigation_ctrl::*GLOBAL_MODE* 1)
(intern "*CMD_VEL_MODE*" (find-package "USER_MESSAGES::NAVIGATION_CTRL"))
(shadow '*CMD_VEL_MODE* (find-package "USER_MESSAGES::NAVIGATION_CTRL"))
(defconstant user_messages::navigation_ctrl::*CMD_VEL_MODE* 2)

(defun user_messages::navigation_ctrl-to-symbol (const)
  (cond
        ((= const 0) 'user_messages::navigation_ctrl::*BODY_FRAME*)
        ((= const 1) 'user_messages::navigation_ctrl::*MAP_FRAME*)
        ((= const 0) 'user_messages::navigation_ctrl::*RELATIVE_MODE*)
        ((= const 1) 'user_messages::navigation_ctrl::*GLOBAL_MODE*)
        ((= const 2) 'user_messages::navigation_ctrl::*CMD_VEL_MODE*)
        (t nil)))

(defclass user_messages::navigation_ctrl
  :super ros::object
  :slots (_x _y _z _nav_mode _frame_id _num _execution_time _update_flag ))

(defmethod user_messages::navigation_ctrl
  (:init
   (&key
    ((:x __x) 0.0)
    ((:y __y) 0.0)
    ((:z __z) 0.0)
    ((:nav_mode __nav_mode) 0)
    ((:frame_id __frame_id) 0)
    ((:num __num) 0)
    ((:execution_time __execution_time) 0)
    ((:update_flag __update_flag) 0)
    )
   (send-super :init)
   (setq _x (float __x))
   (setq _y (float __y))
   (setq _z (float __z))
   (setq _nav_mode (round __nav_mode))
   (setq _frame_id (round __frame_id))
   (setq _num (round __num))
   (setq _execution_time (round __execution_time))
   (setq _update_flag (round __update_flag))
   self)
  (:x
   (&optional __x)
   (if __x (setq _x __x)) _x)
  (:y
   (&optional __y)
   (if __y (setq _y __y)) _y)
  (:z
   (&optional __z)
   (if __z (setq _z __z)) _z)
  (:nav_mode
   (&optional __nav_mode)
   (if __nav_mode (setq _nav_mode __nav_mode)) _nav_mode)
  (:frame_id
   (&optional __frame_id)
   (if __frame_id (setq _frame_id __frame_id)) _frame_id)
  (:num
   (&optional __num)
   (if __num (setq _num __num)) _num)
  (:execution_time
   (&optional __execution_time)
   (if __execution_time (setq _execution_time __execution_time)) _execution_time)
  (:update_flag
   (&optional __update_flag)
   (if __update_flag (setq _update_flag __update_flag)) _update_flag)
  (:serialization-length
   ()
   (+
    ;; float32 _x
    4
    ;; float32 _y
    4
    ;; float32 _z
    4
    ;; uint8 _nav_mode
    1
    ;; uint8 _frame_id
    1
    ;; uint16 _num
    2
    ;; uint32 _execution_time
    4
    ;; uint8 _update_flag
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _x
       (sys::poke _x (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _y
       (sys::poke _y (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _z
       (sys::poke _z (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; uint8 _nav_mode
       (write-byte _nav_mode s)
     ;; uint8 _frame_id
       (write-byte _frame_id s)
     ;; uint16 _num
       (write-word _num s)
     ;; uint32 _execution_time
       (write-long _execution_time s)
     ;; uint8 _update_flag
       (write-byte _update_flag s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _x
     (setq _x (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _y
     (setq _y (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _z
     (setq _z (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; uint8 _nav_mode
     (setq _nav_mode (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _frame_id
     (setq _frame_id (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint16 _num
     (setq _num (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; uint32 _execution_time
     (setq _execution_time (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; uint8 _update_flag
     (setq _update_flag (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;;
   self)
  )

(setf (get user_messages::navigation_ctrl :md5sum-) "57540d12dfd9892331224880fa18114a")
(setf (get user_messages::navigation_ctrl :datatype-) "user_messages/navigation_ctrl")
(setf (get user_messages::navigation_ctrl :definition-)
      "float32 x
float32 y
float32 z
uint8 nav_mode
uint8 frame_id
uint16 num
uint32 execution_time
uint8 update_flag

uint8 BODY_FRAME=0
uint8 MAP_FRAME=1
uint8 RELATIVE_MODE=0
uint8 GLOBAL_MODE=1
uint8 CMD_VEL_MODE=2
")



(provide :user_messages/navigation_ctrl "57540d12dfd9892331224880fa18114a")


