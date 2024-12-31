; Auto-generated. Do not edit!


(cl:in-package test-msg)


;//! \htmlinclude piece.msg.html

(cl:defclass <piece> (roslisp-msg-protocol:ros-message)
  ((angle
    :reader angle
    :initarg :angle
    :type cl:float
    :initform 0.0)
   (id
    :reader id
    :initarg :id
    :type cl:integer
    :initform 0)
   (status
    :reader status
    :initarg :status
    :type cl:integer
    :initform 0))
)

(cl:defclass piece (<piece>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <piece>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'piece)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name test-msg:<piece> is deprecated: use test-msg:piece instead.")))

(cl:ensure-generic-function 'angle-val :lambda-list '(m))
(cl:defmethod angle-val ((m <piece>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader test-msg:angle-val is deprecated.  Use test-msg:angle instead.")
  (angle m))

(cl:ensure-generic-function 'id-val :lambda-list '(m))
(cl:defmethod id-val ((m <piece>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader test-msg:id-val is deprecated.  Use test-msg:id instead.")
  (id m))

(cl:ensure-generic-function 'status-val :lambda-list '(m))
(cl:defmethod status-val ((m <piece>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader test-msg:status-val is deprecated.  Use test-msg:status instead.")
  (status m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <piece>) ostream)
  "Serializes a message object of type '<piece>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'angle))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let* ((signed (cl:slot-value msg 'id)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'status)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <piece>) istream)
  "Deserializes a message object of type '<piece>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'angle) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'id) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'status) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<piece>)))
  "Returns string type for a message object of type '<piece>"
  "test/piece")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'piece)))
  "Returns string type for a message object of type 'piece"
  "test/piece")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<piece>)))
  "Returns md5sum for a message object of type '<piece>"
  "306bc2650a33dfc448b8d4bd5ce5a685")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'piece)))
  "Returns md5sum for a message object of type 'piece"
  "306bc2650a33dfc448b8d4bd5ce5a685")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<piece>)))
  "Returns full string definition for message of type '<piece>"
  (cl:format cl:nil "float32 angle   # 旋转角度~%int32 id        # 方格ID~%int32 status    # 小格状态~%~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'piece)))
  "Returns full string definition for message of type 'piece"
  (cl:format cl:nil "float32 angle   # 旋转角度~%int32 id        # 方格ID~%int32 status    # 小格状态~%~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <piece>))
  (cl:+ 0
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <piece>))
  "Converts a ROS message object to a list"
  (cl:list 'piece
    (cl:cons ':angle (angle msg))
    (cl:cons ':id (id msg))
    (cl:cons ':status (status msg))
))
