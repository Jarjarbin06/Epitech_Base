# 📦 Utils Module (`nsf_utils`)
#### part of [Systems](overview.md)

Utility helper module for memory management, optimization hints, and internal tooling.

> Provides allocation helpers, branch prediction macros, and utility abstractions for safe and tracked memory usage.

---

## 🔹 Header

```c
#include <newcsfml/systems/utils.h>
```

---

## 🔹 Structure

```c
typedef struct {
    const bool condition;
    void *ptr;
    void *free_func;
} nsf_free_t;
```

### Description

| Field       | Type     | Description                          |
|-------------|----------|--------------------------------------|
| `condition` | `bool`   | Whether the resource should be freed |
| `ptr`       | `void *` | Pointer to the resource              |
| `free_func` | `void *` | Function used to free the resource   |

---

## 🔹 Purpose

This module provides core utility features used across the NCSFML ecosystem, mainly focused on memory handling and performance hints.

* Main responsibility: provide safe and optional allocation tracking utilities
* Abstracts: low-level memory operations (`malloc`, `free`) with optional `nsf_game_t` tracking
* Architecture role: foundational system module used by higher-level modules and optionally by users

---

## 🔹 Dependencies

| Module      | Usage                          |
|-------------|--------------------------------|
| `nsf_game`  | Allocation tracking (optional) |
| `nsf_other` | Underlying low-level utilities |

---

## 🔹 API

### Creation / Destruction

| Function              | Description                   |
|-----------------------|-------------------------------|
| `nsf_malloc_any(...)` | Allocate memory with tracking |
| `nsf_free_any(...)`   | Free memory with tracking     |

---

### Core Functions

| Function              | Description                            |
|-----------------------|----------------------------------------|
| `nsf_malloc_any(...)` | Allocate memory and update allocations |
| `nsf_free_any(...)`   | Free memory and update allocations     |
| `nsf_auto_free(...)`  | Batch free multiple resources          |

---

### Advanced / Optional

| Function           | Description                             |
|--------------------|-----------------------------------------|
| `NSF_LIKELY(x)`    | Branch prediction hint (expected true)  |
| `NSF_UNLIKELY(x)`  | Branch prediction hint (expected false) |
| `newcsfml_exist()` | Dummy function for linkage/validation   |

---

## 🔹 Parameters Reference

| Name        | Type           | Description                     |
|-------------|----------------|---------------------------------|
| `size`      | `nsf_uint_t`   | Allocation size                 |
| `ptr`       | `void *`       | Pointer to free                 |
| `len`       | `nsf_uint_t`   | Number of elements in free list |
| `free_list` | `nsf_free_t *` | List of resources to free       |
| `game`      | `nsf_game_t *` | Allocation tracking context     |

---

## 🔹 Return Values

| Type      | Meaning                          |
|-----------|----------------------------------|
| `pointer` | Allocated memory                 |
| `NULL`    | Allocation failure               |
| `int`     | Number of freed elements         |
| `void *`  | Always returns `NULL` after free |

---

## 🔹 Notes

* Designed for optional use by NCSFML users
* Not yet fully integrated internally across all modules
* Wraps standard `malloc` / `free` with tracking capability
* Works alongside `nsf_game_t->allocations`
* Branch prediction macros improve performance in critical paths

---

## 🔹 Internal Files

| File              | Role                           |
|-------------------|--------------------------------|
| `nsf_alloc_any.c` | Memory allocation / free logic |

---

## 🔹 Related Submodules

* [`nsf_game` 🔗](../games/game.md)
* [`nsf_other` 🔗](other.md)

---

## 🔹 CSFML Mapping (Optional)

| NSF      | CSFML    |
|----------|----------|
| *(none)* | *(none)* |

---

## 🔹 Implementation Notes (for contributors)

* Keep this module lightweight and generic
* Do not introduce high-level logic here
* Ensure compatibility with `nsf_game_t` tracking
* Maintain safe pointer handling
* Follow Epitech C coding style strictly

---

## 🔹 Extension Points

* Add debug allocation tracking (leak detection)
* Extend `nsf_auto_free` with safer typing
* Integrate deeper into internal modules
* Add logging or profiling hooks for allocations

---
