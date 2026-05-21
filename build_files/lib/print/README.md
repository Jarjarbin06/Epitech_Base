# 📦 libprint

> Lightweight custom implementation of `printf` with modular format parsing and extensible conversion system.

---

## 🔹 Short Description

**libprint is a reimplementation of `printf` in C, providing formatted output, flag parsing, and a modular conversion dispatch system.**

It is designed to replicate standard behavior while remaining fully extensible and educational.

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

* C developers learning low-level format parsing
* EPITECH students working on libc-style projects
* Developers implementing custom output systems
* Projects requiring controlled formatted output

---

## 🔹 Platform Support

* Linux compatible
* No external dependencies
* Standard C only

---

## 🔹 Purpose

libprint is designed to replace and reimplement standard `printf` behavior by providing:

* A fully custom format parser
* Modular conversion system via function pointers
* Structured flag handling
* Extensible architecture for new specifiers
* Controlled output behavior without relying on `<stdio.h>`

It is **not a drop-in replacement of libc printf**, but an educational and modular reimplementation.

---

## 🔹 Key Features

* Custom `printf`-like function (`print`)
* Full format string parsing
* Flag system (`+ - 0 # space`)
* Precision and width handling
* Modular conversion dispatch table
* Support for integers, floats, strings, pointers
* Extensible conversion architecture
* Character count return system

---

## 🔹 Architecture Overview

```
            ┌──────────────────────┐
            │      print()         │
            │   (entry function)   │
            └─────────┬────────────┘
                      │
      ┌───────────────┼────────────────┐
      │               │                │
┌────────────┐  ┌──────────────┐  ┌──────────────┐
│ format     │  │ flag parser  │  │ conversion   │
│ validation │  │ (p_flag_t)   │  │ dispatch     │
└────────────┘  └──────────────┘  └──────────────┘
│
┌──────────────────┐
│ output system    │
│ char/string/base │
└──────────────────┘
```

---

## 🔹 Core Concept

The main entry point:

```c
int print(const char *format, ...);
````

It provides:

* Format string parsing
* Variadic argument handling
* Dynamic conversion dispatch
* Character count return

---

## 🔹 Modules Overview

### 🧠 Format Engine

Handles parsing and validation of format strings.

* `check_format`
* format iteration loop
* `%` detection system

---

### ⚙️ Flag System

Handles formatting modifiers.

* `p_flag_t` structure
* flag parsing (`+ - 0 # space`)
* width and precision handling

---

### 🔁 Conversion System

Handles type-specific formatting.

* Integer conversions (`d`, `i`, `u`)
* Hex / Octal conversions (`x`, `o`)
* Float formatting (`f`, `e`, `g`)
* String / char output
* Pointer handling

---

### 🖨️ Output System

Responsible for actual character output.

* `p_put_char`
* `p_put_str`
* base printing system
* floating output handling

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
print("Value: %d\n", 42);
```

---

### Multiple Conversions

```c
print("Hex: %x | Float: %.2f\n", 255, 3.14);
```

---

### Flags Example

```c
print("Value: %+08d\n", 42);
```

---

## 🔹 Memory Model

* No dynamic allocation required
* Stack-based argument processing
* Deterministic execution flow
* Safe variadic handling

---

## 🔹 Design Philosophy

* Modular conversion system
* Function pointer dispatch for scalability
* Strict separation between parsing and output
* Minimal dependencies
* Educational reimplementation of libc behavior

---

## 🔹 Current State

⚠️ The library is **functionally complete but extensible**

Status:

* Core `printf` engine implemented
* Flag system functional
* Conversion dispatch working
* Floating point handling supported
* Future improvements planned:

    * Extended specifiers
    * Full length modifier support
    * Performance optimizations
    * Better standard compliance

---

## 🔹 File Structure

```
includes/   → Public API headers
base/       → Core printing logic
conv/       → Conversion system
flag/       → Flag parsing system
len_mod/    → Length modifiers
Makefile    → Build system
```

---

## 🔹 Documentation Index

This library does not use a separate docs/ system.

---

## 🔹 Notes

* Designed as an educational printf reimplementation
* Focus on modularity and clarity over strict libc compliance
* Fully extensible conversion architecture
* Intended for learning format parsing and variadic processing

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
newcsfml   v0.2.7
newerror   v0.1.1
print      v0.1.5
str        v0.1.5
twodlist   v0.0.0
utils      v0.1.5
</pre>

Author: Nathan (Jarjarbin06) • EPITECH<br>
Licence: GPL v3<br>
Repository: [Epitech Base](https://github.com/Jarjarbin06/Epitech_Base)
</div>

---
