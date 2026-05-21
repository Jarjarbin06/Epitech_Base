# 📦 `<Submodule Name>` (`nsf_<name>`)
#### part of [Category](overview.md)

Short description of the submodule.

> Example:
> Handles input events, state tracking, and low-level interaction logic.

---

## 🔹 Header

```c
#include <newcsfml/<category>/<file>.h>
```

---

## 🔹 Structure

```c
typedef struct nsf_<name>_s {
    // fields
} nsf_<name>_t;
```

### Description

| Field | Type  | Description |
|-------|-------|-------------|
| `...` | `...` | ...         |

---

## 🔹 Purpose

This submodule is responsible for `<main responsibility>`.

* Main responsibility: `<describe responsibility>`
* Abstracts: `<CSFML / internal systems if any>`
* Architecture role: `<where it fits in the engine>`

---

## 🔹 Dependencies

| Module    | Usage |
|-----------|-------|
| `nsf_...` | ...   |
| `nsf_...` | ...   |

---

## 🔹 API

### Creation / Destruction

| Function                  | Description |
|---------------------------|-------------|
| `nsf_<name>_create(...)`  | ...         |
| `nsf_<name>_destroy(...)` | ...         |

---

### Core Functions

| Function                         | Description |
|----------------------------------|-------------|
| `nsf_<name>_set_<property>(...)` | ...         |
| `nsf_<name>_get_<property>(...)` | ...         |
| `nsf_<name>_update(...)`         | ...         |
| `nsf_<name>_handle(...)`         | ...         |
| `nsf_<name>_is_<state>(...)`     | ...         |

---

### Advanced / Optional

| Function                    | Description |
|-----------------------------|-------------|
| `nsf_<name>_<feature>(...)` | ...         |
| `nsf_<name>_<feature>(...)` | ...         |

---

## 🔹 Parameters Reference

| Name  | Type  | Description |
|-------|-------|-------------|
| `...` | `...` | ...         |

---

## 🔹 Return Values

| Type      | Meaning |
|-----------|---------|
| `pointer` | ...     |
| `NULL`    | ...     |
| `int`     | ...     |
| `bool`    | ...     |

---

## 🔹 Notes

* `<important rule 1>`
* `<important rule 2>`
* `<constraint or behavior>`
* Follow Epitech C coding style

---

## 🔹 Internal Files

| File                   | Role |
|------------------------|------|
| `nsf_<name>_struct.c`  | ...  |
| `nsf_<name>_manage*.c` | ...  |
| `nsf_<name>_update.c`  | ...  |
| `nsf_<name>_draw.c`    | ...  |
| `...`                  | ...  |

---

## 🔹 Related Submodules

* [`nsf_...`](...)
* [`nsf_...`](...)

---

## 🔹 CSFML Mapping (Optional)

| NSF                | CSFML   |
|--------------------|---------|
| `nsf_<name>_t`     | `sf...` |
| `nsf_<name>_<api>` | `sf...` |

---

## 🔹 Implementation Notes (for contributors)

* Keep separation between `struct / manage / update / draw`
* Avoid cross-module logic
* Keep functions small and focused
* Validate all pointers before use
* Do not bypass abstraction layers

---

## 🔹 Extension Points

* Add new behaviors in `manage` files
* Extend struct carefully (ABI stability if needed)
* Add optional systems without breaking API
* Keep backward compatibility when possible

---

<div align="center">

## 📦 Epitech Base — Footer

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
