##########################################################
#
# test syscall
#
##########################################################


PROC_VERSION=1.0.0
PROC_SITE=./src/proc
PROC_SITE_METHOD=local


define PROC_BUILD_CMDS
	$(MAKE) $(TARGET_CONFIGURE_OPTS) -C $(@D) all
endef

define PROC_INSTALL_TARGET_CMDS
	$(INSTALL) -D -m 755 $(@D)/main $(TARGET_DIR)/root/main
	$(INSTALL) -D -m 755 $(@D)/proc1 $(TARGET_DIR)/root/proc1
endef


$(eval $(generic-package))
