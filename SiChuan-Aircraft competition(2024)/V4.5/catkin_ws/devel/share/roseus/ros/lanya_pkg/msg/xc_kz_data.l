;; Auto-generated. Do not edit!


(when (boundp 'lanya_pkg::xc_kz_data)
  (if (not (find-package "LANYA_PKG"))
    (make-package "LANYA_PKG"))
  (shadow 'xc_kz_data (find-package "LANYA_PKG")))
(unless (find-package "LANYA_PKG::XC_KZ_DATA")
  (make-package "LANYA_PKG::XC_KZ_DATA"))

(in-package "ROS")
;;//! \htmlinclude xc_kz_data.msg.html


(defclass lanya_pkg::xc_kz_data
  :super ros::object
  :slots (_kz_str ))

(defmethod lanya_pkg::xc_kz_data
  (:init
   (&key
    ((:kz_str __kz_str) "")
    )
   (send-super :init)
   (setq _kz_str (string __kz_str))
   self)
  (:kz_str
   (&optional __kz_str)
   (if __kz_str (setq _kz_str __kz_str)) _kz_str)
  (:serialization-length
   ()
   (+
    ;; string _kz_str
    4 (length _kz_str)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _kz_str
       (write-long (length _kz_str) s) (princ _kz_str s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _kz_str
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _kz_str (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(setf (get lanya_pkg::xc_kz_data :md5sum-) "faf6e880b42507c6d64b003da8b79bd3")
(setf (get lanya_pkg::xc_kz_data :datatype-) "lanya_pkg/xc_kz_data")
(setf (get lanya_pkg::xc_kz_data :definition-)
      "string kz_str

")



(provide :lanya_pkg/xc_kz_data "faf6e880b42507c6d64b003da8b79bd3")


