#
# This file was derived from the 'Hello World!' example recipe in the
# Yocto Project Development Manual.
#

SUMMARY = "Simple on board led on/off application"
SECTION = "examples"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

TARGET_CC_ARCH += ${LDFLAGS}

SRC_URI = "file://helloblinky.c"

S = "${WORKDIR}"

do_compile() {
	     ${CC} helloblinky.c -o helloblinky ${LDFLAGS}
}

do_install() {
	     install -d ${D}${bindir}
	     install -m 0755 helloblinky ${D}${bindir}
}
