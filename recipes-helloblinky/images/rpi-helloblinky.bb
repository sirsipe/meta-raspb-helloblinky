LICENSE = "GPLv3+"
inherit core-image

require ../meta-raspberrypi/recipes-core/images/rpi-basic-image.bb

IMAGE_INSTALL_append = " helloblinky connman connman-client "

export IMAGE_BASENAME = "rpi-helloblinky"

