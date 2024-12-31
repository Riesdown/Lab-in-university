;; Auto-generated. Do not edit!


(when (boundp 'number_recognize_node::numeber_info_msgs)
  (if (not (find-package "NUMBER_RECOGNIZE_NODE"))
    (make-package "NUMBER_RECOGNIZE_NODE"))
  (shadow 'numeber_info_msgs (find-package "NUMBER_RECOGNIZE_NODE")))
(unless (find-package "NUMBER_RECOGNIZE_NODE::NUMEBER_INFO_MSGS")
  (make-package "NUMBER_RECOGNIZE_NODE::NUMEBER_INFO_MSGS"))

(in-package "ROS")
;;//! \htmlinclude numeber_info_msgs.msg.html


(defclass number_recognize_node::numeber_info_msgs
  :super ros::object
  :slots (_num _center_x _center_y _flag ))

(defmethod number_recognize_node::numeber_info_msgs
  (:init
   (&key
    ((:num __num) 0)
    ((:center_x __center_x) 0)
    ((:center_y __center_y) 0)
    ((:flag __flag) nil)
    )
   (send-super :init)
   (setq _num (round __num))
   (setq _center_x (round __center_x))
   (setq _center_y (round __center_y))
   (setq _flag __flag)
   self)
  (:num
   (&optional __num)
   (if __num (setq _num __num)) _num)
  (:center_x
   (&optional __center_x)
   (if __center_x (setq _center_x __center_x)) _center_x)
  (:center_y
   (&optional __center_y)
   (if __center_y (setq _center_y __center_y)) _center_y)
  (:flag
   (&optional __flag)
   (if __flag (setq _flag __flag)) _flag)
  (:serialization-length
   ()
   (+
    ;; int32 _num
    4
    ;; int32 _center_x
    4
    ;; int32 _center_y
    4
    ;; bool _flag
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _num
       (write-long _num s)
     ;; int32 _center_x
       (write-long _center_x s)
     ;; int32 _center_y
       (write-long _center_y s)
     ;; bool _flag
       (if _flag (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _num
     (setq _num (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _center_x
     (setq _center_x (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _center_y
     (setq _center_y (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; bool _flag
     (setq _flag (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(setf (get number_recognize_node::numeber_info_msgs :md5sum-) "d26e9a9b11d6e0b99d95bf5f9545549a")
(setf (get number_recognize_node::numeber_info_msgs :datatype-) "number_recognize_node/numeber_info_msgs")
(setf (get number_recognize_node::numeber_info_msgs :definition-)
      "int32 num
int32 center_x
int32 center_y
bool flag
")



(provide :number_recognize_node/numeber_info_msgs "d26e9a9b11d6e0b99d95bf5f9545549a")


