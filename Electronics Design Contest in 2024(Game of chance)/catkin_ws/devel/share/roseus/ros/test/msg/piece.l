;; Auto-generated. Do not edit!


(when (boundp 'test::piece)
  (if (not (find-package "TEST"))
    (make-package "TEST"))
  (shadow 'piece (find-package "TEST")))
(unless (find-package "TEST::PIECE")
  (make-package "TEST::PIECE"))

(in-package "ROS")
;;//! \htmlinclude piece.msg.html


(defclass test::piece
  :super ros::object
  :slots (_angle _id _status ))

(defmethod test::piece
  (:init
   (&key
    ((:angle __angle) 0.0)
    ((:id __id) 0)
    ((:status __status) 0)
    )
   (send-super :init)
   (setq _angle (float __angle))
   (setq _id (round __id))
   (setq _status (round __status))
   self)
  (:angle
   (&optional __angle)
   (if __angle (setq _angle __angle)) _angle)
  (:id
   (&optional __id)
   (if __id (setq _id __id)) _id)
  (:status
   (&optional __status)
   (if __status (setq _status __status)) _status)
  (:serialization-length
   ()
   (+
    ;; float32 _angle
    4
    ;; int32 _id
    4
    ;; int32 _status
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _angle
       (sys::poke _angle (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; int32 _id
       (write-long _id s)
     ;; int32 _status
       (write-long _status s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _angle
     (setq _angle (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; int32 _id
     (setq _id (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _status
     (setq _status (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get test::piece :md5sum-) "306bc2650a33dfc448b8d4bd5ce5a685")
(setf (get test::piece :datatype-) "test/piece")
(setf (get test::piece :definition-)
      "float32 angle   # 旋转角度
int32 id        # 方格ID
int32 status    # 小格状态



")



(provide :test/piece "306bc2650a33dfc448b8d4bd5ce5a685")


