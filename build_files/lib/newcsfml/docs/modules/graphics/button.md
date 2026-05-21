# 📦 Button Module (`nsf_button`)
#### part of [Graphics](overview.md)

Interactive UI component built on top of SFML rectangles.
It provides clickable elements with texture support, visual states, and mouse interaction handling.

> Example:
> Handles UI buttons with hover/press state detection and rendering.

---

## 🔹 Header

```c
#include <newcsfml/graphics/button.h>
```

---

## 🔹 Structure

```c
typedef struct {
    sfRectangleShape *button;
    const nsf_texture_t *texture;
    nsf_fvector_t size;
    nsf_fvector_t position;
    nsf_color_t fill_color;
    nsf_color_t outline_color;
    nsf_cstr_t name;
} nsf_button_t;
```

### Description

| Field           | Type                    | Description                             |
|-----------------|-------------------------|-----------------------------------------|
| `button`        | `sfRectangleShape *`    | SFML rectangle shape used for rendering |
| `texture`       | `const nsf_texture_t *` | Optional texture applied to the button  |
| `size`          | `nsf_fvector_t`         | Button size in pixels                   |
| `position`      | `nsf_fvector_t`         | Button position in world space          |
| `fill_color`    | `nsf_color_t`           | Background color                        |
| `outline_color` | `nsf_color_t`           | Border color                            |
| `name`          | `nsf_cstr_t`            | Identifier used for lookup              |

---

## 🔹 Purpose

Represents an interactive UI element that reacts to mouse input.

* Encapsulates SFML rectangle shape into a higher-level UI component
* Supports texture rendering and color styling
* Provides runtime state detection (hovered, pressed, idle)
* Integrates with window element system for centralized management

---

## 🔹 Dependencies

| Module        | Usage                                  |
|---------------|----------------------------------------|
| `nsf_texture` | Optional texture binding               |
| `nsf_window`  | Mouse position and rendering context   |
| `nsf_game`    | Memory tracking and allocation control |

---

## 🔹 API

### Creation / Destruction

| Function                  | Description                  |
|---------------------------|------------------------------|
| `nsf_button_create(...)`  | Create a new button instance |
| `nsf_button_destroy(...)` | Destroy and free button      |

---

### Core Functions

| Function                       | Description                            |
|--------------------------------|----------------------------------------|
| `nsf_button_set_texture(...)`  | Assign texture to button               |
| `nsf_button_set_position(...)` | Set button position                    |
| `nsf_button_set_size(...)`     | Set button size                        |
| `nsf_button_set_colors(...)`   | Configure fill, outline, and thickness |
| `nsf_button_get_state(...)`    | Return current interaction state       |

---

### Advanced / Optional

| Function                   | Description                                   |
|----------------------------|-----------------------------------------------|
| *(none currently defined)* | State system already covers interaction logic |

---

## 🔹 Parameters Reference

| Name                | Type                 | Description                       |
|---------------------|----------------------|-----------------------------------|
| `button`            | `nsf_button_t *`     | Button instance                   |
| `texture`           | `nsf_texture_t *`    | Texture resource                  |
| `position`          | `nsf_fvector_t *`    | Position vector                   |
| `size`              | `nsf_fvector_t *`    | Size vector                       |
| `window`            | `nsf_window_t *`     | Render window context             |
| `mouse_button`      | `nsf_mouse_button_t` | Mouse button used for interaction |
| `fill_color`        | `nsf_color_t`        | Background color                  |
| `outline_color`     | `nsf_color_t`        | Border color                      |
| `outline_thickness` | `nsf_uint_t`         | Border thickness                  |

---

## 🔹 Return Values

| Type                  | Meaning                              |
|-----------------------|--------------------------------------|
| `pointer`             | Valid button object                  |
| `NULL`                | Allocation or initialization failure |
| `int`                 | Status code (`E_SUCCESS`, `E_ERROR`) |
| `nsf_button_status_t` | Interaction state result             |

---

## 🔹 Notes

* Button state is computed dynamically using mouse position and input state
* Texture is optional; button works without it
* Must be drawn via `nsf_button_draw`
* Memory ownership is tracked through `nsf_game_t`
* State system is purely query-based (no internal event storage)

---

## 🔹 Internal Files

| File                      | Role                           |
|---------------------------|--------------------------------|
| `nsf_button_struct.c`     | Creation and destruction logic |
| `nsf_button_manage_get.c` | Getters                        |
| `nsf_button_manage_set.c` | Setters and state logic        |
| `nsf_button_draw.c`       | Rendering                      |

---

## 🔹 Related Submodules

* [`nsf_window` 🔗](../games/window.md)
* [`nsf_texture` 🔗](texture.md)
* [`nsf_game` 🔗](../games/game.md)

---

## 🔹 CSFML Mapping (Optional)

| NSF                    | CSFML                                          |
|------------------------|------------------------------------------------|
| `nsf_button_t`         | `sfRectangleShape`                             |
| `nsf_button_draw`      | `sfRenderWindow_drawRectangleShape`            |
| `nsf_button_get_state` | `sfMouse_* + sfRectangleShape_getGlobalBounds` |

---

## 🔹 Implementation Notes (for contributors)

* Always validate pointers before SFML calls
* Keep state computation stateless and deterministic
* Do not store transient input state inside the structure
* Texture assignment must not break shape size consistency
* Follow strict separation between:

    * creation/destruction
    * state logic
    * rendering

---

## 🔹 Extension Points

* Add click callback system (event binding)
* Add animation states (hover transition, click feedback)
* Support text labels on buttons
* Extend with UI theme system
* Add input abstraction layer for controller support

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
newcsfml   v0.2.7
newerror   v0.1.1
print      v0.1.5
str        v0.1.5
twodlist   v0.0.0
utils      v0.1.5
</pre>

Author: Nathan (Jarjarbin06) • EPITECH<br>
Licence: GPL v3<br>
Repository: [Epitech Base](https://github.com/Jarjarbin06/Epitech_Base)
</div>

---
