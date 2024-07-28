# so_long

## Project Description

The `so_long` project is part of the School 42 curriculum, designed to enhance your understanding of graphics programming, game mechanics, and event handling using the MiniLibX library. The goal of this project is to create a simple 2D game where a player navigates through a map to collect items and reach an exit.

## What It Does

The `so_long` program is a 2D game where the player controls a character on a grid-based map. The player must collect all collectible items on the map and reach the exit to win the game. The game supports basic movements and displays the game state graphically.

## Implementation Details

- **Language**: The project is implemented in C.
- **Libraries**:
  - **MiniLibX**: Used for graphics rendering and handling window events.
- **Game Features**:
  - **Map Parsing**: Reads and parses a map file to set up the game environment.
  - **Player Movement**: Allows the player to move up, down, left, and right.
  - **Collectibles**: Items that the player must collect before reaching the exit.
  - **Exit**: The goal that the player must reach after collecting all items.
  - **Graphical Display**: Renders the game map, player, collectibles, and exit using MiniLibX.
- **Headers**:
  - `#include <mlx.h>`: For MiniLibX functions.
  - `#include <stdlib.h>`: For memory management.
  - `#include <unistd.h>`: For standard input/output.
  - `#include <fcntl.h>`: For file operations.
  - `#include <stdio.h>`: For standard I/O functions.

### How It Works

1. **Map Parsing**:
   - Reads a map file (typically `.ber` format) to initialize the game grid.
   - Validates the map to ensure it contains walls, a player start position, collectibles, and an exit.

2. **Initializing Game State**:
   - Sets up the game window using MiniLibX.
   - Loads textures for the player, walls, collectibles, and exit.
   - Initializes the player's starting position and other game variables.

3. **Event Handling**:
   - Listens for keyboard events to move the player.
   - Updates the game state based on player movements, such as collecting items and reaching the exit.

4. **Rendering Graphics**:
   - Draws the game map, player, collectibles, and exit on the window.
   - Continuously updates the display based on the player's actions.

5. **Game Logic**:
   - Ensures the player can only move to valid positions.
   - Tracks the number of moves and collectibles.
   - Ends the game when all collectibles are gathered, and the player reaches the exit.

This project provides a practical exercise in graphics programming and game development, building skills that are essential for creating interactive applications.
