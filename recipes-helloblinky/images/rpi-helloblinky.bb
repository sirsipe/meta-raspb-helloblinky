LICENSE = "GPLv3+"
inherit core-image

include meta-raspberrypi/recipes-core/images/rpi-basic-image.bb

IMAGE_INSTALL_append = " helloblinky "

export IMAGE_BASENAME = "rpi-helloblinky"

