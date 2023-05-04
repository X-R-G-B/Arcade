# Arcade

## Dependencies

- sdl2
- sdl2_image
- sdl2_mixer
- sdl2_ttf
- SFML
- ncurses

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
