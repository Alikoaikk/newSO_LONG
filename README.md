# so_long

A 2D game project from the 42 curriculum where the player must collect all items and find the exit in a maze-like map.

## Description

so_long is a small 2D game built using the MiniLibX graphics library. The player controls Harry Potter who needs to collect all Horcruxes and reach the exit. The game features a tile-based map system with wall collision detection and pathfinding validation.

## Features

- Tile-based rendering with 120x120 pixel sprites
- Player movement in 4 directions (arrow keys)
- Collectibles system (Horcruxes)
- Exit that opens after collecting all items
- Movement counter display
- Map validation (walls, path checking, duplicates)
- Custom map support via `.ber` files

## Requirements

- Linux operating system
- X11 development libraries
- Make
- GCC compiler

## Installation

```bash
make
```

This will compile the project along with the included MiniLibX library and create the `so_long` executable.

## Usage

```bash
./so_long <map_file.ber>
```

Example:
```bash
./so_long maps/valid_maps/map_normal.ber
```

## Controls

- **Arrow Keys / WASD**: Move player
- **ESC**: Exit game
- **Window Close Button**: Exit game

## Map Format

Maps must be `.ber` files with the following characters:

- `1`: Wall
- `0`: Floor (empty space)
- `P`: Player starting position
- `C`: Collectible (Horcrux)
- `E`: Exit

### Map Rules

- Map must be rectangular
- Map must be surrounded by walls (`1`)
- Must contain exactly one player (`P`)
- Must contain exactly one exit (`E`)
- Must contain at least one collectible (`C`)
- Must have a valid path from player to all collectibles and the exit

### Example Map

```
111111
1P0C01
100001
1C00E1
111111
```

## Project Structure

```
.
├── srcs/              # Main source files
├── includes/          # Header files
├── mlx/              # MiniLibX graphics library
├── ft_printf/        # Custom printf implementation
├── get_next_line/    # File reading utility
├── sprites/          # Game sprites (.xpm files)
└── maps/             # Map files
    ├── valid_maps/   # Valid test maps
    └── invalid_maps/ # Invalid test maps
```

## Compilation Commands

- `make`: Build the project
- `make clean`: Remove object files
- `make fclean`: Remove object files and executable
- `make re`: Rebuild the project

## Author

akoaik (42 student)
