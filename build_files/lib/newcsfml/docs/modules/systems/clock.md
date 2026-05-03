# 📦 `nsf_clock`

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
typedef struct {
    sfClock *clock;
    float last;
    float delta;
    nsf_cstr_t name;
} nsf_clock_t;
```

### Description

| Field   | Type         | Description                          |
|---------|--------------|--------------------------------------|
| `clock` | `sfClock *`  | Underlying CSFML clock instance      |
| `last`  | `float`      | Last recorded time (seconds)         |
| `delta` | `float`      | Delta time between updates (seconds) |
| `name`  | `nsf_cstr_t` | Identifier for debugging / tracking  |

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

| Function                     | Description                           |
|------------------------------|---------------------------------------|
| `nsf_clock_restart(...)`     | Restart clock and return elapsed time |
| `nsf_clock_get_elapsed(...)` | Get total elapsed time (seconds)      |
| `nsf_clock_get_delta(...)`   | Get last computed delta time          |
| `nsf_clock_update(...)`      | Update internal delta time            |

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

| Type      | Meaning                       |
|-----------|-------------------------------|
| `pointer` | Valid clock instance          |
| `NULL`    | Allocation failure            |
| `int`     | `EXIT_SUCCESS` / `EXIT_ERROR` |
| `float`   | Time value in seconds         |

---

## 🔹 Notes

* Uses `nsf_game_t` for allocation tracking (`+3 / -3`)
* Internally relies on `malloc_any` / `free_any` (core-only usage)
* Delta time must be updated manually via `nsf_clock_update`
* Safe guards via `NSF_UNLIKELY` / `NSF_LIKELY`

---

## 🔹 Internal Files

| File                 | Role                      |
|----------------------|---------------------------|
| `nsf_clock_struct.c` | Creation / destruction    |
| `nsf_clock_manage.c` | Timing logic / operations |

---

## 🔹 Related Modules

* `nsf_game`
* `nsf_utils`
* `nsf_vector` (commonly used with delta time)

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
