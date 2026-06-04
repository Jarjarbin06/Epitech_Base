<link rel="icon" type="image/x-icon" href="https://raw.githubusercontent.com/Jarjarbin06/Epitech_Base/refs/heads/main/docs/EpitechBaseWebIcon.png">

# 📦 NewCSFML (NCSFML)

> Lightweight C wrapper over CSFML providing safer memory management and simplified game development APIs.

---

## 🔹 Short Description

**NCSFML is a modular C wrapper over CSFML that simplifies game development by adding automatic memory management, structured architecture, and high-level APIs for graphics, audio, input, and systems.**

---

## 🔹 Authors

* Nathan (Jarjarbin06)
* EPITECH Project

---

## 🔹 Licence

GPL v3

---

## 🔹 Target Audience

This library is designed for:

* C developers using CSFML
* Students building graphical projects
* Game developers needing a lightweight framework
* EPITECH-style project developers

---

## 🔹 Platform Support

* Linux only (CSFML dependency requirement)
* Tested with:

    * CSFML 2.6.1 (Fedora package: `CSFML.x86_64`, `CSFML-devel.x86_64`)

---

## 🔹 Purpose

NCSFML is designed to remove the repetitive and unsafe parts of CSFML usage by providing:

* Automatic memory tracking via `nsf_game_t`
* Structured modular architecture
* Simplified object lifecycle (create / use / destroy)
* Clean separation of systems (graphics, audio, game, systems)
* Consistent API naming across modules

It is **not a replacement of CSFML**, but a structured abstraction layer on top of it.

---

## 🔹 Key Features

* Memory-safe architecture (tracked allocations)
* Modular design (game / graphics / audio / systems)
* Simplified CSFML usage
* Built-in game loop structure
* Clean event handling system
* High-level drawable and interactive entities
* Unified audio system (music + sound separation)

---

## 🔹 Architecture Overview

```
                ┌──────────────────────┐
                │     nsf_game_t       │
                │  (core runtime)      │
                └─────────┬────────────┘
                          │
     ┌────────────────────┼────────────────────┐
     │                    │                    │
┌──────────┐      ┌────────────┐      ┌────────────┐
│ Graphics │      │   Audio    │      │  Systems   │
│ sprites  │      │ music/sound│      │ vector/time│
└──────────┘      └────────────┘      └────────────┘
     │
┌──────────┐
│  Window  │
│  Events  │
└──────────┘
```

---

## 🔹 Modules Overview

### 🎮 Game Layer

Handles runtime execution, window lifecycle, and event processing.

* `nsf_game`
* `nsf_window`
* `nsf_event`
* `nsf_window_settings`

---

### 🎨 Graphics Layer

Handles all rendering and UI elements.

* `texture`
* `sprite`
* `button`
* `background`

---

### 🔊 Audio Layer

Provides structured audio management.

* `music`
* `sound`

---

### ⚙️ Systems Layer

Low-level utilities used everywhere.

* `vector`
* `clock`
* `color`
* `utils`
* `other`

---

## 🔹 Build System

### Makefile

The project provides a standard Makefile:

```bash
make
make clean
make fclean
make re
```

Produces:

```
libnewcsfml.a
```

---

### Recommended (CMake)

CMake is recommended for IDE support and auto-completion.

---

## 🔹 Installation Requirements

* CSFML 2.6.x
* CSFML development headers
* Linux environment

---

## 🔹 Quickstart Example

Minimal working window example:

```c
#include <newcsfml/games.h>
#include <newcsfml/systems/color.h>

static nsf_window_t *create_window(nsf_game_t *game)
{
    return nsf_window_create(
        (nsf_window_settings_t[]){{800, 600, 32, 30}},
        "NCSFML Window",
        NSF_WDW_DEFAULT_STYLE,
        game
    );
}

int main(void)
{
    nsf_game_t *game = nsf_game_create();
    nsf_event_t event;

    nsf_game_set_window(game, create_window(game));

    while (nsf_game_isopen(game)) {
        while (nsf_window_get_event(nsf_game_get_window(game), &event)) {
            if (nsf_event_cmp(&event, NSF_EVT_CLOSED))
                nsf_window_close(nsf_game_get_window(game));
        }

        nsf_window_fill(nsf_game_get_window(game), &nsf_color.white);
        nsf_game_draw(game);
        nsf_game_display(game);
    }

    nsf_game_destroy(&game);
    return 0;
}
```

---

## 🔹 Memory Safety Model

All allocations are tracked via:

```
nsf_game_t
```

This ensures:

* Centralized memory ownership
* Automatic cleanup on `nsf_game_destroy`
* Reduced memory leaks risk
* Predictable lifecycle management

---

## 🔹 Design Philosophy

* No raw CSFML exposure in user code
* Explicit creation / destruction model
* Modular independence between systems
* Minimal overhead abstraction
* Predictable runtime behavior

---

## 🔹 Current State

⚠️ The project is **in active development**

Status:

* Core systems implemented
* Graphics module functional
* Audio module functional
* Event system functional
* Future additions planned:

    * Animation system
    * Extended UI system
    * Scene management
    * Potential render optimization layer

---

## 🔹 File Structure

```
includes/   → Public API headers
sources/    → Implementation
docs/       → Full module documentation
Makefile    → Build system
```

---

## 🔹 Documentation Index

This section provides quick access to the main documentation files.
Detailed module-specific documentation is available within each module’s overview.

### Core Documentation

* [File Structure](file_structure.md) — Project organization details
* [Naming Conventions](naming_conventions.md) — Standardized naming rules
* [Quick Reference](quick_reference.md) — Fast access to commonly used elements
* [Best Practices](best_practices.md) — Recommended coding and usage guidelines

---

### Modules Overview

Each module contains its own detailed documentation and subcomponents.

* [Graphics Module](modules/graphics/overview.md)
* [Audio Module](modules/audios/overview.md)
* [Game Module](modules/games/overview.md)
* [Systems Module](modules/systems/overview.md)

---

## 🔹 Notes

* Designed for educational and structured game development
* Focus on clarity over performance complexity
* Strict separation of responsibilities between modules
* Built to scale progressively (not monolithic engine design)

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
