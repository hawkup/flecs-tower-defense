#ifndef FLECS_SYSTEMS_PHYSICS_OCTREE_H
#define FLECS_SYSTEMS_PHYSICS_OCTREE_H

#include <flecs.h>
#include <cglm/cglm.h>
#include "../flecs-components-transform/flecs_components_transform.h"
#include "../flecs-components-geometry/flecs_components_geometry.h"
#include "../flecs-components-physics/flecs_components_physics.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ecs_octree_t ecs_octree_t;

typedef struct ecs_oct_entity_t {
    ecs_entity_t id;
    vec3 pos;
    vec3 size;
} ecs_oct_entity_t;

ecs_octree_t* ecs_octree_new(
    vec3 center,
    float size);

void ecs_octree_free(
    ecs_octree_t *ot);

void ecs_octree_clear(
    ecs_octree_t *ot);

int32_t ecs_octree_insert(
    ecs_octree_t *ot,
    ecs_entity_t e,
    vec3 pos,
    vec3 size);

void ecs_octree_findn(
    ecs_octree_t *ot,
    vec3 pos,
    float range,
    ecs_vec_t *result);

int32_t ecs_octree_dump(
    ecs_octree_t *ot);

#ifdef __cplusplus
}
#endif

#endif
