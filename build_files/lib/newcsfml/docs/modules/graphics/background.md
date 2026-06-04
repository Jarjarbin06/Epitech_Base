---
title: NewCSFML - Graphics - NSF_Background
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

# 📦 Background Module (`nsf_background`)
#### part of [Graphics](overview.md)

The background module manages a full-screen visual layer composed of a sprite and its associated texture. It is designed to be used as the base rendering layer inside a window.

> Example:
> Handles background image rendering and window-sized sprite adaptation.

---

## 🔹 Header

```c
#include <newcsfml/graphics/background.h>
```

---

## 🔹 Structure

```c
typedef struct nsf_background_s {
    nsf_sprite_t *sprite;
    nsf_texture_t *texture;
} nsf_background_t;
```

### Description

| Field     | Type              | Description                              |
|-----------|-------------------|------------------------------------------|
| `sprite`  | `nsf_sprite_t *`  | Sprite used to render the background     |
| `texture` | `nsf_texture_t *` | Texture applied to the background sprite |

---

## 🔹 Purpose

The background module is responsible for displaying a full-window visual layer.

* Main responsibility: render a static or textured background
* Abstracts a CSFML sprite + texture pair configured for full-screen rendering
* Fits at the lowest level of the rendering pipeline, drawn before all UI elements

---

## 🔹 Dependencies

| Module        | Usage                      |
|---------------|----------------------------|
| `nsf_sprite`  | Rendering container        |
| `nsf_texture` | Image data source          |
| `nsf_window`  | Window size reference      |
| `nsf_game`    | Memory allocation tracking |

---

## 🔹 API

### Creation / Destruction

| Function                      | Description                          |
|-------------------------------|--------------------------------------|
| `nsf_background_create(...)`  | Create background (sprite + texture) |
| `nsf_background_destroy(...)` | Free background resources            |

---

### Core Functions

| Function                   | Description              |
|----------------------------|--------------------------|
| `nsf_background_draw(...)` | Render background sprite |

---

### Advanced / Optional

| Function | Description                  |
|----------|------------------------------|
| None     | No advanced features defined |

---

## 🔹 Parameters Reference

| Name     | Type             | Description                      |
|----------|------------------|----------------------------------|
| `path`   | `const char *`   | Texture file path                |
| `window` | `nsf_window_t *` | Window used to adapt sprite size |
| `game`   | `nsf_game_t *`   | Allocation context               |

---

## 🔹 Return Values

| Type      | Meaning                              |
|-----------|--------------------------------------|
| `pointer` | Valid background object              |
| `NULL`    | Allocation or initialization failure |
| `int`     | Status code (destroy function)       |

---

## 🔹 Notes

* Uses `nsf_game_t` for allocation tracking
* Background sprite is automatically resized to match window dimensions
* Must be drawn before any UI or interactive elements
* Currently no effects system implemented (reserved for future extension)

---

## 🔹 Internal Files

| File                      | Role                   |
|---------------------------|------------------------|
| `nsf_background_struct.c` | Creation / destruction |
| `nsf_background_draw.c`   | Rendering logic        |

---

## 🔹 Related Submodules

* [`nsf_sprite` 🔗](sprite.md)
* [`nsf_texture` 🔗](texture.md)
* [`nsf_window` 🔗](../games/window.md)

---

## 🔹 CSFML Mapping (Optional)

| NSF                   | CSFML Equivalent            |
|-----------------------|-----------------------------|
| `nsf_background_t`    | `sfSprite + sfTexture`      |
| `nsf_background_draw` | `sfRenderWindow_drawSprite` |

---

## 🔹 Implementation Notes (for contributors)

* Keep background strictly separated from UI elements
* Do not embed logic unrelated to rendering
* Sprite must always cover full window area
* Follow modular split: `struct`, `draw`

---

## 🔹 Extension Points

* Add shader/effects support (blur, parallax, tint)
* Support animated backgrounds
* Allow multiple layered backgrounds
* Extend struct without breaking sprite/texture relationship
