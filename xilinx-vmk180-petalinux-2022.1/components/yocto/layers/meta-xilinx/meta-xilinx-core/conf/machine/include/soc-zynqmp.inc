DEFAULTTUNE ?= "cortexa72-cortexa53"
SOC_FAMILY ?= "zynqmp"

# Available SOC_VARIANT's for zynqmp:
# "cg" - Zynq UltraScale+  CG Devices
# "eg" - Zynq UltraScale+  EG Devices
# "ev" - Zynq UltraScale+  EV Devices
# "dr" - Zynq UltraScale+  DR Devices

SOC_VARIANT ?= "eg"

require xilinx-soc-family.inc

GRAPHICSOVERRIDES = ""
GRAPHICSOVERRIDES:zynqmp-eg = "mali400:"
GRAPHICSOVERRIDES:zynqmp-ev = "mali400:vcu:"

MACHINEOVERRIDES =. "${GRAPHICSOVERRIDES}"

require soc-tune-include.inc

# Linux Configuration
KERNEL_IMAGETYPE ?= "Image"

# Support multilib on zynqmp
DEFAULTTUNE:virtclass-multilib-lib32 ?= "armv7vethf-neon-vfpv4"

WIC_DEPENDS ?= "virtual/kernel virtual/bootloader virtual/boot-bin virtual/arm-trusted-firmware"

UBOOT_SUFFIX ?= "bin"

XSERVER_EXT:zynqmp ?= "xf86-video-armsoc"

# Default PMU ROM
PMU_ROM ?= "${DEPLOY_DIR_IMAGE}/pmu-rom.elf"


# Default expects the user to provide a specific pmu-firwmare in the deploy
# directory, named "pmu-firmware-${MACHINE}.elf" and "pmu-firmware-${MACHINE}.bin"
PMU_DEPENDS ??= ""
PMU_MCDEPENDS ??= ""
PMU_FIRMWARE_DEPLOY_DIR ??= "${DEPLOY_DIR_IMAGE}"
PMU_FIRMWARE_IMAGE_NAME ??= "pmu-firmware-${MACHINE}"

PMU_FIRMWARE_DEPLOY_DIR[vardepsexclude] += "TOPDIR"
