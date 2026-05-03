# 📦 `Systems`

Core utility and foundational modules providing low-level services such as timing, memory management, math operations, and shared data structures.

> Provides essential building blocks used across all higher-level modules (graphics, window, game, etc.).

---

## 🔹 Header

```c
#include <newcsfml/systems/<module>.h>
```

---

## 🔹 Overview

| Submodule | Role                                      |
|-----------|-------------------------------------------|
| `clock`   | Handles time, delta computation           |
| `color`   | Provides color types and global palette   |
| `vector`  | Offers math and geometric operations      |
| `utils`   | Memory helpers and optimization macros    |
| `other`   | Internal core utilities (low-level tools) |

---

## 🔹 Purpose

The systems module provides the **foundation layer** of the framework.

* Abstracts low-level SFML and C standard features (time, memory, math)
* Provides reusable utilities shared across all modules
* Ensures consistency, safety, and performance in core operations
* Centralizes commonly used data types (vectors, colors, time)

It exists to **avoid duplication**, **standardize behavior**, and **simplify higher-level modules**.

---

## 🔹 Architecture

### Internal Composition

```
systems
├── clock
├── color
├── vector
├── utils
└── other
```

### Flow

```
User / Engine
      ↓
High-Level Modules (graphics, window, game)
      ↓
Systems (vector, clock, utils, etc.)
      ↓
CSFML / Standard C
```

---

## 🔹 Dependencies

| Module      | Usage                           |
|-------------|---------------------------------|
| `nsf_game`  | Allocation tracking (optional)  |
| `nsf_utils` | Shared utilities and macros     |
| `CSFML`     | Backend (clock, color, vectors) |
| `libc`      | Memory and math operations      |

---

## 🔹 Key Responsibilities

* Provide **time management** (`clock`)
* Provide **math utilities** (`vector`)
* Provide **color standardization** (`color`)
* Provide **memory helpers** (`utils`, `other`)
* Ensure **low-level consistency and safety**

Must NOT:

* Handle rendering or UI logic
* Depend on high-level modules (graphics, game logic)
* Introduce heavy abstractions or complex state

---

## 🔹 Submodules

| Submodule | Description                                   |
|-----------|-----------------------------------------------|
| `clock`   | Time tracking and delta computation           |
| `color`   | Global color palette and type alias           |
| `vector`  | 2D math operations and conversions            |
| `utils`   | Memory helpers and performance macros         |
| `other`   | Internal core utilities (allocation, strings) |

---

## 🔹 Public API Summary

### High-Level Functions

| Function        | Description                |
|-----------------|----------------------------|
| *(none global)* | Each submodule is isolated |

---

### Subsystem APIs

| Subsystem | Example Function     |
|-----------|----------------------|
| `clock`   | `nsf_clock_update()` |
| `vector`  | `nsf_vector_add()`   |
| `utils`   | `nsf_malloc_any()`   |
| `color`   | `nsf_color.white`    |

---

## 🔹 Usage Example

```c
nsf_clock_t *clock = nsf.clock.create("main", game);

nsf.clock.update(clock);
float dt = nsf.clock.get_delta(clock);
```

---

## 🔹 Data Flow

| Step | Action                             |
|------|------------------------------------|
| 1    | Module-specific initialization     |
| 2    | Used by higher-level modules       |
| 3    | Runtime operations (math, timing…) |
| 4    | Data returned to caller            |
| 5    | Cleanup (if applicable)            |

---

## 🔹 Design Constraints

* Must remain **lightweight and fast**
* Must avoid unnecessary allocations
* Must be usable independently
* Must not expose raw CSFML unnecessarily
* `other` module must remain **internal-only**

---

## 🔹 Common Patterns

* Stateless utilities (`vector`, `color`)
* Manual update loop (`clock`)
* Safe allocation wrappers (`utils`)
* Output-parameter design for performance (`vector`)

---

## 🔹 Known Limitations

* No 3D math support (vector limited to 2D)
* No advanced timing features (pause, scaling not implemented)
* Partial integration of `utils` across all modules

---

## 🔹 Related Modules

* `nsf_graphics`
* `nsf_window`
* `nsf_game`

---

## 🔹 Notes

* This is the **lowest abstraction layer** in the framework
* All higher modules depend on it
* Designed to remain stable and rarely modified
* Critical for performance-sensitive code

---

## 🔹 Internal Files

| File                   | Role              |
|------------------------|-------------------|
| `nsf_clock_*.c`        | Time management   |
| `nsf_vector_manage*.c` | Math operations   |
| `nsf_color_extern.c`   | Color definitions |
| `nsf_alloc_any.c`      | Memory helpers    |
| `str_*.c`              | String utilities  |

---

## 🔹 Extension Guidelines

* Keep modules **independent**
* Avoid adding high-level logic
* Prefer **pure functions** when possible
* Maintain performance-first design
* Extend only when broadly reusable

---
