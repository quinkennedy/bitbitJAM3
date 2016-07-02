ROM=multi.gb
DEPS=multi.h\
 screen.c screen.h\
 startScreen.c startScreen.h\
 gameScreen.c gameScreen.h\
 player.c player.h\
 background.c background.h\
 input.c input.h\
 background-data.c\
 player-data.c

%.gb: %.c $(DEPS)
	lcc -o $@ $<

all: $(ROM)

run:
	mednafen $(ROM)

clean:
	-rm -f *.gb *.o
