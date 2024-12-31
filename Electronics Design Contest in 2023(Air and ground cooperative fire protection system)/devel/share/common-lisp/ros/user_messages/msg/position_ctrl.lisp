; Auto-generated. Do not edit!


(cl:in-package user_messages-msg)


;//! \htmlinclude position_ctrl.msg.html

(cl:defclass <position_ctrl> (roslisp-msg-protocol:ros-message)
  ((move_flag
    :reader move_flag
    :initarg :move_flag
    :type cl:fixnum
    :initform 0)
   (move_order
    :reader move_order
    :initarg :move_order
    :type cl:fixnum
    :initform 0)
   (move_distance
    :reader move_distance
    :initarg :move_distance
    :type cl:fixnum
    :initform 0))
)

(cl:defclass position_ctrl (<position_ctrl>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <position_ctrl>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'position_ctrl)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name user_messages-msg:<position_ctrl> is deprecated: use user_messages-msg:position_ctrl instead.")))

(cl:ensure-generic-function 'move_flag-val :lambda-list '(m))
(cl:defmethod move_flag-val ((m <position_ctrl>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader user_messages-msg:move_flag-val is deprecated.  Use user_messages-msg:move_flag instead.")
  (move_flag m))

(cl:ensure-generic-function 'move_order-val :lambda-list '(m))
(cl:defmethod move_order-val ((m <position_ctrl>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader user_messages-msg:move_order-val is deprecated.  Use user_messages-msg:move_order instead.")
  (move_order m))

(cl:ensure-generic-function 'move_distance-val :lambda-list '(m))
(cl:defmethod move_distance-val ((m <position_ctrl>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader user_messages-msg:move_distance-val is deprecated.  Use user_messages-msg:move_distance instead.")
  (move_distance m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <position_ctrl>) ostream)
  "Serializes a message object of type '<position_ctrl>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'move_flag)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'move_order)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'move_distance)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'move_distance)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <position_ctrl>) istream)
  "Deserializes a message object of type '<position_ctrl>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'move_flag)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'move_order)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'move_distance)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'move_distance)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<position_ctrl>)))
  "Returns string type for a message object of type '<position_ctrl>"
  "user_messages/position_ctrl")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'position_ctrl)))
  "Returns string type for a message object of type 'position_ctrl"
  "user_messages/position_ctrl")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<position_ctrl>)))
  "Returns md5sum for a message object of type '<position_ctrl>"
  "4b35dc4f304f0d5f7eaa8dda10fe4862")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'position_ctrl)))
  "Returns md5sum for a message object of type 'position_ctrl"
  "4b35dc4f304f0d5f7eaa8dda10fe4862")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<position_ctrl>)))
  "Returns full string definition for message of type '<position_ctrl>"
  (cl:format cl:nil "uint8 move_flag~%uint8 move_order~%uint16 move_distance~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'position_ctrl)))
  "Returns full string definition for message of type 'position_ctrl"
  (cl:format cl:nil "uint8 move_flag~%uint8 move_order~%uint16 move_distance~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <position_ctrl>))
  (cl:+ 0
     1
     1
     2
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <position_ctrl>))
  "Converts a ROS message object to a list"
  (cl:list 'position_ctrl
    (cl:cons ':move_flag (move_flag msg))
    (cl:cons ':move_order (move_order msg))
    (cl:cons ':move_distance (move_distance msg))
))
