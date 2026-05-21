# 📦 `<Module Name>`

Short description of the module.

> Example:
> Provides core functionalities for handling game windows, events, and lifecycle management.

---

## 🔹 Header

```c
#include <newcsfml/<category>/<module>.h>
````

---

## 🔹 Overview

| Submodule       | Role         |
|-----------------|--------------|
| `<submodule_1>` | Handles ...  |
| `<submodule_2>` | Manages ...  |
| `<submodule_3>` | Provides ... |

---

## 🔹 Purpose

Concise explanation of the module’s responsibility inside the framework.

* What it abstracts from CSFML
* What problem it solves
* Why it exists in the architecture

---

## 🔹 Architecture

### Internal Composition

```
<module>
├── <submodule_1>
├── <submodule_2>
└── <submodule_3>
```

### Flow (optional)

```
User → Module API → Internal Systems → CSFML Wrapper → Rendering/Audio/etc
```

---

## 🔹 Dependencies

| Module         | Usage                         |
|----------------|-------------------------------|
| `nsf_game`     | Global context / ownership    |
| `nsf_systems`  | Utilities / vectors / colors  |
| `nsf_graphics` | Rendering support (if needed) |
| `CSFML`        | Low-level backend             |

---

## 🔹 Key Responsibilities

* Main responsibility of the module
* What it manages internally
* What it exposes to the user
* What it must NOT handle

---

## 🔹 Submodules

| Submodule  | Description |
|------------|-------------|
| `<file_1>` | Handles ... |
| `<file_2>` | Handles ... |
| `<file_3>` | Handles ... |

---

## 🔹 Public API Summary

### High-Level Functions

| Function                 | Description          |
|--------------------------|----------------------|
| `nsf_<module>_create()`  | Initialize module    |
| `nsf_<module>_destroy()` | Cleanup module       |
| `nsf_<module>_update()`  | Update logic         |
| `nsf_<module>_draw()`    | Render if applicable |

---

### Subsystem APIs

| Subsystem       | Example Function           |
|-----------------|----------------------------|
| `<submodule_1>` | `nsf_<module>_<feature>()` |
| `<submodule_2>` | `nsf_<module>_<feature>()` |

---

## 🔹 Usage Example

```c
nsf_<module>_t *module = nsf.<module>.create();

nsf.<module>.update(module);
nsf.<module>.draw(module);
```

---

## 🔹 Data Flow

| Step | Action                               |
|------|--------------------------------------|
| 1    | Initialization via `create()`        |
| 2    | Registration into `game` (if needed) |
| 3    | Runtime update loop                  |
| 4    | Rendering / processing               |
| 5    | Cleanup via `destroy()`              |

---

## 🔹 Design Constraints

* Must remain independent from unrelated modules
* Must use `nsf_game_t` when memory tracking is required
* Must avoid direct CSFML exposure
* Must remain lightweight and composable

---

## 🔹 Common Patterns

* Creation → Register → Update → Draw → Destroy
* Name-based retrieval
* Centralized ownership via `game`

---

## 🔹 Known Limitations

* `<limitation_1>`
* `<limitation_2>`
* `<limitation_3>`

---

## 🔹 Documentation Index

This section provides quick access to the module documentation.
Detailed behavior and API are described within each submodule.

### Submodules

* [`<submodule_1>`](<submodule_1>.md) — Short description of the submodule
* [`<submodule_2>`](<submodule_2>.md) — Short description of the submodule
* [`<submodule_3>`](<submodule_3>.md) — Short description of the submodule

---

## 🔹 Related Modules

* `nsf_<related_module_1>`
* `nsf_<related_module_2>`
* `nsf_<related_module_3>`

---

## 🔹 Notes

* This module is part of the core framework architecture
* It is designed to stay modular and replaceable
* Avoid tight coupling with other systems

---

## 🔹 Internal Files

| File                 | Role                            |
|----------------------|---------------------------------|
| `<module>_struct.c`  | Data structures                 |
| `<module>_manage*.c` | Logic implementation            |
| `<module>_draw.c`    | Rendering logic (if applicable) |
| `<module>_utils.c`   | Helpers                         |

---

## 🔹 Extension Guidelines

* Add new features in dedicated `manage` files
* Keep API consistent with `nsf_<module>_<action>`
* Avoid breaking public API
* Prefer composition over modification

---

<div align="center">

## 📦 Epitech Base — Footer

</div>
<div align="center">

<img src="https://raw.githubusercontent.com/Jarjarbin06/Epitech_Base/refs/heads/main/docs/EpitechBaseLogo.png" width="120"  alt="Epitech Base Logo"/>

Epitech Base • Modular C Ecosystem

Libraries:\
• `file` - `v0.1.2`\
• `flag` - `v0.1.1`\
• `llist` - `v0.0.0`\
• `newcsfml` - `v0.2.7`\
• `newerror` - `v0.1.1`\
• `print` - `v0.1.5`\
• `str` - `v0.1.5`\
• `print` - `v0.0.0`\
• `twodlist` - `v0.1.5`\
• `utils` - `v0.1.5`

Author: Nathan (Jarjarbin06) • EPITECH  
Licence: GPL v3\
Repository: [Epitech Base](https://github.com/Jarjarbin06/Epitech_Base)
</div>

---
