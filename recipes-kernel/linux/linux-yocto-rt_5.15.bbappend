#
# Copyright (C) 2023 Wind River Systems, Inc.
#

require linux-yocto-tegra.inc

COMPATIBLE_MACHINE:nvidia-orin = "nvidia-orin"

KBRANCH:nvidia-orin  = "v5.15/standard/preempt-rt/nvidia-orin"
KMACHINE:nvidia-orin = "nvidia-orin"

SRC_URI:append:nvidia-orin = " file://orin-rt.scc"

FILESEXTRAPATHS:prepend:nvidia-orin := "${THISDIR}/linux-yocto:"
