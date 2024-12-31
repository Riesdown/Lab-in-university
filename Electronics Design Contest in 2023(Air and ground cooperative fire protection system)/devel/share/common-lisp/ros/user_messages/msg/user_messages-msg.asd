
(cl:in-package :asdf)

(defsystem "user_messages-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "navigation_ctrl" :depends-on ("_package_navigation_ctrl"))
    (:file "_package_navigation_ctrl" :depends-on ("_package"))
    (:file "position_ctrl" :depends-on ("_package_position_ctrl"))
    (:file "_package_position_ctrl" :depends-on ("_package"))
    (:file "serialport_decode" :depends-on ("_package_serialport_decode"))
    (:file "_package_serialport_decode" :depends-on ("_package"))
  ))