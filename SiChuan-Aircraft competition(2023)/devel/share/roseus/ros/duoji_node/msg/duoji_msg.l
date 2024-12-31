;; Auto-generated. Do not edit!


(when (boundp 'duoji_node::duoji_msg)
  (if (not (find-package "DUOJI_NODE"))
    (make-package "DUOJI_NODE"))
  (shadow 'duoji_msg (find-package "DUOJI_NODE")))
(unless (find-package "DUOJI_NODE::DUOJI_MSG")
  (make-package "DUOJI_NODE::DUOJI_MSG"))

(in-package "ROS")
;;//! \htmlinclude duoji_msg.msg.html


(defclass duoji_node::duoji_msg
  :super ros::object
  :slots (_Duoji_angle ))

(defmethod duoji_node::duoji_msg
  (:init
   (&key
    ((:Duoji_angle __Duoji_angle) 0)
    )
   (send-super :init)
   (setq _Duoji_angle (round __Duoji_angle))
   self)
  (:Duoji_angle
   (&optional __Duoji_angle)
   (if __Duoji_angle (setq _Duoji_angle __Duoji_angle)) _Duoji_angle)
  (:serialization-length
   ()
   (+
    ;; int32 _Duoji_angle
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _Duoji_angle
       (write-long _Duoji_angle s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _Duoji_angle
     (setq _Duoji_angle (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get duoji_node::duoji_msg :md5sum-) "9bb68250934646b96771efd253d0ba16")
(setf (get duoji_node::duoji_msg :datatype-) "duoji_node/duoji_msg")
(setf (get duoji_node::duoji_msg :definition-)
      "int32 Duoji_angle
")



(provide :duoji_node/duoji_msg "9bb68250934646b96771efd253d0ba16")


