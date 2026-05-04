# 📦 Window Settings Module (`nsf_window_settings`)
#### part of [Games](overview.md)

Lightweight configuration structure used to define and manage window properties such as resolution, frame rate, and color depth.

> Example:
> Stores and manages the runtime configuration of a render window.

---

## 🔹 Header

```c
#include <newcsfml/games/window_settings.h>
```

---

## 🔹 Structure

```c
typedef struct {
    unsigned int width;
    unsigned int height;
    unsigned int fps;
    unsigned int bpp;
} nsf_window_settings_t;
```

### Description

| Field    | Type           | Description                  |
|----------|----------------|------------------------------|
| `width`  | `unsigned int` | Window width in pixels       |
| `height` | `unsigned int` | Window height in pixels      |
| `fps`    | `unsigned int` | Target frame rate            |
| `bpp`    | `unsigned int` | Bits per pixel (color depth) |

---

## 🔹 Purpose

Defines the configuration parameters used to create and update a window.

* Stores resolution, refresh rate, and color format
* Acts as a reusable configuration container for window creation
* Decouples window initialization from runtime logic
* Provides a stable snapshot of window properties

---

## 🔹 Dependencies

| Module       | Usage                                       |
|--------------|---------------------------------------------|
| `nsf_game`   | Allocation tracking and lifecycle ownership |
| `nsf_window` | Consumes settings during window creation    |

---

## 🔹 API

### Creation / Destruction

| Function                           | Description                            |
|------------------------------------|----------------------------------------|
| `nsf_window_settings_create(...)`  | Allocate and copy a settings structure |
| `nsf_window_settings_destroy(...)` | Free settings structure                |

---

### Core Functions

| Function | Description                         |
|----------|-------------------------------------|
| *(none)* | This module is purely data-oriented |

---

### Advanced / Optional

| Function | Description                  |
|----------|------------------------------|
| *(none)* | No extended behavior defined |

---

## 🔹 Parameters Reference

| Name       | Type                      | Description                 |
|------------|---------------------------|-----------------------------|
| `settings` | `nsf_window_settings_t[]` | Source configuration values |
| `game`     | `nsf_game_t *`            | Allocation context          |

---

## 🔹 Return Values

| Type      | Meaning                                    |
|-----------|--------------------------------------------|
| `pointer` | Successfully allocated settings object     |
| `NULL`    | Allocation failure                         |
| `int`     | Status code (`EXIT_SUCCESS`, `EXIT_ERROR`) |
| `bool`    | Not used                                   |

---

## 🔹 Notes

* This module is purely a data container
* No direct interaction with SFML occurs here
* Memory ownership is tracked through `nsf_game_t`
* Must be created before window initialization
* Should remain immutable after creation in most cases

---

## 🔹 Internal Files

| File                           | Role                           |
|--------------------------------|--------------------------------|
| `nsf_window_settings_struct.c` | Creation and destruction logic |

---

## 🔹 Related Submodules

* [`nsf_window` 🔗](window.md)
* [`nsf_game` 🔗](game.md)

---

## 🔹 CSFML Mapping (Optional)

| NSF                     | CSFML Equivalent                    |
|-------------------------|-------------------------------------|
| `nsf_window_settings_t` | `sfVideoMode` (partial abstraction) |

---

## 🔹 Implementation Notes (for contributors)

* Keep structure minimal and stable
* Do not add runtime logic here
* Ensure values remain consistent with SFML constraints
* Avoid mixing with rendering or event systems
* Follow strict separation of concerns

---

## 🔹 Extension Points

* Add fullscreen or scaling presets
* Support dynamic resolution profiles
* Extend with monitor configuration metadata
* Integrate display mode presets system

---
