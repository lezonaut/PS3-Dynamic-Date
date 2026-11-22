.SUFFIXES:

ifeq ($(strip $(PSL1GHT)),)
$(error PSL1GHT environment variable is missing)
endif

TITLE := PS3 Dynamic Date
APPID := DDAT00001
CONTENTID := UP0001-$(APPID)_00-0000000000000000

include $(PSL1GHT)/ppu_rules

TARGET := ps3-dynamic-date
BUILD := build
SOURCES := src
INCLUDES :=

CFLAGS := -Wall -O2 -mcpu=cell $(MACHDEP) $(INCLUDE)
LDFLAGS := $(MACHDEP)

LIBS := -lsysutil -lio -lrt -llv2 -lm

.PHONY: all pkg clean

all: $(BUILD) $(OUTPUT).self

pkg: $(BUILD) $(OUTPUT).pkg

$(BUILD):
	mkdir -p $(BUILD)

ifneq ($(BUILD),$(notdir $(CURDIR)))

export OUTPUT := $(CURDIR)/$(TARGET)
export VPATH := $(CURDIR)/$(SOURCES)
export DEPSDIR := $(CURDIR)/$(BUILD)
export BUILDDIR := $(CURDIR)/$(BUILD)

CFILES := $(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.c)))
OFILES := $(CFILES:.c=.o)

export LD := $(CC)
export INCLUDE := $(LIBPSL1GHT_INC) -I$(CURDIR)/$(BUILD)
export LIBPATHS := $(LIBPSL1GHT_LIB)

$(BUILD):
	mkdir -p $(BUILD)
	$(MAKE) --no-print-directory -C $(BUILD) -f $(CURDIR)/Makefile

$(OUTPUT).self: $(OUTPUT).elf

$(OUTPUT).elf: $(OFILES)

clean:
	rm -rf $(BUILD) $(OUTPUT).elf $(OUTPUT).self $(OUTPUT).pkg

else

DEPENDS := $(OFILES:.o=.d)

$(OUTPUT).elf: $(OFILES)

-include $(DEPENDS)

endif
