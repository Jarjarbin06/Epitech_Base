# 📦 `Game System (nsf_game)`

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

| Function                 | Description                        |
|--------------------------|------------------------------------|
| `nsf_game_create()`      | Create a new game context          |
| `nsf_game_destroy(game)` | Destroy and free entire game state |

---

### Core Lifecycle

| Function                 | Description                       |
|--------------------------|-----------------------------------|
| `nsf_game_update(game)`  | Update window settings and timing |
| `nsf_game_display(game)` | Render current frame              |
| `nsf_game_draw(game)`    | Draw all registered elements      |

---

### Window Control

| Function                            | Description              |
|-------------------------------------|--------------------------|
| `nsf_game_set_window(game, window)` | Assign main window       |
| `nsf_game_get_window(game)`         | Retrieve current window  |
| `nsf_game_isopen(game)`             | Check if window is open  |
| `nsf_game_close(game)`              | Close application window |
| `nsf_game_get_event(game, event)`   | Poll events              |

---

### Graphics Management

| Function                            | Description     |
|-------------------------------------|-----------------|
| `nsf_game_add_sprite(game, sprite)` | Register sprite |
| `nsf_game_add_button(game, button)` | Register button |

---

### Audio Management

| Function                                  | Description       |
|-------------------------------------------|-------------------|
| `nsf_game_set_music(game, music)`         | Set global music  |
| `nsf_game_get_music(game)`                | Get current music |
| `nsf_game_play_music(game)`               | Play music        |
| `nsf_game_stop_music(game)`               | Stop music        |
| `nsf_game_set_music_volume(game, volume)` | Adjust volume     |

---

### Sound Control

| Function                                  | Description           |
|-------------------------------------------|-----------------------|
| `nsf_game_play_sound(game, name)`         | Play sound by name    |
| `nsf_game_pause_sound(game, name)`        | Pause sound           |
| `nsf_game_stop_sound(game, name)`         | Stop sound            |
| `nsf_game_all_sound_volume(game, volume)` | Set all sounds volume |
| `nsf_game_stop_all_sound(game)`           | Stop all sounds       |

---

### Resource Access

| Function                          | Description     |
|-----------------------------------|-----------------|
| `nsf_game_get_sprite(game, name)` | Retrieve sprite |
| `nsf_game_get_button(game, name)` | Retrieve button |
| `nsf_game_get_sound(game, name)`  | Retrieve sound  |

---

### Environment / State

| Function                                    | Description      |
|---------------------------------------------|------------------|
| `nsf_game_set_background(game, background)` | Set background   |
| `nsf_game_get_background(game)`             | Get background   |
| `nsf_game_set_clock(game, clock)`           | Set global clock |
| `nsf_game_get_clock(game)`                  | Get clock        |

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

| File                 | Role                         |
|----------------------|------------------------------|
| `nsf_game_struct.c`  | Creation / destruction logic |
| `nsf_game_manage*.c` | Core system orchestration    |
| `nsf_game_draw.c`    | Frame rendering              |

---

## 🔹 Related Modules

* `nsf_window`
* `nsf_music`
* `nsf_clock`
* `nsf_sprite`
* `nsf_button`
* `nsf_sound`

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

---
