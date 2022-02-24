CC := g++

SOURCES += $(wildcard *.cpp)
SOURCES += $(wildcard */*.cpp)

CFLAGS := -g -Wall -w -I./include
EXEC := ./bin/app

$(EXEC): $(SOURCES)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf $(EXEC)