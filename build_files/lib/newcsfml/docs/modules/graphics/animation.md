---
title: NewCSFML - Graphics - NSF_Animation
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

# 📦 Animation Module (`nsf_animation`)
#### part of [Graphics](overview.md)

Sprite sheet animation module handling frame extraction and progression.

> Example:
> Handles frame-based animation using a texture atlas (sprite sheet), updating the visible rectangle over time.

---

## 🔹 Header

```c
#include <newcsfml/graphics/animation.h>
```

---

## 🔹 Structure

```c
typedef struct nsf_animation_s {
    sfTexture *texture;
    sfIntRect rect;
    nsf_uvector_t sheet_size;
    nsf_uvector_t sprite_size;
    nsf_uvector_t offset;
    int current_line;
    nsf_uint_t rows;
    nsf_uint_t columns;
    nsf_uint_t step;
    nsf_cstr_t name;
} nsf_animation_t;
```

### Description

| Field          | Type            | Description                           |
|----------------|-----------------|---------------------------------------|
| `texture`      | `sfTexture *`   | Source texture (sprite sheet)         |
| `rect`         | `sfIntRect`     | Current frame rectangle               |
| `sheet_size`   | `nsf_uvector_t` | Full texture size                     |
| `sprite_size`  | `nsf_uvector_t` | Size of a single frame                |
| `offset`       | `nsf_uvector_t` | Spacing between frames                |
| `current_line` | `int`           | Current selected frame                |
| `rows`         | `nsf_uint_t`    | Number of rows in the sprite sheet    |
| `columns`      | `nsf_uint_t`    | Number of columns in the sprite sheet |
| `step`         | `nsf_uint_t`    | Current animation frame index         |
| `name`         | `nsf_cstr_t`    | Identifier                            |

---

## 🔹 Purpose

Provides a lightweight system to handle sprite sheet animations.

* Main responsibility: compute and update the visible frame rectangle
* Abstracts: `sfTexture` + `sfIntRect` frame selection
* Architecture role: used by rendering modules (e.g., `nsf_sprite`) to animate textures

---

## 🔹 Dependencies

| Module       | Usage                          |
|--------------|--------------------------------|
| `nsf_game`   | Allocation tracking            |
| `nsf_utils`  | Logging and safety checks      |
| `nsf_vector` | Offset manipulation            |
| *(CSFML)*    | Texture and rectangle handling |

---

## 🔹 API

### Creation / Destruction

| Function                     | Description                   |
|------------------------------|-------------------------------|
| `nsf_animation_create(...)`  | Create animation from texture |
| `nsf_animation_destroy(...)` | Destroy and free animation    |

---

### Core Functions

| Function                        | Description                |
|---------------------------------|----------------------------|
| `nsf_animation_update(...)`     | Update frame rectangle     |
| `nsf_animation_set_step(...)`   | Set current frame index    |
| `nsf_animation_set_sizes(...)`  | Define rows and columns    |
| `nsf_animation_set_offset(...)` | Set spacing between frames |

---

### Advanced / Optional

| Function                       | Description               |
|--------------------------------|---------------------------|
| `nsf_animation_<feature>(...)` | Custom animation behavior |
| `nsf_animation_<feature>(...)` | Extended control          |

---

## 🔹 Parameters Reference

| Name        | Type                | Description        |
|-------------|---------------------|--------------------|
| `path`      | `const char *`      | Texture file path  |
| `name`      | `const char *`      | Identifier         |
| `game`      | `nsf_game_t *`      | Allocation context |
| `animation` | `nsf_animation_t *` | Animation instance |
| `step`      | `nsf_uint_t`        | Frame index        |
| `columns`   | `nsf_uint_t`        | Number of columns  |
| `rows`      | `nsf_uint_t`        | Number of rows     |
| `offset`    | `nsf_uvector_t *`   | Frame spacing      |

---

## 🔹 Return Values

| Type      | Meaning                     |
|-----------|-----------------------------|
| `pointer` | Valid animation object      |
| `NULL`    | Allocation failure          |
| `int`     | Status code                 |
| `void`    | No return (in-place update) |

---

## 🔹 Notes

* Requires valid `columns` and `rows` before update
* Frame selection is computed using `step`
* Automatically clamps `step` within valid range
* No internal timing → must be driven externally (e.g., clock or game loop)
* Uses defensive programming (`NSF_UNLIKELY`)

---

## 🔹 Internal Files

| File                            | Role                      |
|---------------------------------|---------------------------|
| `nsf_animation_struct.c`        | Creation / destruction    |
| `nsf_animation_manage_set.c`    | Setters                   |
| `nsf_animation_manage_update.c` | Frame computation         |
| `nsf_animation_draw.c`          | Rendering (if applicable) |

---

## 🔹 Related Modules

* `nsf_sprite`
* `nsf_texture`
* `nsf_window`

---

## 🔹 CSFML Mapping (Optional)

| NSF               | CSFML                    |
|-------------------|--------------------------|
| `nsf_animation_t` | *(no direct equivalent)* |
| `rect`            | `sfIntRect`              |
| `texture`         | `sfTexture`              |

---

## 🔹 Implementation Notes (for contributors)

* Keep update logic independent from rendering
* Validate all pointers before usage
* Avoid recomputing values unnecessarily
* Maintain strict separation between `set` and `update`
* Follow Epitech C coding style

---

## 🔹 Extension Points

* Add time-based animation (FPS / delta time)
* Add looping / ping-pong modes
* Add named animation states
* Support irregular sprite sheets
* Integrate directly with `nsf_sprite`
