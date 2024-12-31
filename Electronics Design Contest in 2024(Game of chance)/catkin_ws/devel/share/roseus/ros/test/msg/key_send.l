;; Auto-generated. Do not edit!


(when (boundp 'test::key_send)
  (if (not (find-package "TEST"))
    (make-package "TEST"))
  (shadow 'key_send (find-package "TEST")))
(unless (find-package "TEST::KEY_SEND")
  (make-package "TEST::KEY_SEND"))

(in-package "ROS")
;;//! \htmlinclude key_send.msg.html


(defclass test::key_send
  :super ros::object
  :slots (_chess_change _chess_num _position ))

(defmethod test::key_send
  (:init
   (&key
    ((:chess_change __chess_change) 0)
    ((:chess_num __chess_num) 0)
    ((:position __position) 0)
    )
   (send-super :init)
   (setq _chess_change (round __chess_change))
   (setq _chess_num (round __chess_num))
   (setq _position (round __position))
   self)
  (:chess_change
   (&optional __chess_change)
   (if __chess_change (setq _chess_change __chess_change)) _chess_change)
  (:chess_num
   (&optional __chess_num)
   (if __chess_num (setq _chess_num __chess_num)) _chess_num)
  (:position
   (&optional __position)
   (if __position (setq _position __position)) _position)
  (:serialization-length
   ()
   (+
    ;; int32 _chess_change
    4
    ;; int32 _chess_num
    4
    ;; int32 _position
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _chess_change
       (write-long _chess_change s)
     ;; int32 _chess_num
       (write-long _chess_num s)
     ;; int32 _position
       (write-long _position s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _chess_change
     (setq _chess_change (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _chess_num
     (setq _chess_num (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _position
     (setq _position (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get test::key_send :md5sum-) "1f77ffe24d4ef0b7fc703ecd866700bb")
(setf (get test::key_send :datatype-) "test/key_send")
(setf (get test::key_send :definition-)
      "int32 chess_change      # 棋子改变
int32 chess_num         # 棋子编号
int32 position          # 位置





")



(provide :test/key_send "1f77ffe24d4ef0b7fc703ecd866700bb")


