# platform_sco5.0.0-fsu-pthread.GNU,v 4.9 1999/07/16 17:49:46 schmidt Exp
#
# Note 1: the above file from PDL 4.6 has been modified by Mike P. to get 
# rid of thread related stuff until we can obtain fsu-threads library.
#
# Note 2: You must setup FSU_PTHREADS_DIR environment var to your FSU
# pthreads directory.  

# Requires gcc 2.7.2 Skunkware 97
# to produce libPDL.so correctly changed the specs file for gcc 2.7.2
# for not link -lc and -lgcc and other not shared libraries

debug = 0
optimize = 1

CC              = gcc
# for no threads
LDLIBS		+= -lm -L $(PD_DIR)/pdl 
CXX		= g++
CFLAGS		+= -melf -m386 -w 
CCFLAGS		+= -melf -m386  
ifneq ($(FSU_PTHREADS_DIR),"")
CCFLAGS		+= -I$(FSU_PTHREADS_DIR)/include
endif
# -g option not supported for C++ on systems using the DWARF debugging format
DCFLAGS		+= -g
DCCFLAGS	+= $(DCFLAGS)
CDLD            = $(CC)
DLD             = $(CXX)
LD              = $(CXX) /usr/lib/libc.so.1
ifneq ($(FSU_PTHREADS_DIR),"")
LIBS		+= -L$(FSU_PTHREADS_DIR)/lib
endif
LIBS		+= -lgthreads
LIBS            += -lnsl -lsocket
LIBS		+= -lgthreads
OCFLAGS		+= -O2
OCCFLAGS        += $(OCFLAGS) $(added_optimizer_flag)
PIC             = -fpic
AR              = ar
ARFLAGS         = ruv
RANLIB          = /bin/true

SOFLAGS = 
SOLINK = gcc $(PIC) -melf -shared
SOBUILD = $(SOLINK) -o $(VSHDIR)$*.so $<
PRELIB  = @true
