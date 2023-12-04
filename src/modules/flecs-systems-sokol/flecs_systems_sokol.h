#ifndef FLECS_SYSTEMS_SOKOL_H
#define FLECS_SYSTEMS_SOKOL_H

#include <flecs.h>
#include "../flecs-components-gui/flecs_components_gui.h"
#include "../flecs-components-input/flecs_components_input.h"
#include "../flecs-components-graphics/flecs_components_graphics.h"
#include "../flecs-components-transform/flecs_components_transform.h"
#include "../flecs-components-geometry/flecs_components_geometry.h"
#include "../flecs-systems-transform/flecs_systems_transform.h"
#include "../flecs-game/flecs_game.h"

#ifdef __cplusplus
extern "C" {
#endif

void FlecsSystemsSokolImport(
    ecs_world_t *world);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
#ifndef FLECS_NO_CPP

namespace flecs {
namespace systems {

class sokol {
public:
    sokol(flecs::world& ecs) {
        // Load module contents
        FlecsSystemsSokolImport(ecs);

        // Bind C++ types with module contents
        ecs.module<flecs::systems::sokol>();
    }
};

}
}

#endif
#endif

#endif
