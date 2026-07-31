CC = gcc

SDL_CFLAGS = $(shell pkg-config --cflags sdl3)
SDL_LDFLAGS = $(shell pkg-config --libs sdl3)

CFLAGS = -std=c17 $(SDL_CFLAGS)

exe_file = main

# Handle debug case
DEBUG ?= 1
ifeq ($(DEBUG), 1)
	CFLAGS += -g -Wall
else
	CFLAGS += -DNDEBUG -O3
endif

SRCDIR = .
SRCEXT = c
SOURCES = $(shell find $(SRCDIR) -type f -name "*.$(SRCEXT)")
OBJECTS = $(SOURCES:.c=.o)
DEP = $(OBJECTS:.o=.d)

$(exe_file): $(OBJECTS)
	$(CC) $^ -o $(exe_file) $(SDL_LDFLAGS)

-include $(DEP)

%.d: %.$(SRCEXT)
	@$(CC) $(CFLAGS) $< -MM -MT $(@:.d=.o) >$@

%.o: %.$(SRCEXT)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f *.out *.o *.d $(exe_file)

run: 
	clear; ./main

valgrind:
	clear; valgrind --leak-check=full --track-origins=yes -s ./main

operation: 
	make clean && clear && make && make run

.PHONY: clean
