---
title: Library - Flag
---
<link rel="icon" type="image/x-icon" href="https://raw.githubusercontent.com/Jarjarbin06/Epitech_Base/refs/heads/main/docs/EpitechBaseWebIcon.png">

# 📦 libflag

> Lightweight and structured command-line flag parsing library for C.

---

## 🔹 Short Description

**libflag is a minimal C library designed to handle command-line flags in a structured, extensible and type-safe way.**

It provides a complete system for defining flags, parsing `argv`, retrieving values, and tracking active options without relying on external dependencies or complex runtime systems.

---

## 🔹 Authors

* Nathan (Jarjarbin06)
* EPITECH Project

---

## 🔹 License

GPL v3

---

## 🔹 Target Audience

This library is designed for:

* C developers needing CLI argument parsing
* EPITECH students working on system projects
* Tools requiring structured flag handling
* Projects replacing manual `argv` parsing logic

---

## 🔹 Platform Support

* Linux compatible
* No external dependencies
* Pure standard C implementation

---

## 🔹 Purpose

libflag is designed to replace fragile manual argument parsing with a unified system that provides:

* Structured flag definitions (`flag_t`, `flag_set_t`)
* Automatic `argv` parsing and loading
* Short (`-f`) and long (`--flag`) support
* Value-based and boolean flags
* Runtime flag querying system
* Centralized memory-managed flag container

It is **not a full CLI framework**, but a lightweight parsing and management layer.

---

## 🔹 Key Features

* Flag container system (`flags_t`)
* Batch or single flag registration
* Automatic `argv` parsing (`flag_load`)
* Short and long flag support
* Optional value binding (`--file path`)
* Runtime query API:

    * `flag_get`
    * `flag_get_active`
    * `flag_get_value`
* Debug display system (`flag_show`)
* Safe memory management wrappers (`malloc_any`, `free_any`)
* Extensible flag metadata model

---

## 🔹 Architecture Overview

```
            ┌──────────────────────┐
            │     flag_load()      │
            │ (argv parser)        │
            └─────────┬────────────┘
                      │
        ┌─────────────┼──────────────────┐
        │             │                  │
┌──────────────┐ ┌──────────────┐ ┌──────────────┐
│ flag storage │ │ flag lookup  │ │ flag update  │
│ flags_t      │ │ get / query  │ │ activation   │
└──────────────┘ └──────────────┘ └──────────────┘
        │
┌──────────────────────┐
│ memory utilities      │
│ malloc_any / free_any │
└──────────────────────┘
```

---

## 🔹 Core Concept

The system revolves around three main structures:

### Flag definition input

```c
typedef struct {
    char *name;
    char simple;
    char *advanced;
    bool need_value;
    const char *base_value;
    bool last_flag
} flag_set_t;
```

### Runtime flag instance

```c
typedef struct {
    char *name;
    char simple;
    char *advanced;
    bool active;
    bool need_value;
    char *value;
    bool is_loaded;
} flag_t;
```

### Container

```c
typedef struct {
    flag_t *flags;
    size_t loaded;
    size_t size;
    size_t max_size;
} flags_t;
```

---

## 🔹 Modules Overview

### 🧠 Core System

Handles creation, storage and lifecycle of flags.

* `flag_create`
* `flag_destroy`
* `flag_add`
* `flag_add_batch`

---

### ⚙️ Parser System

Processes command-line arguments.

* `flag_load`
* Supports `-f value` and `--flag value`
* Automatic flag matching and activation

---

### 🔍 Query System

Runtime access to parsed flags.

* `flag_get`
* `flag_get_active`
* `flag_get_value`

---

### 🖨️ Debug System

Displays all registered flags.

* `flag_show`
* Human-readable CLI debug output
* Includes short + long form display

---

## 🔹 Build System

### Makefile

```bash
make
make clean
make fclean
make re
```

---

## 🔹 Installation Requirements

* GCC / Clang compatible compiler
* Standard C library
* Linux environment recommended

---

## 🔹 Quickstart Example

### Define and create flags

```c
flags_t *flags = flag_create(10);
```

---

### Add flags

```c
flag_add(flags, (flag_set_t[]){
    {"helper", 'h', "help"}
});

```

---

### Load from argv

```c
flag_load(flags, argc, argv);
```

---

### Query flags

```c
if (flag_get_active(flags, "help"))
    return 0;
```

---

### Get values

```c
const char *file = flag_get_value(flags, "file");
```

---

## 🔹 Memory Model

* Heap-based container (`flags_t`)
* Individual flag allocations via `str_dup`
* Controlled cleanup via `flag_destroy`
* Uses custom memory wrappers (`malloc_any`, `free_any`)

⚠️ Responsibility: user must destroy `flags_t` to avoid leaks.

---

## 🔹 Design Philosophy

* Flags are structured objects, not raw strings
* CLI parsing is deterministic and predictable
* Short and long flags are treated uniformly
* Runtime access should be simple and fast
* Minimal dependencies, maximal portability

---

## 🔹 Current State

⚠️ The library is **functional but still evolving**

Status:

* Core flag container implemented
* Parsing system functional
* Query API stable
* Debug output available
* Future improvements planned:

    * Improved type system for values
    * Automatic default value handling
    * Better error reporting
    * Flag grouping / namespaces

---

## 🔹 File Structure

```
includes/   → Public API headers
sources/    → Implementation
Makefile    → Build system
```

---

## 🔹 Internal Design Notes

* Flags are dynamically duplicated using `str_dup`
* Parsing supports incremental argv scanning
* Each flag tracks:

    * activation state
    * loaded state
    * optional value binding
* Simple and advanced identifiers are both supported

---

## 🔹 Notes

* Designed for EPITECH-style CLI programs
* Lightweight alternative to getopt-based systems
* Fully custom implementation (no libc getopt dependency)
* Intended for learning structured parsing systems

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
