;; Auto-generated. Do not edit!


(when (boundp 'test::next_piece)
  (if (not (find-package "TEST"))
    (make-package "TEST"))
  (shadow 'next_piece (find-package "TEST")))
(unless (find-package "TEST::NEXT_PIECE")
  (make-package "TEST::NEXT_PIECE"))

(in-package "ROS")
;;//! \htmlinclude next_piece.msg.html


(defclass test::next_piece
  :super ros::object
  :slots (_next ))

(defmethod test::next_piece
  (:init
   (&key
    ((:next __next) 0)
    )
   (send-super :init)
   (setq _next (round __next))
   self)
  (:next
   (&optional __next)
   (if __next (setq _next __next)) _next)
  (:serialization-length
   ()
   (+
    ;; int32 _next
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _next
       (write-long _next s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _next
     (setq _next (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get test::next_piece :md5sum-) "89e3abdd267d92f91c4ae5f000c4dde5")
(setf (get test::next_piece :datatype-) "test/next_piece")
(setf (get test::next_piece :definition-)
      "int32 next
")



(provide :test/next_piece "89e3abdd267d92f91c4ae5f000c4dde5")


