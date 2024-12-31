; Auto-generated. Do not edit!


(cl:in-package lanya_pkg-msg)


;//! \htmlinclude xc_wz_data.msg.html

(cl:defclass <xc_wz_data> (roslisp-msg-protocol:ros-message)
  ((xc_x
    :reader xc_x
    :initarg :xc_x
    :type cl:float
    :initform 0.0)
   (xc_y
    :reader xc_y
    :initarg :xc_y
    :type cl:float
    :initform 0.0))
)

(cl:defclass xc_wz_data (<xc_wz_data>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <xc_wz_data>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'xc_wz_data)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name lanya_pkg-msg:<xc_wz_data> is deprecated: use lanya_pkg-msg:xc_wz_data instead.")))

(cl:ensure-generic-function 'xc_x-val :lambda-list '(m))
(cl:defmethod xc_x-val ((m <xc_wz_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader lanya_pkg-msg:xc_x-val is deprecated.  Use lanya_pkg-msg:xc_x instead.")
  (xc_x m))

(cl:ensure-generic-function 'xc_y-val :lambda-list '(m))
(cl:defmethod xc_y-val ((m <xc_wz_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader lanya_pkg-msg:xc_y-val is deprecated.  Use lanya_pkg-msg:xc_y instead.")
  (xc_y m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <xc_wz_data>) ostream)
  "Serializes a message object of type '<xc_wz_data>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'xc_x))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'xc_y))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <xc_wz_data>) istream)
  "Deserializes a message object of type '<xc_wz_data>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'xc_x) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'xc_y) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<xc_wz_data>)))
  "Returns string type for a message object of type '<xc_wz_data>"
  "lanya_pkg/xc_wz_data")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'xc_wz_data)))
  "Returns string type for a message object of type 'xc_wz_data"
  "lanya_pkg/xc_wz_data")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<xc_wz_data>)))
  "Returns md5sum for a message object of type '<xc_wz_data>"
  "0af5983c67c5a0659bc718afae52c5bd")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'xc_wz_data)))
  "Returns md5sum for a message object of type 'xc_wz_data"
  "0af5983c67c5a0659bc718afae52c5bd")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<xc_wz_data>)))
  "Returns full string definition for message of type '<xc_wz_data>"
  (cl:format cl:nil "float32 xc_x~%float32 xc_y~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'xc_wz_data)))
  "Returns full string definition for message of type 'xc_wz_data"
  (cl:format cl:nil "float32 xc_x~%float32 xc_y~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <xc_wz_data>))
  (cl:+ 0
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <xc_wz_data>))
  "Converts a ROS message object to a list"
  (cl:list 'xc_wz_data
    (cl:cons ':xc_x (xc_x msg))
    (cl:cons ':xc_y (xc_y msg))
))
