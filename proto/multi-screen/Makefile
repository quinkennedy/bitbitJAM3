ROM=multi.gb
DEPS=screen.c screen.h\
 startScreen.c startScreen.h\
 multi.h

%.gb: %.c $(DEPS)
	lcc -o $@ $<

all: $(ROM)

run:
	mednafen $(ROM)

clean:
	-rm -f *.gb *.o
