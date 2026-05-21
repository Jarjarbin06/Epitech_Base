# 📦 `Games`
#### part of [NewCSFML](../../README.md)

Provides core systems for **application lifecycle, window management, and input handling** within the framework.

> Example:
> Acts as the central runtime layer coordinating window rendering, event processing, and global game state.

---

## 🔹 Header

```c
#include <newcsfml/games/games.h>
```

---

## 🔹 Overview

| Submodule         | Role                                               |
|-------------------|----------------------------------------------------|
| `event`           | Handles input abstraction and event utilities      |
| `keyboard`        | Handles keyboard input utilities                   |
| `game`            | Central runtime controller and system orchestrator |
| `window`          | Rendering, event polling, and element management   |
| `window_settings` | Window configuration container                     |

---

## 🔹 Purpose

This module defines the **core runtime layer** of the framework.

* Abstracts CSFML windowing and event systems
* Centralizes application lifecycle management
* Provides a structured way to manage rendering and input
* Ensures consistent ownership and resource tracking via `nsf_game_t`

It exists to **bridge low-level CSFML systems with high-level engine architecture**, enabling modular and scalable applications.

---

## 🔹 Architecture

### Internal Composition

```
games
├── event
├── keyboard
├── game
├── window
└── window_settings
```

### Flow

```
User → nsf_game → nsf_window → nsf_event → nsf_keyboard → CSFML
                     ↓
               Rendering / Audio / Input
```

---

## 🔹 Dependencies

| Module         | Usage                              |
|----------------|------------------------------------|
| `nsf_game`     | Core ownership and orchestration   |
| `nsf_systems`  | Utilities (vector, utils, etc.)    |
| `nsf_graphics` | Rendering elements (sprites, etc.) |
| `nsf_audio`    | Sound and music systems            |
| `CSFML`        | Windowing and input backend        |

---

## 🔹 Key Responsibilities

* Manage the **main application lifecycle**
* Handle **window creation, rendering, and destruction**
* Process **user input (keyboard, mouse, events)**
* Provide a **centralized runtime context (`nsf_game_t`)**
* Coordinate interactions between subsystems

**Must NOT:**

* Implement game logic
* Contain heavy rendering logic (delegated to graphics)
* Directly expose CSFML internals to users

---

## 🔹 Submodules

| Submodule                      | Description                          |
|--------------------------------|--------------------------------------|
| `nsf_event_manage.c`           | Event comparison and input utilities |
| `nsf_keyboard_manage.c`        | Keyboard input utilities             |
| `nsf_game_manage*.c`           | Core orchestration and lifecycle     |
| `nsf_game_draw.c`              | Frame rendering logic                |
| `nsf_window_manage*`           | Window logic and element registry    |
| `nsf_window_draw.c`            | Rendering pipeline                   |
| `nsf_window_settings_struct.c` | Settings creation/destruction        |

---

## 🔹 Public API Summary

### High-Level Functions

| Function             | Description                  |
|----------------------|------------------------------|
| `nsf_game_create()`  | Initialize game context      |
| `nsf_game_destroy()` | Cleanup all systems          |
| `nsf_game_update()`  | Update runtime state         |
| `nsf_game_display()` | Display rendered frame       |
| `nsf_game_draw()`    | Draw all registered elements |

---

### Subsystem APIs

| Subsystem         | Example Function               |
|-------------------|--------------------------------|
| `event`           | `nsf_event_cmp()`              |
| `keyboard`        | `nsf_keyboard_is_pressed()`    |
| `window`          | `nsf_window_create()`          |
| `window_settings` | `nsf_window_settings_create()` |
| `game`            | `nsf_game_get_window()`        |

---

## 🔹 Usage Example

```c
nsf_game_t *game = nsf.game.create();

while (nsf.game.isopen(game)) {
    nsf.game.update(game);
    nsf.game.draw(game);
    nsf.game.display(game);
}

nsf.game.destroy(game);
```

---

## 🔹 Data Flow

| Step | Action                                      |
|------|---------------------------------------------|
| 1    | Initialize `nsf_game`                       |
| 2    | Create and assign `nsf_window_settings`     |
| 3    | Create window and attach to game            |
| 4    | Enter main loop (`update → draw → display`) |
| 5    | Poll and process events via `nsf_event`     |
| 6    | Process keyboard input `nsf_keyboard`       |
| 7    | Cleanup all resources via `destroy()`       |

---

## 🔹 Design Constraints

* Strict separation between:

    * event handling
    * window management
    * game orchestration
* Must use `nsf_game_t` as the **single ownership root**
* No direct CSFML exposure outside implementation
* Must remain modular and extensible

---

## 🔹 Common Patterns

* Central loop: `update → draw → display`
* Event polling via window → processed by event module
* Resource registration through window/game
* Ownership hierarchy: `game → window → elements`

---

## 🔹 Known Limitations

* Single-window architecture (no multi-window support)
* Event system is minimal (no advanced input mapping)
* No built-in scene or state manager

---

## 🔹 Documentation Index

This section provides quick access to the audio module documentation.
Detailed behavior and API are described within each submodule.

### Submodules

* [Event](event.md) — Event managing
* [Keyboard](keyboard.md) — Keyboard managing
* [Mouse](mouse.md) — Mouse managing
* [Game](game.md) — Main ownership structure
* [Window](window.md) — Core rendering system
* [Window Settings](window_settings.md) — Rendering settings

---

## 🔹 Related Modules

* [Audios](../audios/overview.md)
* [Graphics](../graphics/overview.md)
* [Systems](../systems/overview.md)

---

## 🔹 Notes

* This module is the **foundation of runtime execution**
* Designed to stay minimal and focused on orchestration
* All high-level systems depend on it
* Encourages clean separation between engine and game logic

---

## 🔹 Internal Files

| File          | Role                        |
|---------------|-----------------------------|
| `*_struct.c`  | Data structures & lifecycle |
| `*_manage*.c` | Logic and transformations   |
| `*_draw.c`    | Rendering logic             |

---

## 🔹 Extension Guidelines

* Add new systems via `nsf_game_t` or composition
* Extend window capabilities without breaking API
* Keep event system stateless and lightweight
* Avoid coupling modules directly together
* Maintain strict API naming consistency

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
