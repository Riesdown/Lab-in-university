; Auto-generated. Do not edit!


(cl:in-package test-msg)


;//! \htmlinclude arm_state.msg.html

(cl:defclass <arm_state> (roslisp-msg-protocol:ros-message)
  ((chess_aim_x
    :reader chess_aim_x
    :initarg :chess_aim_x
    :type cl:float
    :initform 0.0)
   (chess_aim_y
    :reader chess_aim_y
    :initarg :chess_aim_y
    :type cl:float
    :initform 0.0))
)

(cl:defclass arm_state (<arm_state>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <arm_state>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'arm_state)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name test-msg:<arm_state> is deprecated: use test-msg:arm_state instead.")))

(cl:ensure-generic-function 'chess_aim_x-val :lambda-list '(m))
(cl:defmethod chess_aim_x-val ((m <arm_state>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader test-msg:chess_aim_x-val is deprecated.  Use test-msg:chess_aim_x instead.")
  (chess_aim_x m))

(cl:ensure-generic-function 'chess_aim_y-val :lambda-list '(m))
(cl:defmethod chess_aim_y-val ((m <arm_state>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader test-msg:chess_aim_y-val is deprecated.  Use test-msg:chess_aim_y instead.")
  (chess_aim_y m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <arm_state>) ostream)
  "Serializes a message object of type '<arm_state>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'chess_aim_x))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'chess_aim_y))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <arm_state>) istream)
  "Deserializes a message object of type '<arm_state>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'chess_aim_x) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'chess_aim_y) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<arm_state>)))
  "Returns string type for a message object of type '<arm_state>"
  "test/arm_state")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'arm_state)))
  "Returns string type for a message object of type 'arm_state"
  "test/arm_state")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<arm_state>)))
  "Returns md5sum for a message object of type '<arm_state>"
  "021ae4e1499fe0af22a25b5797cdfc12")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'arm_state)))
  "Returns md5sum for a message object of type 'arm_state"
  "021ae4e1499fe0af22a25b5797cdfc12")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<arm_state>)))
  "Returns full string definition for message of type '<arm_state>"
  (cl:format cl:nil "float32 chess_aim_x     # 棋子目的位置x~%float32 chess_aim_y     # 棋子目的位置y~%~%~%~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'arm_state)))
  "Returns full string definition for message of type 'arm_state"
  (cl:format cl:nil "float32 chess_aim_x     # 棋子目的位置x~%float32 chess_aim_y     # 棋子目的位置y~%~%~%~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <arm_state>))
  (cl:+ 0
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <arm_state>))
  "Converts a ROS message object to a list"
  (cl:list 'arm_state
    (cl:cons ':chess_aim_x (chess_aim_x msg))
    (cl:cons ':chess_aim_y (chess_aim_y msg))
))
