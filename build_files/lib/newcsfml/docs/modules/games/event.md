# 📦 Event Module (`nsf_event`)
#### part of [Games](overview.md)

Lightweight abstraction over SFML event handling, providing safer comparisons and helper accessors for keyboard and mouse-related input.

> Example:
> Handles event type checking, key comparison, and extraction of mouse movement / wheel data from SFML event polling.

---

## 🔹 Header

```c
#include <newcsfml/games/event.h>
```

---

## 🔹 Structure

```c
typedef sfEvent nsf_event_t;
```

### Description

| Field              | Type                      | Description                                          |
|--------------------|---------------------------|------------------------------------------------------|
| `type` (internal)  | `sfEventType`             | Event category (closed, key press, mouse move, etc.) |
| `key`              | `sfKeyEvent`              | Keyboard event data (code, modifiers)                |
| `mouseMove`        | `sfMouseMoveEvent`        | Mouse position data                                  |
| `mouseWheelScroll` | `sfMouseWheelScrollEvent` | Mouse wheel delta                                    |
| `...`              | `...`                     | Other SFML event payload fields                      |

---

## 🔹 Purpose

This module provides a thin but safe abstraction layer over SFML events.

* Standardizes event comparisons (type, key)
* Extracts mouse movement and wheel data safely
* Avoids direct SFML field access in higher-level systems
* Acts as a helper layer for input handling in `nsf_window`

It does **not replace SFML event system**, but simplifies its usage inside the engine architecture.

---

## 🔹 Dependencies

| Module            | Usage                            |
|-------------------|----------------------------------|
| `sfEvent` (CSFML) | Base event structure             |
| `nsf_keyboard`    | Key code abstraction             |
| `nsf_mouse`       | Mouse input mapping              |
| `nsf_vector`      | Mouse position output formatting |
| `nsf_window`      | Event polling integration        |

---

## 🔹 API

### Event Comparison

| Function                        | Description                                |
|---------------------------------|--------------------------------------------|
| `nsf_event_cmp(event, type)`    | Compare event type with `nsf_event_type_t` |
| `nsf_event_cmp_key(event, key)` | Compare keyboard event key code            |

---

### Mouse Input Access

| Function                               | Description                         |
|----------------------------------------|-------------------------------------|
| `nsf_event_get_mouse_move(event, out)` | Retrieve mouse movement coordinates |
| `nsf_event_get_mouse_wheel(event)`     | Get mouse wheel scroll delta        |

---

## 🔹 Parameters Reference

| Name         | Type               | Description                      |
|--------------|--------------------|----------------------------------|
| `event`      | `nsf_event_t *`    | SFML event instance              |
| `event_type` | `nsf_event_type_t` | Abstracted event type            |
| `key_code`   | `nsf_key_code_t`   | Abstracted keyboard key          |
| `out`        | `nsf_ivector_t[]`  | Output vector for mouse position |

---

## 🔹 Return Values

| Type        | Meaning                          |
|-------------|----------------------------------|
| `bool`      | True if match / valid comparison |
| `float`     | Mouse wheel delta                |
| `void`      | Output-based functions           |
| `false / 0` | Invalid or null input            |

---

## 🔹 Notes

* Direct SFML event structure is reused (no wrapper allocation)
* Always validate event pointer before usage
* Mouse helpers only extract data, they do not modify SFML state
* Designed for polling systems inside `nsf_window`
* Safe to use in tight input loops

---

## 🔹 Internal Files

| File                         | Role                                |
|------------------------------|-------------------------------------|
| `nsf_event_manage_compare.c` | Event type + key comparison logic   |
| `nsf_event_manage_get.c`     | Mouse movement and wheel extraction |

---

## 🔹 Related Modules

* `nsf_window`
* `nsf_keyboard`
* `nsf_mouse`
* `nsf_game`

---

## 🔹 CSFML Mapping (Optional)

| NSF                         | CSFML                            |
|-----------------------------|----------------------------------|
| `nsf_event_t`               | `sfEvent`                        |
| `nsf_event_cmp`             | `sfEvent.type` comparison        |
| `nsf_event_get_mouse_move`  | `sfEvent.mouseMove`              |
| `nsf_event_get_mouse_wheel` | `sfEvent.mouseWheelScroll.delta` |

---

## 🔹 Implementation Notes (for contributors)

* Keep event functions stateless (pure helpers)
* Do not extend SFML event structure manually
* Avoid allocations in event processing path
* Keep comparisons branch-light for performance
* Follow strict separation between compare and extract logic

---

## 🔹 Extension Points

* Add key press/release helpers (hold system abstraction)
* Add event buffering layer for input replay
* Add normalized mouse position relative to window/view
* Extend abstraction for joystick and touch input
* Add higher-level input mapping system (actions/binds)

---
