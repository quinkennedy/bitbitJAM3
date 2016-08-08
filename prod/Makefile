AS=lcc
CC=lcc
ROM=HerSovereignVirus.gb
C_FILES=$(wildcard src/*.c)
O_FILES=$(addprefix obj/,$(notdir $(C_FILES:.c=.o)))
H_FILES=$(wildcard src/include/*.h)
LD_FLAGS=
CC_FLAGS=-I../gbdk/gbdk-lib/include

obj/%.o: src/%.c
	$(AS) -c $(CC_FLAGS) -o $@ $<

%.gb: obj/%.o $(O_FILES)
	$(CC) -o $@ $<

all: clean font $(ROM)

font: fontFilter/fontFilter.c src/tiles/custom-font.c
	cc -o fontFilter/fontFilter.out fontFilter/fontFilter.c;
	fontFilter/fontFilter.out > src/tiles/minimized-font.c;

run:
	mednafen $(ROM)

clean:
	-rm -rf *.gb *.o obj/*
