---
title: Epitech Base | Library | NewCSFML - Games - NSF_Keyboard
---
<link rel="icon" type="image/x-icon" href="https://raw.githubusercontent.com/Jarjarbin06/Epitech_Base/refs/heads/main/build_files/lib/newcsfml/resouces/NCSFML_logo_transparent.png">

# 📦 Keyboard Module (`nsf_keyboard`)
#### part of [Games](overview.md)

Low-level input abstraction module providing a clean wrapper over SFML keyboard handling.
It exposes a unified key enumeration and a simple API to query real-time key states.

> Example:
> Detects whether a specific key is currently pressed using a unified internal key mapping system.

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

| Field / Value       | Type | Description                                      |
|---------------------|------|--------------------------------------------------|
| `NSF_KEY_*`         | enum | Unified key representation independent from SFML |
| `NSF_KEY_A-Z`       | enum | Alphabet keys                                    |
| `NSF_KEY_0-9`       | enum | Numeric keys                                     |
| `NSF_KEY_F_*`       | enum | Function keys                                    |
| `NSF_KEY_L_* / R_*` | enum | Modifier keys (Ctrl, Shift, Alt, System)         |
| `NSF_KEY_*` arrows  | enum | Directional input keys                           |
| `NSF_KEY_COUNT`     | enum | Total number of supported keys                   |

---

## 🔹 Purpose

Keyboard module abstraction built on top of SFML input system.

* Provides a **portable and unified key mapping**
* Wraps `sfKeyboard_isKeyPressed` into a safe API
* Decouples game logic from SFML key codes
* Ensures consistent input handling across the engine

This module is part of the **input layer** in NCSFML and is typically used alongside the event system.

---

## 🔹 Dependencies

| Module      | Usage                                 |
|-------------|---------------------------------------|
| `sfml`      | Direct backend input query            |
| `nsf_event` | Often combined for event-driven input |
| `nsf_game`  | Input context in game loop (indirect) |

---

## 🔹 API

### Creation / Destruction

Not applicable (stateless module)

| Function | Description            |
|----------|------------------------|
| *(none)* | No allocation required |

---

### Core Functions

| Function                       | Description                          |
|--------------------------------|--------------------------------------|
| `nsf_keyboard_is_pressed(...)` | Checks if a key is currently pressed |

---

### Advanced / Optional

| Function | Description          |
|----------|----------------------|
| *(none)* | No advanced features |

---

## 🔹 Parameters Reference

| Name  | Type             | Description             |
|-------|------------------|-------------------------|
| `key` | `nsf_key_code_t` | Key identifier to check |

---

## 🔹 Return Values

| Type   | Meaning                  |
|--------|--------------------------|
| `bool` | `true` if key is pressed |
| `bool` | `false` otherwise        |

---

## 🔹 Notes

* This module is **stateless and lightweight**
* It directly maps `nsf_key_code_t → sfKeyCode`
* No memory allocation or internal state
* Should be used for **real-time polling input only**
* Prefer `nsf_event` for discrete input events

---

## 🔹 Internal Files

| File                              | Role               |
|-----------------------------------|--------------------|
| `nsf_keyboard_manage_key_press.c` | Key state querying |

---

## 🔹 Related Modules

* [`nsf_event` 🔗](event.md)
* [`nsf_window` 🔗](window.md)
* [`nsf_mouse` 🔗](mouse.md)

---

## 🔹 CSFML Mapping (Optional)

| NSF Function              | CSFML Equivalent          |
|---------------------------|---------------------------|
| `nsf_keyboard_is_pressed` | `sfKeyboard_isKeyPressed` |
| `nsf_key_code_t`          | `sfKeyCode`               |

---

## 🔹 Implementation Notes (for contributors)

* Keep mapping strictly aligned with SFML `sfKeyCode`
* Do not introduce engine-side key remapping here
* Avoid adding state (module must remain stateless)
* Ensure enum completeness matches SFML version used
* Keep function inline-friendly if possible for performance

---

## 🔹 Extension Points

* Add key remapping layer (optional higher abstraction module)
* Add input buffering system (for gameplay systems)
* Add support for combination keys (Ctrl + key, etc.)
* Extend to gamepad abstraction layer if needed

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
