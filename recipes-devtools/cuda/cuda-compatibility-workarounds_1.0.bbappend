do_install:prepend:nvidia-orin() {
    install -d ${D}${includedir}/cuda-compat-workarounds/bits
}
