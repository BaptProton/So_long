# so_long

`so_long` is a small 2D tile-based game written in C.
The program loads a map from a `.ber` file, renders it using MiniLibX, and lets the player collect all collectibles before reaching the exit.

## What the game does

- Parses a map file (`.ber`) and validates its rules (shape, walls, required entities).
- Checks that the map is solvable (all collectibles and the exit are reachable from the player).
- Opens a window and draws the map using XPM sprites (32x32 tiles).
- Handles keyboard input to move the player and counts the number of moves.

## Map format (`.ber`)

The map is a rectangle of characters:

- `1` : wall
- `0` : floor
- `P` : player start (must be exactly 1)
- `C` : collectible (must be at least 1)
- `E` : exit (must be exactly 1)

Rules enforced by the parser:

- The map must be rectangular.
- The map must be surrounded by walls (`1`) on the first/last row and left/right borders.
- Only the characters above are allowed.
- The map must be solvable: a flood-fill style recursion is run on a cloned map to ensure all `C` and `E` can be reached.

## Build and run

### Requirements (Linux)

- `gcc`, `make`
- X11 + zlib development packages (commonly `libx11-dev`, `libxext-dev`, `zlib1g-dev`)

### Compile

```bash
make
```

This will also build:

- MiniLibX (in `minilibx-linux/`)
- `ft_printf` (in `ft_printf/`)

Object files are generated under `obj/`.

### Run

```bash
./so_long path/to/map.ber
```

### Clean

```bash
make clean   # removes obj/
make fclean  # removes obj/ + the binary
make re      # rebuilds everything
```

## Controls

- `W/A/S/D`: move
- `ESC`: quit

Note: keycodes can differ between macOS and Linux; this project targets MiniLibX on Linux (X11).

## Project structure (high level)

- `map_parsing/`: map validation + solvability check
- `image_related/`: rendering, textures, and movement logic
- `minilibx-linux/`: graphics library (X11)
- `ft_printf/`: custom printf implementation

## What this project taught me

- How to design a small program architecture (parsing → validation → rendering → event loop).
- Robust input validation (detecting invalid maps early and returning clear errors).
- Implementing reachability checks (recursive flood-fill on a cloned grid).
- Basic graphics programming with MiniLibX: window creation, image loading (XPM), drawing tiles.
- Event-driven programming: handling key events and cleanly closing the program.
- Memory management in C (allocations, freeing 2D arrays, avoiding leaks/crashes).
- Writing a Makefile that manages multiple subprojects and keeps build artifacts organized (`obj/`).

