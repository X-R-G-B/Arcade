# Arcade

Student project: Make multiple games with the graphics render library that can be switch at runtime.

When you play the games, you can switch to a SFML, SDL2, or ncurses backend.

## Game implemented

- Snake
- Nibleur

## Graphical lib wrapped

- SDL2
- SFML
- ncurses

## Objectif

Change game/graphical lib at runtime

## Install

### Dependencies

- sdl2
- sdl2_image
- sdl2_mixer
- sdl2_ttf
- SFML
- ncurses

### Build

```bash
mkdir build && cd build && cmake . && make -j8
```

## Usage

```
./arcade ./lib/arcade_sfml.so
./arcade ./lib/arcade_sdl2.soo
./arcade ./lib/arcade_ncurses.so
./arcade
```

## Archi: https://github.com/ARCADE-TEK-2026/archi_arcade
