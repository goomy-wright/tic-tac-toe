COMPILER=g++
MAIN_FILE=src/main.cpp
BUILD_PATH=bin/app

.SILENT:
all: build

build:
	$(COMPILER) $(MAIN_FILE) -o $(BUILD_PATH)
