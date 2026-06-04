---
title: Library - NewError
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

# 📦 liberror

> Lightweight, structured and extensible error handling system for C.

---

## 🔹 Short Description

**liberror is a minimal C error handling library that provides structured error objects, contextual debugging information, and unified return-based error utilities.**

It replaces traditional string-based error handling with a consistent, composable and context-aware system.

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

* C developers needing structured error handling
* EPITECH students working on system-level projects
* Projects requiring consistent debugging output
* Developers replacing ad-hoc error strings with typed errors

---

## 🔹 Platform Support

* Linux compatible
* No external dependencies
* Pure standard C implementation

---

## 🔹 Purpose

liberror is designed to replace fragile and inconsistent error handling patterns in C by providing:

* Structured error objects (`err_t`)
* Automatic context capture (file / function / line)
* Unified printing system
* Consistent return-value error helpers
* Zero dynamic allocation design

It is **not a logging framework**, but a strict error handling abstraction layer.

---

## 🔹 Key Features

* Structured error representation (`err_t`)
* Automatic context injection via macros
* Fatal / non-fatal error distinction
* Unified printing system with formatted output
* Return-aware helpers (int / bool / pointer / void)
* Centralized API via `nerr` dispatcher
* Zero heap allocation design

---

## 🔹 Architecture Overview

```
            ┌────────────────────┐
            │      ERR()         │
            │ (entry macro)      │
            └─────────┬──────────┘
                      │
      ┌───────────────┼────────────────┐
      │               │                │
┌────────────┐  ┌──────────────┐  ┌──────────────┐
│ err_t data │  │ update layer │  │ print layer  │
│ structure  │  │ (upt / ftl)  │  │ err_print    │
└────────────┘  └──────────────┘  └──────────────┘
│
┌──────────────────┐
│ return helpers   │
│ nerr.i / nerr.p  │
└──────────────────┘
```

---

## 🔹 Core Concept

The system is built around a single structured type:

```c
typedef struct {
    const char *title;
    const char *msg;
    const char *file;
    const char *func;
    int line;
    bool fatal;
} err_t;
````

---

## 🔹 Modules Overview

### 🧠 Core System

Handles creation, update, and lifecycle of error objects.

* `ERR()` macro (entry point)
* `upt()` context updates
* `ftl()` fatal marking

---

### 🖨️ Output System

Responsible for formatted error display.

* `err_print()`
* ANSI-colored output
* Context-aware formatting

---

### 🔁 Return Helpers

Standardized return-based error propagation.

* Integer handling (`nerr.i`, `nerr.ie`)
* Pointer handling (`nerr.p`, `nerr.pn`)
* Boolean handling (`nerr.b`, `nerr.bf`)
* Void handling (`nerr.v`)

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
return nerr.i(ERR(), 0);
```

---

### With Context

```c
return nerr.i(upt(ERR(), "Error", "Something failed"), 0);
```

---

### Fatal Error

```c
return nerr.ie(ftl(upt(ERR(), "Critical", "Fatal issue")));
```

---

## 🔹 Memory Model

* No dynamic allocation
* Stack-based error objects
* Fully deterministic lifecycle
* Zero ownership complexity

---

## 🔹 Design Philosophy

* Errors are **data**, not strings
* Context must be automatic, not manual
* API must remain consistent and minimal
* No hidden allocations or side effects
* Explicit return-based control flow

---

## 🔹 Current State

⚠️ The library is **stable but extensible**

Status:

* Core error structure implemented
* Print system functional
* Return helpers implemented
* Shortcut API available
* Future improvements planned:
  * Extended formatting modes
  * Optional logging backend
  * Error chaining system

---

## 🔹 File Structure

```
includes/   → Public API headers
sources/    → Implementation
Makefile    → Build system
```

---

## 🔹 Documentation Index

This library does not use a separate docs/ system.

---

## 🔹 Notes

* Designed for low-level C projects
* Focus on clarity and predictability
* No runtime overhead or heap allocation
* Intended as a drop-in utility library

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
