TARGET := ps3-dynamic-date

OFILES := src/main.o
CFLAGS := -I$(PS3DEV)/ppu/include -std=gnu99 -O2 -Wall
LDFLAGS :=
LIBS := -lsysutil

BUILDDIR := build

TITLE := PS3 Dynamic Date
APPID := DDAT00001
CONTENTID := UP0001-$(APPID)_00-0000000000000000
ICON0 := $(PS3DEV)/bin/ICON0.PNG

include $(PSL1GHT)/ppu_rules

.PHONY: pkg clean

pkg: $(TARGET).pkg

clean:
\trm -rf $(TARGET)*.elf $(TARGET)*.self $(TARGET)*.pkg $(BUILDDIR)
