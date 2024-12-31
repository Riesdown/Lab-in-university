; Auto-generated. Do not edit!


(cl:in-package lanya_pkg-msg)


;//! \htmlinclude fj_wz_data.msg.html

(cl:defclass <fj_wz_data> (roslisp-msg-protocol:ros-message)
  ((fj_x
    :reader fj_x
    :initarg :fj_x
    :type cl:float
    :initform 0.0)
   (fj_y
    :reader fj_y
    :initarg :fj_y
    :type cl:float
    :initform 0.0))
)

(cl:defclass fj_wz_data (<fj_wz_data>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <fj_wz_data>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'fj_wz_data)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name lanya_pkg-msg:<fj_wz_data> is deprecated: use lanya_pkg-msg:fj_wz_data instead.")))

(cl:ensure-generic-function 'fj_x-val :lambda-list '(m))
(cl:defmethod fj_x-val ((m <fj_wz_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader lanya_pkg-msg:fj_x-val is deprecated.  Use lanya_pkg-msg:fj_x instead.")
  (fj_x m))

(cl:ensure-generic-function 'fj_y-val :lambda-list '(m))
(cl:defmethod fj_y-val ((m <fj_wz_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader lanya_pkg-msg:fj_y-val is deprecated.  Use lanya_pkg-msg:fj_y instead.")
  (fj_y m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <fj_wz_data>) ostream)
  "Serializes a message object of type '<fj_wz_data>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'fj_x))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'fj_y))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <fj_wz_data>) istream)
  "Deserializes a message object of type '<fj_wz_data>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'fj_x) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'fj_y) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<fj_wz_data>)))
  "Returns string type for a message object of type '<fj_wz_data>"
  "lanya_pkg/fj_wz_data")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'fj_wz_data)))
  "Returns string type for a message object of type 'fj_wz_data"
  "lanya_pkg/fj_wz_data")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<fj_wz_data>)))
  "Returns md5sum for a message object of type '<fj_wz_data>"
  "11a2e9cf43a8ca7a8685679601c4ed90")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'fj_wz_data)))
  "Returns md5sum for a message object of type 'fj_wz_data"
  "11a2e9cf43a8ca7a8685679601c4ed90")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<fj_wz_data>)))
  "Returns full string definition for message of type '<fj_wz_data>"
  (cl:format cl:nil "float32 fj_x~%float32 fj_y~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'fj_wz_data)))
  "Returns full string definition for message of type 'fj_wz_data"
  (cl:format cl:nil "float32 fj_x~%float32 fj_y~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <fj_wz_data>))
  (cl:+ 0
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <fj_wz_data>))
  "Converts a ROS message object to a list"
  (cl:list 'fj_wz_data
    (cl:cons ':fj_x (fj_x msg))
    (cl:cons ':fj_y (fj_y msg))
))
