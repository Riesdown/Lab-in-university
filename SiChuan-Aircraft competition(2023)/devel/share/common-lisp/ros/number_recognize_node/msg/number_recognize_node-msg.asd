
(cl:in-package :asdf)

(defsystem "number_recognize_node-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "numeber_info_msgs" :depends-on ("_package_numeber_info_msgs"))
    (:file "_package_numeber_info_msgs" :depends-on ("_package"))
  ))