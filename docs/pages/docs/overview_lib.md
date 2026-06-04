---
title: Libraries
sidebar: sidebar
permalink: overview_lib.html
folder: docs
---
# 📦 Epitech Base Libraries

> Collection of reusable C libraries designed for EPITECH projects, focusing on modularity, consistency, and structured development.

---

## 🔹 Short Description

**Epitech Base is a centralized repository containing multiple reusable C libraries, ranging from low-level utilities to higher-level frameworks such as NewCSFML.**  
Each library is designed with a consistent architecture, clear API design, and compatibility with EPITECH project standards.

---

## 🔹 Authors

* Nathan (Jarjarbin06)
* EPITECH Project

---

## 🔹 Licence

GPL v3 across the full repo libraries

---

## 🔹 Target Audience

This repository is designed for:

* EPITECH students
* C developers building modular projects
* Developers needing reusable utility libraries
* Game developers using CSFML abstractions

---

## 🔹 Purpose

This repository centralizes commonly used libraries to:

* Avoid code duplication across projects
* Provide consistent APIs and coding patterns
* Improve development speed and maintainability
* Offer modular and reusable components
* Standardize internal tooling and utilities

---

## 🔹 Repository Architecture

```

build_files/
├── lib/        → All reusable libraries
└── tree/       → Repo template

```

Each library follows a structured layout:

```

includes/   → Public headers
sources/    → Implementation
docs/       → Documentation (if available)
README.md   → Description (if no docs/)
Makefile    → Compilation and cleanup 

````

---

## 🔹 Libraries Overview

### 🎮 Frameworks

#### NewCSFML Library (NCSFML)

> High-level wrapper over CSFML for structured game development

* Modular architecture (graphics, audio, systems, game)
* Memory-safe via `nsf_game_t`
* Simplified rendering and event handling
* Logging implementation across whole library

📖 Documentation:  
→ [NewCSFML Documentation](../../../docs_2/lib/newcsfml/README.md)

---

### 🧱 Core Utility Libraries

#### NewError Library (NERROR)

> Structured error handling library

* Error management
* Custom error systems

📖 Entry point:  
→ [NewError README](../../../docs_2/lib/newerror/README.md)

---

#### Utils Library (UTILS)

> General-purpose helper functions

📖 Entry point:  
→ [Utils README](../../../docs_2/lib/utils/README.md)

---

#### Print Library (PRINT)

> Custom formatted output system

* Conversion system
* Modular formatting

📖 Entry point:  
→ [Print README](../../../docs_2/lib/print/README.md)

---

### 📦 Data Structures

#### Flag Library (FLAG)

> Easy to use file reader

* Customisable flag
* Easy to use
* Fast fetch and auto handling

📖 Entry point:  
→ [Flag README](../../../docs_2/lib/flag/README.md)

---

#### File Library (FILE)

> Command argument (flag) handler

* Auto file reader
* Manual/custom file reader

📖 Entry point:  
→ [File README](../../../docs_2/lib/file/README.md)

---

#### String Library (STR)

> String manipulation utilities

* Transformations
* Checks and validations
* String operations

📖 Entry point:  
→ [Str README](../../../docs_2/lib/str/README.md)

---

#### Linked List Library (LLIST)

> Generic linked list implementation

📖 Entry point:  
→ [LList README](../../../docs_2/lib/llist/README.md)

---

#### Two-Dimensional List Library (TWODLIST)

> Advanced list structure for complex data layouts

📖 Entry point:  
→ [TwoDList README](../../../docs_2/lib/twodlist/README.md)

---

### 🧪 Testing

#### test_lib

> Internal testing and experimentation folder

---
### 🧩 Project Template

#### Tree

> Base project template used as a foundation for new repositories

* Provides a standardized project structure
* Includes base Makefile integration
* Designed to be copied into new projects
* Supports extensible layouts (including bonus structure and lib import Makefile rules)

---

## 🔹 Build System

Each library provide its own build system.

### Common commands

```bash
make
make clean
make fclean
make re
````

---

## 🔹 Installation

No global installer is provided.

Usage pattern:

1. Navigate to the desired library
2. Build it using its Makefile
3. Link it to your project

Example:

```bash
cd build_files/lib/str
make
```

---

## 🔹 Design Philosophy

* Modular and independent libraries
* Consistent naming conventions
* Clear separation of responsibilities
* Minimal abstraction overhead
* Focus on maintainability and reuse

---

## 🔹 Documentation Access

Each library exposes its own documentation:

* Libraries with `docs/` → start from `docs/README.md`
* Libraries without docs → use root directory as entry point

---

## 🔹 Current State

⚠️ Repository is **actively evolving**

Status:

* Core libraries implemented
* NewCSFML under active development
* Utilities stable and reusable
* Documentation progressively improving

---

## 🔹 Notes

* Designed primarily for EPITECH workflow
* Libraries are independent but interoperable
* Not intended as a monolithic framework
* Encourages clean and scalable project architecture
