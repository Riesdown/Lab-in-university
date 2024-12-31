;; Auto-generated. Do not edit!


(when (boundp 'lanya_pkg::fj_wz_data)
  (if (not (find-package "LANYA_PKG"))
    (make-package "LANYA_PKG"))
  (shadow 'fj_wz_data (find-package "LANYA_PKG")))
(unless (find-package "LANYA_PKG::FJ_WZ_DATA")
  (make-package "LANYA_PKG::FJ_WZ_DATA"))

(in-package "ROS")
;;//! \htmlinclude fj_wz_data.msg.html


(defclass lanya_pkg::fj_wz_data
  :super ros::object
  :slots (_fj_x _fj_y ))

(defmethod lanya_pkg::fj_wz_data
  (:init
   (&key
    ((:fj_x __fj_x) 0.0)
    ((:fj_y __fj_y) 0.0)
    )
   (send-super :init)
   (setq _fj_x (float __fj_x))
   (setq _fj_y (float __fj_y))
   self)
  (:fj_x
   (&optional __fj_x)
   (if __fj_x (setq _fj_x __fj_x)) _fj_x)
  (:fj_y
   (&optional __fj_y)
   (if __fj_y (setq _fj_y __fj_y)) _fj_y)
  (:serialization-length
   ()
   (+
    ;; float32 _fj_x
    4
    ;; float32 _fj_y
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _fj_x
       (sys::poke _fj_x (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _fj_y
       (sys::poke _fj_y (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _fj_x
     (setq _fj_x (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _fj_y
     (setq _fj_y (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get lanya_pkg::fj_wz_data :md5sum-) "11a2e9cf43a8ca7a8685679601c4ed90")
(setf (get lanya_pkg::fj_wz_data :datatype-) "lanya_pkg/fj_wz_data")
(setf (get lanya_pkg::fj_wz_data :definition-)
      "float32 fj_x
float32 fj_y
")



(provide :lanya_pkg/fj_wz_data "11a2e9cf43a8ca7a8685679601c4ed90")


