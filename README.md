# flecs-tower-defense

https://github.com/SanderMertens/tower_defense change to use local modules and cmake

## Module lists

- flecs-components-cglm
- flecs-components-transform
- flecs-components-graphics
- flecs-components-geometry
- flecs-components-gui
- flecs-components-physics
- flecs-components-input
- flecs-systems-physics
- flecs-systems-transform
- flecs-game
- flecs-systems-sokol

## Prerequisites

- vcpkg
- cmake

## Build & Run

```cmd
# Build
cmake -S . -B build
cmake --build build

# Run
./build/demo
```
