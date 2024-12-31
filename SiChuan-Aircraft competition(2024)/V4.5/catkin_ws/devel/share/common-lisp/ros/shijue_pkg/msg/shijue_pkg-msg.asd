
(cl:in-package :asdf)

(defsystem "shijue_pkg-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "weizhi_data" :depends-on ("_package_weizhi_data"))
    (:file "_package_weizhi_data" :depends-on ("_package"))
  ))