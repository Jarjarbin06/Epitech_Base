---
title: Epitech Base | Library | NewCSFML - Games - NSF_Joystick
---
<link rel="icon" type="image/x-icon" href="https://raw.githubusercontent.com/Jarjarbin06/Epitech_Base/refs/heads/main/build_files/lib/newcsfml/resouces/NCSFML_logo_transparent.png">

# 📦 Joystick Module (`nsf_joystick`)
#### part of [Games](overview.md)

Input abstraction layer built on top of SFML joystick system.
It provides a unified Xbox-style mapping for axes and buttons, plus a high-level update system for polling joystick state.

> Example:
> Handles controller connection detection, axis normalization, and button state polling in a single structured object.

---

## 🔹 Header

```c
#include <newcsfml/games/joystick.h>
```

---

## 🔹 Structure

```c
typedef struct nsf_joystick_s {
    sfBool connected;
    nsf_joystick_id_t id;
    float axes[NSF_JOYSTICK_AXIS_XBOX_COUNT];
    sfBool buttons[NSF_JOYSTICK_BUTTON_XBOX_COUNT];
} nsf_joystick_xbox_t;
```

### Description

| Field       | Type                | Description                            |
|-------------|---------------------|----------------------------------------|
| `connected` | `sfBool`            | Whether a joystick is currently active |
| `id`        | `nsf_joystick_id_t` | SFML joystick index (0–7)              |
| `axes`      | `float[]`           | Cached axis values (Xbox mapping)      |
| `buttons`   | `sfBool[]`          | Cached button states (Xbox mapping)    |

---

## 🔹 Purpose

Provides a simplified and Xbox-oriented abstraction over SFML joystick API.

* Detects connected controllers automatically
* Converts raw SFML axis inputs into a structured Xbox layout
* Stores button and axis states for fast access
* Reduces direct dependency on SFML joystick calls

---

## 🔹 Dependencies

| Module       | Usage                       |
|--------------|-----------------------------|
| `sfJoystick` | Low-level hardware input    |
| `nsf_utils`  | Logging and error reporting |

---

## 🔹 Axis Mapping (Xbox Layout)

| Axis Enum                    | Meaning            |
|------------------------------|--------------------|
| `NSF_JOYSTICK_XBOX_LSTICK_X` | Left stick X-axis  |
| `NSF_JOYSTICK_XBOX_LSTICK_Y` | Left stick Y-axis  |
| `NSF_JOYSTICK_XBOX_RSTICK_X` | Right stick X-axis |
| `NSF_JOYSTICK_XBOX_RSTICK_Y` | Right stick Y-axis |
| `NSF_JOYSTICK_XBOX_LTRIGGER` | Left trigger       |
| `NSF_JOYSTICK_XBOX_RTRIGGER` | Right trigger      |
| `NSF_JOYSTICK_XBOX_DPAD_X`   | D-Pad horizontal   |
| `NSF_JOYSTICK_XBOX_DPAD_Y`   | D-Pad vertical     |

---

## 🔹 Button Mapping (Xbox Layout)

| Button Enum                      | Meaning           |
|----------------------------------|-------------------|
| `NSF_JOYSTICK_BUTTON_XBOX_A`     | A button          |
| `NSF_JOYSTICK_BUTTON_XBOX_B`     | B button          |
| `NSF_JOYSTICK_BUTTON_XBOX_X`     | X button          |
| `NSF_JOYSTICK_BUTTON_XBOX_Y`     | Y button          |
| `NSF_JOYSTICK_BUTTON_XBOX_LB`    | Left bumper       |
| `NSF_JOYSTICK_BUTTON_XBOX_RB`    | Right bumper      |
| `NSF_JOYSTICK_BUTTON_XBOX_BACK`  | Back button       |
| `NSF_JOYSTICK_BUTTON_XBOX_START` | Start button      |
| `NSF_JOYSTICK_BUTTON_XBOX_LS`    | Left stick click  |
| `NSF_JOYSTICK_BUTTON_XBOX_RS`    | Right stick click |

