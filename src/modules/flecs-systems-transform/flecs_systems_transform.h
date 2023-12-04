#ifndef FLECS_SYSTEMS_TRANSFORM_H
#define FLECS_SYSTEMS_TRANSFORM_H

#include <flecs.h>
#include <cglm/cglm.h>
#include "../flecs-components-transform/flecs_components_transform.h"

#ifdef __cplusplus
extern "C"
{
#endif

  void FlecsSystemsTransformImport(
      ecs_world_t *world);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
#ifndef FLECS_NO_CPP

namespace flecs
{
  namespace systems
  {

    class transform
    {
    public:
      transform(flecs::world &ecs)
      {
        // Load module contents
        FlecsSystemsTransformImport(ecs);

        // Bind module contents with C++ types
        ecs.module<flecs::systems::transform>();
      }
    };

  }
}

#endif // FLECS_NO_CPP
#endif // __cplusplus

#endif
