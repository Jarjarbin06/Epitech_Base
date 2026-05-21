# 📦 Text Module (`nsf_text`)
#### part of [Graphics](overview.md)

Interactive UI component built on top of SFML rectangles.
It provides clickable elements with texture support, visual states, and mouse interaction handling.

> Example:
> Show debug info and FPS counter on screen.

---

## 🔹 Header

```c
#include <newcsfml/graphics/text.h>
```

---

## 🔹 Structure

```c
typedef struct nsf_text_s {
    sfText *text;
    const sfFont *font;
    nsf_fvector_t postition;
    nsf_fvector_t origin;
    nsf_uint_t size;
    float rotation;
    nsf_str_t string;
    nsf_color_t color;
    nsf_cstr_t name;
} nsf_text_t;
```

### Description

| Field      | Type             | Description                                         |
|------------|------------------|-----------------------------------------------------|
| `text`     | `sfText *`       | SFML text used for rendering                        |
| `font`     | `const sfFont *` | Font applied to the text                            |
| `position` | `nsf_fvector_t`  | World position                                      |
| `origin`   | `nsf_fvector_t`  | Rotation/scaling origin                             |
| `size`     | `nsf_uint_t`     | Character size                                      |
| `rotation` | `float`          | Rotation angle (unused in current API but reserved) |
| `string`   | `nsf_str_t`      | Actual text                                         |
| `color`    | `nsf_color_t`    | Text color                                          |
| `name`     | `nsf_cstr_t`     | Identifier used for lookup                          |

---

## 🔹 Purpose

Represents an UI text element.

* Supports color styling and runtime text modification
* Integrates with window element system for centralized management

---

## 🔹 Dependencies

| Module        | Usage                                  |
|---------------|----------------------------------------|
| `nsf_window`  | Rendering context                      |
| `nsf_game`    | Memory tracking and allocation control |

---

## 🔹 API

### Creation / Destruction

| Function                | Description                |
|-------------------------|----------------------------|
| `nsf_text_create(...)`  | Create a new text instance |
| `nsf_text_destroy(...)` | Destroy and free text      |

---

### Core Functions

| Function                     | Description                  |
|------------------------------|------------------------------|
| `nsf_text_set_string(...)`   | Set the text to a new string |
| `nsf_text_set_size(...)`     | Set text size                |
| `nsf_text_set_position(...)` | Set text position            |
| `nsf_text_set_color(...)`    | Configure text color         |
| `nsf_text_draw(...)`         | Render text                  |

---

### Advanced / Optional

| Function                            | Description                             |
|-------------------------------------|-----------------------------------------|
| `nsf_text_set_watcher(...)`         | Set a watcher linked to a pointer       |
| `nsf_text_get_watcher(...)`         | Get the linked watcher                  |
| `nsf_text_update_from_watcher(...)` | Update the text string from the watcher |

---

## 🔹 Parameters Reference

| Name        | Type              | Description           |
|-------------|-------------------|-----------------------|
| `name`      | `const char *`    | Text identifier       |
| `font_path` | `const char *`    | Path to font          |
| `game`      | `nsf_game_t *`    | Allocation context    |
| `text`      | `nsf_text_t *`    | Text instance         |
| `watcher`   | `nsf_watcher_t *` | Watcher instance      |
| `position`  | `nsf_fvector_t *` | Position vector       |
| `size`      | `nsf_uint_t`      | Size                  |
| `window`    | `nsf_window_t *`  | Render window context |
| `color`     | `nsf_color_t *`   | Text color            |

---

## 🔹 Return Values

| Type      | Meaning                              |
|-----------|--------------------------------------|
| `pointer` | Valid text object                    |
| `NULL`    | Allocation or initialization failure |
| `int`     | Status code (`E_SUCCESS`, `E_ERROR`) |

---

## 🔹 Notes

* Must be drawn via `nsf_text_draw`
* Memory ownership is tracked through `nsf_game_t`
* State system is purely query-based (no internal event storage)

---

## 🔹 Internal Files

| File                        | Role                           |
|-----------------------------|--------------------------------|
| `nsf_text_struct.c`         | Creation and destruction logic |
| `nsf_text_manage_set.c`     | Setters and state logic        |
| `nsf_text_manage_get.c`     | Getters                        |
| `nsf_text_manage_watcher.c` | Watcher setters and logic      |
| `nsf_text_draw.c`           | Rendering                      |

---

## 🔹 Related Submodules

* [`nsf_window` 🔗](../games/window.md)
* [`nsf_game` 🔗](../games/game.md)
* [`nsf_button` 🔗](button.md)
* [`nsf_watcher` 🔗](../systems/watcher.md)

---

## 🔹 CSFML Mapping (Optional)

| NSF                    | CSFML                                          |
|------------------------|------------------------------------------------|
| `nsf_text_t`           | `sfText + sfFont`                              |

---

## 🔹 Implementation Notes (for contributors)

* Always validate pointers before SFML calls
* Follow strict separation between:

    * creation/destruction
    * rendering

---

## 🔹 Extension Points

* Add animation and effects
* Support linking to button
* Extend with UI theme system

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
