# 📦 Mouse Module (`nsf_mouse`)
#### part of [Games](overview.md)

Low-level input abstraction module providing a unified enumeration for mouse buttons within the NCSFML system.
It is designed to standardize mouse input handling across the engine while remaining fully compatible with SFML.

> Example:
> Provides a consistent mouse button enumeration used for input processing and event handling abstraction.

---

## 🔹 Header

```c
#include <newcsfml/games/mouse.h>
```

---

## 🔹 Structure

```c
typedef enum nsf_mouse_button_e {
    NSF_MSE_UNKNOWN = -1,
    NSF_MSE_LEFT,
    NSF_MSE_RIGHT,
    NSF_MSE_MIDDLE,
    NSF_MSE_X_BTTN_1,
    NSF_MSE_X_BTTN_2,
    NSF_MSE_COUNT
} nsf_mouse_button_t;
```

### Description

| Field              | Type | Description                             |
|--------------------|------|-----------------------------------------|
| `NSF_MSE_UNKNOWN`  | enum | Undefined or invalid mouse button       |
| `NSF_MSE_LEFT`     | enum | Left mouse button                       |
| `NSF_MSE_RIGHT`    | enum | Right mouse button                      |
| `NSF_MSE_MIDDLE`   | enum | Middle mouse button (scroll click)      |
| `NSF_MSE_X_BTTN_1` | enum | Additional mouse button 1               |
| `NSF_MSE_X_BTTN_2` | enum | Additional mouse button 2               |
| `NSF_MSE_COUNT`    | enum | Total number of supported mouse buttons |

---

## 🔹 Purpose

Mouse input abstraction layer built on top of SFML mouse system.

* Provides a **unified and engine-specific mouse button enumeration**
* Abstracts SFML mouse constants into a controlled internal type system
* Serves as a base for event handling and input processing modules
* Ensures consistency across all input-related subsystems

This module is part of the **input layer** in NCSFML and is typically used alongside `nsf_event` and `nsf_keyboard`.

---

## 🔹 Dependencies

| Module       | Usage                                              |
|--------------|----------------------------------------------------|
| `sfml`       | Backend mouse input handling                       |
| `nsf_event`  | Mouse event processing abstraction                 |
| `nsf_window` | Window-relative mouse position handling (indirect) |

---

## 🔹 API

### Creation / Destruction

Not applicable (stateless enumeration module)

| Function | Description                    |
|----------|--------------------------------|
| *(none)* | No runtime allocation required |

---

### Core Functions

| Function | Description                                 |
|----------|---------------------------------------------|
| *(none)* | Mouse input is handled via SFML/event layer |

---

### Advanced / Optional

| Function | Description             |
|----------|-------------------------|
| *(none)* | No advanced API defined |

---

## 🔹 Parameters Reference

| Name     | Type | Description                    |
|----------|------|--------------------------------|
| *(none)* | -    | This module defines only types |

---

## 🔹 Return Values

| Type | Meaning                                        |
|------|------------------------------------------------|
| enum | Mouse button identifier                        |
| int  | Internal numeric representation (SFML mapping) |

---

## 🔹 Notes

* This module is purely a **type abstraction layer**
* No runtime logic or memory allocation is involved
* Values are designed to map directly to `sfMouseButton`
* Intended to be used in event comparison and input systems
* Should not contain game-specific logic or state

---

## 🔹 Internal Files

| File     | Role              |
|----------|-------------------|
| *(none)* | No internal files |

---

## 🔹 Related Modules

* `nsf_event` — mouse event detection and processing
* `nsf_keyboard` — complementary keyboard input system
* `nsf_window` — window context for mouse position handling

---

## 🔹 CSFML Mapping (Optional)

| NSF                  | CSFML           |
|----------------------|-----------------|
| `nsf_mouse_button_t` | `sfMouseButton` |
| `NSF_MSE_LEFT`       | `sfMouseLeft`   |
| `NSF_MSE_RIGHT`      | `sfMouseRight`  |
| `NSF_MSE_MIDDLE`     | `sfMouseMiddle` |

---

## 🔹 Implementation Notes (for contributors)

* Keep enum strictly synchronized with SFML mouse button definitions
* Do not introduce behavior or logic in this module
* Maintain minimal and stable ABI for cross-module usage
* Ensure naming consistency with other input modules (`nsf_key_code_t`, etc.)

---

## 🔹 Extension Points

* Add mouse wheel abstraction layer (if extended beyond event system)
* Add high-level input helper module (click detection, drag system)
* Extend into full input state manager (keyboard + mouse unified API)
* Add support for custom input devices (future scope)

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
Repository: <a href="https://github.com/Jarjarbin06/Epitech_Base">Epitech Base</a>
</div>

---
