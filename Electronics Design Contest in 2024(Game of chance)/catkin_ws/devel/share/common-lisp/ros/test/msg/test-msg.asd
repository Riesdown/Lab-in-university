
(cl:in-package :asdf)

(defsystem "test-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "all_position" :depends-on ("_package_all_position"))
    (:file "_package_all_position" :depends-on ("_package"))
    (:file "key_send" :depends-on ("_package_key_send"))
    (:file "_package_key_send" :depends-on ("_package"))
    (:file "next_piece" :depends-on ("_package_next_piece"))
    (:file "_package_next_piece" :depends-on ("_package"))
    (:file "piece" :depends-on ("_package_piece"))
    (:file "_package_piece" :depends-on ("_package"))
  ))