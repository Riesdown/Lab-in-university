
(cl:in-package :asdf)

(defsystem "serialport-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "position_cmd" :depends-on ("_package_position_cmd"))
    (:file "_package_position_cmd" :depends-on ("_package"))
  ))