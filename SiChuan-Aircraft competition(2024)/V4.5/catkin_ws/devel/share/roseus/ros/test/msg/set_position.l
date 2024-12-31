;; Auto-generated. Do not edit!


(when (boundp 'test::set_position)
  (if (not (find-package "TEST"))
    (make-package "TEST"))
  (shadow 'set_position (find-package "TEST")))
(unless (find-package "TEST::SET_POSITION")
  (make-package "TEST::SET_POSITION"))

(in-package "ROS")
;;//! \htmlinclude set_position.msg.html


(defclass test::set_position
  :super ros::object
  :slots (_x _y _z _flag1 ))

(defmethod test::set_position
  (:init
   (&key
    ((:x __x) 0.0)
    ((:y __y) 0.0)
    ((:z __z) 0.0)
    ((:flag1 __flag1) 0.0)
    )
   (send-super :init)
   (setq _x (float __x))
   (setq _y (float __y))
   (setq _z (float __z))
   (setq _flag1 (float __flag1))
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
  (:flag1
   (&optional __flag1)
   (if __flag1 (setq _flag1 __flag1)) _flag1)
  (:serialization-length
   ()
   (+
    ;; float32 _x
    4
    ;; float32 _y
    4
    ;; float32 _z
    4
    ;; float32 _flag1
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
     ;; float32 _flag1
       (sys::poke _flag1 (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
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
   ;; float32 _flag1
     (setq _flag1 (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get test::set_position :md5sum-) "5f7db468f1f67d536e537686487991cd")
(setf (get test::set_position :datatype-) "test/set_position")
(setf (get test::set_position :definition-)
      "float32  x
float32  y
float32  z
float32 flag1



")



(provide :test/set_position "5f7db468f1f67d536e537686487991cd")


