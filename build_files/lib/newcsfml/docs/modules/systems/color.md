---
title: NewCSFML - Systems - NSF_Color
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

# 📦 Color Module (`nsf_color`)
#### part of [Systems](overview.md)

Provides a unified color type and a predefined global palette of commonly used colors for UI and rendering.

> Example:
> Offers a centralized set of SFML colors (black, white, red, etc.) for consistent usage across the engine.

---

## 🔹 Header

```c
#include <newcsfml/systems/color.h>
```

---

## 🔹 Structure

```c
typedef sfColor nsf_color_t;
```

### Description

| Field | Type      | Description                          |
|-------|-----------|--------------------------------------|
| —     | `sfColor` | Direct alias of SFML RGBA color type |

---

### Shortcut Structure

```c
typedef struct {
    const nsf_color_t black;
    const nsf_color_t white;
    const nsf_color_t red;
    const nsf_color_t green;
    const nsf_color_t blue;
    const nsf_color_t yellow;
    const nsf_color_t magenta;
    const nsf_color_t cyan;
    const nsf_color_t grey;
    const nsf_color_t transparent;
} nsf_colors_shortcut_t;
```

### Description

| Field         | Type          | Description           |
|---------------|---------------|-----------------------|
| `black`       | `nsf_color_t` | RGBA(0,0,0,255)       |
| `white`       | `nsf_color_t` | RGBA(255,255,255,255) |
| `red`         | `nsf_color_t` | RGBA(255,0,0,255)     |
| `green`       | `nsf_color_t` | RGBA(0,255,0,255)     |
| `blue`        | `nsf_color_t` | RGBA(0,0,255,255)     |
| `yellow`      | `nsf_color_t` | RGBA(255,255,0,255)   |
| `magenta`     | `nsf_color_t` | RGBA(255,0,255,255)   |
| `cyan`        | `nsf_color_t` | RGBA(0,255,255,255)   |
| `grey`        | `nsf_color_t` | RGBA(100,100,100,255) |
| `transparent` | `nsf_color_t` | RGBA(0,0,0,0)         |

---

## 🔹 Purpose

This module centralizes color usage across the entire framework.

* Provides a type alias over `sfColor`
* Exposes a global immutable palette (`nsf_color`)
* Ensures consistent UI and rendering colors
* Avoids manual RGBA duplication in code

It acts as a lightweight utility layer above SFML colors.

---

## 🔹 Dependencies

| Module  | Usage                     |
|---------|---------------------------|
| `SFML`  | Core color representation |
| `nsf_*` | UI, sprites, buttons, etc |

---

## 🔹 API

### Creation / Destruction

Not applicable (no dynamic allocation).

---

### Core Functions

Not applicable (static data only).

---

### Advanced / Optional

Not applicable.

---

## 🔹 Parameters Reference

Not applicable.

---

## 🔹 Return Values

Not applicable.

---

## 🔹 Notes

* `nsf_color_t` is a direct alias of `sfColor`
* `nsf_color` is a global constant palette
* No memory allocation is involved
* Values are read-only and safe to share across modules

---

## 🔹 Internal Files

| File                 | Role                     |
|----------------------|--------------------------|
| `nsf_color_extern.c` | Global color definitions |

---

## 🔹 Related Submodules

* [`nsf_sprite` 🔗](../graphics/sprite.md)
* [`nsf_button` 🔗](../graphics/button.md)
* [`nsf_window` 🔗](../games/window.md)
* [`nsf_background` 🔗](../graphics/background.md)

---

## 🔹 CSFML Mapping (Optional)

| NSF               | CSFML     |
|-------------------|-----------|
| `nsf_color_t`     | `sfColor` |
| `nsf_color.black` | `sfBlack` |
| `nsf_color.white` | `sfWhite` |

---

## 🔹 Implementation Notes (for contributors)

* Do not modify the global `nsf_color` at runtime
* Keep palette values consistent with SFML conventions
* Avoid introducing dynamic color allocation
* Extend palette only if strictly necessary

---

## 🔹 Extension Points

* Add themed palettes (dark mode / UI themes)
* Introduce color interpolation utilities
* Add alpha manipulation helpers
* Expand predefined color set if needed

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
