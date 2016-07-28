ROM=custom_font.gb
DEPS=

%.gb: %.c $(DEPS)
	lcc -o $@ $<

all: $(ROM)

run:
	mednafen $(ROM)

clean:
	-rm -f *.gb *.o
