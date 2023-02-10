TARGET=linked_list
TARGET_BIN=bin/$(TARGET)
TARGET_BIN_DEV=$(TARGET_BIN)_dev


CLFAGS=-O2
CFLAGS+=-g
ALL_CFLAGS=lib/liblinklist.c -I lib/ $(CFLAGS)
ALL_CFLAGS_DEV=lib/liblinklist.c -I lib/ -g -Wall $(CFLAGS)
#==DO NOT EDIT BELLOW ===
LIBS_SRCS=$(wildcard lib/*)

build: $(TARGET_BIN)
all: $(TARGET_BIN) $(TARGET_BIN_DEV)

$(TARGET_BIN): src/linked_list.c $(LIBS_SRCS)
	cc -o $@ $< $(ALL_CFLAGS)
$(TARGET_BIN_DEV): src/linked_list.c
	cc -o $@ $< $(ALL_CFLAGS_DEV)
clean:
	rm -rf bin/*
run: $(TARGET_BIN)
	$<
debug: $(TARGET_BIN_DEV)
	gdb $<
