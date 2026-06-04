---
title: NewCSFML - Graphics - Overview
---
<link rel="icon" type="image/x-icon" href="https://raw.githubusercontent.com/Jarjarbin06/Epitech_Base/refs/heads/main/build_files/lib/newcsfml/resouces/NCSFML_logo_transparent.png">

# 📦 `Graphics`
#### part of [NewCSFML](../../README.md)

Rendering and visual system built on top of CSFML, providing abstraction for textures, sprites, UI elements, and background rendering.

> Example:
> Handles all drawable elements including sprites, textures, UI buttons, and background layers.

---

## 🔹 Header

```c
#include <newcsfml/graphics/<module>.h>
````

---

## 🔹 Overview

| Submodule    | Role                                     |
|--------------|------------------------------------------|
| `texture`    | Loads and manages image resources        |
| `sprite`     | Handles drawable 2D objects              |
| `button`     | Provides interactive UI elements         |
| `background` | Manages full-screen background rendering |

---

## 🔹 Purpose

The graphics module is responsible for all visual rendering within the framework.

* Abstracts CSFML rendering primitives (`sfTexture`, `sfSprite`, shapes)
* Provides a structured and reusable rendering pipeline
* Separates resource management (textures) from rendering logic (sprites/UI)
* Enables consistent handling of drawable and interactive elements

It exists to unify all rendering operations under a modular and extensible architecture.

---

## 🔹 Architecture

### Internal Composition

```
graphics
├── texture
├── sprite
├── button
└── background
```

### Flow

```
User → Graphics API → Sprite/Button/Background → Texture → CSFML → Rendering
```

---

## 🔹 Dependencies

| Module        | Usage                       |
|---------------|-----------------------------|
| `nsf_game`    | Memory tracking / ownership |
| `nsf_systems` | Vectors, colors, utilities  |
| `nsf_window`  | Rendering target            |
| `CSFML`       | Low-level rendering backend |

---

## 🔹 Key Responsibilities

* Manage graphical resources (textures)
* Provide drawable entities (sprites, background)
* Handle UI interaction elements (buttons)
* Abstract CSFML rendering calls
* Ensure consistent transformation and rendering pipeline

**Must NOT:**

* Handle game logic
* Store input state (except query-based UI state)
* Directly manage window lifecycle

---

## 🔹 Submodules

| Submodule    | Description                          |
|--------------|--------------------------------------|
| `texture`    | Loads and stores GPU textures        |
| `sprite`     | Drawable entity with transformations |
| `button`     | Interactive UI component             |
| `background` | Full-screen rendering layer          |

---

## 🔹 Public API Summary

### High-Level Functions

| Function                   | Description        |
|----------------------------|--------------------|
| `nsf_texture_create()`     | Load texture       |
| `nsf_texture_destroy()`    | Free texture       |
| `nsf_sprite_create()`      | Create sprite      |
| `nsf_sprite_destroy()`     | Destroy sprite     |
| `nsf_button_create()`      | Create button      |
| `nsf_button_destroy()`     | Destroy button     |
| `nsf_background_create()`  | Create background  |
| `nsf_background_destroy()` | Destroy background |

---

### Subsystem APIs

| Subsystem    | Example Function             |
|--------------|------------------------------|
| `sprite`     | `nsf_sprite_set_position()`  |
| `button`     | `nsf_button_get_state()`     |
| `background` | `nsf_background_draw()`      |
| `texture`    | *(creation only, immutable)* |

---

## 🔹 Usage Example

```c
nsf_texture_t *tex = nsf.texture.create("player.png", "player", game);
nsf_sprite_t *sprite = nsf.sprite.create("player", game);

nsf.sprite.set_texture(sprite, tex);
nsf.sprite.set_position(sprite, &(nsf_fvector_t){100, 200});

nsf.sprite.draw(sprite, window);
```

---

## 🔹 Data Flow

| Step | Action                              |
|------|-------------------------------------|
| 1    | Load texture via `texture_create()` |
| 2    | Create sprite/button/background     |
| 3    | Bind texture to drawable            |
| 4    | Update transformations              |
| 5    | Render via window                   |
| 6    | Cleanup resources                   |

---

## 🔹 Design Constraints

* Must not expose raw CSFML objects
* Must use `nsf_game_t` for allocation tracking
* Textures must remain immutable after creation
* Rendering must go through module APIs only
* Must remain modular and composable

---

## 🔹 Common Patterns

* Resource → Bind → Transform → Draw
* Name-based resource identification
* Stateless UI interaction (button states)
* Separation between data (struct) and logic (manage/draw)

---

## 🔹 Known Limitations

* No built-in animation system
* No batching optimization yet
* No shader/effects pipeline implemented

---

## 🔹 Documentation Index

This section provides quick access to the audio module documentation.
Detailed behavior and API are described within each submodule.

### Submodules

* [Animation](animation.md) — Animation texture
* [Texture](texture.md) — Normal texture
* [Sprite](sprite.md) — Drawable entity
* [Particle](particle.md) — Entity with customisable behaviour
* [Background](background.md) — Background image
* [Button](button.md) — Interactive element
* [Text](text.md) — Text element
* [View](view.md) — Window view system

---

## 🔹 Related Modules

* [Games](../games/overview.md)
* [Systems](../systems/overview.md)

---

## 🔹 Notes

* This module is central to all rendering operations
* Designed to be extensible (UI, animations, effects)
* Strong separation between rendering and logic layers

---

## 🔹 Internal Files

| File          | Role                        |
|---------------|-----------------------------|
| `*_struct.c`  | Data structures & lifecycle |
| `*_manage*.c` | Logic and transformations   |
| `*_draw.c`    | Rendering logic             |

---

## 🔹 Extension Guidelines

* Add new drawable types as separate submodules
* Keep texture handling centralized
* Avoid modifying existing structures directly
* Prefer composition (e.g., UI system on top of button)

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
