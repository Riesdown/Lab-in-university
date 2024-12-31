;; Auto-generated. Do not edit!


(when (boundp 'user_messages::serialport_decode)
  (if (not (find-package "USER_MESSAGES"))
    (make-package "USER_MESSAGES"))
  (shadow 'serialport_decode (find-package "USER_MESSAGES")))
(unless (find-package "USER_MESSAGES::SERIALPORT_DECODE")
  (make-package "USER_MESSAGES::SERIALPORT_DECODE"))

(in-package "ROS")
;;//! \htmlinclude serialport_decode.msg.html


(defclass user_messages::serialport_decode
  :super ros::object
  :slots (_buf _cnt ))

(defmethod user_messages::serialport_decode
  (:init
   (&key
    ((:buf __buf) (make-array 0 :initial-element 0 :element-type :char))
    ((:cnt __cnt) 0)
    )
   (send-super :init)
   (setq _buf __buf)
   (setq _cnt (round __cnt))
   self)
  (:buf
   (&optional __buf)
   (if __buf (setq _buf __buf)) _buf)
  (:cnt
   (&optional __cnt)
   (if __cnt (setq _cnt __cnt)) _cnt)
  (:serialization-length
   ()
   (+
    ;; uint8[] _buf
    (* 1    (length _buf)) 4
    ;; uint16 _cnt
    2
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint8[] _buf
     (write-long (length _buf) s)
     (princ _buf s)
     ;; uint16 _cnt
       (write-word _cnt s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint8[] _buf
   (let ((n (sys::peek buf ptr- :integer))) (incf ptr- 4)
     (setq _buf (make-array n :element-type :char))
     (replace _buf buf :start2 ptr-) (incf ptr- n))
   ;; uint16 _cnt
     (setq _cnt (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;;
   self)
  )

(setf (get user_messages::serialport_decode :md5sum-) "b64998cbe9ab1eb940716392cc08fe66")
(setf (get user_messages::serialport_decode :datatype-) "user_messages/serialport_decode")
(setf (get user_messages::serialport_decode :definition-)
      "uint8[] buf
uint16 cnt

")



(provide :user_messages/serialport_decode "b64998cbe9ab1eb940716392cc08fe66")


