TEGRA_UEFI_SIGNING_CLASS ??= "tegra-uefi-signing"
inherit l4t_bsp ${TEGRA_UEFI_SIGNING_CLASS}

KERNEL_DISABLE_FW_USER_HELPER ?= "y"

# All of our device trees are out-of-tree
KERNEL_DEVICETREE:forcevariable = ""


COMPATIBLE_MACHINE = "(tegra|nvidia-orin)"

RRECOMMENDS:${KERNEL_PACKAGE_NAME}-base = ""

# kernel.bbclass automatically adds a dependency on the intramfs image
# even if INITRAMFS_IMAGE_BUNDLE is disabled.  This creates a circular
# dependency for tegra builds, where we need to combine initramfs (as an
# initrd) and kernel artifacts into a bootable image, so break that
# dependency here.
python () {
    image = d.getVar('INITRAMFS_IMAGE')
    if image and not bb.utils.to_boolean(d.getVar('INITRAMFS_IMAGE_BUNDLE')):
        flags = d.getVarFlag('do_bundle_initramfs', 'depends', False).split()
        try:
            i = flags.index('${INITRAMFS_IMAGE}:do_image_complete')
            del flags[i]
            d.setVarFlag('do_bundle_initramfs', 'depends', ' '.join(flags))
        except ValueError:
            bb.warn('did not find it in %s' % ','.join(flags))
            pass
}
