---
title: NewCSFML - Games - NSF_Game
---
<style>
    * {
      position: relative;
      z-index: 5;
    body {
      font-family: "Roboto", sans-serif;
      margin: 0;
      padding: 0;
      overflow-x: hidden;
    }
    a {
      text-decoration: none;
    }
}
</style>
<link rel="icon" type="image/x-icon" href="https://raw.githubusercontent.com/Jarjarbin06/Epitech_Base/refs/heads/main/build_files/lib/newcsfml/resouces/NCSFML_logo_transparent.png">

# 📦 Game Module (`nsf_game`)
#### part of [Games](overview.md)

Central runtime controller of the framework. It manages the window, audio, global state, and acts as the main entry point for all subsystems.

> Example:
> Provides a unified interface to update, render, and control the full application state.

---

## 🔹 Header

```c
#include <newcsfml/games/game.h>
```

---

## 🔹 Structure

```c
typedef struct nsf_game_s {
    nsf_window_t *window;
    nsf_music_t *music;
    nsf_clock_t *clock;
    nsf_game_fps_t real_fps;
    int allocations;
    void *data;
} nsf_game_t;
```

### Description

| Field         | Type             | Description                            |
|---------------|------------------|----------------------------------------|
| `window`      | `nsf_window_t *` | Main rendering window and event system |
| `music`       | `nsf_music_t *`  | Global music controller                |
| `clock`       | `nsf_clock_t *`  | Global timing system                   |
| `real_fps`    | `nsf_game_fps_t` | Drawing fps computing                  |
| `allocations` | `int`            | Debug / tracking of allocated objects  |
| `data`        | `void *`         | User-defined global context pointer    |

---

## 🔹 Purpose

The game module is the **core orchestrator** of the framework.

* Owns and links all major systems (window, audio, timing)
* Acts as the main runtime context passed across the engine
* Centralizes resource management and lifecycle coordination
* Serves as the single entry point for application-level logic

It abstracts the concept of a "game instance" over CSFML by adding:

* memory tracking (`allocations`)
* unified access to subsystems
* controlled propagation of state changes

---

## 🔹 Dependencies

| Module           | Usage                      |
|------------------|----------------------------|
| `nsf_window`     | Rendering + event handling |
| `nsf_music`      | Global audio control       |
| `nsf_clock`      | Timing system              |
| `nsf_sprite`     | Drawable management        |
| `nsf_button`     | UI interaction             |
| `nsf_sound`      | Sound control              |
| `nsf_background` | Scene background           |

---

## 🔹 API

### Creation / Destruction

| Function                | Description                        |
|-------------------------|------------------------------------|
| `nsf_game_create()`     | Create a new game context          |
| `nsf_game_destroy(...)` | Destroy and free entire game state |

---

### Core Lifecycle

| Function                | Description                       |
|-------------------------|-----------------------------------|
| `nsf_game_update(...)`  | Update window settings and timing |
| `nsf_game_display(...)` | Render current frame              |
| `nsf_game_draw(...)`    | Draw all registered elements      |

---

### Window Control

| Function                   | Description              |
|----------------------------|--------------------------|
| `nsf_game_set_window(...)` | Assign main window       |
| `nsf_game_get_window(...)` | Retrieve current window  |
| `nsf_game_isopen(...)`     | Check if window is open  |
| `nsf_game_close(...)`      | Close application window |
| `nsf_game_get_event(...)`  | Poll events              |

---

### Screen Management

| Function                   | Description                    |
|----------------------------|--------------------------------|
| `nsf_game_add_screen(...)` | Add a new screen to the window |
| `nsf_game_set_screen(...)` | Select a screen to draw        |

---

### Graphics Management

| Function                     | Description       |
|------------------------------|-------------------|
| `nsf_game_add_sprite(...)`   | Register sprite   |
| `nsf_game_add_button(...)`   | Register button   |
| `nsf_game_add_text(...)`     | Register text     |
| `nsf_game_add_sound(...)`    | Register sound    |
| `nsf_game_add_particle(...)` | Register particle |

---

### Audio Management

| Function                         | Description       |
|----------------------------------|-------------------|
| `nsf_game_set_music(...)`        | Set global music  |
| `nsf_game_get_music(...)`        | Get current music |
| `nsf_game_play_music(...)`       | Play music        |
| `nsf_game_stop_music(...)`       | Stop music        |
| `nsf_game_set_music_volume(...)` | Adjust volume     |

---

### Sound Control

