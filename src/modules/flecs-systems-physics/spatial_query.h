#ifndef FLECS_SYSTEMS_PHYSICS_SQUERY_H
#define FLECS_SYSTEMS_PHYSICS_SQUERY_H

#include <flecs.h>
#include <cglm/cglm.h>
#include "../flecs-components-transform/flecs_components_transform.h"
#include "../flecs-components-geometry/flecs_components_geometry.h"
#include "../flecs-components-physics/flecs_components_physics.h"
#include "octree.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ecs_squery_t ecs_squery_t;

ecs_squery_t* ecs_squery_new(
    ecs_world_t *world,
    ecs_id_t filter,
    vec3 center,
    float size);

void ecs_squery_free(
    ecs_squery_t *sq);

void ecs_squery_update(
    ecs_squery_t *sq);

void ecs_squery_findn(
    const ecs_squery_t *sq,
    vec3 position,
    float range,
    ecs_vec_t *result);

#ifdef __cplusplus
}
#endif
#endif
