#
# Copyright (C) 2025 Wind River Systems, Inc.
#

COMPATIBLE_MACHINE:nvidia-orin = "nvidia-orin"

TARGET_SUPPORTED_KTYPES:nvidia-orin = "standard preempt-rt"

KMACHINE:nvidia-orin-agx = "nvidia-orin-nx"

KERNEL_DTC_FLAGS:append:nvidia-orin = " -@"

require ${@'recipes-kernel/linux/tegra-kernel.inc' if 'tegra' in d.getVar('MACHINEOVERRIDES').split(':') else ''}
