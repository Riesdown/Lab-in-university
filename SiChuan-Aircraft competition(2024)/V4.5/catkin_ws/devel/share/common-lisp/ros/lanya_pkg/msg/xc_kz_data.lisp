; Auto-generated. Do not edit!


(cl:in-package lanya_pkg-msg)


;//! \htmlinclude xc_kz_data.msg.html

(cl:defclass <xc_kz_data> (roslisp-msg-protocol:ros-message)
  ((kz_str
    :reader kz_str
    :initarg :kz_str
    :type cl:string
    :initform ""))
)

(cl:defclass xc_kz_data (<xc_kz_data>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <xc_kz_data>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'xc_kz_data)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name lanya_pkg-msg:<xc_kz_data> is deprecated: use lanya_pkg-msg:xc_kz_data instead.")))

(cl:ensure-generic-function 'kz_str-val :lambda-list '(m))
(cl:defmethod kz_str-val ((m <xc_kz_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader lanya_pkg-msg:kz_str-val is deprecated.  Use lanya_pkg-msg:kz_str instead.")
  (kz_str m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <xc_kz_data>) ostream)
  "Serializes a message object of type '<xc_kz_data>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'kz_str))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'kz_str))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <xc_kz_data>) istream)
  "Deserializes a message object of type '<xc_kz_data>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'kz_str) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'kz_str) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<xc_kz_data>)))
  "Returns string type for a message object of type '<xc_kz_data>"
  "lanya_pkg/xc_kz_data")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'xc_kz_data)))
  "Returns string type for a message object of type 'xc_kz_data"
  "lanya_pkg/xc_kz_data")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<xc_kz_data>)))
  "Returns md5sum for a message object of type '<xc_kz_data>"
  "faf6e880b42507c6d64b003da8b79bd3")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'xc_kz_data)))
  "Returns md5sum for a message object of type 'xc_kz_data"
  "faf6e880b42507c6d64b003da8b79bd3")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<xc_kz_data>)))
  "Returns full string definition for message of type '<xc_kz_data>"
  (cl:format cl:nil "string kz_str~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'xc_kz_data)))
  "Returns full string definition for message of type 'xc_kz_data"
  (cl:format cl:nil "string kz_str~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <xc_kz_data>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'kz_str))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <xc_kz_data>))
  "Converts a ROS message object to a list"
  (cl:list 'xc_kz_data
    (cl:cons ':kz_str (kz_str msg))
))
