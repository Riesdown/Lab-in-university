;; Auto-generated. Do not edit!


(when (boundp 'lanya_pkg::xc_wz_data)
  (if (not (find-package "LANYA_PKG"))
    (make-package "LANYA_PKG"))
  (shadow 'xc_wz_data (find-package "LANYA_PKG")))
(unless (find-package "LANYA_PKG::XC_WZ_DATA")
  (make-package "LANYA_PKG::XC_WZ_DATA"))

(in-package "ROS")
;;//! \htmlinclude xc_wz_data.msg.html


(defclass lanya_pkg::xc_wz_data
  :super ros::object
  :slots (_xc_x _xc_y ))

(defmethod lanya_pkg::xc_wz_data
  (:init
   (&key
    ((:xc_x __xc_x) 0.0)
    ((:xc_y __xc_y) 0.0)
    )
   (send-super :init)
   (setq _xc_x (float __xc_x))
   (setq _xc_y (float __xc_y))
   self)
  (:xc_x
   (&optional __xc_x)
   (if __xc_x (setq _xc_x __xc_x)) _xc_x)
  (:xc_y
   (&optional __xc_y)
   (if __xc_y (setq _xc_y __xc_y)) _xc_y)
  (:serialization-length
   ()
   (+
    ;; float32 _xc_x
    4
    ;; float32 _xc_y
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _xc_x
       (sys::poke _xc_x (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _xc_y
       (sys::poke _xc_y (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _xc_x
     (setq _xc_x (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _xc_y
     (setq _xc_y (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get lanya_pkg::xc_wz_data :md5sum-) "0af5983c67c5a0659bc718afae52c5bd")
(setf (get lanya_pkg::xc_wz_data :datatype-) "lanya_pkg/xc_wz_data")
(setf (get lanya_pkg::xc_wz_data :definition-)
      "float32 xc_x
float32 xc_y

")



(provide :lanya_pkg/xc_wz_data "0af5983c67c5a0659bc718afae52c5bd")


