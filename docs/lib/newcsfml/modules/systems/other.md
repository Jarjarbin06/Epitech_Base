---
title: Epitech Base -- Library -- NewCSFML - Systems - Other/Core Utilities
---
<link rel="icon" type="image/x-icon" href="https://raw.githubusercontent.com/Jarjarbin06/Epitech_Base/refs/heads/main/build_files/lib/newcsfml/resouces/NCSFML_logo_transparent.png">

# 📦 Other Module (Core Utilities)
#### part of [Systems](overview.md)

Low-level internal utility module providing memory management and string helpers for the NCSFML core.

> Example:
> Provides safe allocation, deallocation, and basic string manipulation used internally by all modules.

---

## 🔹 Header

```c
#include <newcsfml/systems/other.h>
```

---

## 🔹 Structure

```c
typedef struct {
    bool condition;
    void *ptr;
    void_func_t free_func;
} free_t;
```

### Description

| Field       | Type          | Description                          |
|-------------|---------------|--------------------------------------|
| `condition` | `bool`        | Whether the resource should be freed |
| `ptr`       | `void *`      | Pointer to the resource              |
| `free_func` | `void_func_t` | Function used to free the resource   |

---

### Additional Types

| Type          | Definition          | Description                   |
|---------------|---------------------|-------------------------------|
| `void_func_t` | `void *(*)(void *)` | Generic free function pointer |
| `str_t`       | `char *`            | Mutable string                |
| `cstr_t`      | `const char *`      | Immutable string              |
| `cc_t`        | `const char`        | Immutable character           |

---

## 🔹 Purpose

This module provides foundational utilities required by the internal engine.

* Memory allocation wrappers (`malloc_any`, `free_any`)
* Bulk resource cleanup (`auto_free`, `free_array`)
* Basic string utilities (`str_dup`, `str_len`, `str_cmp`)

It is strictly part of the **core system layer** and is not intended for public use.

---

## 🔹 Dependencies

| Module   | Usage                             |
|----------|-----------------------------------|
| `stdlib` | Memory allocation (`malloc/free`) |
| `nsf_*`  | Used internally by all modules    |

---

## 🔹 API

### Creation / Destruction

| Function           | Description                   |
|--------------------|-------------------------------|
| `malloc_any(size)` | Allocate memory safely        |
| `free_any(ptr)`    | Free memory and return `NULL` |

---

### Core Functions

| Function                    | Description                |
|-----------------------------|----------------------------|
| `auto_free(len, free_list)` | Batch free with conditions |
| `free_array(array)`         | Free NULL-terminated array |
| `str_dup(src)`              | Duplicate string           |
| `str_len(string)`           | Compute string length      |
| `str_cmp(str1, str2)`       | Compare two strings        |

---

### Advanced / Optional

| Function         | Description                |
|------------------|----------------------------|
| `auto_free(...)` | Flexible cleanup mechanism |

---

## 🔹 Parameters Reference

| Name        | Type           | Description                     |
|-------------|----------------|---------------------------------|
| `size`      | `unsigned`     | Allocation size                 |
| `ptr`       | `void *`       | Pointer to free                 |
| `len`       | `unsigned`     | Number of elements in free list |
| `free_list` | `free_t[]`     | List of resources to free       |
| `src`       | `const char *` | Source string                   |
| `array`     | `void **`      | NULL-terminated array           |

---

## 🔹 Return Values

| Type      | Meaning                             |
|-----------|-------------------------------------|
| `pointer` | Allocated memory                    |
| `NULL`    | Allocation failure or freed pointer |
| `int`     | Status / comparison result          |
| `bool`    | Not used directly                   |

---

## 🔹 Notes

* **Internal use only** — not part of the public API
* Must not be used outside NCSFML core modules
* Ensures consistent memory handling across the engine
* Simplifies error handling and cleanup patterns

---

## 🔹 Internal Files

| File           | Role                        |
|----------------|-----------------------------|
| `alloc_any.c`  | Memory allocation utilities |
| `str_strdup.c` | String duplication          |
| `str_strlen.c` | String length computation   |
| `str_strcmp.c` | String comparison           |

---

## 🔹 Related Submodules

* [`nsf_game` 🔗](../games/game.md)
* [`nsf_window` 🔗](../games/window.md)
* [`nsf_sprite` 🔗](../graphics/sprite.md)
* [`nsf_texture` 🔗](../graphics/texture.md)

---

## 🔹 CSFML Mapping (Optional)

| NSF           | Standard C   |
|---------------|--------------|
| `malloc_any`  | `malloc`     |
| `free_any`    | `free`       |
| `nsf_* str_*` | `<string.h>` |

---

## 🔹 Implementation Notes (for contributors)

* Never expose this module to external users
* Keep functions minimal and generic
* Avoid adding high-level logic here
* Ensure all allocations are paired with safe deallocation
* Follow Epitech C coding style strictly

---

## 🔹 Extension Points

* Add debug allocation tracking
* Add memory leak detection hooks
* Extend string utilities if strictly necessary
* Introduce safer abstractions (optional, without overhead)

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
