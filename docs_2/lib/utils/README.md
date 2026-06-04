---
title: Library - Utils
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
<link rel="icon" type="image/x-icon" href="https://raw.githubusercontent.com/Jarjarbin06/Epitech_Base/refs/heads/main/docs/EpitechBaseWebIcon.png">

# 📦 libutils

> Minimal and safe utility library focused on memory management helpers and controlled deallocation patterns.

---

## 🔹 Short Description

**libutils is a lightweight C utility library providing standardized memory allocation, safe deallocation, and automated batch-free mechanisms.**

It is designed to centralize memory handling patterns and reduce manual error-prone `malloc/free` usage.

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

* C developers needing safer memory utilities
* EPITECH students managing complex allocations
* Projects requiring structured deallocation logic
* Developers building modular memory systems

---

## 🔹 Platform Support

* Linux compatible
* Standard C only
* No external dependencies

---

## 🔹 Purpose

libutils is designed to simplify memory handling by providing:

* Unified allocation (`malloc_any`)
* Safe deallocation (`free_any`)
* Conditional batch freeing (`auto_free`)
* Safe array cleanup (`free_array`)
* Consistent pointer reset behavior

It is **not a full memory allocator**, but a structured helper layer over standard `malloc/free`.

---

## 🔹 Key Features

* Safe allocation wrapper (`malloc_any`)
* Null-safe deallocation (`free_any`)
* Conditional batch free system (`auto_free`)
* NULL-terminated array cleanup (`free_array`)
* Pointer reset after free operations
* Structured `free_t` management system
* Lightweight and dependency-free design

---

## 🔹 Architecture Overview

```
            ┌──────────────────────┐
            │    malloc_any()      │
            │  (allocation layer)  │
            └─────────┬────────────┘
                      │
 ┌────────────────────┼────────────────────┐
 │                    │                    │
┌────────────┐   ┌──────────────┐   ┌──────────────┐
│ free_any   │   │ auto_free    │   │ free_array   │
│ (single)   │   │ (batch/cond) │   │ (array free) │
└────────────┘   └──────────────┘   └──────────────┘
```

---

## 🔹 Core Concept

Memory handling is standardized through:

* Allocation wrapper → `malloc_any`
* Safe single free → `free_any`
* Conditional structured free → `auto_free`
* Full array cleanup → `free_array`

This ensures **consistent lifecycle management for all dynamic allocations**.

---

## 🔹 Function Overview

### 🧠 Allocation

#### `malloc_any`

```c
void *malloc_any(unsigned size);
````

* Safe wrapper over `malloc`
* Returns `NULL` on failure
* Centralized allocation entry point

---

### 🧹 Deallocation

#### `free_any`

```c
void *free_any(void *ptr);
```

* Frees memory safely
* Returns `NULL` for immediate reassignment
* Prevents dangling pointers

---

### 🔁 Batch Conditional Freeing

#### `auto_free`

```c
int auto_free(unsigned len, free_t free_list[]);
```

* Frees elements based on condition flag
* Uses function pointer for flexible freeing logic
* Sets pointers to `NULL` after freeing
* Returns number of freed elements

---

### 📦 Array Cleanup

#### `free_array`

```c
void *free_array(void **array);
```

* Frees NULL-terminated pointer arrays
* Frees each element individually
* Frees the array container itself
* Returns `NULL` for safe reassignment

---

## 🔹 Core Structure

```c
typedef struct {
    bool condition;
    void *ptr;
    void_func_t free_func;
} free_t;
```

Used by `auto_free` to manage controlled memory cleanup.

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

### Allocation + Free

```c
int *arr = malloc_any(sizeof(int) * 10);
arr = free_any(arr);
```

---

### Conditional Free

```c
free_t list[] = {
    {true, &ptr1, (void_func_t)free_any},
    {false, &ptr2, (void_func_t)free_any}
};

auto_free(2, list);
```

---

### Array Free

```c
char **tab = malloc_any(sizeof(char *) * 5);
/* allocate strings */

tab = free_array((void **)tab);
```

---

## 🔹 Memory Model

* All allocations go through `malloc_any`
* All frees normalize pointer to `NULL`
* Batch freeing supported via structured descriptors
* No hidden allocations

---

## 🔹 Design Philosophy

* Centralize memory handling logic
* Reduce direct `malloc/free` usage
* Enforce pointer safety after free
* Provide reusable batch cleanup system
* Keep abstraction minimal and predictable

---

## 🔹 Current State

⚠️ The library is **stable and minimal by design**

Status:

* Allocation wrapper implemented
* Safe free utilities implemented
* Batch freeing system available
* Array cleanup functional
* No extended memory tracking system (by design)

Future improvements:

* Optional allocation tracking layer
* Debug mode for leaks detection
* Extended safety assertions

---

## 🔹 File Structure

```
includes/   → Public headers
sources/    → Implementation
Makefile    → Build system
```

---

## 🔹 Documentation Index

This library does not use a separate docs/ system.

---

## 🔹 Notes

* Designed for predictable memory handling in C
* Avoids direct repetitive `malloc/free` patterns
* Encourages structured memory lifecycle design
* Focused on simplicity over feature bloat

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
