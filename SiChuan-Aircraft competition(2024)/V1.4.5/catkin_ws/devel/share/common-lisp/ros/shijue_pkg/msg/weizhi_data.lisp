; Auto-generated. Do not edit!


(cl:in-package shijue_pkg-msg)


;//! \htmlinclude weizhi_data.msg.html

(cl:defclass <weizhi_data> (roslisp-msg-protocol:ros-message)
  ((wz_x
    :reader wz_x
    :initarg :wz_x
    :type cl:float
    :initform 0.0)
   (wz_y
    :reader wz_y
    :initarg :wz_y
    :type cl:float
    :initform 0.0)
   (flag
    :reader flag
    :initarg :flag
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass weizhi_data (<weizhi_data>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <weizhi_data>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'weizhi_data)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name shijue_pkg-msg:<weizhi_data> is deprecated: use shijue_pkg-msg:weizhi_data instead.")))

(cl:ensure-generic-function 'wz_x-val :lambda-list '(m))
(cl:defmethod wz_x-val ((m <weizhi_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader shijue_pkg-msg:wz_x-val is deprecated.  Use shijue_pkg-msg:wz_x instead.")
  (wz_x m))

(cl:ensure-generic-function 'wz_y-val :lambda-list '(m))
(cl:defmethod wz_y-val ((m <weizhi_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader shijue_pkg-msg:wz_y-val is deprecated.  Use shijue_pkg-msg:wz_y instead.")
  (wz_y m))

(cl:ensure-generic-function 'flag-val :lambda-list '(m))
(cl:defmethod flag-val ((m <weizhi_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader shijue_pkg-msg:flag-val is deprecated.  Use shijue_pkg-msg:flag instead.")
  (flag m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <weizhi_data>) ostream)
  "Serializes a message object of type '<weizhi_data>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'wz_x))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'wz_y))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'flag) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <weizhi_data>) istream)
  "Deserializes a message object of type '<weizhi_data>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'wz_x) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'wz_y) (roslisp-utils:decode-single-float-bits bits)))
    (cl:setf (cl:slot-value msg 'flag) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<weizhi_data>)))
  "Returns string type for a message object of type '<weizhi_data>"
  "shijue_pkg/weizhi_data")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'weizhi_data)))
  "Returns string type for a message object of type 'weizhi_data"
  "shijue_pkg/weizhi_data")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<weizhi_data>)))
  "Returns md5sum for a message object of type '<weizhi_data>"
  "9352d5e7401b90403eb2ff4ec8292292")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'weizhi_data)))
  "Returns md5sum for a message object of type 'weizhi_data"
  "9352d5e7401b90403eb2ff4ec8292292")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<weizhi_data>)))
  "Returns full string definition for message of type '<weizhi_data>"
  (cl:format cl:nil "float32 wz_x~%float32 wz_y~%bool flag~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'weizhi_data)))
  "Returns full string definition for message of type 'weizhi_data"
  (cl:format cl:nil "float32 wz_x~%float32 wz_y~%bool flag~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <weizhi_data>))
  (cl:+ 0
     4
     4
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <weizhi_data>))
  "Converts a ROS message object to a list"
  (cl:list 'weizhi_data
    (cl:cons ':wz_x (wz_x msg))
    (cl:cons ':wz_y (wz_y msg))
    (cl:cons ':flag (flag msg))
))
