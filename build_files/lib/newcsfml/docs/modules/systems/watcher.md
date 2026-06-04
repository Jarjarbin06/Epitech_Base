---
title: NewCSFML - Systems - NSF_Watcher
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

# 📦 Watcher Module (`nsf_watcher`)
#### part of [Systems](overview.md)

Watcher system, to link other objects to a variable.

> Provides object that watches a pointer, retrieve its information and links to an object (text for example).

---

## 🔹 Header

```c
#include <newcsfml/systems/watcher.h>
```

---

## 🔹 Structure

```c
typedef struct nsf_watcher_s {
    void *ptr;
    nsf_watcher_type_t type;
} nsf_watcher_t;
```

### Description

| Field  | Type                 | Description                               |
|--------|----------------------|-------------------------------------------|
| `ptr`  | `void *`             | Pointer to watch                          |
| `type` | `nsf_watcher_type_t` | Pointer type (float, int, char or string) |

---

## 🔹 Purpose

This module provides advanced runtime values handling with watchers.

* Main responsibility: provide safe and reliable value retrieval.
* Advanced usage within text

---

## 🔹 Dependencies

| Module      | Usage                          |
|-------------|--------------------------------|
| `nsf_game`  | Allocation tracking (optional) |

---

## 🔹 API

### Creation / Destruction

| Function                   | Description                   |
|----------------------------|-------------------------------|
| `nsf_watcher_create(...)`  | Create and initialize watcher |
| `nsf_watcher_destroy(...)` | Destroy watcher               |

---

### Core Functions

| Function                      | Description           |
|-------------------------------|-----------------------|
| `nsf_watcher_get_float(...)`  | Retrieve float value  |
| `nsf_watcher_get_int(...)`    | Retrieve int value    |
| `nsf_watcher_get_char(...)`   | Retrieve char value   |
| `nsf_watcher_get_string(...)` | Retrieve string value |

---

### Advanced / Optional

| Function                             | Description          |
|--------------------------------------|----------------------|
| `nsf_watcher_get_string_in_buffer()` | Watcher-text linking |

---

## 🔹 Parameters Reference

| Name      | Type                 | Description                 |
|-----------|----------------------|-----------------------------|
| `watcher` | `nsf_watcher_t`      | Watcher instance            |
| `type`    | `nsf_watcher_type_t` | Watcher type                |
| `ptr`     | `void *`             | Pointer to watch            |
| `buffer`  | `char[]`             | Buffer to link              |
| `game`    | `nsf_game_t *`       | Allocation tracking context |

---

## 🔹 Return Values

| Type            | Meaning            |
|-----------------|--------------------|
| `nsf_watcher_t` | Allocated watcher  |
| `NULL`          | Allocation failure |
| `float *`       | Retrieved float    |
| `int *`         | Retrieved int      |
| `char *`        | Retrieved char     |
| `char **`       | Retrieved string   |
| `int`           | Success and error  |

---

## 🔹 Notes

* Designed for optional use by NCSFML users
* Not yet fully integrated internally across all modules
* Not a wrapper (new functionality)
* Works alongside `nsf_game_t->allocations`

---

## 🔹 Internal Files

| File                     | Role                         |
|--------------------------|------------------------------|
| `nsf_watcher_struct.c`   | Watcher creation/destruction |
| `nsf_watcher_manage_*.c` | Watcher retrival logic       |

---

## 🔹 Related Submodules

* [`nsf_game` 🔗](../games/game.md)
* [`nsf_text` 🔗](../graphics/text.md)

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

* Add full watcher support over various objects
* Integrate deeper into internal modules
* Add formating support

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
