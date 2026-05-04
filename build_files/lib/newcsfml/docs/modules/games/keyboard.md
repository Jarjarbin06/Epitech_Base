# 📦 Event Module (`nsf_keyboard`)
#### part of [Games](overview.md)

Provides a lightweight abstraction over CSFML keyboard.

> Example:
> Allows safe keyboard handling without directly exposing SFML keyboard structures.

---

## 🔹 Header

```c
#include <newcsfml/games/keyboard.h>
```

---

## 🔹 Structure

```c
typedef enum nsf_key_code_e {
    NSF_KEY_UNKNOWN = -1,
    NSF_KEY_A,
    NSF_KEY_B,
    NSF_KEY_C,
    NSF_KEY_D,
    NSF_KEY_E,
    NSF_KEY_F,
    NSF_KEY_G,
    NSF_KEY_H,
    NSF_KEY_I,
    NSF_KEY_J,
    NSF_KEY_K,
    NSF_KEY_L,
    NSF_KEY_M,
    NSF_KEY_N,
    NSF_KEY_O,
    NSF_KEY_P,
    NSF_KEY_Q,
    NSF_KEY_R,
    NSF_KEY_S,
    NSF_KEY_T,
    NSF_KEY_U,
    NSF_KEY_V,
    NSF_KEY_W,
    NSF_KEY_X,
    NSF_KEY_Y,
    NSF_KEY_Z,
    NSF_KEY_0,
    NSF_KEY_1,
    NSF_KEY_2,
    NSF_KEY_3,
    NSF_KEY_4,
    NSF_KEY_5,
    NSF_KEY_6,
    NSF_KEY_7,
    NSF_KEY_8,
    NSF_KEY_9,
    NSF_KEY_ESCAPE,
    NSF_KEY_L_CONTROL,
    NSF_KEY_L_SHIFT,
    NSF_KEY_L_ALT,
    NSF_KEY_L_SYSTEM,
    NSF_KEY_R_CONTROL,
    NSF_KEY_R_SHIFT,
    NSF_KEY_R_ALT,
    NSF_KEY_R_SYSTEM,
    NSF_KEY_MENU,
    NSF_KEY_L_BRACKET,
    NSF_KEY_R_BRACKET,
    NSF_KEY_SEMICOLON,
    NSF_KEY_COMMA,
    NSF_KEY_PERIOD,
    NSF_KEY_APOSTROPHE,
    NSF_KEY_SLASH,
    NSF_KEY_BACKSLASH,
    NSF_KEY_GRAVE,
    NSF_KEY_EQUAL,
    NSF_KEY_HYPHEN,
    NSF_KEY_SPACE,
    NSF_KEY_ENTER,
    NSF_KEY_BACKSPACE,
    NSF_KEY_TAB,
    NSF_KEY_PAGE_UP,
    NSF_KEY_PAGE_BOWN,
    NSF_KEY_END,
    NSF_KEY_HOME,
    NSF_KEY_INSERT,
    NSF_KEY_DELETE,
    NSF_KEY_ADD,
    NSF_KEY_SUBTRACT,
    NSF_KEY_MULTIPLY,
    NSF_KEY_DIVIDE,
    NSF_KEY_LEFT,
    NSF_KEY_RIGHT,
    NSF_KEY_UP,
    NSF_KEY_DOWN,
    NSF_KEY_NP_0,
    NSF_KEY_NP_1,
    NSF_KEY_NP_2,
    NSF_KEY_NP_3,
    NSF_KEY_NP_4,
    NSF_KEY_NP_5,
    NSF_KEY_NP_6,
    NSF_KEY_NP_7,
    NSF_KEY_NP_8,
    NSF_KEY_NP_9,
    NSF_KEY_F_1,
    NSF_KEY_F_2,
    NSF_KEY_F_3,
    NSF_KEY_F_4,
    NSF_KEY_F_5,
    NSF_KEY_F_6,
    NSF_KEY_F_7,
    NSF_KEY_F_8,
    NSF_KEY_F_9,
    NSF_KEY_F_10,
    NSF_KEY_F_11,
    NSF_KEY_F_12,
    NSF_KEY_F_13,
    NSF_KEY_F_14,
    NSF_KEY_F_15,
    NSF_KEY_PAUSE,
    NSF_KEY_COUNT
} nsf_key_code_t;
```

### Description

| Field  | Type        | Description                                             |
|--------|-------------|---------------------------------------------------------|
| `type` | `sfKeyCode` | Event category (closed, key pressed, mouse moved, etc.) |

---

## 🔹 Purpose

This module wraps SFML keyboard to provide:

* Safe key state checks
* Simplified keyboard handling
* Lightweight abstraction over raw `sfKeyCode`

It sits at the **keyboard input layer of the framework**, used mainly by the window systems to interpret advanced user interactions.

---

## 🔹 Dependencies

| Module                   | Usage                          |
|--------------------------|--------------------------------|
| `SFML/Window/Keyboard.h` | Base keyboard system           |

---

## 🔹 API

### Event Comparison

| Function                       | Description              |
|--------------------------------|--------------------------|
| `nsf_keyboard_is_pressed(key)` | Checks if key is pressed |

---

## 🔹 Parameters Reference

| Name  | Type             | Description                    |
|-------|------------------|--------------------------------|
| `key` | `nsf_key_code_t` | Event category to compare      |

---

## 🔹 Return Values

| Type    | Meaning     |
|---------|-------------|
| `bool`  | Key pressed |

---

## 🔹 Notes

* Keyboard comparisons rely on direct SFML enum casting

---

## 🔹 Internal Files

| File                    | Role               |
|-------------------------|--------------------|
| `nsf_keyboard_manage.c` | Keyboard utilities |

---

## 🔹 Related Submodules

* [`nsf_event` 🔗](event.md)
* [`nsf_game` 🔗](game.md)
* [`nsf_window` 🔗](window.md)

---

## 🔹 CSFML Mapping (Optional)

| NSF              | CSFML       |
|------------------|-------------|
| `nsf_key_code_t` | `sfKeyCode` |

---

## 🔹 Implementation Notes (for contributors)

* Keyboard handling must remain **stateless**
* Never store `sfKeyboard` pointers long-term
* Avoid exposing SFML-specific logic outside this module

---

## 🔹 Extension Points

* Extend key utilities without modifying structure

---
