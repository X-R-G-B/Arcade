/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** MagicValue
*/

#pragma once


#define TO_FLOAT(x) static_cast<float>(x)
#define TO_INT(x) static_cast<int>(x)

#define SNAKE_HEAD "SNAKE_HEAD"
#define SNAKE_HEAD_SPRITE_COMP "NIBBLER_HEAD_SPRITE_COMP"
#define MOVE_INPUT_COMPS "MOVE_INPUT_COMPS"

#define NUMBER_COLUMNS 50
#define NUMBER_LINES 10
#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080
#define CASE_SIZE_WIDTH (TO_FLOAT(SCREEN_WIDTH) / NUMBER_COLUMNS)
#define CASE_SIZE_HEIGHT (TO_FLOAT(SCREEN_HEIGHT) / NUMBER_LINES)

#define FORWARD_KEY "direction"
#define EATED_EVENT "EATED"
#define RESTART_EVENT "RESTART"
#define APPLE_ENTITY "Apple"
#define APPLE_SPRITE_COMP "apple"
#define SCREENSIZEX 1920
#define SCREENSIZEY 1080
#define NIBBLER_MAP_ID "NIBBLER_map"
#define NIBBLER_WALL_ID "NIBBLER_wall"
#define NIBBLER_MAP_SIZE 32
