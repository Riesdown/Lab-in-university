; Auto-generated. Do not edit!


(cl:in-package user_messages-msg)


;//! \htmlinclude serialport_decode.msg.html

(cl:defclass <serialport_decode> (roslisp-msg-protocol:ros-message)
  ((buf
    :reader buf
    :initarg :buf
    :type (cl:vector cl:fixnum)
   :initform (cl:make-array 0 :element-type 'cl:fixnum :initial-element 0))
   (cnt
    :reader cnt
    :initarg :cnt
    :type cl:fixnum
    :initform 0))
)

(cl:defclass serialport_decode (<serialport_decode>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <serialport_decode>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'serialport_decode)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name user_messages-msg:<serialport_decode> is deprecated: use user_messages-msg:serialport_decode instead.")))

(cl:ensure-generic-function 'buf-val :lambda-list '(m))
(cl:defmethod buf-val ((m <serialport_decode>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader user_messages-msg:buf-val is deprecated.  Use user_messages-msg:buf instead.")
  (buf m))

(cl:ensure-generic-function 'cnt-val :lambda-list '(m))
(cl:defmethod cnt-val ((m <serialport_decode>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader user_messages-msg:cnt-val is deprecated.  Use user_messages-msg:cnt instead.")
  (cnt m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <serialport_decode>) ostream)
  "Serializes a message object of type '<serialport_decode>"
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'buf))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:write-byte (cl:ldb (cl:byte 8 0) ele) ostream))
   (cl:slot-value msg 'buf))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'cnt)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'cnt)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <serialport_decode>) istream)
  "Deserializes a message object of type '<serialport_decode>"
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'buf) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'buf)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:aref vals i)) (cl:read-byte istream)))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'cnt)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'cnt)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<serialport_decode>)))
  "Returns string type for a message object of type '<serialport_decode>"
  "user_messages/serialport_decode")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'serialport_decode)))
  "Returns string type for a message object of type 'serialport_decode"
  "user_messages/serialport_decode")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<serialport_decode>)))
  "Returns md5sum for a message object of type '<serialport_decode>"
  "b64998cbe9ab1eb940716392cc08fe66")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'serialport_decode)))
  "Returns md5sum for a message object of type 'serialport_decode"
  "b64998cbe9ab1eb940716392cc08fe66")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<serialport_decode>)))
  "Returns full string definition for message of type '<serialport_decode>"
  (cl:format cl:nil "uint8[] buf~%uint16 cnt~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'serialport_decode)))
  "Returns full string definition for message of type 'serialport_decode"
  (cl:format cl:nil "uint8[] buf~%uint16 cnt~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <serialport_decode>))
  (cl:+ 0
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'buf) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 1)))
     2
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <serialport_decode>))
  "Converts a ROS message object to a list"
  (cl:list 'serialport_decode
    (cl:cons ':buf (buf msg))
    (cl:cons ':cnt (cnt msg))
))
