.SUFFIXES:

TITLE := PS3 Dynamic Date
APPID := DDAT00001
CONTENTID := UP0001-$(APPID)_00-0000000000000000

include $(PSL1GHT)/ppu_rules

TARGET := ps3-dynamic-date
BUILD := build
SOURCES := src
INCLUDES :=

CFLAGS += -Wall -O2 $(MACHDEP) $(LIBPSL1GHT_INC)
LDFLAGS += $(MACHDEP) $(LIBPSL1GHT_LIB)
LIBS := -lsysutil -lio -lrt -llv2 -lm

