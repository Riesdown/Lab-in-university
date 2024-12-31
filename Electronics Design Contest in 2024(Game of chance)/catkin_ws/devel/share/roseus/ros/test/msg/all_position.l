;; Auto-generated. Do not edit!


(when (boundp 'test::all_position)
  (if (not (find-package "TEST"))
    (make-package "TEST"))
  (shadow 'all_position (find-package "TEST")))
(unless (find-package "TEST::ALL_POSITION")
  (make-package "TEST::ALL_POSITION"))

(in-package "ROS")
;;//! \htmlinclude all_position.msg.html


(defclass test::all_position
  :super ros::object
  :slots (_id _x1 _y1 _x2 _y2 _angle ))

(defmethod test::all_position
  (:init
   (&key
    ((:id __id) 0)
    ((:x1 __x1) 0.0)
    ((:y1 __y1) 0.0)
    ((:x2 __x2) 0.0)
    ((:y2 __y2) 0.0)
    ((:angle __angle) 0.0)
    )
   (send-super :init)
   (setq _id (round __id))
   (setq _x1 (float __x1))
   (setq _y1 (float __y1))
   (setq _x2 (float __x2))
   (setq _y2 (float __y2))
   (setq _angle (float __angle))
   self)
  (:id
   (&optional __id)
   (if __id (setq _id __id)) _id)
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
  (:angle
   (&optional __angle)
   (if __angle (setq _angle __angle)) _angle)
  (:serialization-length
   ()
   (+
    ;; int32 _id
    4
    ;; float64 _x1
    8
    ;; float64 _y1
    8
    ;; float64 _x2
    8
    ;; float64 _y2
    8
    ;; float64 _angle
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _id
       (write-long _id s)
     ;; float64 _x1
       (sys::poke _x1 (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _y1
       (sys::poke _y1 (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _x2
       (sys::poke _x2 (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _y2
       (sys::poke _y2 (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _angle
       (sys::poke _angle (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _id
     (setq _id (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; float64 _x1
     (setq _x1 (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _y1
     (setq _y1 (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _x2
     (setq _x2 (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _y2
     (setq _y2 (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _angle
     (setq _angle (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get test::all_position :md5sum-) "b638085ef920f701afd51e311a64a083")
(setf (get test::all_position :datatype-) "test/all_position")
(setf (get test::all_position :definition-)
      "int32 id
float64 x1
float64 y1
float64 x2
float64 y2

float64 angle


")



(provide :test/all_position "b638085ef920f701afd51e311a64a083")


