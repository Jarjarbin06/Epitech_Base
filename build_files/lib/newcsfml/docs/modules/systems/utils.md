---
title: NewCSFML - Systems - NSF_Utils
---
<link rel="icon" type="image/x-icon" href="https://raw.githubusercontent.com/Jarjarbin06/Epitech_Base/refs/heads/main/build_files/lib/newcsfml/resouces/NCSFML_logo_transparent.png">

# 📦 Utils Module (`nsf_utils`)
#### part of [Systems](overview.md)

Utility helper module for memory management, optimisation hints, logic gates, and internal tooling.

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
| `stdio`     | debug printing                 |
| `nsf_game`  | Allocation tracking (optional) |
| `nsf_other` | Underlying low-level utilities |

---

## 🔹 API

### Memory Functions

| Function                    | Description                              |
|-----------------------------|------------------------------------------|
| `nsf_utils_malloc(...)`     | Allocate memory and update allocations   |
| `nsf_utils_free(...)`       | Free memory and update allocations       |
| `nsf_utils_free_batch(...)` | Batch free multiple resources            |
| `nsf_utils_free_array(...)` | Free an array of any kind (simple array) |

---

### Logic Functions

| Function                          | Description           |
|-----------------------------------|-----------------------|
| `nsf_utils_logic_not(...)`        | NOT logic gate        |
| `nsf_utils_logic_and(...)`        | AND logic gate        |
| `nsf_utils_logic_and_batch(...)`  | Batch AND logic gate  |
| `nsf_utils_logic_nand(...)`       | NAND logic gate       |
| `nsf_utils_logic_nand_batch(...)` | Batch NAND logic gate |
| `nsf_utils_logic_or(...)`         | OR logic gate         |
| `nsf_utils_logic_or_batch(...)`   | Batch OR logic gate   |
| `nsf_utils_logic_nor(...)`        | NOR logic gate        |
| `nsf_utils_logic_nor_batch(...)`  | Batch NOR logic gate  |
| `nsf_utils_logic_xor(...)`        | XOR logic gate        |
| `nsf_utils_logic_xor_batch(...)`  | Batch XOR logic gate  |
| `nsf_utils_logic_nxor(...)`       | NXOR logic gate       |
| `nsf_utils_logic_nxor_batch(...)` | Batch NXOR logic gate |

---

### Environment Checker

| Function                           | Description                            |
|------------------------------------|----------------------------------------|
| `nsf_utils_env_check_display(...)` | Check for DISPLAY environment variable |

---

### Debug Functions

| Function                   | Description                           |
|----------------------------|---------------------------------------|
| `nsf_utils_log(...)`       | Show pretty printded logs             |
| `nsf_utils_log_null(...)`  | Log and return a NULL pointer         |
| `nsf_utils_log_false(...)` | Log and return a false boolean        |
| `nsf_utils_log_error(...)` | Log and return a E_ERROR (84) integer |
| `nsf_utils_log_zero(...)`  | Log and return a 0 integer            |

---

### Advanced / Optional

| Function           | Description                             |
|--------------------|-----------------------------------------|
| `NSF_LIKELY(x)`    | Branch prediction hint (expected true)  |
| `NSF_UNLIKELY(x)`  | Branch prediction hint (expected false) |
| `NSF_FALSE`        | Boolean (false)(0)                      |
| `NSF_TRUE`         | Boolean (true)(1)                       |
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

| File                                | Role                                |
|-------------------------------------|-------------------------------------|
| `nsf_utils_manage_env.c`            | Environement checker                |
| `nsf_utils_manage_logic_advanced.c` | Advanced logic gates (XOR, NXOR)    |
| `nsf_utils_manage_logic_medium.c`   | Medium logic gates (OR, NOR)        |
| `nsf_utils_manage_logic_simple.c`   | Simple logic gates (NOT, AND, NAND) |
| `nsf_utils_manage_memory.c`         | Memory allocation / free logic      |

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
