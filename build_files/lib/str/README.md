# 📦 libstr

> Lightweight and modular string manipulation library for C.

---

## 🔹 Short Description

**libstr is a structured C string utility library providing safe manipulation, transformation, checking, printing, and memory-aware management of strings.**

It centralizes common string operations into grouped APIs for clarity, consistency, and extensibility.

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

* C developers needing safer string utilities
* EPITECH students working on low-level projects
* Developers replacing fragmented string helpers
* Projects requiring structured string APIs

---

## 🔹 Platform Support

* Linux compatible
* Standard C only
* No external dependencies

---

## 🔹 Purpose

libstr is designed to replace scattered string handling functions by providing:

* Grouped string operations (transform, check, get, manage, print)
* Consistent type usage (`str_t`, `cstr_t`, `cc_t`)
* Unified API structure via `str`
* Safer string manipulation patterns
* Extendable architecture for additional utilities

It is **not a replacement for libc strings**, but a structured enhancement layer.

---

## 🔹 Key Features

* Structured string API (`str_str_t`)
* Transformations (case, reverse, swap)
* String validation and checks
* Safe memory-aware string management
* Word splitting utilities
* Consistent type system (`str_t`, `cstr_t`)
* Shortcut global dispatcher (`str`)
* Modular function grouping

---

## 🔹 Architecture Overview

```
            ┌──────────────────────┐
            │     str_str_t        │
            │  (API dispatcher)    │
            └─────────┬────────────┘
                      │
 ┌────────────────────┼────────────────────┐
 │                    │                    │
┌────────────┐   ┌──────────────┐   ┌──────────────┐
│ transform  │   │   check      │   │    get       │
│ (t)        │   │ (c)          │   │ (g)          │
└────────────┘   └──────────────┘   └──────────────┘
 │
┌──────────────────┐
│ manage + print   │
│ (m + p layers)   │
└──────────────────┘
```

---

## 🔹 Core Concept

The system is built around:

```c
typedef struct {
    str_transform_t t;
    str_put_t p;
    str_check_t c;
    str_get_t g;
    str_manage_t m;
} str_str_t;
````

This provides a **namespaced and grouped API system** for all string operations.

---

## 🔹 Modules Overview

### 🔁 Transformations (`t`)

Handles string modifications.

* `str_reverse`
* `str_capitalize`
* `str_upcase`
* `str_lowcase`
* `str_c_swap`

---

### 🧪 Checks (`c`)

Handles validation and comparisons.

* Alpha / numeric checks
* Upper / lower checks
* Printable checks
* String comparison

---

### 📥 Getters (`g`)

Handles extraction and parsing.

* String length
* Integer parsing
* Word array splitting

---

### 🧱 Management (`m`)

Handles memory-safe string operations.

* Copy / duplicate
* Concatenation
* Partial duplication

---

### 🖨️ Printing (`p`)

Handles output utilities.

* String printing
* Character printing
* Integer printing

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

### Basic Usage

```c
str_put_str("Hello World!\n");
str_put_nbr(42);
```

---

### Transformations

```c
str_t s = str_dup("hello");
s = str_capitalize(s);   // Hello
s = str_upcase(s);       // HELLO
s = str_reverse(s);      // OLLEH
```

---

### Checks

```c
if (str_is_alpha("Hello"))
    str_put_str("Alphabetic string\n");
```

---

### Word Split

```c
str_t *words = str_to_word_array("a,b,c", ',');
str_put_str(words[1]);
free_array((void **)words);
```

---

## 🔹 Memory Model

* String duplication uses heap allocation
* Must be freed manually using provided utilities
* Safe array cleanup via `free_array`
* Consistent ownership rules across API

---

## 🔹 Design Philosophy

* Grouped string operations by responsibility
* Clear separation between transform / check / manage
* Consistent type abstraction (`str_t`)
* Minimal surprises in memory behavior
* Fully extensible function grouping system

---

## 🔹 Current State

⚠️ The library is **stable but partially evolving**

Status:

* Core string operations implemented
* Transformation system functional
* Word splitting available
* Memory helpers integrated
* Some functions marked `.off` still in progress

Future improvements:

* Extended parsing utilities
* Performance optimizations
* Additional string algorithms

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

* Designed for structured string manipulation in C
* Avoids scattered libc-style functions
* Encourages grouped API usage
* Built for extensibility and clarity
* Uses unified `str_t` type system across all modules

---
