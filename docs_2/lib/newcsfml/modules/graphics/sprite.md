---
title: NewCSFML - Graphics - NSF_Sprite
---
<style>
    * {
      position: relative;
      z-index: 5;
    body {
      font-family: "Roboto", sans-serif;
      margin: 0;
      padding: 0;
      overflow-x: hidden;
    }
    a {
      text-decoration: none;
    }
}
</style>
<link rel="icon" type="image/x-icon" href="https://raw.githubusercontent.com/Jarjarbin06/Epitech_Base/refs/heads/main/build_files/lib/newcsfml/resouces/NCSFML_logo_transparent.png">

# 📦 Sprite Module (`nsf_sprite`)
#### part of [Graphics](overview.md)

The sprite module is responsible for handling 2D drawable objects, including texture binding, transformations (position, scale, origin, rotation), and rendering through CSFML.

> Example:
> Handles sprite rendering, transformation, texture binding, and update synchronization.

---

## 🔹 Header

```c
#include <newcsfml/graphics/sprite.h>
```

---

## 🔹 Structure

```c
typedef struct nsf_sprite_s {
    sfSprite *sprite;
    const nsf_texture_t *texture;
    nsf_fvector_t scale;
    nsf_fvector_t origin;
    nsf_fvector_t position;
    float rotation;
    nsf_cstr_t name;
    void *data;
} nsf_sprite_t;
```

### Description

| Field      | Type              | Description                                         |
|------------|-------------------|-----------------------------------------------------|
| `sprite`   | `sfSprite *`      | CSFML sprite handle                                 |
| `texture`  | `nsf_texture_t *` | Linked texture resource                             |
| `scale`    | `nsf_fvector_t`   | Sprite scaling factor                               |
| `origin`   | `nsf_fvector_t`   | Rotation/scaling origin                             |
| `position` | `nsf_fvector_t`   | World position                                      |
| `rotation` | `float`           | Rotation angle (unused in current API but reserved) |
| `name`     | `nsf_cstr_t`      | Identifier string                                   |
| `data`     | `void *`          | User-defined extension data                         |

---

## 🔹 Purpose

The sprite module provides a complete abstraction over CSFML sprites, managing both visual representation and transformation state.

* Main responsibility: represent and render 2D textured objects
* Abstracts CSFML `sfSprite` with additional metadata and management helpers
* Central rendering unit used across window, UI, and background systems

---

## 🔹 Dependencies

| Module        | Usage                         |
|---------------|-------------------------------|
| `nsf_texture` | Texture binding and sizing    |
| `nsf_window`  | Rendering target              |
| `nsf_game`    | Memory tracking               |
| `nsf_vector`  | Math utilities for transforms |

---

## 🔹 API

### Creation / Destruction

| Function                  | Description            |
|---------------------------|------------------------|
| `nsf_sprite_create(...)`  | Create sprite instance |
| `nsf_sprite_destroy(...)` | Destroy sprite safely  |

---

### Core Functions

| Function                       | Description                     |
|--------------------------------|---------------------------------|
| `nsf_sprite_set_texture(...)`  | Bind texture and auto-resize    |
| `nsf_sprite_set_scale(...)`    | Set scaling factor              |
| `nsf_sprite_set_size(...)`     | Define sprite size (auto-scale) |
| `nsf_sprite_set_position(...)` | Set world position              |
| `nsf_sprite_set_origin(...)`   | Set transformation origin       |
| `nsf_sprite_update(...)`       | Reapply all transformations     |
| `nsf_sprite_draw(...)`         | Render sprite                   |

---

### Advanced / Optional

| Function                       | Description            |
|--------------------------------|------------------------|
| `nsf_sprite_get_texture(...)`  | Retrieve bound texture |
| `nsf_sprite_get_scale(...)`    | Get current scale      |
| `nsf_sprite_get_size(...)`     | Get computed size      |
| `nsf_sprite_get_position(...)` | Get position           |
| `nsf_sprite_get_origin(...)`   | Get origin             |

---

## 🔹 Parameters Reference

| Name       | Type              | Description        |
|------------|-------------------|--------------------|
| `name`     | `const char *`    | Sprite identifier  |
| `game`     | `nsf_game_t *`    | Allocation context |
| `window`   | `nsf_window_t *`  | Render target      |
| `texture`  | `nsf_texture_t *` | Texture to bind    |
| `scale`    | `nsf_fvector_t *` | Scale vector       |
| `position` | `nsf_fvector_t *` | Position vector    |
| `origin`   | `nsf_fvector_t *` | Origin vector      |

---

## 🔹 Return Values

| Type      | Meaning                          |
|-----------|----------------------------------|
| `pointer` | Valid sprite instance            |
| `NULL`    | Allocation or creation failure   |
| `int`     | Status code (destroy functions)  |
| `bool`    | Success / failure (internal ops) |

---

## 🔹 Notes

* Uses `nsf_game_t` for allocation tracking
* Texture assignment automatically updates sprite scale
* Avoid direct manipulation of CSFML sprite outside module API
* `rotation` field exists but is not yet fully exposed in API
* `update()` re-synchronizes all transformation states

---

## 🔹 Internal Files

| File                         | Role                   |
|------------------------------|------------------------|
| `nsf_sprite_struct.c`        | Creation / destruction |
| `nsf_sprite_manage_get.c`    | Getters                |
| `nsf_sprite_manage_set.c`    | Transform logic        |
| `nsf_sprite_manage_update.c` | Updarer                |
| `nsf_sprite_draw.c`          | Rendering              |

---

## 🔹 Related Submodules

* [`nsf_particle` 🔗](particle.md)
* [`nsf_texture` 🔗](texture.md)
* [`nsf_window` 🔗](../games/window.md)
* [`nsf_background` 🔗](background.md)

---

## 🔹 CSFML Mapping (Optional)

| NSF               | CSFML                       |
|-------------------|-----------------------------|
| `nsf_sprite_t`    | `sfSprite`                  |
| `nsf_sprite_draw` | `sfRenderWindow_drawSprite` |
| `texture`         | `sfTexture`                 |

---

## 🔹 Implementation Notes (for contributors)

* Keep transformation logic centralized in manage files
* Ensure texture and scale remain synchronized
* Avoid modifying `sfSprite` directly outside setters
* Maintain separation between data (struct) and rendering logic

---

## 🔹 Extension Points

* Add rotation API exposure
* Add animation system support
* Extend `data` field for component system / ECS integration
* Add shader or effect support per sprite
