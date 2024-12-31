; Auto-generated. Do not edit!


(cl:in-package user_messages-msg)


;//! \htmlinclude navigation_ctrl.msg.html

(cl:defclass <navigation_ctrl> (roslisp-msg-protocol:ros-message)
  ((x
    :reader x
    :initarg :x
    :type cl:float
    :initform 0.0)
   (y
    :reader y
    :initarg :y
    :type cl:float
    :initform 0.0)
   (z
    :reader z
    :initarg :z
    :type cl:float
    :initform 0.0)
   (nav_mode
    :reader nav_mode
    :initarg :nav_mode
    :type cl:fixnum
    :initform 0)
   (frame_id
    :reader frame_id
    :initarg :frame_id
    :type cl:fixnum
    :initform 0)
   (num
    :reader num
    :initarg :num
    :type cl:fixnum
    :initform 0)
   (execution_time
    :reader execution_time
    :initarg :execution_time
    :type cl:integer
    :initform 0)
   (update_flag
    :reader update_flag
    :initarg :update_flag
    :type cl:fixnum
    :initform 0))
)

(cl:defclass navigation_ctrl (<navigation_ctrl>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <navigation_ctrl>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'navigation_ctrl)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name user_messages-msg:<navigation_ctrl> is deprecated: use user_messages-msg:navigation_ctrl instead.")))

(cl:ensure-generic-function 'x-val :lambda-list '(m))
(cl:defmethod x-val ((m <navigation_ctrl>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader user_messages-msg:x-val is deprecated.  Use user_messages-msg:x instead.")
  (x m))

(cl:ensure-generic-function 'y-val :lambda-list '(m))
(cl:defmethod y-val ((m <navigation_ctrl>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader user_messages-msg:y-val is deprecated.  Use user_messages-msg:y instead.")
  (y m))

(cl:ensure-generic-function 'z-val :lambda-list '(m))
(cl:defmethod z-val ((m <navigation_ctrl>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader user_messages-msg:z-val is deprecated.  Use user_messages-msg:z instead.")
  (z m))

(cl:ensure-generic-function 'nav_mode-val :lambda-list '(m))
(cl:defmethod nav_mode-val ((m <navigation_ctrl>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader user_messages-msg:nav_mode-val is deprecated.  Use user_messages-msg:nav_mode instead.")
  (nav_mode m))

(cl:ensure-generic-function 'frame_id-val :lambda-list '(m))
(cl:defmethod frame_id-val ((m <navigation_ctrl>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader user_messages-msg:frame_id-val is deprecated.  Use user_messages-msg:frame_id instead.")
  (frame_id m))

(cl:ensure-generic-function 'num-val :lambda-list '(m))
(cl:defmethod num-val ((m <navigation_ctrl>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader user_messages-msg:num-val is deprecated.  Use user_messages-msg:num instead.")
  (num m))

(cl:ensure-generic-function 'execution_time-val :lambda-list '(m))
(cl:defmethod execution_time-val ((m <navigation_ctrl>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader user_messages-msg:execution_time-val is deprecated.  Use user_messages-msg:execution_time instead.")
  (execution_time m))

(cl:ensure-generic-function 'update_flag-val :lambda-list '(m))
(cl:defmethod update_flag-val ((m <navigation_ctrl>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader user_messages-msg:update_flag-val is deprecated.  Use user_messages-msg:update_flag instead.")
  (update_flag m))
(cl:defmethod roslisp-msg-protocol:symbol-codes ((msg-type (cl:eql '<navigation_ctrl>)))
    "Constants for message type '<navigation_ctrl>"
  '((:BODY_FRAME . 0)
    (:MAP_FRAME . 1)
    (:RELATIVE_MODE . 0)
    (:GLOBAL_MODE . 1)
    (:CMD_VEL_MODE . 2))
)
(cl:defmethod roslisp-msg-protocol:symbol-codes ((msg-type (cl:eql 'navigation_ctrl)))
    "Constants for message type 'navigation_ctrl"
  '((:BODY_FRAME . 0)
    (:MAP_FRAME . 1)
    (:RELATIVE_MODE . 0)
    (:GLOBAL_MODE . 1)
    (:CMD_VEL_MODE . 2))
)
(cl:defmethod roslisp-msg-protocol:serialize ((msg <navigation_ctrl>) ostream)
  "Serializes a message object of type '<navigation_ctrl>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'x))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'y))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'z))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'nav_mode)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'frame_id)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'num)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'num)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'execution_time)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'execution_time)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'execution_time)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'execution_time)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'update_flag)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <navigation_ctrl>) istream)
  "Deserializes a message object of type '<navigation_ctrl>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'x) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'y) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'z) (roslisp-utils:decode-single-float-bits bits)))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'nav_mode)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'frame_id)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'num)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'num)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'execution_time)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'execution_time)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'execution_time)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'execution_time)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'update_flag)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<navigation_ctrl>)))
  "Returns string type for a message object of type '<navigation_ctrl>"
  "user_messages/navigation_ctrl")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'navigation_ctrl)))
  "Returns string type for a message object of type 'navigation_ctrl"
  "user_messages/navigation_ctrl")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<navigation_ctrl>)))
  "Returns md5sum for a message object of type '<navigation_ctrl>"
  "57540d12dfd9892331224880fa18114a")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'navigation_ctrl)))
  "Returns md5sum for a message object of type 'navigation_ctrl"
  "57540d12dfd9892331224880fa18114a")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<navigation_ctrl>)))
  "Returns full string definition for message of type '<navigation_ctrl>"
  (cl:format cl:nil "float32 x~%float32 y~%float32 z~%uint8 nav_mode~%uint8 frame_id~%uint16 num~%uint32 execution_time~%uint8 update_flag~%~%uint8 BODY_FRAME=0~%uint8 MAP_FRAME=1~%uint8 RELATIVE_MODE=0~%uint8 GLOBAL_MODE=1~%uint8 CMD_VEL_MODE=2~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'navigation_ctrl)))
  "Returns full string definition for message of type 'navigation_ctrl"
  (cl:format cl:nil "float32 x~%float32 y~%float32 z~%uint8 nav_mode~%uint8 frame_id~%uint16 num~%uint32 execution_time~%uint8 update_flag~%~%uint8 BODY_FRAME=0~%uint8 MAP_FRAME=1~%uint8 RELATIVE_MODE=0~%uint8 GLOBAL_MODE=1~%uint8 CMD_VEL_MODE=2~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <navigation_ctrl>))
  (cl:+ 0
     4
     4
     4
     1
     1
     2
     4
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <navigation_ctrl>))
  "Converts a ROS message object to a list"
  (cl:list 'navigation_ctrl
    (cl:cons ':x (x msg))
    (cl:cons ':y (y msg))
    (cl:cons ':z (z msg))
    (cl:cons ':nav_mode (nav_mode msg))
    (cl:cons ':frame_id (frame_id msg))
    (cl:cons ':num (num msg))
    (cl:cons ':execution_time (execution_time msg))
    (cl:cons ':update_flag (update_flag msg))
))
