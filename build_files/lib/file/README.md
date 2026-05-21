# 📦 libfile

> Minimal and structured file handling library for C based on direct system calls (`open`, `read`, `close`) with controlled memory ownership and safe file abstraction.

---

## 🔹 Short Description

**libfile is a lightweight C library providing structured file management, raw content loading, and metadata extraction using low-level POSIX system calls.**

It centralizes file lifecycle handling (creation, loading, display, destruction) into a unified and predictable API.

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

* C developers working with low-level file handling
* EPITECH students building system-oriented projects
* Projects requiring controlled file abstraction layers
* Developers avoiding `FILE*` stdio buffering
* Systems needing raw memory-based file loading

---

## 🔹 Platform Support

* Linux compatible
* POSIX system calls only
* Standard C only
* No external dependencies

---

## 🔹 Purpose

libfile is designed to replace direct and repetitive file handling logic by providing:

* Unified file lifecycle (`file_create`, `file_load`, `file_destroy`)
* Low-level system call abstraction (`open`, `read`, `close`)
* Safe memory allocation for file content (`raw`)
* Structured metadata handling (path, name, size)
* Debug-oriented display system (`file_show`)

It is **not a high-level file parser**, but a controlled abstraction over raw file access.

---

## 🔹 Key Features

* File abstraction structure (`file_t`)
* Direct syscall-based file access
* Raw file loading into heap memory
* Automatic path and filename extraction
* Safe file lifecycle management
* Structured destruction system
* Debug printing utility (`file_show`)
* Memory-safe ownership model
* Lightweight and dependency-free design

---

## 🔹 Architecture Overview

```
            ┌──────────────────────┐
            │   file_create()      │
            │ (metadata builder)   │
            └─────────┬────────────┘
                      │
                      ▼
            ┌──────────────────────┐
            │   file_load()        │
            │ (syscall loader)     │
            └─────────┬────────────┘
                      │
     ┌────────────────┼────────────────┐
     │                │                │
┌────────────┐  ┌────────────┐  ┌──────────────┐
│ open/close │  │ read raw   │  │ metadata     │
│ (syscalls) │  │ buffer     │  │ (size/path)  │
└────────────┘  └────────────┘  └──────────────┘
                      │
                      ▼
            ┌──────────────────────┐
            │   file_show()        │
            │ (debug output)       │
            └──────────────────────┘
```

---

## 🔹 Core Concept

Each file is represented by a structured object:

```c
typedef struct {
    int fd;
    char *full_path;
    char *path;
    char *name;
    size_t size;
    bool is_open;
    rights_t rights;
    char *raw;
} file_t;
```

### Lifecycle model:

1. `file_create()` → initializes metadata
2. `file_load()` → loads raw content
3. `file_show()` → debug representation
4. `file_destroy()` → full cleanup

---

## 🔹 Function Overview

### 🧱 File Creation

#### `file_create`

```c
file_t *file_create(const char full_path[]);
```

* Allocates and initializes file structure
* Extracts:

    * directory path
    * filename
* Initializes metadata fields

---

### 📥 File Loading

#### `file_load`

```c
int file_load(file_t *file);
```

* Loads full file content into `raw`
* Uses:

    * `open`
    * `read`
    * `close`
* Computes file size manually
* Allocates exact buffer for content

---

### 🔓 File Access Control

#### `file_open`

```c
int file_open(file_t *file);
```

* Opens file descriptor using `open()`
* Sets `is_open` flag

---

#### `file_close`

```c
int file_close(file_t *file);
```

* Closes file descriptor
* Resets state

---

### 🧹 File Destruction

#### `file_destroy`

```c
int file_destroy(file_t **file);
```

* Frees all allocated memory:

    * `full_path`
    * `path`
    * `name`
    * `raw`
    * struct itself
* Prevents dangling pointer by setting NULL

---

### 🖨️ Debug Display

#### `file_show`

```c
void file_show(file_t *file);
```

* Prints structured file information:

    * full path
    * path
    * name
    * open state
    * raw content preview

---

## 🔹 Core Structure

### File representation

```c
typedef struct {
    int fd;
    char *full_path;
    char *path;
    char *name;
    size_t size;
    bool is_open;
    rights_t rights;
    char *raw;
} file_t;
```

### Rights structure

```c
typedef struct rights_s {
    bool read;
    bool write;
    bool execute;
} rights_t;
```

---

## 🔹 Memory Model

* File metadata is heap-allocated
* `raw` contains full file content in memory
* Ownership is explicit and manual
* Full cleanup required via `file_destroy`
* No hidden allocations

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
* Linux environment recommended
* POSIX-compliant system calls

---

## 🔹 Quickstart Example

### Basic usage

```c
file_t *file = file_create("sources/main.c");

file_load(file);
file_show(file);

file_destroy(&file);
```

---

### Lifecycle example

```c
file_t *file = file_create(path);

if (file_load(file) == E_SUCCESS)
    printf("File loaded successfully\n");

file_destroy(&file);
```

---

## 🔹 Design Philosophy

* Direct system call usage (no stdio abstraction)
* Explicit memory ownership rules
* Clear lifecycle separation
* Minimal hidden behavior
* Debug-friendly structure output
* Lightweight and predictable design

---

## 🔹 Current State

⚠️ The library is **stable and functional but minimal**

Status:

* File creation implemented
* Raw loading implemented (syscall-based)
* Metadata extraction implemented
* Debug display available
* Full destruction system implemented

Known limitations:

* No buffered reading system
* No parsing layer (lines not yet implemented)
* No error diagnostics system beyond return codes
* No async or lazy loading

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

* Designed for low-level file manipulation in C
* Avoids stdio buffering entirely
* Focuses on explicit lifecycle control
* Intended as a foundation for higher-level parsing systems
* Built for extensibility (parsers, buffers, loaders can be added later)

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
