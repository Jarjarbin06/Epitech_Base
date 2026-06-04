---
title: NewCSFML - Graphics - NSF_View
---
<link rel="icon" type="image/x-icon" href="https://raw.githubusercontent.com/Jarjarbin06/Epitech_Base/refs/heads/main/build_files/lib/newcsfml/resouces/NCSFML_logo_transparent.png">

# 📦 View Module (`nsf_view`)

#### part of [Graphics](overview.md)

The view module provides a minimal abstraction over camera handling using CSFML views. It allows control over what portion of the world is visible in the render window.

> Example:
> Handles camera positioning and viewport size for rendering scenes.

---

## 🔹 Header

```c
#include <newcsfml/graphics/view.h>
```

---

## 🔹 Structure

```c
typedef struct nsf_view_s {
    sfView *view;
    nsf_fvector_t center;
    nsf_fvector_t size;
    float rotation;
} nsf_view_t;
```

### Description

| Field      | Type            | Description                        |
|------------|-----------------|------------------------------------|
| `view`     | `sfView *`      | Underlying CSFML view              |
| `center`   | `nsf_fvector_t` | Center position of the view        |
| `size`     | `nsf_fvector_t` | Visible area size                  |
| `rotation` | `float`         | Rotation angle (reserved / unused) |

---

## 🔹 Purpose

The view module abstracts the CSFML camera system, allowing control over how the scene is viewed.

* Main responsibility: define the visible area of the scene
* Abstracts CSFML `sfView`
* Provides a foundation for camera systems (tracking, zoom, scrolling)

---

## 🔹 Dependencies

| Module       | Usage               |
|--------------|---------------------|
| `nsf_game`   | Memory tracking     |
| `nsf_vector` | Vector manipulation |

---

## 🔹 API

### Creation / Destruction

| Function                | Description           |
|-------------------------|-----------------------|
| `nsf_view_create(...)`  | Create a new view     |
| `nsf_view_destroy(...)` | Destroy and free view |

---

### Core Functions

| Function                   | Description           |
|----------------------------|-----------------------|
| `nsf_view_set_center(...)` | Set view center       |
| `nsf_view_set_size(...)`   | Set visible area size |

---

### Advanced / Optional

| Function     | Description |
|--------------|-------------|
| *(none yet)* |             |

---

## 🔹 Parameters Reference

| Name     | Type              | Description        |
|----------|-------------------|--------------------|
| `view`   | `nsf_view_t *`    | View instance      |
| `game`   | `nsf_game_t *`    | Allocation context |
| `center` | `nsf_fvector_t *` | Center position    |
| `size`   | `nsf_fvector_t *` | View dimensions    |

---

## 🔹 Return Values

| Type      | Meaning             |
|-----------|---------------------|
| `pointer` | Valid view instance |
| `NULL`    | Allocation failure  |
| `int`     | Status code         |

---

## 🔹 Notes

* Minimal implementation (early stage module)
* Rotation field exists but is not yet exposed in API
* Direct CSFML calls are wrapped but not fully abstracted yet
* Designed to evolve into a full camera system
* Must be manually applied to a window (not automated yet)

---

## 🔹 Internal Files

| File                    | Role                    |
|-------------------------|-------------------------|
| `nsf_view_struct.c`     | Creation / destruction  |
| `nsf_view_manage_set.c` | Setters (center / size) |
| `nsf_view_manage_get.c` | Getters                 |

---

## 🔹 Related Modules

* [`nsf_window` 🔗](../games/window.md)
* [`nsf_sprite` 🔗](sprite.md)
* [`nsf_vector` 🔗](../systems/vector.md)

---

## 🔹 CSFML Mapping (Optional)

| NSF              | CSFML         |
|------------------|---------------|
| `nsf_view_t`     | `sfView`      |
| `nsf_view_set_*` | `sfView_set*` |

---

## 🔹 Implementation Notes (for contributors)

* Keep abstraction thin but consistent
* Avoid exposing raw `sfView` outside module unless necessary
* Maintain synchronization between struct fields and CSFML object
* Prepare for future features (zoom, rotation, viewport, tracking)

---

## 🔹 Extension Points

* Add rotation support (`set_rotation`)
* Add zoom functionality
* Add viewport control
* Integrate with window rendering pipeline
* Support camera follow systems (entity tracking)

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

Other:
Makefile   v1.0.6
</pre>

Author: Nathan (Jarjarbin06) • EPITECH<br>
Licence: GPL v3<br>
Repository: <a href="https://github.com/Jarjarbin06/Epitech_Base">Epitech Base</a>
</div>

---
