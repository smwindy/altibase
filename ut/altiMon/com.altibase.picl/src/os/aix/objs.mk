# PICL source for IBM aix
# $Id
#

PICL_SRCS = $(UT_DIR)/altiMon/com.altibase.picl/src/os/aix/picl_aix.c

PICL_SHOBJS  = $(patsubst $(DEV_DIR)/%,$(TARGET_DIR)/%_soc.$(OBJEXT)     ,$(basename $(PICL_SRCS)))

#PICL_SHLIB_PATH = $(UT_DIR)/altiMon/com.altibase.altimon/lib/$(LIBPRE)picl_sl.$(SOEXT)
PICL_SHLIB_PATH = $(UT_DIR)/altiMon/com.altibase.altimon/lib/aix-ppc64-5.so
