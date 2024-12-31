; Auto-generated. Do not edit!


(cl:in-package test-msg)


;//! \htmlinclude next_piece.msg.html

(cl:defclass <next_piece> (roslisp-msg-protocol:ros-message)
  ((next
    :reader next
    :initarg :next
    :type cl:integer
    :initform 0))
)

(cl:defclass next_piece (<next_piece>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <next_piece>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'next_piece)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name test-msg:<next_piece> is deprecated: use test-msg:next_piece instead.")))

(cl:ensure-generic-function 'next-val :lambda-list '(m))
(cl:defmethod next-val ((m <next_piece>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader test-msg:next-val is deprecated.  Use test-msg:next instead.")
  (next m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <next_piece>) ostream)
  "Serializes a message object of type '<next_piece>"
  (cl:let* ((signed (cl:slot-value msg 'next)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <next_piece>) istream)
  "Deserializes a message object of type '<next_piece>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'next) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<next_piece>)))
  "Returns string type for a message object of type '<next_piece>"
  "test/next_piece")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'next_piece)))
  "Returns string type for a message object of type 'next_piece"
  "test/next_piece")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<next_piece>)))
  "Returns md5sum for a message object of type '<next_piece>"
  "89e3abdd267d92f91c4ae5f000c4dde5")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'next_piece)))
  "Returns md5sum for a message object of type 'next_piece"
  "89e3abdd267d92f91c4ae5f000c4dde5")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<next_piece>)))
  "Returns full string definition for message of type '<next_piece>"
  (cl:format cl:nil "int32 next~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'next_piece)))
  "Returns full string definition for message of type 'next_piece"
  (cl:format cl:nil "int32 next~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <next_piece>))
  (cl:+ 0
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <next_piece>))
  "Converts a ROS message object to a list"
  (cl:list 'next_piece
    (cl:cons ':next (next msg))
))
