#pragma once

#define CHASE 1
#define SCATTER 2
#define FRIGHTENED 3
#define EATEN 4
#define GHOST_INIT_SPEED 2
#define GHOST_EATEN_SPEED 5
#define TIME_BETWEEN_SCATTERS 35000
#define DIRECTION_CHANGE_COOLDOWN 250
#define FRIGHTENED_MODE_DURATION 4000
#define SCATTER_MODE_DURATION 3500
#define BLINKY_INDEX 0
#define INKY_INDEX 1
#define PINKY_INDEX 2
#define CLYDE_INDEX 3
#define CLYDE_SCATTER_RANGE 4
#define PINKY_FRONT_SIGHT 4

#define PLAYER_START_X 10
#define PLAYER_START_Y 8
#define PLAYER_SPEED 4
#define PLAYER_INIT_LIFES 3

#define GAME_LOOP_TICK_DURATION 25
#define TIME_BETWEEN_ANIMATION_FRAMES 4
#define BOOST_PELLET_FLICKER_DURATION 10

#define PELLET_POINTS 25
#define BOOST_PELLET_POINTS 50
#define GHOST_EATEN_POINTS 100

#define TILE_W 16
#define TILE_H 16
#define TILE_ROWS 36
#define TILE_COLS 28
#define WIDTH ((TILE_COLS) * TILE_W)
#define HEIGHT (TILE_ROWS * TILE_H)
#define PELLET_SIZE 8
#define BOOST_PELLET_SIZE 16

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

#define CAGE_ENTRY_TILE 31
#define PELLET_TILE 26
#define BOOST_PELLET_TILE 27
#define EMPTY_TILE 30

