#ifndef FLECS_COMPONENTS_CGLM_H
#define FLECS_COMPONENTS_CGLM_H

#include <flecs.h>
#include <cglm/cglm.h>

#ifdef __cplusplus
extern "C"
{
#endif

  extern ECS_COMPONENT_DECLARE(vec3);

  void FlecsComponentsCglmImport(
      ecs_world_t *world);

#ifdef __cplusplus
}
#endif

#endif
