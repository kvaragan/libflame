

#
# Makefile
#
# Field G. Van Zee
# 
# Makefile for libflame test suite driver.
#



#
# --- Include libflame config makefile fragment --------------------------------
#

# Determine the path to the libflame config makefile fragment. We'll use
# several variables defined there.
BUILD_DIRPATH       := ../build
CONFIG_DIRPATH      := ../config
HOST                := $(shell sh $(BUILD_DIRPATH)/ac-utils/config.guess)
CONFIG_MK_FRAGMENT  := $(CONFIG_DIRPATH)/$(HOST)/config.mk

# Include the definitions in the config makefile fragment.
-include $(CONFIG_MK_FRAGMENT)



#
# --- Optional overrides -------------------------------------------------------
#

# Uncomment and modify these definitions if you wish to override the values
# present in the master config makefile fragment.
# CC             := gcc
# LINKER         := $(CC)
#CFLAGS         := -g -O0 -Wall -Wno-comment
LDFLAGS          := -lm
# INSTALL_PREFIX := $(HOME)/flame



#
# --- BLAS and LAPACK implementations ------------------------------------------
#

# BLAS implementation path. A BLAS library must be given in order to run
# the libflame test suite. Modify these definitions if needed.
LIBBLAS_PATH   := $(INSTALL_PREFIX)/lib
#LIBBLAS        := $(LIBBLAS_PATH)/libblas.a
#LIBBLAS        := $(LIBBLAS_PATH)/libgoto.a
#LIBBLAS        := $(HOME)/blis/lib/libblis.a
#LIBBLAS       := $(HOME)/libs/blistrsmpubRepoTrsmOpt/lib/libblis.a # with TRSM only opt
LIBBLAS       := $(HOME)/libs/blistrsmMacroOpt/lib/libblis.a

# LAPACK implementation path. These values only matter if libflame was
# configured with the external-lapack-interfaces option enabled. Modify
# these definitions if needed.
LIBLAPACK_PATH := $(INSTALL_PREFIX)/lib
#LIBLAPACK      := $(LIBLAPACK_PATH)/liblapack.a
#LIBLAPACK      := 


#
# --- General build definitions ------------------------------------------------
#

TEST_SRC_PATH  := src
TEST_OBJ_PATH  := obj

FLA_LIB_PATH   := $(INSTALL_PREFIX)/lib
FLA_INC_PATH   := $(INSTALL_PREFIX)/include
LIBFLAME       := $(FLA_LIB_PATH)/libflame.a

CFLAGS         += -I$(FLA_INC_PATH) -I$(TEST_SRC_PATH) #-DAMD_ONLY_PERFORMANCE

FNAME          := libflame

TEST_OBJS      := $(patsubst $(TEST_SRC_PATH)/%.c, \
                             $(TEST_OBJ_PATH)/%.o, \
                             $(wildcard $(TEST_SRC_PATH)/*.c))
TEST_BIN       := test_$(FNAME).x

$(TEST_OBJ_PATH)/%.o: $(TEST_SRC_PATH)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

test_$(FNAME): $(TEST_OBJS)
	$(LINKER) $(TEST_OBJS) $(LIBFLAME) $(LIBLAPACK) $(LIBBLAS) $(LDFLAGS) -o $(TEST_BIN)

clean:
	$(RM_F) $(TEST_OBJS) $(TEST_BIN)

