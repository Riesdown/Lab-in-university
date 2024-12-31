;; Auto-generated. Do not edit!


(when (boundp 'test::send_position)
  (if (not (find-package "TEST"))
    (make-package "TEST"))
  (shadow 'send_position (find-package "TEST")))
(unless (find-package "TEST::SEND_POSITION")
  (make-package "TEST::SEND_POSITION"))
(unless (find-package "TEST::SEND_POSITIONREQUEST")
  (make-package "TEST::SEND_POSITIONREQUEST"))
(unless (find-package "TEST::SEND_POSITIONRESPONSE")
  (make-package "TEST::SEND_POSITIONRESPONSE"))

(in-package "ROS")





(defclass test::send_positionRequest
  :super ros::object
  :slots (_x _y _z ))

(defmethod test::send_positionRequest
  (:init
   (&key
    ((:x __x) 0.0)
    ((:y __y) 0.0)
    ((:z __z) 0.0)
    )
   (send-super :init)
   (setq _x (float __x))
   (setq _y (float __y))
   (setq _z (float __z))
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
  (:serialization-length
   ()
   (+
    ;; float32 _x
    4
    ;; float32 _y
    4
    ;; float32 _z
    4
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
   ;;
   self)
  )

(defclass test::send_positionResponse
  :super ros::object
  :slots ())

(defmethod test::send_positionResponse
  (:init
   (&key
    )
   (send-super :init)
   self)
  (:serialization-length
   ()
   (+
    0
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;;
   self)
  )

(defclass test::send_position
  :super ros::object
  :slots ())

(setf (get test::send_position :md5sum-) "cc153912f1453b708d221682bc23d9ac")
(setf (get test::send_position :datatype-) "test/send_position")
(setf (get test::send_position :request) test::send_positionRequest)
(setf (get test::send_position :response) test::send_positionResponse)

(defmethod test::send_positionRequest
  (:response () (instance test::send_positionResponse :init)))

(setf (get test::send_positionRequest :md5sum-) "cc153912f1453b708d221682bc23d9ac")
(setf (get test::send_positionRequest :datatype-) "test/send_positionRequest")
(setf (get test::send_positionRequest :definition-)
      "float32 x
float32 y
float32 z




---
")

(setf (get test::send_positionResponse :md5sum-) "cc153912f1453b708d221682bc23d9ac")
(setf (get test::send_positionResponse :datatype-) "test/send_positionResponse")
(setf (get test::send_positionResponse :definition-)
      "float32 x
float32 y
float32 z




---
")



(provide :test/send_position "cc153912f1453b708d221682bc23d9ac")


