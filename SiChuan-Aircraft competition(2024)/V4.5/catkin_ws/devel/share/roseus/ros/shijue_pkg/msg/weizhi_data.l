;; Auto-generated. Do not edit!


(when (boundp 'shijue_pkg::weizhi_data)
  (if (not (find-package "SHIJUE_PKG"))
    (make-package "SHIJUE_PKG"))
  (shadow 'weizhi_data (find-package "SHIJUE_PKG")))
(unless (find-package "SHIJUE_PKG::WEIZHI_DATA")
  (make-package "SHIJUE_PKG::WEIZHI_DATA"))

(in-package "ROS")
;;//! \htmlinclude weizhi_data.msg.html


(defclass shijue_pkg::weizhi_data
  :super ros::object
  :slots (_wz_x _wz_y _flag ))

(defmethod shijue_pkg::weizhi_data
  (:init
   (&key
    ((:wz_x __wz_x) 0.0)
    ((:wz_y __wz_y) 0.0)
    ((:flag __flag) nil)
    )
   (send-super :init)
   (setq _wz_x (float __wz_x))
   (setq _wz_y (float __wz_y))
   (setq _flag __flag)
   self)
  (:wz_x
   (&optional __wz_x)
   (if __wz_x (setq _wz_x __wz_x)) _wz_x)
  (:wz_y
   (&optional __wz_y)
   (if __wz_y (setq _wz_y __wz_y)) _wz_y)
  (:flag
   (&optional __flag)
   (if __flag (setq _flag __flag)) _flag)
  (:serialization-length
   ()
   (+
    ;; float32 _wz_x
    4
    ;; float32 _wz_y
    4
    ;; bool _flag
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _wz_x
       (sys::poke _wz_x (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _wz_y
       (sys::poke _wz_y (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; bool _flag
       (if _flag (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _wz_x
     (setq _wz_x (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _wz_y
     (setq _wz_y (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; bool _flag
     (setq _flag (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(setf (get shijue_pkg::weizhi_data :md5sum-) "9352d5e7401b90403eb2ff4ec8292292")
(setf (get shijue_pkg::weizhi_data :datatype-) "shijue_pkg/weizhi_data")
(setf (get shijue_pkg::weizhi_data :definition-)
      "float32 wz_x
float32 wz_y
bool flag
")



(provide :shijue_pkg/weizhi_data "9352d5e7401b90403eb2ff4ec8292292")


