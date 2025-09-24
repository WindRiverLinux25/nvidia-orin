IMAGE_INSTALL:append = " ${@bb.utils.contains('BUILD_NVIDIA_PROPRIETARY_PACKAGE', '1', \
	'tegra-tools-tegrastats \
	cuda-samples \
	argus-samples \
	gstreamer-tests \
	l4t-graphics-demos-x11 \
	nvgstapps \
	tegra-mmapi-tests \
	vpi3-tests \
	tensorrt-tests \
	cudnn-samples \
	deepstream-tests \
	python3-jetson-stats \
	nvidia-docker \
	nvidia-docker-tests \
	optee-nvsamples \
	optee-test \
	python3-jetson-stats \
	v4l-utils \
	dtc \
	can-utils \
	devmem2 \
	alsa-utils \
	gstreamer1.0-plugins-ugly', '', d)}"

IMAGE_INSTALL:append = " ${@bb.utils.contains('DISTRO_FEATURES', 'opengl x11', 'mesa-demos', '', d)}"
IMAGE_INSTALL:append = " ${@bb.utils.contains('DISTRO_FEATURES', 'vulkan', 'vulkan-tools', '', d)}"

TOOLCHAIN_HOST_TASK:append = " ${@bb.utils.contains('BUILD_NVIDIA_PROPRIETARY_PACKAGE', '1', \
	'nativesdk-packagegroup-cuda-sdk-host', '', d)}"

IMAGE_INSTALL:append = " nvidia-kernel-oot \
                         nvidia-kernel-oot-dtb \
"
