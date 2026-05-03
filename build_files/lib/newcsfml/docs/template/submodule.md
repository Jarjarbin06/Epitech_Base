# 📦 `<Module / Structure Name>`

Short description of the module.

> Example:
> Handles sprite rendering, transformation, and texture binding.

---

## 🔹 Header

```c
#include <newcsfml/<category>/<file>.h>
```

---

## 🔹 Structure

```c
typedef struct {
    // fields
} nsf_<name>_t;
```

### Description

| Field        | Type   | Description |
|--------------|--------|-------------|
| `field_name` | `type` | Explanation |
| `...`        | `...`  | ...         |

---

## 🔹 Purpose

Concise explanation of what this structure is responsible for.

* Main responsibility
* What it abstracts (CSFML equivalent if relevant)
* Where it fits in the architecture

---

## 🔹 Dependencies

| Module        | Usage               |
|---------------|---------------------|
| `nsf_texture` | Used for rendering  |
| `nsf_window`  | Draw target         |
| `nsf_game`    | Allocation tracking |

---

## 🔹 API

### Creation / Destruction

| Function                  | Description           |
|---------------------------|-----------------------|
| `nsf_<name>_create(...)`  | Create a new instance |
| `nsf_<name>_destroy(...)` | Destroy and free      |

---

### Core Functions

| Function                         | Description           |
|----------------------------------|-----------------------|
| `nsf_<name>_set_<property>(...)` | Set property          |
| `nsf_<name>_get_<property>(...)` | Get property          |
| `nsf_<name>_update(...)`         | Update internal state |
| `nsf_<name>_draw(...)`           | Render object         |

---

### Advanced / Optional

| Function                    | Description        |
|-----------------------------|--------------------|
| `nsf_<name>_<feature>(...)` | Advanced behavior  |
| `nsf_<name>_<feature>(...)` | Additional feature |

---

## 🔹 Parameters Reference

| Name     | Type              | Description        |
|----------|-------------------|--------------------|
| `name`   | `const char *`    | Identifier         |
| `game`   | `nsf_game_t *`    | Allocation context |
| `window` | `nsf_window_t *`  | Render target      |
| `pos`    | `nsf_fvector_t *` | Position           |
| `...`    | `...`             | ...                |

---

## 🔹 Return Values

| Type      | Meaning                    |
|-----------|----------------------------|
| `pointer` | Valid object               |
| `NULL`    | Error / allocation failure |
| `int`     | Status code                |
| `bool`    | Success / failure          |

---

## 🔹 Notes

* Uses `nsf_game_t` for memory tracking
* Avoid direct CSFML usage
* All objects should be registered if required
* Naming should remain consistent (`nsf_<module>_<action>`)

---

## 🔹 Internal Files

| File                   | Role                      |
|------------------------|---------------------------|
| `nsf_<name>_struct.c`  | Structure initialization  |
| `nsf_<name>_manage*.c` | Logic / setters / getters |
| `nsf_<name>_draw.c`    | Rendering                 |
| `...`                  | ...                       |

---

## 🔹 Related Modules

* `nsf_<related_module>`
* `nsf_<related_module>`

---

## 🔹 CSFML Mapping (Optional)

| NSF               | CSFML                       |
|-------------------|-----------------------------|
| `nsf_<name>_t`    | `sf<Type>`                  |
| `nsf_<name>_draw` | `sfRenderWindow_draw<Type>` |

---

## 🔹 Implementation Notes (for contributors)

* Respect modular split (`manage`, `draw`, `struct`)
* No cross-module logic leakage
* Keep functions small and focused
* Follow Epitech C coding style

---

## 🔹 Extension Points

* Add new behaviors in `manage` files
* Extend struct carefully (keep ABI stable if needed)
* Avoid breaking API consistency

---
