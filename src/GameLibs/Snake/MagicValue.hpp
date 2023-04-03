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
#define SNAKE_HEAD_SPRITE_COMP "SNAKE_HEAD_SPRITE_COMP"
#define MOVE_INPUT_COMPS "MOVE_INPUT_COMPS"

#define NUMBER_COLUMNS 50
#define NUMBER_LINES 10
#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080
#define CASE_SIZE_WIDTH (TO_FLOAT(SCREEN_WIDTH) / NUMBER_COLUMNS)
#define CASE_SIZE_HEIGHT (TO_FLOAT(SCREEN_HEIGHT) / NUMBER_LINES)

#define SNAKE_MOVE_PER_DTIME 0.5

#define FORWARD_KEY "direction"
#define EATED_EVENT "EATED"
#define RESTART_EVENT "RESTART"
#define SNAKE "snake"
#define SNAKE_GROW_COMPONENT "snakeGrow"
#define APPLE_ENTITY "Apple"
#define APPLE_SPRITE_COMP "apple"
#define APPLE_SPRITE_COMP_PATH "assets/Snake/apple.png"
#define SNAKE_HEAD_PATH "./assets/Snake/head/"
#define SNAKEBODYPATH "assets/snake_body.png"
#define SCREENSIZEX 1920
#define SCREENSIZEY 1080
#define POS_OF_APPLE 20
#define SNAKE_MAP_ID "snake_map"
