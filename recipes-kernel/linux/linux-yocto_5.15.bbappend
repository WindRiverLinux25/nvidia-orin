#
# Copyright (C) 2023 Wind River Systems, Inc.
#

require linux-yocto-tegra.inc

TARGET_SUPPORTED_KTYPES:nvidia-orin = "standard"
COMPATIBLE_MACHINE:nvidia-orin = "nvidia-orin"

KBRANCH:nvidia-orin  = "v5.15/standard/nvidia-orin"
KMACHINE:nvidia-orin = "nvidia-orin"

SRC_URI += "file://orin.scc"

FILESEXTRAPATHS:prepend := "${THISDIR}/linux-yocto:"
