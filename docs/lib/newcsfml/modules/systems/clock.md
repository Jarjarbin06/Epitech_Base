---
title: Epitech Base -- Library -- NewCSFML - Systems - NSF_Clock
---
<link rel="icon" type="image/x-icon" href="https://raw.githubusercontent.com/Jarjarbin06/Epitech_Base/refs/heads/main/build_files/lib/newcsfml/resouces/NCSFML_logo_transparent.png">

# 📦 Clock Module (`nsf_clock`)
#### part of [Systems](overview.md)

Time management module built on top of CSFML clocks.

> Provides delta time computation, elapsed time access, and frame timing utilities.

---

## 🔹 Header

```c
#include <newcsfml/systems/clock.h>
```

---

## 🔹 Structure

```c
typedef struct nsf_clock_s {
    sfClock *clock;
    float last;
    float delta;
    float accumulator;
    nsf_cstr_t name;
} nsf_clock_t;
```

### Description

| Field         | Type         | Description                                 |
|---------------|--------------|---------------------------------------------|
| `clock`       | `sfClock *`  | Underlying CSFML clock instance             |
| `last`        | `float`      | Last recorded time (seconds)                |
| `delta`       | `float`      | Delta time between updates (seconds)        |
| `accumulator` | `float`      | Sum of all delta times before a clock reset |
| `name`        | `nsf_cstr_t` | Identifier for debugging / tracking         |

---

## 🔹 Purpose

Provides a high-level abstraction over CSFML timing utilities.

* Main responsibility
  Handle time measurement and delta computation for frame-based logic

* What it abstracts
  Wraps `sfClock` and `sfTime` into a simpler interface

* Where it fits
  Core system module used by update loops, animations, physics, and game timing

---

## 🔹 Dependencies

| Module      | Usage                           |
|-------------|---------------------------------|
| `nsf_game`  | Allocation tracking             |
| `nsf_utils` | Safety macros (LIKELY/UNLIKELY) |
| `nsf_other` | Internal allocation utilities   |

---

## 🔹 API

### Creation / Destruction

| Function                 | Description                   |
|--------------------------|-------------------------------|
| `nsf_clock_create(...)`  | Create and initialize a clock |
| `nsf_clock_destroy(...)` | Destroy and free the clock    |

---

### Core Functions

| Function                      | Description                               |
|-------------------------------|-------------------------------------------|
| `nsf_clock_restart(...)`      | Restart clock and return elapsed time     |
| `nsf_clock_get_elapsed(...)`  | Get total elapsed time (seconds)          |
| `nsf_clock_get_delta(...)`    | Get last computed delta time              |
| `nsf_clock_update(...)`       | Update internal delta time                |
| `nsf_clock_reset(...)`        | Reset the accumulator                     |
| `nsf_clock_is_new_loop(...)`  | Check if the clock reached the threashold |
| `nsf_clock_set_new_loop(...)` | Set the new loop based on the threashold  |

---

### Advanced / Optional

| Function     | Description                   |
|--------------|-------------------------------|
| *(none yet)* | Module kept minimal by design |

---

## 🔹 Parameters Reference

| Name    | Type            | Description                 |
|---------|-----------------|-----------------------------|
| `name`  | `const char *`  | Clock identifier            |
| `game`  | `nsf_game_t *`  | Allocation tracking context |
| `clock` | `nsf_clock_t *` | Target clock                |
| `...`   | `...`           | ...                         |

---

## 🔹 Return Values

| Type      | Meaning                 |
|-----------|-------------------------|
| `pointer` | Valid clock instance    |
| `NULL`    | Allocation failure      |
| `int`     | `E_SUCCESS` / `E_ERROR` |
| `float`   | Time value in seconds   |

---

## 🔹 Notes

* Uses `nsf_game_t` for allocation tracking (`+3 / -3`)
* Internally relies on `malloc_any` / `free_any` (core-only usage)
* Delta time must be updated manually via `nsf_clock_update`
* Safe guards via `NSF_UNLIKELY` / `NSF_LIKELY`

---

## 🔹 Internal Files

| File                         | Role                      |
|------------------------------|---------------------------|
| `nsf_clock_struct.c`         | Creation / destruction    |
| `nsf_clock_manage_runtime.c` | Timing logic / operations |
| `nsf_clock_manage_update.c`  | Updater                   |
| `nsf_clock_manage_get.c`     | Getter                    |

---

## 🔹 Related Submodules

* [`nsf_game` 🔗](../games/game.md)
* [`nsf_utils` 🔗](utils.md)
* [`nsf_vector` 🔗](vector.md)

---

## 🔹 CSFML Mapping (Optional)

| NSF                     | CSFML                    |
|-------------------------|--------------------------|
| `nsf_clock_t`           | `sfClock`                |
| `nsf_clock_restart`     | `sfClock_restart`        |
| `nsf_clock_get_elapsed` | `sfClock_getElapsedTime` |

---

## 🔹 Implementation Notes (for contributors)

* Always validate pointers (`NSF_UNLIKELY`)
* Keep delta computation consistent (`update` required each frame)
* Do not expose raw `sfClock` outside the module
* Respect separation between struct and manage files

---

## 🔹 Extension Points

* Add pause/resume functionality
* Add time scaling (slow motion, speed-up)
* Add global clock registry (linked with `nsf_game`)
* Provide fixed timestep utilities for physics systems

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
