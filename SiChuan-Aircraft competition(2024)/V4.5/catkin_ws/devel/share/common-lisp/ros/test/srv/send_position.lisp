; Auto-generated. Do not edit!


(cl:in-package test-srv)


;//! \htmlinclude send_position-request.msg.html

(cl:defclass <send_position-request> (roslisp-msg-protocol:ros-message)
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
    :initform 0.0))
)

(cl:defclass send_position-request (<send_position-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <send_position-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'send_position-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name test-srv:<send_position-request> is deprecated: use test-srv:send_position-request instead.")))

(cl:ensure-generic-function 'x-val :lambda-list '(m))
(cl:defmethod x-val ((m <send_position-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader test-srv:x-val is deprecated.  Use test-srv:x instead.")
  (x m))

(cl:ensure-generic-function 'y-val :lambda-list '(m))
(cl:defmethod y-val ((m <send_position-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader test-srv:y-val is deprecated.  Use test-srv:y instead.")
  (y m))

(cl:ensure-generic-function 'z-val :lambda-list '(m))
(cl:defmethod z-val ((m <send_position-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader test-srv:z-val is deprecated.  Use test-srv:z instead.")
  (z m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <send_position-request>) ostream)
  "Serializes a message object of type '<send_position-request>"
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
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <send_position-request>) istream)
  "Deserializes a message object of type '<send_position-request>"
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
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<send_position-request>)))
  "Returns string type for a service object of type '<send_position-request>"
  "test/send_positionRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'send_position-request)))
  "Returns string type for a service object of type 'send_position-request"
  "test/send_positionRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<send_position-request>)))
  "Returns md5sum for a message object of type '<send_position-request>"
  "cc153912f1453b708d221682bc23d9ac")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'send_position-request)))
  "Returns md5sum for a message object of type 'send_position-request"
  "cc153912f1453b708d221682bc23d9ac")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<send_position-request>)))
  "Returns full string definition for message of type '<send_position-request>"
  (cl:format cl:nil "float32 x~%float32 y~%float32 z~%~%~%~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'send_position-request)))
  "Returns full string definition for message of type 'send_position-request"
  (cl:format cl:nil "float32 x~%float32 y~%float32 z~%~%~%~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <send_position-request>))
  (cl:+ 0
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <send_position-request>))
  "Converts a ROS message object to a list"
  (cl:list 'send_position-request
    (cl:cons ':x (x msg))
    (cl:cons ':y (y msg))
    (cl:cons ':z (z msg))
))
;//! \htmlinclude send_position-response.msg.html

(cl:defclass <send_position-response> (roslisp-msg-protocol:ros-message)
  ()
)

(cl:defclass send_position-response (<send_position-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <send_position-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'send_position-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name test-srv:<send_position-response> is deprecated: use test-srv:send_position-response instead.")))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <send_position-response>) ostream)
  "Serializes a message object of type '<send_position-response>"
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <send_position-response>) istream)
  "Deserializes a message object of type '<send_position-response>"
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<send_position-response>)))
  "Returns string type for a service object of type '<send_position-response>"
  "test/send_positionResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'send_position-response)))
  "Returns string type for a service object of type 'send_position-response"
  "test/send_positionResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<send_position-response>)))
  "Returns md5sum for a message object of type '<send_position-response>"
  "cc153912f1453b708d221682bc23d9ac")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'send_position-response)))
  "Returns md5sum for a message object of type 'send_position-response"
  "cc153912f1453b708d221682bc23d9ac")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<send_position-response>)))
  "Returns full string definition for message of type '<send_position-response>"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'send_position-response)))
  "Returns full string definition for message of type 'send_position-response"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <send_position-response>))
  (cl:+ 0
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <send_position-response>))
  "Converts a ROS message object to a list"
  (cl:list 'send_position-response
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'send_position)))
  'send_position-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'send_position)))
  'send_position-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'send_position)))
  "Returns string type for a service object of type '<send_position>"
  "test/send_position")