DISTRO = "tegrademo"
DISTRO_NAME = "OE4Tegra Demonstration Distro"
DISTRO_VERSION_BASE = "4.3"
DISTRO_VERSION = "${DISTRO_VERSION_BASE}+snapshot-${METADATA_REVISION}"
DISTRO_CODENAME = "master"
SDK_VENDOR = "-tdsdk"
SDK_VERSION := "${@'${DISTRO_VERSION}'.replace('snapshot-${METADATA_REVISION}','snapshot')}"
SDK_VERSION[vardepvalue] = "${SDK_VERSION}"

MAINTAINER = "OE4Tegra team <oe4tegra@madison.systems>"

TARGET_VENDOR = "-oe4t"

# New ${DISTRO}-<version> setting for sanity checks.
# Increment version number (and the corresponding
# setting int the template bblayers.conf.sample file)
# each time the layer settings are changed.
REQUIRED_TD_BBLAYERS_CONF_VERSION = "${DISTRO}-5"

LOCALCONF_VERSION = "2"

TD_DEFAULT_DISTRO_FEATURES = "largefile opengl ptest multiarch wayland vulkan systemd pam virtualization usrmerge"

DISTRO_FEATURES ?= "${DISTRO_FEATURES_DEFAULT} ${TD_DEFAULT_DISTRO_FEATURES}"

# Jetson platforms do not use linux-yocto, but for QEMU testing
# align with the poky distro.
PREFERRED_VERSION_linux-yocto ?= "5.19%"
PREFERRED_VERSION_linux-yocto-rt ?= "5.19%"

SDK_NAME = "${DISTRO}-${TCLIBC}-${SDKMACHINE}-${IMAGE_BASENAME}-${TUNE_PKGARCH}-${MACHINE}"
SDKPATHINSTALL = "/opt/${DISTRO}/${SDK_VERSION}"

TCLIBCAPPEND = ""

PACKAGE_CLASSES ?= "package_rpm"

SANITY_TESTED_DISTROS ?= " \
            ubuntu-18.04 \n \
            ubuntu-20.04 \n \
            ubuntu-22.04 \n \
            "

# CUDA 10.2 requires gcc 8
CUDA_GCCVERSION = "8.%"

# Most NVIDIA-supplied services expect systemd
INIT_MANAGER = "systemd"

require conf/distro/include/no-static-libs.inc
require conf/distro/include/yocto-uninative.inc
require conf/distro/include/security_flags.inc
INHERIT += "uninative"

LICENSE_FLAGS_ACCEPTED += "commercial_faad2 commercial_x264"

OLDEST_KERNEL:aarch64 = "5.10"