| Function                         | Description           |
|----------------------------------|-----------------------|
| `nsf_game_play_sound(...)`       | Play sound by name    |
| `nsf_game_pause_sound(...)`      | Pause sound           |
| `nsf_game_stop_sound(...)`       | Stop sound            |
| `nsf_game_all_sound_volume(...)` | Set all sounds volume |
| `nsf_game_stop_all_sound(...)`   | Stop all sounds       |

---

### Resource Access

| Function                     | Description       |
|------------------------------|-------------------|
| `nsf_game_get_sprite(...)`   | Retrieve sprite   |
| `nsf_game_get_button(...)`   | Retrieve button   |
| `nsf_game_get_text(...)`     | Retrieve text     |
| `nsf_game_get_sound(...)`    | Retrieve sound    |
| `nsf_game_get_particle(...)` | Retrieve particle |

---

### Environment / State

| Function                       | Description                                   |
|--------------------------------|-----------------------------------------------|
| `nsf_game_set_background(...)` | Set background                                |
| `nsf_game_get_background(...)` | Get background                                |
| `nsf_game_set_clock(...)`      | Set global clock                              |
| `nsf_game_get_clock(...)`      | Get clock                                     |
| `nsf_game_update_clock(...)`   | Update game clock<br/>Return true if new loop |
| `nsf_game_wait_new_loop(...)`  | Automatically wait for a new loop             |

---

## 🔹 Parameters Reference

| Name     | Type             | Description          |
|----------|------------------|----------------------|
| `game`   | `nsf_game_t *`   | Main runtime context |
| `window` | `nsf_window_t *` | Render window        |
| `sprite` | `nsf_sprite_t *` | Drawable sprite      |
| `button` | `nsf_button_t *` | UI element           |
| `sound`  | `nsf_sound_t *`  | Sound effect         |
| `music`  | `nsf_music_t *`  | Background music     |
| `event`  | `nsf_event_t *`  | Input event          |
| `volume` | `float`          | Audio volume level   |

---

## 🔹 Return Values

| Type      | Meaning                |
|-----------|------------------------|
| `int`     | Success / error code   |
| `bool`    | State validation       |
| `pointer` | Valid object reference |
| `NULL`    | Failure / not found    |

---

## 🔹 Notes

* Game must be initialized before any subsystem usage
* Acts as the **single ownership root** of all resources
* Destruction cascades to window and audio systems
* All allocations should be tracked via `allocations`
* Window pointer is the central dependency for most operations

---

## 🔹 Internal Files

| File                              | Role                          |
|-----------------------------------|-------------------------------|
| `nsf_game_struct.c`               | Data structures & lifecycle   |
| `nsf_game_manage_background.c`    | Background manager            |
| `nsf_game_manage_clock.c`         | Clock manager                 |
| `nsf_game_manage_elementes_add.c` | Sprite/button/etc... registry |
| `nsf_game_manage_elementes_get.c` | Sprite/button/etc... getter   |
| `nsf_game_manage_background.c`    | Background manager            |
| `nsf_game_manage_runtime.c`       | Event and display handling    |
| `nsf_game_manage_sound.c`         | Sound manager                 |
| `nsf_game_manage_state.c`         | Window state control          |
| `nsf_game_manage_window.c`        | Window manager                |
| `nsf_game_manage_update.c`        | Updater                       |
| `nsf_game_draw.c`                 | Rendering logic               |

---

## 🔹 Related Submodules

* [`nsf_window` 🔗](window.md)
* [`nsf_music` 🔗](../audios/music.md)
* [`nsf_clock` 🔗](../systems/clock.md)
* [`nsf_sprite` 🔗](../graphics/sprite.md)
* [`nsf_button` 🔗](../graphics/button.md)
* [`nsf_sound` 🔗](../audios/sound.md)

---

## 🔹 CSFML Mapping (Optional)

| NSF          | CSFML                                           |
|--------------|-------------------------------------------------|
| `nsf_game_t` | No direct equivalent (engine layer abstraction) |
| window       | `sfRenderWindow`                                |
| event        | `sfEvent`                                       |
| music        | `sfMusic`                                       |

---

## 🔹 Implementation Notes (for contributors)

* Game must remain a **thin orchestration layer**, not a logic container
* Avoid embedding rendering or audio logic directly in game functions
* Always validate pointers before delegation
* Keep ownership rules strict (game owns window/music/clock)
* Ensure destruction order prevents dangling references

---

## 🔹 Extension Points

* Add global systems via `data` pointer or new fields
* Extend resource management (sprite/button registry expansion)
* Add higher-level engine systems (UI manager, scene system)
* Improve allocation tracking for debugging tools
