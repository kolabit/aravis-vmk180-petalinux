FILESEXTRAPATHS:prepend := "${THISDIR}/linux-xlnx:"

SRC_URI:append:zybo-linux-bd-zynq7 = " \
	file://0001-drm-xilinx-Add-encoder-for-Digilent-boards.patch \
	file://0002-clk-Add-driver-for-axi_dynclk-IP-Core.patch \
	file://0003-drm-xilinx-Fix-DPMS-transition-to-on.patch \
	"

SRC_URI:append:minized-zynq7 = " file://0004-minized-wifi-bluetooth.cfg"
