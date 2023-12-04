#ifndef GAME_H
#define GAME_H

#include <cglm/cglm.h>
#include <flecs.h>
#include "../flecs-components-input/flecs_components_input.h"
#include "../flecs-components-graphics/flecs_components_graphics.h"
#include "../flecs-components-gui/flecs_components_gui.h"
#include "../flecs-components-transform/flecs_components_transform.h"
#include "../flecs-components-geometry/flecs_components_geometry.h"
#include "../flecs-components-physics/flecs_components_physics.h"
#include "../flecs-systems-physics/flecs_systems_physics.h"

// Reflection system boilerplate
#undef ECS_META_IMPL
#ifndef FLECS_GAME_IMPL
#define ECS_META_IMPL EXTERN // Ensure meta symbols are only defined once
#endif

// Number of bits to shift from x/y coordinate before creating the spatial hash.
// Larger numbers create larger cells.
#define FLECS_GAME_WORLD_CELL_SHIFT (8)

// Convenience macro to get size of world cell
#define FLECS_GAME_WORLD_CELL_SIZE (1 << FLECS_GAME_WORLD_CELL_SHIFT)

#ifdef __cplusplus
extern "C" {
#endif

extern ECS_DECLARE(EcsCameraController);

ECS_STRUCT(EcsCameraAutoMove, {
    float after;
    float speed;
    float t;
});

ECS_STRUCT(EcsTimeOfDay, {
    float t;
    float speed;
});

extern ECS_DECLARE(EcsWorldCell);

extern ECS_DECLARE(EcsWorldCellRoot);

ECS_STRUCT(EcsWorldCellCoord, {
    int64_t x;
    int64_t y;
    int32_t size;
});

ECS_STRUCT(ecs_grid_slot_t, {
    ecs_entity_t prefab;
    float chance;
});

ECS_STRUCT(ecs_grid_coord_t, {
    int32_t count;
    float spacing;
    float variation;
});

ECS_STRUCT(EcsGrid, {
    ecs_grid_coord_t x;
    ecs_grid_coord_t y;
    ecs_grid_coord_t z;

    EcsPosition3 border;
    EcsPosition3 border_offset;

    ecs_entity_t prefab;
    ecs_grid_slot_t variations[20];
});

void FlecsGameImport(ecs_world_t *world);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
#ifndef FLECS_NO_CPP
#include <iostream>

namespace flecs {

struct game {
    static flecs::entity_t CameraController;

    game(flecs::world& ecs) {
        // Load module contents
        FlecsGameImport(ecs);

        CameraController = EcsCameraController;

        // Bind C++ types with module contents
        ecs.module<flecs::game>();
    }
};

flecs::entity_t game::CameraController = 0;

}

#endif
#endif

#endif
