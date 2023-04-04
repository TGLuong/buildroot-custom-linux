################################################################################
#
# sconeserver
#
################################################################################

SCONESERVER_VERSION = 8d1935919a2013358993a8e9dfa992cbde56e503
SCONESERVER_SITE = $(call github,sconemad,sconeserver,$(SCONESERVER_VERSION))
SCONESERVER_LICENSE = GPL-2.0+
SCONESERVER_LICENSE_FILES = COPYING
SCONESERVER_DEPENDENCIES = \
	host-pkgconf \
	$(if $(BR2_PACKAGE_PCRE),pcre) \
	zlib
# disable image as it fails to build with ImageMagick
# disable markdown module because its git submodule cmark
# https://github.com/sconemad/sconeserver/tree/master/markdown
# has no cross-compile support provided by the sconeserver build system
SCONESERVER_CONF_OPTS += \
	-DCMAKE_CXX_FLAGS="$(TARGET_CXXFLAGS) -std=c++11" \
	-DWITH_IMAGE=OFF \
	-DWITH_MARKDOWN=OFF

ifeq ($(BR2_PACKAGE_OPENSSL),y)
SCONESERVER_DEPENDENCIES += openssl
SCONESERVER_CONF_OPTS += -DWITH_SSL=ON
else
SCONESERVER_CONF_OPTS += -DWITH_SSL=OFF
endif

ifeq ($(BR2_PACKAGE_SCONESERVER_BLUETOOTH),y)
SCONESERVER_DEPENDENCIES += bluez5_utils
SCONESERVER_CONF_OPTS += -DWITH_BLUETOOTH=ON
else
SCONESERVER_CONF_OPTS += -DWITH_BLUETOOTH=OFF
endif

ifeq ($(BR2_PACKAGE_SCONESERVER_EXAMPLES),y)
SCONESERVER_CONF_OPTS += -DWITH_EXAMPLES=ON
else
SCONESERVER_CONF_OPTS += -DWITH_EXAMPLES=OFF
endif

ifeq ($(BR2_PACKAGE_SCONESERVER_HTTP_SCONESITE),y)
SCONESERVER_DEPENDENCIES += libxml2
SCONESERVER_CONF_OPTS += -DWITH_SCONESITE=ON
else
SCONESERVER_CONF_OPTS += -DWITH_SCONESITE=OFF
endif

ifeq ($(BR2_PACKAGE_SCONESERVER_LOCATION),y)
SCONESERVER_DEPENDENCIES += gpsd
SCONESERVER_CONF_OPTS += -DWITH_LOCATION=ON
else
SCONESERVER_CONF_OPTS += -DWITH_LOCATION=OFF
endif

ifeq ($(BR2_PACKAGE_SCONESERVER_MATHS),y)
SCONESERVER_DEPENDENCIES += mpfr
SCONESERVER_CONF_OPTS += -DWITH_MATHS=ON
else
SCONESERVER_CONF_OPTS += -DWITH_MATHS=OFF
endif

ifeq ($(BR2_PACKAGE_SCONESERVER_MYSQL),y)
SCONESERVER_DEPENDENCIES += mysql
SCONESERVER_CONF_OPTS += -DWITH_MYSQL=ON
else
SCONESERVER_CONF_OPTS += -DWITH_MYSQL=OFF
endif

ifeq ($(BR2_PACKAGE_SCONESERVER_RSS),y)
SCONESERVER_DEPENDENCIES += libxml2
SCONESERVER_CONF_OPTS += -DWITH_RSS=ON
else
SCONESERVER_CONF_OPTS += -DWITH_RSS=OFF
endif

ifeq ($(BR2_PACKAGE_SCONESERVER_SQLITE),y)
SCONESERVER_DEPENDENCIES += sqlite
SCONESERVER_CONF_OPTS += -DWITH_SQLITE=ON
else
SCONESERVER_CONF_OPTS += -DWITH_SQLITE=OFF
endif

ifeq ($(BR2_PACKAGE_SCONESERVER_TESTBUILDER),y)
SCONESERVER_CONF_OPTS += -DWITH_TESTBUILDER=ON
else
SCONESERVER_CONF_OPTS += -DWITH_TESTBUILDER=OFF
endif

$(eval $(cmake-package))