---

## 🔹 API

### Connection

| Function                        | Description                    |
|---------------------------------|--------------------------------|
| `nsf_joystick_is_connected(id)` | Check if joystick is connected |

---

### Input Reading

| Function                                     | Description                  |
|----------------------------------------------|------------------------------|
| `nsf_joystick_get_axis_position(id, axis)`   | Get axis value (-100 to 100) |
| `nsf_joystick_is_button_pressed(id, button)` | Check if button is pressed   |

---

### Xbox Wrapper

| Function                         | Description                         |
|----------------------------------|-------------------------------------|
| `nsf_joystick_xbox_update(xbox)` | Update full joystick state snapshot |

---

## 🔹 Parameters Reference

| Name     | Type                         | Description             |
|----------|------------------------------|-------------------------|
| `id`     | `nsf_joystick_id_t`          | Joystick index (0–7)    |
| `axis`   | `nsf_joystick_axis_xbox_t`   | Xbox axis enum          |
| `button` | `nsf_joystick_button_xbox_t` | Xbox button enum        |
| `xbox`   | `nsf_joystick_xbox_t *`      | Cached controller state |

---

## 🔹 Return Values

| Type     | Meaning                    |
|----------|----------------------------|
| `sfBool` | Boolean state (true/false) |
| `float`  | Axis position value        |
| `-1`     | Invalid joystick ID        |

---

## 🔹 Behavior

* Only supports up to `8` joysticks (`NSF_JOYSTICK_COUNT`)
* Automatically logs invalid joystick access
* Xbox mapping is fixed and not configurable
* State must be refreshed manually via `nsf_joystick_xbox_update`

---

## 🔹 Internal Implementation

### Connection Scan

```c
static void set_connection(nsf_joystick_xbox_t *xbox);
```

* Iterates through available joystick slots
* Selects first connected device
* Stores active joystick ID

---

### Update Flow

```
nsf_joystick_xbox_update
 ├── detect connection
 ├── update axis values
 └── update button states
```

---

## 🔹 Notes

* SFML joystick layer is fully wrapped
* Axis and button values are cached per update
* No automatic polling (manual update required)
* Designed for Xbox controller layout only
* Safe against invalid joystick IDs (logs warning)

---

## 🔹 Limitations

* Only supports SFML joystick backend
* Fixed Xbox mapping (no remapping system)
* No per-button event history (state only)
* No deadzone handling (must be implemented externally if needed)

---

## 🔹 Internal Files

| File                               | Role                            |
|------------------------------------|---------------------------------|
| `nsf_joystick_manage_connection.c` | Connection checker              |
| `nsf_joystick_manage_get.c`        | Axis and buttons status getters |
| `nsf_joystick_manage_update.c`     | Xbox joystick manager           |

## 🔹 Related Modules

* [`nsf_window` 🔗](window.md)
* [`nsf_game` 🔗](game.md)
* [`nsf_keyboard` 🔗](keyboard.md)

---

## 🔹 CSFML Mapping

| NSF Function                     | CSFML Equivalent             |
|----------------------------------|------------------------------|
| `nsf_joystick_is_connected`      | `sfJoystick_isConnected`     |
| `nsf_joystick_get_axis_position` | `sfJoystick_getAxisPosition` |
| `nsf_joystick_is_button_pressed` | `sfJoystick_isButtonPressed` |

---

## 🔹 Extension Ideas

* Add deadzone filtering
* Add vibration support (if backend allows)
* Add multi-controller manager
* Add event-based input system
* Add configurable mapping profiles

---

## 🔹 Implementation Notes (for contributors)

* Always validate joystick ID before SFML calls
* Keep Xbox mapping consistent across project
* Avoid direct SFML usage outside module
* Ensure update function remains deterministic
* Logging must use `nsf_utils_log`

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
