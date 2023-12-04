cmake_minimum_required(VERSION 3.17)

set(VCPKG_ROOT "$ENV{VCPKG_ROOT}")

set(CMAKE_TOOLCHAIN_FILE
  "${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake"
  CACHE STRING "Vcpkg toolchain file")
set(VCPKG_INSTALL_OPTIONS "--allow-unsupported")

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_BUILD_TYPE Debug)

project(flecs-tower-defense)

#=== LIBRARY: sokol
# add headers to the the file list because they are useful to have in IDEs
set(SOKOL_HEADERS
    sokol/sokol_gfx.h
    sokol/sokol_app.h
    sokol/sokol_glue.h
    sokol/sokol_log.h)
add_library(sokol STATIC sokol/sokol.c ${SOKOL_HEADERS})
if(CMAKE_SYSTEM_NAME STREQUAL Darwin)
    # compile sokol.c as Objective-C
    target_compile_options(sokol PRIVATE -x objective-c)
    target_link_libraries(sokol
        "-framework QuartzCore"
        "-framework Cocoa"
        "-framework MetalKit"
        "-framework Metal"
        "-framework OpenGL"
        "-framework AudioToolbox")
else()
    if (CMAKE_SYSTEM_NAME STREQUAL Linux)
        target_link_libraries(sokol INTERFACE X11 Xi Xcursor GL asound dl m)
        target_link_libraries(sokol PUBLIC Threads::Threads)
    endif()
endif()
target_include_directories(sokol INTERFACE sokol)

find_package(flecs CONFIG REQUIRED)
find_package(cglm CONFIG REQUIRED)

add_executable(
  demo
    src/main.cpp
    src/modules/flecs-components-cglm/flecs_components_cglm.c
    src/modules/flecs-components-transform/flecs_components_transform.c
    src/modules/flecs-components-graphics/flecs_components_graphics.c
    src/modules/flecs-components-geometry/flecs_components_geometry.c
    src/modules/flecs-components-gui/flecs_components_gui.c
    src/modules/flecs-components-physics/flecs_components_physics.c
    src/modules/flecs-components-input/flecs_components_input.c
    src/modules/flecs-systems-physics/flecs_systems_physics.c
    src/modules/flecs-systems-physics/octree.c
    src/modules/flecs-systems-physics/spatial_query.c
    src/modules/flecs-systems-transform/flecs_systems_transform.c
    src/modules/flecs-game/flecs_game.c
    src/modules/flecs-game/camera_container.c
    src/modules/flecs-game/light_controller.c
    src/modules/flecs-game/world_cells.c

    src/modules/flecs-systems-sokol/fx/fog.c
    src/modules/flecs-systems-sokol/fx/fx.c
    src/modules/flecs-systems-sokol/fx/hdr.c
    src/modules/flecs-systems-sokol/fx/ssao.c
    src/modules/flecs-systems-sokol/modules/geometry/geometry.c
    src/modules/flecs-systems-sokol/modules/materials/materials.c
    src/modules/flecs-systems-sokol/modules/renderer/renderer.c
    src/modules/flecs-systems-sokol/atmosphere.c
    src/modules/flecs-systems-sokol/depth.c
    src/modules/flecs-systems-sokol/effect.c
    src/modules/flecs-systems-sokol/flecs_systems_sokol.c
    src/modules/flecs-systems-sokol/resources.c
    src/modules/flecs-systems-sokol/scene.c
    src/modules/flecs-systems-sokol/screen.c
    src/modules/flecs-systems-sokol/shader_loader.c
    src/modules/flecs-systems-sokol/shadow.c
)

# executable
target_link_libraries(
  demo
  PRIVATE
    flecs::flecs_static
    cglm::cglm
    sokol
)
