<link rel="icon" type="image/x-icon" href="https://raw.githubusercontent.com/Jarjarbin06/Epitech_Base/refs/heads/main/docs/EpitechBaseWebIcon.png">

# 📦 Particle Module (`nsf_particle`)
#### part of [Graphics](overview.md)

The particle module provides a lightweight particle system built on top of sprites, enabling dynamic effects such as fire, smoke, or explosions through procedural updates.

> Example:  
> Handles particle spawning, lifetime management, velocity updates, and rendering using a shared sprite.

---

## 🔹 Header

```c
#include <newcsfml/graphics/particle.h>
````

---

## 🔹 Structure

```c
typedef struct nsf_particle_s {
    nsf_single_particle_t *particles;
    nsf_sprite_t *sprite;
    nsf_uint_t max_particles;
    nsf_uint_t alive_count;
    nsf_uint_t max_lifetime;
    nsf_uint_t ups;
    nsf_fvector_t source;
    nsf_particle_start_func_t start_func;
    nsf_particle_update_func_t update_func;
    nsf_clock_t *clock;
    nsf_cstr_t name;
} nsf_particle_t;
```

### Description

| Field           | Type                         | Description                          |
|-----------------|------------------------------|--------------------------------------|
| `particles`     | `nsf_single_particle_t *`    | Array of particle instances          |
| `sprite`        | `nsf_sprite_t *`             | Shared sprite used for rendering     |
| `max_particles` | `nsf_uint_t`                 | Maximum number of particles          |
| `alive_count`   | `nsf_uint_t`                 | Current active particle count        |
| `max_lifetime`  | `nsf_uint_t`                 | Lifetime of each particle            |
| `ups`           | `nsf_uint_t`                 | Updates per second                   |
| `source`        | `nsf_fvector_t`              | Spawn position                       |
| `start_func`    | `nsf_particle_start_func_t`  | Initialization function per particle |
| `update_func`   | `nsf_particle_update_func_t` | Per-frame update function            |
| `clock`         | `nsf_clock_t *`              | Internal timing system               |
| `name`          | `nsf_cstr_t`                 | Identifier                           |

---

## 🔹 Purpose

The particle module provides a flexible and efficient system to simulate multiple dynamic elements using a shared rendering resource.

* Main responsibility: manage and render particle systems
* Abstracts multiple moving entities using a single sprite
* Provides customizable behavior via function pointers
* Integrates tightly with the game loop and rendering system

---

## 🔹 Dependencies

| Module        | Usage                              |
|---------------|------------------------------------|
| `nsf_sprite`  | Rendering particles                |
| `nsf_texture` | Texture binding                    |
| `nsf_window`  | Draw target                        |
| `nsf_game`    | Memory tracking                    |
| `nsf_vector`  | Position and velocity updates      |
| `nsf_clock`   | Timing and update synchronization  |
| `utils`       | Memory helpers (`malloc_any`, etc) |

---

## 🔹 API

### Creation / Destruction

| Function                    | Description             |
|-----------------------------|-------------------------|
| `nsf_particle_create(...)`  | Create particle system  |
| `nsf_particle_destroy(...)` | Destroy particle system |

---

### Core Functions

| Function                             | Description                         |
|--------------------------------------|-------------------------------------|
| `nsf_particle_update(...)`           | Update all particles                |
| `nsf_particle_draw(...)`             | Update (timed) and render particles |
| `nsf_particle_set_texture(...)`      | Set particle texture                |
| `nsf_particle_set_scale(...)`        | Set sprite scale                    |
| `nsf_particle_set_size(...)`         | Set sprite size                     |
| `nsf_particle_set_source(...)`       | Set spawn position                  |
| `nsf_particle_set_max_lifetime(...)` | Set particle lifetime               |
| `nsf_particle_set_ups(...)`          | Set update frequency                |

---

### Advanced / Custom Behavior

| Function                       | Description         |
|--------------------------------|---------------------|
| `nsf_particle_set_start(...)`  | Set spawn behavior  |
| `nsf_particle_set_update(...)` | Set update behavior |

---

## 🔹 Parameters Reference

| Name          | Type                         | Description          |
|---------------|------------------------------|----------------------|
| `name`        | `const char *`               | Identifier           |
| `game`        | `nsf_game_t *`               | Allocation context   |
| `particle`    | `nsf_particle_t *`           | Particle system      |
| `texture`     | `nsf_texture_t *`            | Texture resource     |
| `source`      | `nsf_fvector_t *`            | Spawn position       |
| `ups`         | `nsf_uint_t`                 | Updates per second   |
| `start_func`  | `nsf_particle_start_func_t`  | Spawn initialization |
| `update_func` | `nsf_particle_update_func_t` | Per-frame behavior   |

---

## 🔹 Return Values

| Type      | Meaning                      |
|-----------|------------------------------|
| `pointer` | Valid particle system        |
| `NULL`    | Allocation failure           |
| `int`     | Status code (destroy/update) |
| `bool`    | Success / failure (internal) |

---

## 🔹 Behavior Overview

### Particle Lifecycle

1. Particle is spawned at `source`
2. `start_func` initializes velocity and properties
3. Each update:

    * Position += velocity
    * `update_func` modifies state
    * Lifetime decreases
4. When lifetime reaches 0:

    * Particle is replaced (swap with last alive)
    * New particle is spawned

---

### Update Timing

* Controlled via `ups` (updates per second)
* Internally synchronized using `nsf_clock`
* Prevents frame-dependent behavior

---

## 🔹 Notes

* Uses **single sprite instance** for all particles (performance optimization)
* Particle data stored in contiguous array
* Swap-removal ensures efficient deletion (O(1))
* Behavior fully customizable via function pointers
* `ups = 0` may result in no updates (must be set properly)

---

## 🔹 Internal Files

| File                               | Role                     |
|------------------------------------|--------------------------|
| `nsf_particle_struct.c`            | Creation / destruction   |
| `nsf_particle_manage_set_update.c` | Update functions setters |
| `nsf_particle_manage_set_value.c`  | Settings setters         |
| `nsf_particle_manage_update.c`     | Update logic & spawning  |
| `nsf_particle_draw.c`              | Rendering + timed update |

---

## 🔹 Related Submodules

* [`nsf_sprite` 🔗](sprite.md)
* [`nsf_texture` 🔗](texture.md)
* [`nsf_window` 🔗](../games/window.md)
* [`nsf_clock` 🔗](../systems/clock.md)

---

## 🔹 CSFML Mapping (Optional)

| NSF               | CSFML                       |
|-------------------|-----------------------------|
| `nsf_particle_t`  | *(no direct equivalent)*    |
| `nsf_sprite_draw` | `sfRenderWindow_drawSprite` |
| `nsf_fvector_t`   | `sfVector2f`                |

---

## 🔹 Implementation Notes (for contributors)

* Keep update logic split between spawn and update phases
* Avoid reallocating particle array during runtime
* Maintain separation between logic and rendering
* Ensure `alive_count` consistency when removing particles
* Do not bypass `start_func` / `update_func` abstraction

---

## 🔹 Extension Points

* Add color / alpha fading over lifetime
* Add per-particle rotation support
* Add multiple sprite support (texture atlas / animation)
* Add emission shapes (circle, cone, line)
* Integrate with ECS or scene systems

---

## 🔹 Example Usage

```c
void start_particle(nsf_single_particle_t *p)
{
    nsf_fvector_copy((nsf_fvector_t[]){
        {(rand() % 3) - 1.5f, (rand() % 6) - 3.0f}
    }, &p->velocity);
    // set initial velocity
}

