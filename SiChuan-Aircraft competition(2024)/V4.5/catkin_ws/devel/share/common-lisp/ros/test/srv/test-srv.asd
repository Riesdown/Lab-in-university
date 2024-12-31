
(cl:in-package :asdf)

(defsystem "test-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "init" :depends-on ("_package_init"))
    (:file "_package_init" :depends-on ("_package"))
  ))