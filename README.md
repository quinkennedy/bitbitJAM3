# bitbitJAM3
central repository for experiments, assets, and game dev for [bitbitJAM3: Red Hot Princess Carnage][1]

* [Overview](#overview)
* [Game](#game)
* [Directory Structure](#directory-structure)
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

## Directory Structure

This repository is broken up into four main parts

* [art/]() contains art assets (backgrounds, sprites, fonts) created for the game
* [gbdk/]() is the GBDK included as a submodule
* [prod/]() is the actual game
* [proto/]() contains a series of tests and prototypes

Other folders include

* [tools/]() contains some utilities, mainly for producing art assets
* [vagrant_files/]() contains Vagrant-specific scripts and configuration files

## Dev Setup
### Linux:

Most of the development occured on an Ubuntu 16.04 machine. I used Vagrant to create a development sandbox, which means this should work relatively painlessly on Windows or OSX as well.

#### Dependencies

* [VirtualBox](https://www.virtualbox.org/)
* [Vagrant](https://www.vagrantup.com/)
* [git](https://git-scm.com/)
* [mednafen](http://mednafen.fobby.net/)

#### Setup

0. `git clone --recursive https://github.com/quinkennedy/bitbitJAM3.git`
0. `cd bitbitJAM3`
0. `vagrant up`
  * This will update the Vagrant box with the necessary dependencies and compile the GBDK
0. `vagrant ssh`

#### Usage

When you are logged into the Vagrant guest OS, you can run `make` from any project directory to build that project into a GameBoy ROM image.

From your host OS you can run the GameBoy ROM image using `make run`.

### OSX

### Windows

[1]: http://bitbitjam.com/
[2]: http://mednafen.fobby.net/
[3]: http://greggman.com/downloads/examples/html5bytebeat/html5bytebeat.html
