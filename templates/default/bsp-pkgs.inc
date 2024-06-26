# CUDA libraries
TOOLCHAIN_HOST_TASK += "nativesdk-packagegroup-cuda-sdk-host"
IMAGE_INSTALL:append = " cuda-cccl cuda-command-line-tools cuda-compat cuda-compiler cuda-cudart \
                         cuda-cuobjdump cuda-cupti cuda-cuxxfilt cuda-driver cuda-gdb \
                         cuda-libraries cuda-nvcc-headers cuda-nvcc cuda-nvdisasm cuda-nvml \
                         cuda-nvprune cuda-nvrtc cuda-nvtx cuda-profiler-api cuda-samples \
                         cuda-sanitizer cuda-toolkit libcublas libcudla libcufft \
                         libcufile libcurand libcusolver libcusparse libnpp libnvjitlink "

# Base utils
IMAGE_FEATURES += "ssh-server-openssh"
CORE_IMAGE_BASE_INSTALL += " \
    haveged \
    procps \
    sshfs-fuse \
    strace \
    tegra-tools-tegrastats \
    nsight-systems-cli \
    ${@' less systemd-analyze' if d.getVar('VIRTUAL-RUNTIME_init_manager') == 'systemd' else ''} \
"
CORE_IMAGE_BASE_INSTALL += ""

# Optee tests
CORE_IMAGE_BASE_INSTALL += " \
    optee-nvsamples \
    optee-test \
"

# Docker virtualization
CORE_IMAGE_BASE_INSTALL += "nvidia-docker"

# Tests
TOOLCHAIN_HOST_TASK += "nativesdk-packagegroup-cuda-sdk-host"
IMAGE_FEATURES += "splash x11-base x11-sato hwcodecs"
CORE_IMAGE_BASE_INSTALL += "${@bb.utils.contains('DISTRO_FEATURES', 'vulkan', 'vulkan-tools', '', d)}"
IMAGE_INSTALL:append = " \
    argus-samples \
    cuda-libraries \
    cuda-samples \
    git \
    glmark2 \
    kernel-module-uvcvideo \
    l4t-graphics-demos-x11 \
    mesa-demos \
    nvgstapps \
"
# Tools:
# Add the canutils and i2c-tools packages
IMAGE_INSTALL:append = " i2c-tools canutils rt-tests"

# TensorRT, cudnn, mmapi, and vpi3 libs+tests
IMAGE_INSTALL:append = " tensorrt-core tensorrt-plugins tensorrt-trtexec tensorrt-trtexec-prebuilt"
IMAGE_INSTALL:append = " cudnn-samples cudnn"
IMAGE_INSTALL:append = " libnvvpi3"
