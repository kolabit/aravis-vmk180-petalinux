# Add MicroBlaze Patches
FILESEXTRAPATHS:append:microblaze := ":${THISDIR}/files"
SRC_URI:append:microblaze = " \
    file://0001-Patch-microblaze-Add-config-microblaze.mt-for-target.patch \
    file://0002-Patch-microblaze-Modified-_exceptional_handler.patch \
    file://0003-LOCAL-Add-missing-declarations-for-xil_printf-to-std.patch \
    file://0004-Local-deleting-the-xil_printf.c-file-as-now-it-part-.patch \
    file://0005-Local-deleting-the-xil_printf.o-from-MAKEFILE.patch \
    file://0006-MB-X-intial-commit.patch \
    file://0007-Patch-Microblaze-newlib-port-for-microblaze-m64-flag.patch \
    file://0008-fixing-the-bug-in-crt-files-added-addlik-instead-of-.patch \
    file://0009-Patch-MicroBlaze-Added-MB-64-support-to-strcmp-strcp.patch \
    file://0010-Patch-MicroBlaze-Removing-the-Assembly-implementatio.patch \
    file://0011-Fixed-the-bug-in-crtinit.s-for-MB-64.patch \
    "

EXTRA_OECONF:append:xilinx-standalone:microblaze = " \
    --disable-newlib-reent-check-verify \
"
