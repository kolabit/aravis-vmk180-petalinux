DESCRIPTION = "Jupyter notebook examples for Platform Management (PM) in Versal devices"
LICENSE = "BSD-3-Clause"
LIC_FILES_CHKSUM = "file://../../LICENSE;md5=268f2517fdae6d70f4ea4c55c4090aa8"

inherit jupyter-examples

SRC_URI = "git://github.com/Xilinx/platform-management-notebooks.git;branch=xlnx_rel_v2022.1;protocol=https \
           file://LICENSE \
           "

SRCREV = "74693121d9dbc72d5e8290805708b64d37042d79"

S = "${WORKDIR}/git/pm-notebooks"

COMPATIBLE_MACHINE = "^$"
COMPATIBLE_MACHINE:versal = "versal"

RDEPENDS:${PN} = "packagegroup-petalinux-jupyter \
                  python3-ipywidgets \
                  python3-pydot \
                  "

do_install() {
    install -d ${D}/${JUPYTER_DIR}/pm-notebooks
    install -d ${D}/${JUPYTER_DIR}/pm-notebooks/pmutil
    install -d ${D}/${JUPYTER_DIR}/pm-notebooks/pmutil/data

    install -m 0644 ${S}/README ${D}/${JUPYTER_DIR}/pm-notebooks
    install -m 0755 ${S}/*.ipynb ${D}/${JUPYTER_DIR}/pm-notebooks
    install -m 0755 ${S}/pmutil/*.py ${D}/${JUPYTER_DIR}/pm-notebooks/pmutil
    install -m 0755 ${S}/pmutil/data/*.png ${D}/${JUPYTER_DIR}/pm-notebooks/pmutil/data
}

