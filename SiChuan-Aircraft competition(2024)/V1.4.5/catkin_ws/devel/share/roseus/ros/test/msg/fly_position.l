;; Auto-generated. Do not edit!


(when (boundp 'test::fly_position)
  (if (not (find-package "TEST"))
    (make-package "TEST"))
  (shadow 'fly_position (find-package "TEST")))
(unless (find-package "TEST::FLY_POSITION")
  (make-package "TEST::FLY_POSITION"))

(in-package "ROS")
;;//! \htmlinclude fly_position.msg.html


(defclass test::fly_position
  :super ros::object
  :slots (_x1 _y1 _x2 _y2 _x3 _y3 _x4 _y4 _x5 _y5 _x6 _y6 ))

(defmethod test::fly_position
  (:init
   (&key
    ((:x1 __x1) 0.0)
    ((:y1 __y1) 0.0)
    ((:x2 __x2) 0.0)
    ((:y2 __y2) 0.0)
    ((:x3 __x3) 0.0)
    ((:y3 __y3) 0.0)
    ((:x4 __x4) 0.0)
    ((:y4 __y4) 0.0)
    ((:x5 __x5) 0.0)
    ((:y5 __y5) 0.0)
    ((:x6 __x6) 0.0)
    ((:y6 __y6) 0.0)
    )
   (send-super :init)
   (setq _x1 (float __x1))
   (setq _y1 (float __y1))
   (setq _x2 (float __x2))
   (setq _y2 (float __y2))
   (setq _x3 (float __x3))
   (setq _y3 (float __y3))
   (setq _x4 (float __x4))
   (setq _y4 (float __y4))
   (setq _x5 (float __x5))
   (setq _y5 (float __y5))
   (setq _x6 (float __x6))
   (setq _y6 (float __y6))
   self)
  (:x1
   (&optional __x1)
   (if __x1 (setq _x1 __x1)) _x1)
  (:y1
   (&optional __y1)
   (if __y1 (setq _y1 __y1)) _y1)
  (:x2
   (&optional __x2)
   (if __x2 (setq _x2 __x2)) _x2)
  (:y2
   (&optional __y2)
   (if __y2 (setq _y2 __y2)) _y2)
  (:x3
   (&optional __x3)
   (if __x3 (setq _x3 __x3)) _x3)
  (:y3
   (&optional __y3)
   (if __y3 (setq _y3 __y3)) _y3)
  (:x4
   (&optional __x4)
   (if __x4 (setq _x4 __x4)) _x4)
  (:y4
   (&optional __y4)
   (if __y4 (setq _y4 __y4)) _y4)
  (:x5
   (&optional __x5)
   (if __x5 (setq _x5 __x5)) _x5)
  (:y5
   (&optional __y5)
   (if __y5 (setq _y5 __y5)) _y5)
  (:x6
   (&optional __x6)
   (if __x6 (setq _x6 __x6)) _x6)
  (:y6
   (&optional __y6)
   (if __y6 (setq _y6 __y6)) _y6)
  (:serialization-length
   ()
   (+
    ;; float32 _x1
    4
    ;; float32 _y1
    4
    ;; float32 _x2
    4
    ;; float32 _y2
    4
    ;; float32 _x3
    4
    ;; float32 _y3
    4
    ;; float32 _x4
    4
    ;; float32 _y4
    4
    ;; float32 _x5
    4
    ;; float32 _y5
    4
    ;; float32 _x6
    4
    ;; float32 _y6
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _x1
       (sys::poke _x1 (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _y1
       (sys::poke _y1 (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _x2
       (sys::poke _x2 (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _y2
       (sys::poke _y2 (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _x3
       (sys::poke _x3 (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _y3
       (sys::poke _y3 (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _x4
       (sys::poke _x4 (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _y4
       (sys::poke _y4 (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _x5
       (sys::poke _x5 (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _y5
       (sys::poke _y5 (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _x6
       (sys::poke _x6 (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _y6
       (sys::poke _y6 (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _x1
     (setq _x1 (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _y1
     (setq _y1 (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _x2
     (setq _x2 (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _y2
     (setq _y2 (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _x3
     (setq _x3 (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _y3
     (setq _y3 (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _x4
     (setq _x4 (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _y4
     (setq _y4 (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _x5
     (setq _x5 (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _y5
     (setq _y5 (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _x6
     (setq _x6 (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _y6
     (setq _y6 (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get test::fly_position :md5sum-) "d3c31e442f291e7849f095629277239d")
(setf (get test::fly_position :datatype-) "test/fly_position")
(setf (get test::fly_position :definition-)
      "float32  x1
float32  y1

float32  x2
float32  y2

float32  x3
float32  y3

float32  x4
float32  y4

float32  x5
float32  y5

float32  x6
float32  y6
")



(provide :test/fly_position "d3c31e442f291e7849f095629277239d")


