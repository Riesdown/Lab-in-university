; Auto-generated. Do not edit!


(cl:in-package test-msg)


;//! \htmlinclude key_send.msg.html

(cl:defclass <key_send> (roslisp-msg-protocol:ros-message)
  ((chess_change
    :reader chess_change
    :initarg :chess_change
    :type cl:integer
    :initform 0)
   (chess_num
    :reader chess_num
    :initarg :chess_num
    :type cl:integer
    :initform 0)
   (position
    :reader position
    :initarg :position
    :type cl:integer
    :initform 0))
)

(cl:defclass key_send (<key_send>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <key_send>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'key_send)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name test-msg:<key_send> is deprecated: use test-msg:key_send instead.")))

(cl:ensure-generic-function 'chess_change-val :lambda-list '(m))
(cl:defmethod chess_change-val ((m <key_send>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader test-msg:chess_change-val is deprecated.  Use test-msg:chess_change instead.")
  (chess_change m))

(cl:ensure-generic-function 'chess_num-val :lambda-list '(m))
(cl:defmethod chess_num-val ((m <key_send>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader test-msg:chess_num-val is deprecated.  Use test-msg:chess_num instead.")
  (chess_num m))

(cl:ensure-generic-function 'position-val :lambda-list '(m))
(cl:defmethod position-val ((m <key_send>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader test-msg:position-val is deprecated.  Use test-msg:position instead.")
  (position m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <key_send>) ostream)
  "Serializes a message object of type '<key_send>"
  (cl:let* ((signed (cl:slot-value msg 'chess_change)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'chess_num)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'position)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <key_send>) istream)
  "Deserializes a message object of type '<key_send>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'chess_change) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'chess_num) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'position) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<key_send>)))
  "Returns string type for a message object of type '<key_send>"
  "test/key_send")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'key_send)))
  "Returns string type for a message object of type 'key_send"
  "test/key_send")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<key_send>)))
  "Returns md5sum for a message object of type '<key_send>"
  "1f77ffe24d4ef0b7fc703ecd866700bb")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'key_send)))
  "Returns md5sum for a message object of type 'key_send"
  "1f77ffe24d4ef0b7fc703ecd866700bb")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<key_send>)))
  "Returns full string definition for message of type '<key_send>"
  (cl:format cl:nil "int32 chess_change      # 棋子改变~%int32 chess_num         # 棋子编号~%int32 position          # 位置~%~%~%~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'key_send)))
  "Returns full string definition for message of type 'key_send"
  (cl:format cl:nil "int32 chess_change      # 棋子改变~%int32 chess_num         # 棋子编号~%int32 position          # 位置~%~%~%~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <key_send>))
  (cl:+ 0
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <key_send>))
  "Converts a ROS message object to a list"
  (cl:list 'key_send
    (cl:cons ':chess_change (chess_change msg))
    (cl:cons ':chess_num (chess_num msg))
    (cl:cons ':position (position msg))
))
