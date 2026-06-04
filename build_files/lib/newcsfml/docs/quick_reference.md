---
title: Epitech Base | Library | NewCSFML - Quick Reference
---
<link rel="icon" type="image/x-icon" href="https://raw.githubusercontent.com/Jarjarbin06/Epitech_Base/refs/heads/main/build_files/lib/newcsfml/resouces/NCSFML_logo_transparent.png">

# 📦 Quick Reference

Compact overview of the most used APIs in the NewCSFML framework for fast lookup during development.

> Example:
> Provides a minimal cheat sheet of core functions, structures, and naming conventions.

---

## 🔹 Core Lifecycle

### Game

| Function                  | Description           |
|---------------------------|-----------------------|
| `nsf_game_create()`       | Create game context   |
| `nsf_game_destroy()`      | Destroy game context  |

---

### Window

| Function                  | Description              |
|---------------------------|--------------------------|
| `nsf_window_create(...)`  | Create render window     |
| `nsf_window_destroy(...)` | Destroy window safely    |

---

## 🔹 Graphics

### Sprite

| Function                       | Description           |
|--------------------------------|-----------------------|
| `nsf_sprite_create(...)`       | Create sprite         |
| `nsf_sprite_destroy(...)`      | Destroy sprite safely |
| `nsf_sprite_set_texture(...)`  | Assign texture        |
| `nsf_sprite_set_position(...)` | Set position          |
| `nsf_sprite_set_scale(...)`    | Set scale             |
| `nsf_sprite_set_size(...)`     | Set size from texture |
| `nsf_sprite_set_origin(...)`   | Set origin            |

---

### Texture

| Function              | Description        |
|-----------------------|--------------------|
| `nsf_texture_create`  | Create texture     |
| `nsf_texture_destroy` | Free texture       |

---

### Button

| Function                       | Description           |
|--------------------------------|-----------------------|
| `nsf_button_create`            | Create button         |
| `nsf_button_draw`              | Render button         |
| `nsf_sprite_set_texture(...)`  | Assign texture        |
| `nsf_sprite_set_position(...)` | Set position          |
| `nsf_sprite_set_size(...)`     | Set size from texture |
| `nsf_button_set_colors(...)`   | Set colors            |
| `nsf_button_get_state(...)`    | Get state             |

---

## 🔹 Audio

### Music

| Function              | Description        |
|-----------------------|--------------------|
| `nsf_music_create`    | Load music stream  |
| `nsf_music_play`      | Play music         |
| `nsf_music_destroy`   | Free music         |

---

### Sound

| Function              | Description        |
|-----------------------|--------------------|
| `nsf_sound_create`    | Load sound buffer  |
| `nsf_sound_play`      | Play sound         |
| `nsf_sound_destroy`   | Free sound         |

---

## 🔹 Systems

### Vector

| Function                  | Description        |
|---------------------------|--------------------|
| `nsf_vector_copy`         | Copy vector        |
| `nsf_vector_clamp_x`      | Clamp X axis       |
| `nsf_vector_clamp_y`      | Clamp Y axis       |

---

### Clock

| Function              | Description        |
|-----------------------|--------------------|
| `nsf_clock_create`    | Create clock       |
| `nsf_clock_restart`   | Reset clock        |

---

### Utils

| Function     | Description      |
|--------------|------------------|
| `malloc_any` | Safe allocation  |
| `free_any`   | Safe free        |
| `str_dup`    | Duplicate string |

---

## 🔹 Game Element System

| Type                     | Description            |
|--------------------------|------------------------|
| `NSF_SPRITE_ELEMENT`     | Sprite in window       |
| `NSF_BUTTON_ELEMENT`     | UI button              |
| `NSF_SOUND_ELEMENT`      | Sound element          |

---

## 🔹 Naming Rules

| Element   | Pattern                  |
|-----------|--------------------------|
| Functions | `nsf_<module>_<action>`  |
| Structs   | `nsf_<name>_t`           |
| Files     | `nsf_<name>_<feature>.c` |
| Headers   | `snake_case.h`           |

---

## 🔹 Common Rules

* Always check pointers before use
* Always use provided setters/getters
* Never call SFML directly outside implementation
* Game context must be passed for allocation

---

## 🔹 Dependency Flow

```text
systems → graphics → audios → games → application
````

---

## 🔹 Most Important Rule

> If a function exists in the API, it must be used instead of direct SFML manipulation.

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
