FILESEXTRAPATHS:prepend:nvidia-orin := "${THISDIR}/${PN}:"

SRC_URI:append:nvidia-orin = " file://0001-cyptodev-tests-make-sure-address-of-data-structure-a.patch \
"
