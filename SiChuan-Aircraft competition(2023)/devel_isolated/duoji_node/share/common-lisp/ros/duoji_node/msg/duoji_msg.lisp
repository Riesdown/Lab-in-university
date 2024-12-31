; Auto-generated. Do not edit!


(cl:in-package duoji_node-msg)


;//! \htmlinclude duoji_msg.msg.html

(cl:defclass <duoji_msg> (roslisp-msg-protocol:ros-message)
  ((Duoji_angle
    :reader Duoji_angle
    :initarg :Duoji_angle
    :type cl:integer
    :initform 0))
)

(cl:defclass duoji_msg (<duoji_msg>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <duoji_msg>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'duoji_msg)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name duoji_node-msg:<duoji_msg> is deprecated: use duoji_node-msg:duoji_msg instead.")))

(cl:ensure-generic-function 'Duoji_angle-val :lambda-list '(m))
(cl:defmethod Duoji_angle-val ((m <duoji_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader duoji_node-msg:Duoji_angle-val is deprecated.  Use duoji_node-msg:Duoji_angle instead.")
  (Duoji_angle m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <duoji_msg>) ostream)
  "Serializes a message object of type '<duoji_msg>"
  (cl:let* ((signed (cl:slot-value msg 'Duoji_angle)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <duoji_msg>) istream)
  "Deserializes a message object of type '<duoji_msg>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'Duoji_angle) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<duoji_msg>)))
  "Returns string type for a message object of type '<duoji_msg>"
  "duoji_node/duoji_msg")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'duoji_msg)))
  "Returns string type for a message object of type 'duoji_msg"
  "duoji_node/duoji_msg")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<duoji_msg>)))
  "Returns md5sum for a message object of type '<duoji_msg>"
  "9bb68250934646b96771efd253d0ba16")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'duoji_msg)))
  "Returns md5sum for a message object of type 'duoji_msg"
  "9bb68250934646b96771efd253d0ba16")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<duoji_msg>)))
  "Returns full string definition for message of type '<duoji_msg>"
  (cl:format cl:nil "int32 Duoji_angle~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'duoji_msg)))
  "Returns full string definition for message of type 'duoji_msg"
  (cl:format cl:nil "int32 Duoji_angle~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <duoji_msg>))
  (cl:+ 0
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <duoji_msg>))
  "Converts a ROS message object to a list"
  (cl:list 'duoji_msg
    (cl:cons ':Duoji_angle (Duoji_angle msg))
))
