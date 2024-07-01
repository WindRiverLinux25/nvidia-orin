# CUDA libraries
TOOLCHAIN_HOST_TASK += "nativesdk-packagegroup-cuda-sdk-host"
IMAGE_INSTALL += "cuda-cccl cuda-command-line-tools cuda-compat cuda-compiler \
    cuda-cudart cuda-cuobjdump cuda-cupti cuda-cuxxfilt cuda-driver cuda-gdb \
    cuda-libraries cuda-nvcc-headers cuda-nvcc cuda-nvdisasm cuda-nvml \
    cuda-nvprune cuda-nvrtc cuda-nvtx cuda-profiler-api cuda-samples \
    cuda-sanitizer cuda-toolkit libcublas libcudla libcufft libcufile libcurand \
    libcusolver libcusparse libnpp libnvjitlink \
"

# Base utils
IMAGE_FEATURES += "ssh-server-openssh"

# Tests
TOOLCHAIN_HOST_TASK += "nativesdk-packagegroup-cuda-sdk-host"
IMAGE_FEATURES += "splash x11-base x11-sato hwcodecs"
IMAGE_INSTALL += "\
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
IMAGE_INSTALL += "i2c-tools canutils rt-tests"

# TensorRT, cudnn, mmapi, and vpi3 libs+tests
IMAGE_INSTALL += "tensorrt-core tensorrt-plugins tensorrt-trtexec tensorrt-trtexec-prebuilt"
IMAGE_INSTALL += "cudnn-samples cudnn"
IMAGE_INSTALL += "libnvvpi3"
