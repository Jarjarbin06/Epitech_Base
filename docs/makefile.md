# 📦 Epitech Base Makefile System

> Advanced and modular Makefile designed to automate compilation, library management, testing, and repository workflow for EPITECH projects.

---

## 🔹 Short Description

**This Makefile provides a complete build and project management system for EPITECH-style repositories, integrating multi-library compilation, automated imports, testing tools, and Git workflows.**

It acts as both:
* A **build orchestrator**
* A **project bootstrap system**

---

## 🔹 Authors

* Nathan (Jarjarbin06)
* EPITECH Project

---

## 🔹 Versioning

* Version: `v0.3.1`
* Last update: `2026/05/05`
* Maintained via central base repository

---

## 🔹 Purpose

This Makefile is designed to:

* Automate compilation of projects and libraries
* Standardize project structure
* Simplify library integration
* Provide built-in testing tools
* Automate Git workflows
* Enable fast project bootstrapping

---

## 🔹 Core Features

* 🔁 Automatic library compilation (`lib/`)
* 📦 Dynamic library linking
* 🧱 Modular project structure
* ⚙️ Integrated testing system (Criterion, Valgrind, gcovr)
* 🔄 Git automation (commit, push, update)
* 🏗️ Project template bootstrap (`build`)
* 📥 Library import system
* 🧹 Advanced cleanup system
* 🧪 Debug tools (ASAN, coverage)

---

## 🔹 Architecture Overview

```

EpitechBase Root
│
└── build_files/          → Base repository (external reference)

Project Root
│
├── includes/             → Headers
├── sources/              → Project source files
├── lib/                  → Imported libraries (.a + sources)
├── tests/                → Test files (Criterion)
├── bonus/                → Project bonus
│
└── Makefile              → Central controller

````

---

## 🔹 Compilation System

### Automatic Source Detection

```make
SRC = $(shell find sources -type f -name "*.c" ! -name "main.c")
````

* Detects all `.c` files automatically
* Excludes `main.c` (handled separately)

---

### Include Handling

```make
INCLUDES = $(shell find includes -type d -printf '-I%p ')
```

* Recursively includes all header directories

---

### Library Detection

```make
LIBS_LIST = $(notdir $(shell find lib -mindepth 1 -maxdepth 1 -type d))
```

* Automatically detects all libraries in `lib/`

---

### Automatic Linking

```make
LIB_FLAGS = -l<libname>
```

* Only links libraries that are already compiled (`lib<name>.a`)

---

### CSFML Auto-Linking

```make
ifneq ($(filter -lnewcsfml,$(CFLAGS_PLUS)),)
```

Automatically adds:

```
-lcsfml-graphics
-lcsfml-window
-lcsfml-system
-lcsfml-audio
-lm
```

---

## 🔹 Build Rules

### Main Compilation

```bash
make
```

Steps:

1. Compile all libraries
2. Compile project
3. Link everything into `binary`

---

### Standard Rules

```bash
make clean     # Remove object files
make fclean    # Remove binaries + libs
make re        # Full rebuild
make run       # Compile and run
```

---

### Debugging

```bash
make asan
```

* Enables AddressSanitizer

---

## 🔹 Library System

### Compile All Libraries

```bash
make compile_libs
```

* Builds each library inside `lib/`
* Copies `.a` files into `lib/`
* Runs `ranlib` automatically

---

### Clean Libraries

```bash
make clean_libs
make fclean_libs
```

---

## 🔹 Testing System

### Unit Tests (Criterion)

```bash
make test_unit_tests
make test_unit_tests_run
```

---

### Valgrind

```bash
make test_valgrind
```

---

### Coverage

```bash
make test_gcovr
```

---

### Coding Style

```bash
make test_style
```

* Uses `epiclang`

---

## 🔹 Git Integration

### Utilities

```bash
make git_pull
make git_info
make git_get_commit
```

---

### Auto Push System

Controlled by:

```make
ALLOW_AUTO_PUSH = true
```

---

### Auto Commit Examples

```bash
make push_setup
make push_makefile
make push_lib
```

---

## 🔹 Project Bootstrap System

### Build (Project Initialization)

```bash
make build
```

* Copies:

    * `.gitignore`
    * Base project structure
    * Template files

⚠️ Only works if repository is clean

---

### Unbuild (Dangerous)

```bash
make unbuild
```

* Deletes:

    * sources/
    * includes/
    * lib/
    * tests/
    * bonus/

Requires:

```make
ALLOW_UNBUILD = true
```

---

## 🔹 Library Import System

### Import Individual Libraries

```bash
make import_str
make import_print
make import_utils
make import_newcsfml
make import_newerror
make import_llist
make import_twodlist
make import_file
```

---

### Import All

```bash
make import_all
```

---

### Behavior

Each import:

1. Deletes old version
2. Copies from base repository
3. Copies headers into `includes/lib_includes/`
4. Commits & pushes (if enabled)

---

## 🔹 Configuration Variables

### Paths

```make
EPITECH_BASE_PATH = /path/to/Epitech_Base
```

---

### Compilation

```make
CC      = clang
CFLAGS  = -g3 -O0 -O3 -Wall -Wextra
```

---

### Behavior Flags

```make
ALLOW_UNBUILD     = false
ALLOW_AUTO_PUSH   = true
```

---

## 🔹 Internal Flow

### Build Flow

```
make
 ├── compile_libs
 │    └── build each lib
 │
 └── compile binary
      ├── compile sources
      └── link libs
```

---

### Import Flow

```
import_lib
 ├── remove old lib
 ├── copy new lib
 ├── copy headers
 └── push changes
```

---

## 🔹 Design Philosophy

* Fully automated workflow
* Minimal manual configuration
* Modular and scalable
* EPITECH-compatible
* Centralized tooling
* Reproducible environments

---

## 🔹 Security & Safety Notes

* `build` and `unbuild` are **destructive**
* Git auto-push should be used carefully
* Imports overwrite existing libraries
* Requires valid `EPITECH_BASE_PATH`

---

## 🔹 Limitations

* Linux-focused environment
* Requires consistent repo structure
* Depends on external base repository
* No dependency versioning system

---

## 🔹 Best Practices

* Keep `lib/` clean and organized
* Use `import_*` instead of manual copying
* Disable auto-push in team environments if needed
* Always test after imports
* Avoid modifying imported libraries directly

---

## 🔹 Help Command

```bash
make help
```

Displays:

* Main commands
* Testing commands
* Utility rules

---

## 🔹 Notes

* Designed for **high productivity in EPITECH projects**
* Encourages **modular architecture**
* Centralizes **all project operations in one tool**
* Scales from small projects to full frameworks (e.g., NewCSFML)

---
