*This project has been created as part of the 42 curriculum by ojastrze, estolarc.*

---

# cub3D



## Description

**cub3D** is a 3D graphical representation project inspired by the world-famous Wolfenstein 3D game, which is considered the first true "First Person Shooter" in the history of video games. This project aims to explore ray-casting.

The goal is to create a "realistic" 3D graphical representation of the inside of a maze from a first-person perspective using the ray-casting principles similar to those used in the original Wolfenstein 3D.

### Key Features
- Ray-casting engine for 3D rendering
- First-person perspective navigation
- Texture mapping for walls (North, South, East, West)
- Customizable floor and ceiling colors
- Real-time keyboard controls for movement and rotation
- Map parsing and validation from `.cub` scene files

---

## Instructions

### Prerequisites
- Linux operating system
- GCC compiler
- MinilibX library

### Compilation
To compile the project, run:
```bash
make
```

This will compile the project and create the `cub3d` executable.

### Usage
Run the program with a scene description file as an argument:
```bash
./cub3d <map_file.cub>
```

Example:
```bash
./cub3d map.cub
```

### Controls
- **W, A, S, D**: Move through the maze (forward, left, backward, right)
- **Left Arrow, Right Arrow**: Rotate the camera left and right
- **ESC**: Exit the program cleanly
- **Red Cross (X)**: Close the window and quit the program

### Map File Format
The `.cub` file must contain:
- **NO**: Path to the north wall texture (`.xpm` file)
- **SO**: Path to the south wall texture
- **WE**: Path to the west wall texture
- **EA**: Path to the east wall texture
- **F**: Floor color in RGB format (e.g., `220,100,0`)
- **C**: Ceiling color in RGB format (e.g., `225,30,0`)
- **Map**: Grid layout using:
  - `0` for empty space
  - `1` for walls
  - `N`, `S`, `E`, or `W` for player start position and orientation

### Cleaning
To remove object files:
```bash
make clean
```

To remove all compiled files:
```bash
make fclean
```

To recompile everything:
```bash
make re
```

---

## Resources

### Classic References
- [Ray-Casting Tutorial by Lode Vandevenne](https://lodev.org/cgtutor/raycasting.html) - Comprehensive guide to ray-casting algorithms
- [Wolfenstein 3D Source Code](https://github.com/id-Software/wolf3d) - Original game source code for reference

### Technical Documentation
- [MinilibX Documentation](https://harm-smits.github.io/42docs/libs/minilibx) - Graphics library used for rendering
- [DDA Algorithm](https://www.geeksforgeeks.org/computer-graphics/dda-line-generation-algorithm-computer-graphics/) - Line drawing algorithm used in ray-casting

### AI Usage Disclosure
During the development of this project, AI tools were used for:
- Understanding mathematical concepts related to ray-casting algorithms (research for resources and references to learn from)

---

## Project Structure

```
cub3D/
├── includes/
│   └── cub3d.h          # Main header file
├── src/
│   ├── main.c           # Entry point and initialization
│   ├── casting_rays.c   # Ray-casting engine
│   ├── check_args.c     # Argument validation
│   ├── check_map_size.c # Map dimension checking
│   ├── colors_convert.c # RGB color conversion
│   ├── fill_map_vals_*.c # Map configuration parsing
│   ├── load_textures.c  # Texture loading and management
│   ├── map_*.c          # Map validation and processing
│   ├── mapping_check.c  # Map boundary and player checks
│   ├── player_control.c # Player movement and rotation
│   └── ray_utils.c      # Ray-casting utilities
├── libft/               # Custom C library
├── minilibx-linux/      # Graphics library
├── textures/            # Wall texture files (.xpm)
├── *.cub                # Example map files
├── Makefile
└── README.md
```

