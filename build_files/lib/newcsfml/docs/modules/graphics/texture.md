# 📦 Texture Module (`nsf_texture`)
#### part of [Graphics](overview.md)

Handles loading, storing, and managing SFML textures used by sprites and UI elements.

> Example:
> Loads image files into GPU textures and provides a reusable reference system for rendering.

---

## 🔹 Header

```c
#include <newcsfml/graphics/texture.h>
```

---

## 🔹 Structure

```c
typedef struct nsf_texture_s {
    sfTexture *texture;
    nsf_cstr_t name;
} nsf_texture_t;
```

### Description

| Field     | Type          | Description                          |
|-----------|---------------|--------------------------------------|
| `texture` | `sfTexture *` | SFML texture loaded from image file  |
| `name`    | `nsf_cstr_t`  | Identifier used for lookup / caching |

---

## 🔹 Purpose

This module is responsible for managing graphical textures in a centralized and reusable way.

* Loads image files into SFML textures
* Stores textures with an associated identifier
* Provides a clean abstraction over `sfTexture`
* Used by sprites and other renderable objects

It sits at the base of the rendering system, since most visual elements depend on it.

---

## 🔹 Dependencies

| Module      | Usage                        |
|-------------|------------------------------|
| `nsf_game`  | Memory tracking / allocation |
| `sfTexture` | Core SFML texture system     |

---

## 🔹 API

### Creation / Destruction

| Function                               | Description            |
|----------------------------------------|------------------------|
| `nsf_texture_create(path, name, game)` | Load texture from file |
| `nsf_texture_destroy(texture, game)`   | Free texture resources |

---

### Core Functions

This module is intentionally minimal.

| Function | Description                           |
|----------|---------------------------------------|
| —        | No setters/getters (immutable design) |
| —        | Texture is read-only after creation   |

---

### Advanced / Optional

| Function | Description                                |
|----------|--------------------------------------------|
| —        | No advanced features currently implemented |

---

## 🔹 Parameters Reference

| Name   | Type           | Description                 |
|--------|----------------|-----------------------------|
| `path` | `const char *` | File path to image          |
| `name` | `const char *` | Identifier for the texture  |
| `game` | `nsf_game_t *` | Allocation tracking context |

---

## 🔹 Return Values

| Type      | Meaning                        |
|-----------|--------------------------------|
| `pointer` | Valid texture instance         |
| `NULL`    | File load / allocation failure |
| `int`     | Status code (destroy function) |
| `bool`    | Not used                       |

---

## 🔹 Notes

* Uses `nsf_game_t` for allocation tracking
* Texture is shared by reference (do not duplicate manually)
* Must be destroyed via `nsf_texture_destroy`
* Designed to be lightweight and reusable

---

## 🔹 Internal Files

| File                   | Role                   |
|------------------------|------------------------|
| `nsf_texture_struct.c` | Creation / destruction |

---

## 🔹 Related Submodules

* [`nsf_sprite` 🔗](sprite.md)
* [`nsf_background` 🔗](background.md)
* [`nsf_button` 🔗](button.md)

---

## 🔹 CSFML Mapping (Optional)

| NSF             | CSFML         |
|-----------------|---------------|
| `nsf_texture_t` | `sfTexture`   |
| `texture` field | `sfTexture *` |

---

## 🔹 Implementation Notes (for contributors)

* Keep texture immutable after creation
* Avoid duplicating SFML textures
* Ensure proper cleanup in `destroy`
* Follow Epitech C coding style strictly

---

## 🔹 Extension Points

* Add texture caching system (avoid duplicate loads)
* Add reference counting if sharing becomes complex
* Extend with async loading if needed

---

<div align="center">

## 📦 Epitech Base — Footer

</div>
<div align="center">

<img src="https://raw.githubusercontent.com/Jarjarbin06/Epitech_Base/refs/heads/main/docs/EpitechBaseLogo.png" width="120"  alt="Epitech Base Logo"/>

Epitech Base • Modular C Ecosystem

Libraries:<br>
• `file` - `v0.1.2`<br>
• `flag` - `v0.1.1`<br>
• `llist` - `v0.0.0`<br>
• `newcsfml` - `v0.2.7`<br>
• `newerror` - `v0.1.1`<br>
• `print` - `v0.1.5`<br>
• `str` - `v0.1.5`<br>
• `print` - `v0.0.0`<br>
• `twodlist` - `v0.1.5`<br>
• `utils` - `v0.1.5`<br>

Author: Nathan (Jarjarbin06) • EPITECH<br>
Licence: GPL v3<br>
Repository: [Epitech Base](https://github.com/Jarjarbin06/Epitech_Base)
</div>

---
