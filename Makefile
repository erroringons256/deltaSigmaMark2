# Makefile - Requires GNU Make v3.81 or later

BUILD_DIR = build
CC = gcc
CFLAGS = -O3 -march=x86-64 -mtune=generic

SRC_FILE = deltaSigma.c ringBuf.c
OBJ_FILE := $(addprefix $(BUILD_DIR)/,$(SRC_FILE:.c=.o))

.PHONY: all clean

all: deltaSigma

deltaSigma: $(OBJ_FILE)
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/$@ $^

clean:
	rm -rf $(BUILD_DIR)

$(BUILD_DIR)/.:
	mkdir -p $@

$(BUILD_DIR)%/.:
	mkdir -p $@

.SECONDEXPANSION:

$(BUILD_DIR)/%.o: %.c | $$(@D)/.
	$(CC) -c $(CFLAGS) -o $@ $<

$(BUILD_DIR)/%.avx2.o: %.avx2.c | $$(@D)/.
	$(CC) -c $(CFLAGS) -mavx -mavx2 -o $@ $<

$(BUILD_DIR)/%.sse3.o: %.sse3.c | $$(@D)/.
	$(CC) -c $(CFLAGS) -mmmx -msse -msse2 -msse3 -o $@ $<