; Auto-generated. Do not edit!


(cl:in-package test-srv)


;//! \htmlinclude init-request.msg.html

(cl:defclass <init-request> (roslisp-msg-protocol:ros-message)
  ((h1
    :reader h1
    :initarg :h1
    :type cl:float
    :initform 0.0)
   (h2
    :reader h2
    :initarg :h2
    :type cl:float
    :initform 0.0)
   (w_l
    :reader w_l
    :initarg :w_l
    :type cl:float
    :initform 0.0)
   (w_r
    :reader w_r
    :initarg :w_r
    :type cl:float
    :initform 0.0))
)

(cl:defclass init-request (<init-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <init-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'init-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name test-srv:<init-request> is deprecated: use test-srv:init-request instead.")))

(cl:ensure-generic-function 'h1-val :lambda-list '(m))
(cl:defmethod h1-val ((m <init-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader test-srv:h1-val is deprecated.  Use test-srv:h1 instead.")
  (h1 m))

(cl:ensure-generic-function 'h2-val :lambda-list '(m))
(cl:defmethod h2-val ((m <init-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader test-srv:h2-val is deprecated.  Use test-srv:h2 instead.")
  (h2 m))

(cl:ensure-generic-function 'w_l-val :lambda-list '(m))
(cl:defmethod w_l-val ((m <init-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader test-srv:w_l-val is deprecated.  Use test-srv:w_l instead.")
  (w_l m))

(cl:ensure-generic-function 'w_r-val :lambda-list '(m))
(cl:defmethod w_r-val ((m <init-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader test-srv:w_r-val is deprecated.  Use test-srv:w_r instead.")
  (w_r m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <init-request>) ostream)
  "Serializes a message object of type '<init-request>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'h1))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'h2))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'w_l))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'w_r))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <init-request>) istream)
  "Deserializes a message object of type '<init-request>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'h1) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'h2) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'w_l) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'w_r) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<init-request>)))
  "Returns string type for a service object of type '<init-request>"
  "test/initRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'init-request)))
  "Returns string type for a service object of type 'init-request"
  "test/initRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<init-request>)))
  "Returns md5sum for a message object of type '<init-request>"
  "642f7aacdf0e5b4d32599cf72b5a2ba9")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'init-request)))
  "Returns md5sum for a message object of type 'init-request"
  "642f7aacdf0e5b4d32599cf72b5a2ba9")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<init-request>)))
  "Returns full string definition for message of type '<init-request>"
  (cl:format cl:nil "float32 h1~%float32 h2~%~%float32 w_l~%float32 w_r~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'init-request)))
  "Returns full string definition for message of type 'init-request"
  (cl:format cl:nil "float32 h1~%float32 h2~%~%float32 w_l~%float32 w_r~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <init-request>))
  (cl:+ 0
     4
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <init-request>))
  "Converts a ROS message object to a list"
  (cl:list 'init-request
    (cl:cons ':h1 (h1 msg))
    (cl:cons ':h2 (h2 msg))
    (cl:cons ':w_l (w_l msg))
    (cl:cons ':w_r (w_r msg))
))
;//! \htmlinclude init-response.msg.html

(cl:defclass <init-response> (roslisp-msg-protocol:ros-message)
  ((success
    :reader success
    :initarg :success
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass init-response (<init-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <init-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'init-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name test-srv:<init-response> is deprecated: use test-srv:init-response instead.")))

(cl:ensure-generic-function 'success-val :lambda-list '(m))
(cl:defmethod success-val ((m <init-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader test-srv:success-val is deprecated.  Use test-srv:success instead.")
  (success m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <init-response>) ostream)
  "Serializes a message object of type '<init-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'success) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <init-response>) istream)
  "Deserializes a message object of type '<init-response>"
    (cl:setf (cl:slot-value msg 'success) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<init-response>)))
  "Returns string type for a service object of type '<init-response>"
  "test/initResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'init-response)))
  "Returns string type for a service object of type 'init-response"
  "test/initResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<init-response>)))
  "Returns md5sum for a message object of type '<init-response>"
  "642f7aacdf0e5b4d32599cf72b5a2ba9")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'init-response)))
  "Returns md5sum for a message object of type 'init-response"
  "642f7aacdf0e5b4d32599cf72b5a2ba9")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<init-response>)))
  "Returns full string definition for message of type '<init-response>"
  (cl:format cl:nil "bool success~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'init-response)))
  "Returns full string definition for message of type 'init-response"
  (cl:format cl:nil "bool success~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <init-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <init-response>))
  "Converts a ROS message object to a list"
  (cl:list 'init-response
    (cl:cons ':success (success msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'init)))
  'init-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'init)))
  'init-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'init)))
  "Returns string type for a service object of type '<init>"
  "test/init")