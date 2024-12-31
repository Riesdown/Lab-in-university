
(cl:in-package :asdf)

(defsystem "lanya_pkg-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "fj_wz_data" :depends-on ("_package_fj_wz_data"))
    (:file "_package_fj_wz_data" :depends-on ("_package"))
    (:file "xc_kz_data" :depends-on ("_package_xc_kz_data"))
    (:file "_package_xc_kz_data" :depends-on ("_package"))
    (:file "xc_wz_data" :depends-on ("_package_xc_wz_data"))
    (:file "_package_xc_wz_data" :depends-on ("_package"))
  ))