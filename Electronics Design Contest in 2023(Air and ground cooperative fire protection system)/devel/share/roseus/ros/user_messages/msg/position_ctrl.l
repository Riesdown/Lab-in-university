;; Auto-generated. Do not edit!


(when (boundp 'user_messages::position_ctrl)
  (if (not (find-package "USER_MESSAGES"))
    (make-package "USER_MESSAGES"))
  (shadow 'position_ctrl (find-package "USER_MESSAGES")))
(unless (find-package "USER_MESSAGES::POSITION_CTRL")
  (make-package "USER_MESSAGES::POSITION_CTRL"))

(in-package "ROS")
;;//! \htmlinclude position_ctrl.msg.html


(defclass user_messages::position_ctrl
  :super ros::object
  :slots (_move_flag _move_order _move_distance ))

(defmethod user_messages::position_ctrl
  (:init
   (&key
    ((:move_flag __move_flag) 0)
    ((:move_order __move_order) 0)
    ((:move_distance __move_distance) 0)
    )
   (send-super :init)
   (setq _move_flag (round __move_flag))
   (setq _move_order (round __move_order))
   (setq _move_distance (round __move_distance))
   self)
  (:move_flag
   (&optional __move_flag)
   (if __move_flag (setq _move_flag __move_flag)) _move_flag)
  (:move_order
   (&optional __move_order)
   (if __move_order (setq _move_order __move_order)) _move_order)
  (:move_distance
   (&optional __move_distance)
   (if __move_distance (setq _move_distance __move_distance)) _move_distance)
  (:serialization-length
   ()
   (+
    ;; uint8 _move_flag
    1
    ;; uint8 _move_order
    1
    ;; uint16 _move_distance
    2
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint8 _move_flag
       (write-byte _move_flag s)
     ;; uint8 _move_order
       (write-byte _move_order s)
     ;; uint16 _move_distance
       (write-word _move_distance s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint8 _move_flag
     (setq _move_flag (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _move_order
     (setq _move_order (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint16 _move_distance
     (setq _move_distance (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;;
   self)
  )

(setf (get user_messages::position_ctrl :md5sum-) "4b35dc4f304f0d5f7eaa8dda10fe4862")
(setf (get user_messages::position_ctrl :datatype-) "user_messages/position_ctrl")
(setf (get user_messages::position_ctrl :definition-)
      "uint8 move_flag
uint8 move_order
uint16 move_distance

")



(provide :user_messages/position_ctrl "4b35dc4f304f0d5f7eaa8dda10fe4862")


