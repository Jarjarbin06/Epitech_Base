# 📦 Event Module (`nsf_event`)
#### part of [Games](overview.md)

Provides a lightweight abstraction over CSFML events, including input handling, event comparison, and mouse utilities.

> Example:
> Allows safe event filtering (keyboard, mouse, window events) without directly exposing SFML event structures.

---

## 🔹 Header

```c
#include <newcsfml/games/event.h>
```

---

## 🔹 Union

```c
typedef sfEvent nsf_event_t;
```

### Description

| Field              | Type                      | Description                                             |
|--------------------|---------------------------|---------------------------------------------------------|
| `type`             | `sfEventType`             | Event category (closed, key pressed, mouse moved, etc.) |
| `key`              | `sfKeyEvent`              | Keyboard event data                                     |
| `mouseMove`        | `sfMouseMoveEvent`        | Mouse position data                                     |
| `mouseWheelScroll` | `sfMouseWheelScrollEvent` | Mouse wheel delta                                       |
| `...`              | `...`                     | Other SFML event variants                               |

---

## 🔹 Purpose

This module wraps SFML events to provide:

* Safe comparison utilities
* Simplified keyboard and mouse handling
* Lightweight abstraction over raw `sfEvent`

It sits at the **input layer of the framework**, used mainly by the game and window systems to interpret user interactions.

---

## 🔹 Dependencies

| Module                  | Usage                          |
|-------------------------|--------------------------------|
| `SFML/Window/Event.h`   | Base event system              |
| `SFML/System/Vector2.h` | Mouse position vectors         |
| `nsf_systems/vector`    | Vector copying utilities       |
| `nsf_systems/utils`     | Safety macros (`NSF_UNLIKELY`) |

---

## 🔹 API

### Event Comparison

| Function                        | Description                                   |
|---------------------------------|-----------------------------------------------|
| `nsf_event_cmp(event, type)`    | Checks if event matches a specific event type |
| `nsf_event_cmp_key(event, key)` | Checks if keyboard event matches a key        |

---

### Mouse Utilities

| Function                               | Description                         |
|----------------------------------------|-------------------------------------|
| `nsf_event_get_mouse_move(event, out)` | Retrieves mouse position from event |
| `nsf_event_get_mouse_wheel(event)`     | Retrieves mouse wheel delta         |

---

## 🔹 Parameters Reference

| Name         | Type                  | Description                    |
|--------------|-----------------------|--------------------------------|
| `event`      | `const nsf_event_t *` | Input event reference          |
| `event_type` | `nsf_event_type_t`    | Event category to compare      |
| `key_code`   | `nsf_key_code_t`      | Key identifier                 |
| `out`        | `nsf_ivector_t[]`     | Output vector (mouse position) |

---

## 🔹 Return Values

| Type    | Meaning                   |
|---------|---------------------------|
| `bool`  | Event matches condition   |
| `float` | Mouse wheel delta         |
| `void`  | Output filled via pointer |

---

## 🔹 Notes

* Always validate event pointers before usage (already handled internally where needed)
* Event comparisons rely on direct SFML enum casting
* Mouse utilities do not allocate memory
* Output vectors must be preallocated before calling `nsf_event_get_mouse_move`

---

## 🔹 Internal Files

| File                 | Role                         |
|----------------------|------------------------------|
| `nsf_event_manage.c` | Event comparison + utilities |

---

## 🔹 Related Submodules

* [`nsf_game` 🔗](game.md)
* [`nsf_window` 🔗](window.md)
* [`nsf_vector` 🔗](../systems/vector.md)

---

## 🔹 CSFML Mapping (Optional)

| NSF                | CSFML         |
|--------------------|---------------|
| `nsf_event_t`      | `sfEvent`     |
| `nsf_key_code_t`   | `sfKeyCode`   |
| `nsf_event_type_t` | `sfEventType` |

---

## 🔹 Implementation Notes (for contributors)

* Event handling must remain **stateless**
* Never store `sfEvent` pointers long-term
* Keep comparison functions pure (no side effects)
* Avoid exposing SFML-specific logic outside this module
* Use safe guards (`NSF_UNLIKELY`) for all external inputs

---

## 🔹 Extension Points

* Add joystick helpers in a future manage file
* Extend key/mouse utilities without modifying structure
* Wrap additional SFML event types if needed (touch, sensors)

---
