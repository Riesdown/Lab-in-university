
(cl:in-package :asdf)

(defsystem "duoji_node-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "duoji_msg" :depends-on ("_package_duoji_msg"))
    (:file "_package_duoji_msg" :depends-on ("_package"))
  ))