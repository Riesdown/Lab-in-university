; Auto-generated. Do not edit!


(cl:in-package number_recognize_node-msg)


;//! \htmlinclude numeber_info_msgs.msg.html

(cl:defclass <numeber_info_msgs> (roslisp-msg-protocol:ros-message)
  ((num
    :reader num
    :initarg :num
    :type cl:integer
    :initform 0)
   (center_x
    :reader center_x
    :initarg :center_x
    :type cl:integer
    :initform 0)
   (center_y
    :reader center_y
    :initarg :center_y
    :type cl:integer
    :initform 0)
   (flag
    :reader flag
    :initarg :flag
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass numeber_info_msgs (<numeber_info_msgs>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <numeber_info_msgs>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'numeber_info_msgs)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name number_recognize_node-msg:<numeber_info_msgs> is deprecated: use number_recognize_node-msg:numeber_info_msgs instead.")))

(cl:ensure-generic-function 'num-val :lambda-list '(m))
(cl:defmethod num-val ((m <numeber_info_msgs>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader number_recognize_node-msg:num-val is deprecated.  Use number_recognize_node-msg:num instead.")
  (num m))

(cl:ensure-generic-function 'center_x-val :lambda-list '(m))
(cl:defmethod center_x-val ((m <numeber_info_msgs>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader number_recognize_node-msg:center_x-val is deprecated.  Use number_recognize_node-msg:center_x instead.")
  (center_x m))

(cl:ensure-generic-function 'center_y-val :lambda-list '(m))
(cl:defmethod center_y-val ((m <numeber_info_msgs>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader number_recognize_node-msg:center_y-val is deprecated.  Use number_recognize_node-msg:center_y instead.")
  (center_y m))

(cl:ensure-generic-function 'flag-val :lambda-list '(m))
(cl:defmethod flag-val ((m <numeber_info_msgs>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader number_recognize_node-msg:flag-val is deprecated.  Use number_recognize_node-msg:flag instead.")
  (flag m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <numeber_info_msgs>) ostream)
  "Serializes a message object of type '<numeber_info_msgs>"
  (cl:let* ((signed (cl:slot-value msg 'num)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'center_x)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'center_y)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'flag) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <numeber_info_msgs>) istream)
  "Deserializes a message object of type '<numeber_info_msgs>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'num) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'center_x) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'center_y) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:setf (cl:slot-value msg 'flag) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<numeber_info_msgs>)))
  "Returns string type for a message object of type '<numeber_info_msgs>"
  "number_recognize_node/numeber_info_msgs")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'numeber_info_msgs)))
  "Returns string type for a message object of type 'numeber_info_msgs"
  "number_recognize_node/numeber_info_msgs")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<numeber_info_msgs>)))
  "Returns md5sum for a message object of type '<numeber_info_msgs>"
  "d26e9a9b11d6e0b99d95bf5f9545549a")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'numeber_info_msgs)))
  "Returns md5sum for a message object of type 'numeber_info_msgs"
  "d26e9a9b11d6e0b99d95bf5f9545549a")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<numeber_info_msgs>)))
  "Returns full string definition for message of type '<numeber_info_msgs>"
  (cl:format cl:nil "int32 num~%int32 center_x~%int32 center_y~%bool flag~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'numeber_info_msgs)))
  "Returns full string definition for message of type 'numeber_info_msgs"
  (cl:format cl:nil "int32 num~%int32 center_x~%int32 center_y~%bool flag~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <numeber_info_msgs>))
  (cl:+ 0
     4
     4
     4
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <numeber_info_msgs>))
  "Converts a ROS message object to a list"
  (cl:list 'numeber_info_msgs
    (cl:cons ':num (num msg))
    (cl:cons ':center_x (center_x msg))
    (cl:cons ':center_y (center_y msg))
    (cl:cons ':flag (flag msg))
))
