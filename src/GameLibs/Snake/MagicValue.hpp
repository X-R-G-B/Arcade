/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Magic Values
*/

#pragma once

#define TO_FLOAT(x) static_cast<float>(x)
#define TO_INT(x) static_cast<int>(x)

#define SNAKE_HEAD "SNAKE_HEAD"
#define SNAKE_SPRITE "SNAKE_SPRITE"
#define MOVE_INPUT_COMPS "MOVE_INPUT_COMPS"

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

#define SNAKE_MOVE_PER_DTIME 0.5

#define FORWARD_KEY "direction"
#define EATED_EVENT "EATED"
#define RESTART_EVENT "RESTART"
#define SNAKE "snake"
#define SNAKE_GROW_COMPONENT "snakeGrow"
#define APPLE_ENTITY "Apple"
#define APPLE_SPRITE_COMP "apple"
#define SNAKE_HEAD_PATH "./assets/snake/normal/fill_body.png"
#define SNAKEBODYPATH "assets/snake/normal/fill_body.png"
#define SCREENSIZEX 1920
#define SCREENSIZEY 1080
#define SNAKE_MAP_ID "snake_map"

#define SNAKE_PADDING_WINDOW_X 535
#define SNAKE_PADDING_WINDOW_Y 165
#define MAP_RIGHT (SNAKE_PADDING_WINDOW_X + PARCELL_SIZE * MAP_PARCELLS_X)
#define MAP_BOTTOM (SNAKE_PADDING_WINDOW_Y + PARCELL_SIZE * MAP_PARCELLS_Y)
#define PARCELL_SIZE 50
#define MAP_PARCELLS_X 17
#define MAP_PARCELLS_Y 15
