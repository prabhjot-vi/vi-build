CC := gcc
FLAGS := -g

SRC_FILES := src/main.c src/arena.c

BUILD_DIR := build
APP := $(BUILD_DIR)/vi-build

.PHONY: clean run build

build: $(SRC_FILES)
	$(CC) $(FLAGS) -o $(APP) $^

run: build
	mkdir $(BUILD_DIR)
	./$(APP)

clean:
	rm -rf $(BUILD_DIR)
