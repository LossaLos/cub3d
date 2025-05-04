cat > README.md << 'EOF'
# Cub3D

## 🕹️ Overview

**Cub3D** is a 3D game engine inspired by **Wolfenstein 3D**, built using C and the **MiniLibX** graphics library. It uses **raycasting** to simulate a 3D environment from a 2D map.

## 🚀 Features

- 3D rendering using raycasting
- Player movement and rotation
- Textured walls
- Mini-map (bonus)
- Doors and sprites (bonus)
- Floor and ceiling colors
- Collision detection
- Input handling via keyboard

## 🗺️ Map Format

\`\`\`
NO ./textures/wall_north.xpm
SO ./textures/wall_south.xpm
WE ./textures/wall_west.xpm
EA ./textures/wall_east.xpm
F 220,100,0
C 225,30,0

111111
100001
1000N1
111111
\`\`\`

## 🕹 Controls

| Key             | Action              |
|-----------------|---------------------|
| W / S           | Move forward/back   |
| A / D           | Strafe left/right   |
| Left / Right    | Rotate              |
| ESC             | Exit the game       |

## 📦 Installation

\`\`\`bash
make
./cub3D maps/example.cub
\`\`\`