void update_particle(nsf_single_particle_t *p)
{
    p->velocity.y += 1.0f;
    nsf_vector_clamp_y(&p->velocity, -1.5f, 20.0f, &p->velocity);
    // clamp y to have max speed of 20px/s
}

nsf_particle_t *p = nsf_particle_create("particle", 30, game);
nsf_particle_set_texture(p, texture);
nsf_particle_set_start(p, start_particle);
nsf_particle_set_update(p, update_particle);
nsf_particle_set_ups(p, 5);
nsf_particle_set_max_lifetime(p, 10);
nsf_particle_set_source(p, (nsf_fvector_t[]){{50.0f, 20.0f}});
```

---

<div align="center">

<h2>📦 Epitech Base — Footer</h2>

<img src="https://raw.githubusercontent.com/Jarjarbin06/Epitech_Base/refs/heads/main/docs/EpitechBaseLogo.png" width="120"  alt="Epitech Base Logo"/><br>

<h3>Epitech Base • Modular C Ecosystem<br></h3>

<pre>
Libraries:
file       v0.1.2
flag       v0.1.1
llist      v0.0.0
newcsfml   v0.2.8
newerror   v0.1.1
print      v0.1.5
str        v0.1.5
twodlist   v0.0.0
utils      v0.1.5
</pre>

Author: Nathan (Jarjarbin06) • EPITECH<br>
Licence: GPL v3<br>
Repository: <a href="https://github.com/Jarjarbin06/Epitech_Base">Epitech Base</a>
</div>

---
