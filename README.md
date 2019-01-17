# navy

This project was a small project from my first year at EPITECH (2016 - 2017)

The goal was to code a terminal version of the famous [Battleship game](https://en.wikipedia.org/wiki/Battleship_(game)),
using **SIGUSR1** and **SIGUSR2** [signals](https://en.wikipedia.org/wiki/Signal_(IPC)) to communicate between the 2 players.

<br>

Language: **C**

Group size: **2** (me and [**Etienne Filliat**](https://github.com/EtienneFilliat))

Project duration: **~3 weeks** (30/01/2017 - 19/02/2017)

Compilation: **on GNU/Linux via Makefile**

<br>

## Usage

```
$> ./navy -h
USAGE
	./navy [first player pid] navy_positions

DESCRIPTION
	first_player_pid	only for the 2nd player. pid of the first player.
	navy_positions		file representing the positions of the ships.
```

## Position file

The file passed as parameter must contain lines formatted the following way:

`LENGTH:FIRST_SQUARE:LAST_SQUARE`

where `LENGTH` is the length of the ship, `FIRST_SQUARE` and `LAST_SQUARE` its first and last positions.

In this file, you must have 4 ships (of lengths 2,3,4 and 5).

**Position file example:**

```
$> cat examples/pos1
2:C1:C2
3:D4:F4
4:B5:B8
5:D7:H7
```
<br>

## Authorized functions for this project:

`open, close, read, write, lseek, malloc, free, getpid, kill, signal,
sigaction, sigemptyset, setcontext, getcontext, usleep, nanosleep, pause`
