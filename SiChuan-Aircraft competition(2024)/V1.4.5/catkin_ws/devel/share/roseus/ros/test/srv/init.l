;; Auto-generated. Do not edit!


(when (boundp 'test::init)
  (if (not (find-package "TEST"))
    (make-package "TEST"))
  (shadow 'init (find-package "TEST")))
(unless (find-package "TEST::INIT")
  (make-package "TEST::INIT"))
(unless (find-package "TEST::INITREQUEST")
  (make-package "TEST::INITREQUEST"))
(unless (find-package "TEST::INITRESPONSE")
  (make-package "TEST::INITRESPONSE"))

(in-package "ROS")





(defclass test::initRequest
  :super ros::object
  :slots (_h1 _h2 _w_l _w_r ))

(defmethod test::initRequest
  (:init
   (&key
    ((:h1 __h1) 0.0)
    ((:h2 __h2) 0.0)
    ((:w_l __w_l) 0.0)
    ((:w_r __w_r) 0.0)
    )
   (send-super :init)
   (setq _h1 (float __h1))
   (setq _h2 (float __h2))
   (setq _w_l (float __w_l))
   (setq _w_r (float __w_r))
   self)
  (:h1
   (&optional __h1)
   (if __h1 (setq _h1 __h1)) _h1)
  (:h2
   (&optional __h2)
   (if __h2 (setq _h2 __h2)) _h2)
  (:w_l
   (&optional __w_l)
   (if __w_l (setq _w_l __w_l)) _w_l)
  (:w_r
   (&optional __w_r)
   (if __w_r (setq _w_r __w_r)) _w_r)
  (:serialization-length
   ()
   (+
    ;; float32 _h1
    4
    ;; float32 _h2
    4
    ;; float32 _w_l
    4
    ;; float32 _w_r
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _h1
       (sys::poke _h1 (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _h2
       (sys::poke _h2 (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _w_l
       (sys::poke _w_l (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _w_r
       (sys::poke _w_r (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _h1
     (setq _h1 (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _h2
     (setq _h2 (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _w_l
     (setq _w_l (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _w_r
     (setq _w_r (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(defclass test::initResponse
  :super ros::object
  :slots (_success ))

(defmethod test::initResponse
  (:init
   (&key
    ((:success __success) nil)
    )
   (send-super :init)
   (setq _success __success)
   self)
  (:success
   (&optional __success)
   (if __success (setq _success __success)) _success)
  (:serialization-length
   ()
   (+
    ;; bool _success
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _success
       (if _success (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _success
     (setq _success (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(defclass test::init
  :super ros::object
  :slots ())

(setf (get test::init :md5sum-) "642f7aacdf0e5b4d32599cf72b5a2ba9")
(setf (get test::init :datatype-) "test/init")
(setf (get test::init :request) test::initRequest)
(setf (get test::init :response) test::initResponse)

(defmethod test::initRequest
  (:response () (instance test::initResponse :init)))

(setf (get test::initRequest :md5sum-) "642f7aacdf0e5b4d32599cf72b5a2ba9")
(setf (get test::initRequest :datatype-) "test/initRequest")
(setf (get test::initRequest :definition-)
      "float32 h1
float32 h2

float32 w_l
float32 w_r
---
bool success

")

(setf (get test::initResponse :md5sum-) "642f7aacdf0e5b4d32599cf72b5a2ba9")
(setf (get test::initResponse :datatype-) "test/initResponse")
(setf (get test::initResponse :definition-)
      "float32 h1
float32 h2

float32 w_l
float32 w_r
---
bool success

")



(provide :test/init "642f7aacdf0e5b4d32599cf72b5a2ba9")


