---
title: Epitech Base | Makefile
---
<link rel="icon" type="image/x-icon" href="https://raw.githubusercontent.com/Jarjarbin06/Epitech_Base/refs/heads/main/docs/EpitechBaseWebIcon.png">

# 📦 Epitech Base Makefile System

> Advanced and modular Makefile system designed to automate compilation, library management, testing, and repository workflow for EPITECH projects.

---

## 🔹 Short Description

**This Makefile provides a complete build and project management system for EPITECH-style repositories, integrating multi-library compilation, automated imports, testing tools, and Git workflows.**

It acts as both:

* A **build orchestrator**
* A **project bootstrap and maintenance system**

---

## 🔹 Authors

* Nathan (Jarjarbin06)
* EPITECH Project

---

## 🔹 Versioning

* Version: `v1.0.6`
* Last update: `2026/06/03 09h`
* Makefile name: `Makefile`

---

## 🔹 Purpose

This Makefile is designed to:

* Automate compilation of projects and libraries
* Standardize project structure
* Simplify library integration
* Provide built-in testing tools
* Automate Git workflows
* Enable fast project bootstrapping and maintenance

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
* ⚡ CSFML optional integration (`HAS_CSFML`)

---

## 🔹 Configuration Variables

### Project Metadata

```make
info_NAME = Epitech Base
info_VERSION = v1.0.6
info_LAST_UPDATE = 2026/06/03 09h
info_LIB_MAKER = Makefile
```

---

### Build Configuration

```make
EPITECH_BASE_PATH ?= /home/jarjarbin/Desktop/c/Epitech_Base
NAME ?= binary
ARCH ?= generic
```

---

### Feature Flags

```make
HAS_CSFML ?= false
ALLOW_UNBUILD ?= false
ALLOW_AUTO_PUSH ?= false
BONUS ?= false
DEBUG ?= false
```

---

## 🔹 Purpose of Flags

| Flag              | Description                                  |
|-------------------|----------------------------------------------|
| `HAS_CSFML`       | Enables CSFML linking                        |
| `ALLOW_UNBUILD`   | Allows destructive project reset             |
| `ALLOW_AUTO_PUSH` | Enables automatic git push for libs/makefile |
| `BONUS`           | Enables bonus compilation                    |
| `DEBUG`           | Switches between debug and release mode      |

---

## 🔹 Project Structure

```
Project Root
│
├── sources/              → Source files (.c)
├── includes/             → Headers
├── lib/                  → External + internal libraries
├── tests/                → Unit tests (Criterion)
├── bonus/                → Bonus code
├── resources/            → Resource files (instructions pdf, assets, etc...)
│
└── Makefile              → Build system controller
```

---

## 🔹 Compilation System

### Source Detection

Automatically detects all `.c` files excluding `main.c`.

```make
SRC = $(sort $(shell find sources -type f -name "*.c" ! -name "main.c"))
```

---

### Include Detection

Automatically includes all header directories.

```make
INCLUDES = $(sort $(addprefix -I,$(shell find includes -type d)))
```

---

### Library Detection

Automatically detects libraries inside `lib/`.

```make
LIBS_LIST = $(sort $(notdir $(shell find lib -mindepth 1 -maxdepth 1 -type d)))
```

---

### Library Linking

Only links compiled libraries:

```make
LIB_FLAGS = -l<libname>
```

---

### CSFML Support

When enabled:

```make
HAS_CSFML = true
```

Adds:

* `-lcsfml-graphics`
* `-lcsfml-window`
* `-lcsfml-system`
* `-lcsfml-audio`
* `-lm`

---

## 🔹 Build Rules

### Main Build

```bash
make
```

Steps:

1. Build libraries (`lib-build`)
2. Compile sources
3. Link binary (`$(NAME)`)

---

### Standard Commands

```bash
make clean     # Remove objects and temporary files
make fclean    # Full cleanup (binary + libs)
make re        # Rebuild everything
make run       # Build and execute
```

---

### Debug Build

```bash
make debug-asan
```

Enables:

* AddressSanitizer
* Frame pointer preservation

---

## 🔹 Library System

### Build Libraries

```bash
make lib-build
```

* Builds each module inside `lib/`
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

Uses:

* Criterion (`-lcriterion`)

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

Uses:

* LLVM coverage tools (`llvm-cov gcov`)
* gcovr filtering

---

### Style Check

```bash
make test-style
```

Uses:

* `epiclang` compiler

---

## 🔹 Git Integration

### Basic Commands

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

Commands:

```bash
make git-push-repo
make git-push-libs
make git-push-makefile
```

---

### Behavior Notes

* Push is disabled by default if `ALLOW_AUTO_PUSH=false`

---

## 🔹 Project Setup System

### Initialize Project

```bash
make setup-build
```

Copies:

* `.gitignore`
* Base project structure from `EPITECH_BASE_PATH`

---

### Destructive Reset

```bash
make setup-unbuild
```

⚠️ Requires:

```make
ALLOW_UNBUILD = true
```

Deletes everything inside the project

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

1. Removes existing library
2. Copies from base repository (`build_files`)
3. Copies headers into `includes/lib_includes/`
4. Optionally triggers git push

---

## 🔹 Build Flow

```
make
 ├── lib-build
 ├── compile sources
 └── link binary
```

---

## 🔹 Import Flow

```
setup-import-*
 ├── remove old library
 ├── copy new library
 ├── copy headers
 └── git push (if enabled)
```

---

## 🔹 Help System

### Main Help

```bash
make help
```

Displays grouped commands:

* build
* clean
* test
* git
* setup
* lib

---

## 🔹 Dependencies & Tools

* Clang compiler (`CC = clang`)
* Criterion for unit tests
* Valgrind for memory checking
* gcovr + llvm-cov for coverage
* Git CLI
* Optional CSFML libraries

---

## 🔹 Limitations

* Linux-oriented workflow
* Requires strict directory structure
* No versioning system for libraries
* Depends on external base repository path

---

## 🔹 Security Notes

* `setup-unbuild` is destructive
* Auto-push must be carefully enabled
* Library imports overwrite local state
* `EPITECH_BASE_PATH` must be valid

---

## 🔹 Best Practices

* Prefer `setup-import-*` over manual edits
* Keep `lib/` synchronized
* Avoid modifying imported libraries directly
* Use `DEBUG=true` for debugging builds
* Disable auto-push in shared environments

---

## 🔹 Notes

* Designed for EPITECH workflow automation
* Centralizes build + git + setup operations
* Scales from small projects to full frameworks
* Enforces modular architecture

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
