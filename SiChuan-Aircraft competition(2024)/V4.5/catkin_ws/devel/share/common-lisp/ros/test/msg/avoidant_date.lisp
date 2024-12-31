; Auto-generated. Do not edit!


(cl:in-package test-msg)


;//! \htmlinclude avoidant_date.msg.html

(cl:defclass <avoidant_date> (roslisp-msg-protocol:ros-message)
  ((x
    :reader x
    :initarg :x
    :type cl:float
    :initform 0.0)
   (y
    :reader y
    :initarg :y
    :type cl:float
    :initform 0.0))
)

(cl:defclass avoidant_date (<avoidant_date>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <avoidant_date>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'avoidant_date)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name test-msg:<avoidant_date> is deprecated: use test-msg:avoidant_date instead.")))

(cl:ensure-generic-function 'x-val :lambda-list '(m))
(cl:defmethod x-val ((m <avoidant_date>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader test-msg:x-val is deprecated.  Use test-msg:x instead.")
  (x m))

(cl:ensure-generic-function 'y-val :lambda-list '(m))
(cl:defmethod y-val ((m <avoidant_date>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader test-msg:y-val is deprecated.  Use test-msg:y instead.")
  (y m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <avoidant_date>) ostream)
  "Serializes a message object of type '<avoidant_date>"
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
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <avoidant_date>) istream)
  "Deserializes a message object of type '<avoidant_date>"
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
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<avoidant_date>)))
  "Returns string type for a message object of type '<avoidant_date>"
  "test/avoidant_date")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'avoidant_date)))
  "Returns string type for a message object of type 'avoidant_date"
  "test/avoidant_date")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<avoidant_date>)))
  "Returns md5sum for a message object of type '<avoidant_date>"
  "ff8d7d66dd3e4b731ef14a45d38888b6")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'avoidant_date)))
  "Returns md5sum for a message object of type 'avoidant_date"
  "ff8d7d66dd3e4b731ef14a45d38888b6")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<avoidant_date>)))
  "Returns full string definition for message of type '<avoidant_date>"
  (cl:format cl:nil "float32  x~%float32  y~%~%~%~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'avoidant_date)))
  "Returns full string definition for message of type 'avoidant_date"
  (cl:format cl:nil "float32  x~%float32  y~%~%~%~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <avoidant_date>))
  (cl:+ 0
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <avoidant_date>))
  "Converts a ROS message object to a list"
  (cl:list 'avoidant_date
    (cl:cons ':x (x msg))
    (cl:cons ':y (y msg))
))
