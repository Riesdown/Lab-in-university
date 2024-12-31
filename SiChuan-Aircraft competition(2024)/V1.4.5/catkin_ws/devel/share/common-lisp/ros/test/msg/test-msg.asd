
(cl:in-package :asdf)

(defsystem "test-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "avoidant_date" :depends-on ("_package_avoidant_date"))
    (:file "_package_avoidant_date" :depends-on ("_package"))
    (:file "circle" :depends-on ("_package_circle"))
    (:file "_package_circle" :depends-on ("_package"))
    (:file "cloud_date" :depends-on ("_package_cloud_date"))
    (:file "_package_cloud_date" :depends-on ("_package"))
    (:file "fly_position" :depends-on ("_package_fly_position"))
    (:file "_package_fly_position" :depends-on ("_package"))
    (:file "set_position" :depends-on ("_package_set_position"))
    (:file "_package_set_position" :depends-on ("_package"))
  ))