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
#define LAST_SNAKE_BODY_COMP "LAST_SNAKE_BODY_COMP"

#define SNAKE_MOVE_PER_DTIME 2

#define FORWARD_KEY "direction"
#define EATED_EVENT "EATED"
#define RESTART_EVENT "RESTART"
#define SNAKE "snake"
#define SAVE_SCORE_NAME "snake"
#define SCORE_TITLE "Current Score: "
#define MAX_SCORE_TITLE "Max Score: "
#define SNAKE_GROW_COMPONENT "snakeGrow"
#define APPLE_ENTITY "Apple"
#define APPLE_SPRITE_COMP "apple"
#define SNAKE_HEAD_PATH "./assets/snake/normal/fill_body.png"
#define SNAKEBODYPATH "assets/snake/normal/fill_body.png"
#define SNAKE_MAP_ID "snake_map"
#define SNAKE_BODY_PART "snake_body_part_"

#define SNAKE_PADDING_WINDOW_X 416
#define SNAKE_PADDING_WINDOW_Y 30
#define MAP_RIGHT (SNAKE_PADDING_WINDOW_X + PARCELL_SIZE * MAP_PARCELLS_X)
#define MAP_BOTTOM (SNAKE_PADDING_WINDOW_Y + PARCELL_SIZE * MAP_PARCELLS_Y)
#define PARCELL_SIZE 64
#define MAP_PARCELLS_X 17
#define MAP_PARCELLS_Y 15

#define PATH_SCORE "./assets/score.txt"

#define SCORE_ENTITY "SCORE_ENTITY"
#define SCORE_ENTITY_COMP_CURRENT "SCORE_ENTITY_COMP_CURRENT"
#define SCORE_ENTITY_COMP_MAX "SCORE_ENTITY_COMP_MAX"

#define PATH_FONT "./assets/fonts/arial.ttf"
