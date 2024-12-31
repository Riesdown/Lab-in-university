; Auto-generated. Do not edit!


(cl:in-package test-msg)


;//! \htmlinclude set_position.msg.html

(cl:defclass <set_position> (roslisp-msg-protocol:ros-message)
  ((x
    :reader x
    :initarg :x
    :type cl:float
    :initform 0.0)
   (y
    :reader y
    :initarg :y
    :type cl:float
    :initform 0.0)
   (z
    :reader z
    :initarg :z
    :type cl:float
    :initform 0.0)
   (flag1
    :reader flag1
    :initarg :flag1
    :type cl:float
    :initform 0.0))
)

(cl:defclass set_position (<set_position>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <set_position>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'set_position)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name test-msg:<set_position> is deprecated: use test-msg:set_position instead.")))

(cl:ensure-generic-function 'x-val :lambda-list '(m))
(cl:defmethod x-val ((m <set_position>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader test-msg:x-val is deprecated.  Use test-msg:x instead.")
  (x m))

(cl:ensure-generic-function 'y-val :lambda-list '(m))
(cl:defmethod y-val ((m <set_position>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader test-msg:y-val is deprecated.  Use test-msg:y instead.")
  (y m))

(cl:ensure-generic-function 'z-val :lambda-list '(m))
(cl:defmethod z-val ((m <set_position>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader test-msg:z-val is deprecated.  Use test-msg:z instead.")
  (z m))

(cl:ensure-generic-function 'flag1-val :lambda-list '(m))
(cl:defmethod flag1-val ((m <set_position>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader test-msg:flag1-val is deprecated.  Use test-msg:flag1 instead.")
  (flag1 m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <set_position>) ostream)
  "Serializes a message object of type '<set_position>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'x))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'y))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'z))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'flag1))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <set_position>) istream)
  "Deserializes a message object of type '<set_position>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'x) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'y) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'z) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'flag1) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<set_position>)))
  "Returns string type for a message object of type '<set_position>"
  "test/set_position")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'set_position)))
  "Returns string type for a message object of type 'set_position"
  "test/set_position")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<set_position>)))
  "Returns md5sum for a message object of type '<set_position>"
  "5f7db468f1f67d536e537686487991cd")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'set_position)))
  "Returns md5sum for a message object of type 'set_position"
  "5f7db468f1f67d536e537686487991cd")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<set_position>)))
  "Returns full string definition for message of type '<set_position>"
  (cl:format cl:nil "float32  x~%float32  y~%float32  z~%float32 flag1~%~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'set_position)))
  "Returns full string definition for message of type 'set_position"
  (cl:format cl:nil "float32  x~%float32  y~%float32  z~%float32 flag1~%~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <set_position>))
  (cl:+ 0
     4
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <set_position>))
  "Converts a ROS message object to a list"
  (cl:list 'set_position
    (cl:cons ':x (x msg))
    (cl:cons ':y (y msg))
    (cl:cons ':z (z msg))
    (cl:cons ':flag1 (flag1 msg))
))
