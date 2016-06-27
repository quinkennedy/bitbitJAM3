# bitbitJAM3
central repository for experiments, assets, and game dev for [bitbitJAM3: Red Hot Princess Carnage][1]

* [Overview](#overview)
* [Game](#game)
* [Dev Setup](#dev-setup)
  - [Linux](#linux)
  - [OSX](#osx)
  - [Windows](#windows)

## Overview
bitbitJAM is a 1-week game jam to produce a game targetted for a 8-bit or 16-bit computer or game system. David Frankel, Vivekanand Vimal, and Quin Kennedy are working together to create a game. They are targetting the GameBoy(Color?Advanced?) system.

## Game
Undecided. Must incorporate theme of _Red Hot Princess Carnage_. Interests involve:

* recursive game mechanics
* [bytebeat][3] audio
* changing dimensions/modes with color palette swaps

## Dev Setup
### Linux:

* OS: Ubuntu 16.04
* GBDK: [https://www.dropbox.com/s/gnrqkbydyxqasm0/gbdk-linux-kit64_1.0.tar.bz2?dl=0]()
  - extract to _/media/data/appsubu/gbdk/_
  - add `export GBDKDIR=/media/data/appsubu/gbdk/` to _~/.bashrc_
  - change *line 12* of _gbdk/include/gb/hardware.h_
    * from `#define __REG   extern volatile sfr UINT8`
    * to `#define __REG   extern volatile sfr /*UINT8*/`
  - change *line 41* of _gbdk/examples/gb/rpn.c_
    * from `BYTE read_op()`
    * to `BYTE read_op(char* s)`
  - `cd /media/data/appubu/gbdk/examples/gb/`
  - `make`
* Emulator: [Mednafen][2]
  - `sudo apt-get install -y mednafen`

### OSX

### Windows

[1]: http://bitbitjam.com/
[2]: http://mednafen.fobby.net/
[3]: http://greggman.com/downloads/examples/html5bytebeat/html5bytebeat.html
