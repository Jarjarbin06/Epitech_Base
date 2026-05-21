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

* Version: `v1.0.4`
* Last update: `2026/05/18 15h`
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
* 🔄 Git automation (pull, status, commit helpers, push system)
* 🏗️ Project template bootstrap (`setup-build`)
* 📥 Library import system (full + individual modules)
* 🧹 Advanced cleanup system (lib + project + tests)
* 🧪 Debug tools (ASAN, coverage, style checker)

---

## 🔹 Architecture Overview

```
EpitechBase Root
│
└── build_files/          → Base repository (external reference)
```

```
Project Root
│
├── includes/             → Headers
├── sources/              → Project source files
├── lib/                  → Imported libraries (.a + sources)
├── tests/                → Test files (Criterion)
├── bonus/                → Project bonus
│
└── Makefile              → Central controller
```

---

## 🔹 Compilation System

### Automatic Source Detection

```make
SRC = $(sort $(shell [ -d "$(SRC_PATH)" ] && find $(SRC_PATH) -type f -name "*.c" ! -name "main.c"))
```

* Detects all `.c` files automatically
* Excludes `main.c` (handled separately)

---

### Include Handling

```make
INCLUDES = $(sort $(addprefix -I,$(shell [ -d "$(INCLUDE_PATH)" ] && find $(INCLUDE_PATH) -type d)))
```

* Recursively includes all header directories

---

### Library Detection

```make
LIBS_LIST = $(sort $(notdir $(shell [ -d "$(LIB_SRC_PATH)" ] && find $(LIB_SRC_PATH) -mindepth 1 -maxdepth 1 -type d)))
```

* Automatically detects all libraries in `lib/`

---

### Automatic Linking

```make
LIB_FLAGS = $(foreach lib,$(LIBS_LIST), $(if $(wildcard lib/$(lib)/lib$(lib).a),-l$(lib),))
```

* Only links compiled libraries

---

### CSFML Auto-Linking

Enabled via:

```make
HAS_CSFML = true/false
```

If enabled, adds:

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

1. Compile all libraries (`lib-build`)
2. Compile project sources
3. Link everything into `binary`

---

### Standard Rules

```bash
make clean     # Remove object files
make fclean    # Remove binary + libs
make re        # Full rebuild
make run       # Compile and execute
```

---

### Debugging (ASAN)

```bash
make debug-asan
```

* Enables AddressSanitizer build

---

## 🔹 Library System

### Compile All Libraries

```bash
make lib-build
```

* Builds each library inside `lib/`
* Copies `.a` files into root `lib/`
* Runs `ranlib`

---

### Clean Libraries

```bash
make lib-clean
make lib-fclean
```

---

## 🔹 Testing System

### Unit Tests

```bash
make test-run
make test-build
```

---

### Valgrind

```bash
make test-valgrind
```

---

### Coverage

```bash
make test-gcovr
```

---

### Style Check

```bash
make test-style
```

* Uses `epiclang`

---

## 🔹 Git Integration

### Core Commands

```bash
make git-pull
make git-status
make git-commit-msg
```

---

### Push System

Controlled by:

```make
ALLOW_AUTO_PUSH = true
```

Rules:

```bash
make git-push-repo
make git-push-libs
make git-push-makefile
```

---

## 🔹 Project Bootstrap System

### Build Setup

```bash
make setup-build
```

* Copies template project structure
* Copies `.gitignore`
* Initializes base environment

---

### Unbuild (Dangerous)

```bash
make setup-unbuild
```

⚠️ Deletes:

```
bonus/
includes/
lib/
sources/
tests/
main.c
```

Controlled by:

```make
ALLOW_UNBUILD = true
```

---

## 🔹 Library Import System

### Individual Imports

```bash
make setup-import-newerror
make setup-import-llist
make setup-import-newcsfml
make setup-import-print
make setup-import-str
make setup-import-file
make setup-import-flag
make setup-import-utils
make setup-import-twodlist
```

---

### Import All

```bash
make setup-import-all
```

---

### Behavior

Each import:

1. Deletes old library version
2. Copies from base repository
3. Copies headers into `includes/lib_includes/`
4. Optionally pushes to Git

---

## 🔹 Configuration Variables

### Paths

```make
EPITECH_BASE_PATH = /path/to/Epitech_Base
```

---

### Compilation

```make
CC = clang
CFLAGS = -Wall -Wextra -Werror -g3 -O3
```

---

### Flags

```make
ALLOW_UNBUILD = false
ALLOW_AUTO_PUSH = true
DEBUG ?= false
ARCH ?= native
HAS_CSFML = false
```

---

## 🔹 Internal Flow

### Build Flow

```
make
 ├── lib-build
 ├── compile sources
 └── link binary
```

---

### Import Flow

```
setup-import-*
 ├── remove old lib
 ├── copy new lib
 ├── copy headers
 └── git push (if enabled)
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

## 🔹 Security Notes

* `setup-unbuild` is destructive
* Git auto-push must be controlled
* Imports overwrite local libraries
* Requires valid `EPITECH_BASE_PATH`

---

## 🔹 Limitations

* Linux-focused
* Requires strict repo structure
* No version manager for libraries
* Depends on external base repository

---

## 🔹 Best Practices

* Use `setup-import-*` instead of manual copying
* Keep `lib/` clean
* Avoid modifying imported libs directly
* Test after each import
* Disable auto-push in shared environments

---

## 🔹 Help Command

For all help:

```bash
make help
```

For specialised help:

```bash
make help-*
```

---

## 🔹 Notes

* Designed for EPITECH workflow efficiency
* Encourages modular architecture
* Centralizes all operations into a single system
* Scales from small projects to full frameworks (NewCSFML, etc.)

---

<div align="center">

<h1>📦 Epitech Base — Footer</h1>

</div>
<div align="center">

<img src="https://raw.githubusercontent.com/Jarjarbin06/Epitech_Base/refs/heads/main/docs/EpitechBaseLogo.png" width="120"  alt="Epitech Base Logo"/><br>

Epitech Base • Modular C Ecosystem

Libraries:<br>
• `file` - `v0.1.2`<br>
• `flag` - `v0.1.1`<br>
• `llist` - `v0.0.0`<br>
• `newcsfml` - `v0.2.7`<br>
• `newerror` - `v0.1.1`<br>
• `print` - `v0.1.5`<br>
• `str` - `v0.1.5`<br>
• `print` - `v0.0.0`<br>
• `twodlist` - `v0.1.5`<br>
• `utils` - `v0.1.5`<br>

Author: Nathan (Jarjarbin06) • EPITECH<br>
Licence: GPL v3<br>
Repository: [Epitech Base](https://github.com/Jarjarbin06/Epitech_Base)
</div>

---
