/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** MagicValue
*/

#pragma once


#define TO_FLOAT(x) static_cast<float>(x)
#define TO_INT(x) static_cast<int>(x)

<<<<<<< HEAD
#define NIBBLER_HEAD "NIBBLER_HEAD"
#define NIBBLER_HEAD_SPRITE_COMP "NIBBLER_HEAD_SPRITE_COMP"
#define NIBBLER_SPRITE "NIBBLER_SPRITE"
=======
#define SNAKE_HEAD "SNAKE_HEAD"
#define SNAKE_SPRITE "SNAKE_SPRITE"
>>>>>>> ARCADE-7-nibbler
#define MOVE_INPUT_COMPS "MOVE_INPUT_COMPS"
#define LAST_SNAKE_BODY_COMP "LAST_SNAKE_BODY_COMP"

#define NIBBLER_MOVE_PER_DTIME 2

#define FORWARD_KEY "direction"
#define EATED_EVENT "EATED"
#define RESTART_EVENT "RESTART"
#define SNAKE "snake"
#define SNAKE_GROW_COMPONENT "snakeGrow"
#define APPLE_ENTITY "Apple"
#define APPLE_SPRITE_COMP "apple"
#define SNAKE_HEAD_PATH "./assets/snake/normal/fill_body.png"
#define SNAKE_BODY_PART "snake_body_part_"
#define SNAKEBODYPATH "assets/snake/normal/fill_body.png"

#define NIBBLER_MAP_ID "NIBBLER_map"
#define NIBBLER_WALL_ID "NIBBLER_wall"
#define NIBBLER_PADDING_WINDOW_X 416
#define NIBBLER_PADDING_WINDOW_Y 30
#define PARCELL_SIZE 64
#define MAP_PARCELLS_X 17
#define MAP_PARCELLS_Y 15
#define MAP_RIGHT (NIBBLER_PADDING_WINDOW_X + PARCELL_SIZE * MAP_PARCELLS_X)
#define MAP_BOTTOM (NIBBLER_PADDING_WINDOW_Y + PARCELL_SIZE * MAP_PARCELLS_Y)
#define NBR_OF_WALLS 20
#define COLLISION_EVENT "COLLISION_EVENT"
