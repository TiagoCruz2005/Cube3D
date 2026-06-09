*This project has been created as part of the 42 curriculum by thde-sou, tide-pau.*

# cub3D

## Description

cub3D is a 42 school graphics project inspired by Wolfenstein 3D. The goal is
to render a first-person view of a maze using ray-casting and the MiniLibX
graphics library.

The program reads a `.cub` scene file, validates its configuration, loads four
wall textures, applies separate floor and ceiling colors, and opens a window
where the player can move through the map in real time.

Main features:

- ray-casting based 3D wall projection;
- different wall textures for North, South, East, and West faces;
- configurable floor and ceiling RGB colors;
- `.cub` map parsing and validation;
- smooth keyboard movement and rotation;
- clean exit through `ESC` or the window close button;
- collision checks to prevent walking through blocking map cells.

## Instructions

### Requirements

This project is built for Linux with:

- `cc`;
- `make`;
- MiniLibX for Linux;
- X11 development libraries;
- BSD and math libraries.

On Debian/Ubuntu-like systems, the usual system packages are:

```sh
sudo apt install build-essential libx11-dev libxext-dev libbsd-dev
```

### Compilation

Build the project from the repository root:

```sh
make
```

This produces the executable:

```text
cub3D
```

Available Makefile rules:

```sh
make        # build the project
make clean  # remove object files
make fclean # remove object files and executable
make re     # rebuild from scratch
```

### Execution

Run the program with one `.cub` scene file:

```sh
./Cub3d resources/maps/map.cub
```

The program expects exactly one argument. If the file is invalid, misconfigured,
or cannot be loaded, the program exits with:

```text
Error
<explicit error message>
```

### Controls

| Key | Action |
| --- | --- |
| `W` | Move forward |
| `S` | Move backward |
| `A` | Move left |
| `D` | Move right |
| `Left Arrow` | Look left |
| `Right Arrow` | Look right |
| `Up Arrow` | Move view up |
| `Down Arrow` | Move view down |
| `Left Shift` | Increase movement speed |
| `ESC` | Close the game |
| Window close button | Close the game |

## Scene File Format

The scene file must use the `.cub` extension.

Except for the map, each element starts with an identifier followed by its value:

```text
NO ./path_to_north_texture.xpm
SO ./path_to_south_texture.xpm
WE ./path_to_west_texture.xpm
EA ./path_to_east_texture.xpm

F 220,100,0
C 225,30,0
```

Texture identifiers:

- `NO`: north wall texture;
- `SO`: south wall texture;
- `WE`: west wall texture;
- `EA`: east wall texture.

Color identifiers:

- `F`: floor color;
- `C`: ceiling color.

Colors are written as `R,G,B`, and each value must be in the range `0` to `255`.

The map must come last in the file. It may contain only:

- `0` for empty space;
- `1` for a wall;
- `N`, `S`, `E`, or `W` for the player start position and orientation;
- spaces, which are parsed as part of the map.

The map must be closed and surrounded by walls. It must contain exactly one
player start position.

Minimal example:

```text
NO resources/textures/xpm/north_texture.xpm
SO resources/textures/xpm/south_texture.xpm
WE resources/textures/xpm/west_texture.xpm
EA resources/textures/xpm/east_texture.xpm

F 220,100,0
C 225,30,0

111111
100101
101001
1100N1
111111
```

## Project Structure

```text
.
├── includes/            # Project headers and Makefile color definitions
├── libft/               # Local libft implementation
├── minilibx-linux/      # MiniLibX source used by the project
├── resources/
│   ├── maps/            # Example .cub files
│   └── textures/        # Texture assets
├── src/
│   ├── errors/          # Error reporting and cleanup helpers
│   ├── game/            # Window, ray-casting, drawing, movement, input
│   ├── inits/           # Structure initialization
│   ├── main_utils/      # Main flow helpers
│   ├── map/             # .cub parsing, map loading, texture loading
│   ├── open_utils/      # File opening helpers
│   └── verifications/   # File, map, texture, and configuration checks
├── Makefile
└── README.md
```

## Resources

References used to understand and implement the project:

- 42 cub3D subject, version 12.0;
- MiniLibX documentation and manual pages;
- Lode's Computer Graphics Tutorial: Raycasting;
- Wolfenstein 3D and classic ray-casting explanations;
- Linux manual pages for `open`, `close`, `read`, `write`, `malloc`, `free`,
  `perror`, `strerror`, `exit`, `gettimeofday`, and math library functions.

AI was used only as a support tool for documentation and review tasks.
It was not used to blindly generate or submit project logic.

AI support included:

- drafting and organizing this README according to the subject requirements;
- explaining Makefile behavior;
- reviewing build commands and project structure;
- checking that documentation reflects the implemented project behavior;
- helping identify possible edge cases to test manually.

All generated suggestions were reviewed, tested, and adapted by the authors,
who remain responsible for the final implementation.
