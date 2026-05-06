# 📦 Window Module (`nsf_window`)
#### part of [Games](overview.md)

Core rendering and event management module built on top of SFML.
It handles window lifecycle, drawable elements, input events, and audio/sprite integration.

> Example:
> Manages rendering loop, drawable registry (sprites, buttons, sounds), and SFML window abstraction.

---

## 🔹 Header

```c
#include <newcsfml/games/window.h>
```

---

## 🔹 Structure

```c
typedef struct {
    nsf_window_settings_t *settings;
    sfRenderWindow *window;
    nsf_background_t *background;
    nsf_element_list_t elements;
    nsf_cstr_t title;
} nsf_window_t;
```

### Description

| Field        | Type                      | Description                              |
|--------------|---------------------------|------------------------------------------|
| `settings`   | `nsf_window_settings_t *` | Window configuration (size, bpp, style)  |
| `window`     | `sfRenderWindow *`        | Underlying SFML render window            |
| `background` | `nsf_background_t *`      | Background renderer                      |
| `elements`   | `nsf_element_list_t`      | Registry of drawable/interactive objects |
| `title`      | `nsf_cstr_t`              | Window title string                      |

---

## 🔹 Purpose

Central abstraction for rendering and input handling.

* Wraps SFML render window with a managed architecture
* Provides unified system for sprites, buttons, and sounds
* Handles event polling and rendering pipeline
* Ensures proper ownership and cleanup through `nsf_game_t`

---

## 🔹 Dependencies

| Module                | Usage                                        |
|-----------------------|----------------------------------------------|
| `nsf_game`            | Allocation tracking and lifecycle management |
| `nsf_sprite`          | Drawable sprite elements                     |
| `nsf_button`          | UI interaction elements                      |
| `nsf_sound`           | Audio playback system                        |
| `nsf_background`      | Background rendering                         |
| `nsf_window_settings` | Window configuration                         |

---

## 🔹 API

### Creation / Destruction

| Function                  | Description                                |
|---------------------------|--------------------------------------------|
| `nsf_window_create(...)`  | Create a new render window with settings   |
| `nsf_window_destroy(...)` | Destroy window and all registered elements |

---

### Core Functions

| Function                          | Description                     |
|-----------------------------------|---------------------------------|
| `nsf_window_display(...)`         | Display rendered frame          |
| `nsf_window_isopen(...)`          | Check if window is open         |
| `nsf_window_close(...)`           | Close window                    |
| `nsf_window_get_event(...)`       | Poll SFML events                |
| `nsf_window_update_settings(...)` | Sync runtime size into settings |
| `nsf_window_get_mouse(...)`       | Get mouse position              |

---

### Element Management

| Function                     | Description               |
|------------------------------|---------------------------|
| `nsf_window_add_sprite(...)` | Register sprite in window |
| `nsf_window_add_button(...)` | Register button           |
| `nsf_window_add_sound(...)`  | Register sound            |
| `nsf_window_get_sprite(...)` | Retrieve sprite by name   |
| `nsf_window_get_button(...)` | Retrieve button by name   |
| `nsf_window_get_sound(...)`  | Retrieve sound by name    |

---

### Background Control

| Function                         | Description    |
|----------------------------------|----------------|
| `nsf_window_set_background(...)` | Set background |
| `nsf_window_get_background(...)` | Get background |

---

### Audio Control

| Function                           | Description               |
|------------------------------------|---------------------------|
| `nsf_window_play_sound(...)`       | Play sound by name        |
| `nsf_window_pause_sound(...)`      | Pause sound               |
| `nsf_window_stop_sound(...)`       | Stop sound                |
| `nsf_window_all_sound_volume(...)` | Set volume for all sounds |
| `nsf_window_stop_all_sound(...)`   | Stop all sounds           |

---

### Drawing

| Function                      | Description                               |
|-------------------------------|-------------------------------------------|
| `nsf_window_draw(...)`        | Render full frame (background + elements) |
| `nsf_window_fill(...)`        | Clear screen with color                   |
| `nsf_window_draw_lines(...)`  | Draw line strip using vertex array        |
| `nsf_window_draw_points(...)` | Draw points using vertex array            |

---

## 🔹 Parameters Reference

| Name     | Type              | Description          |
|----------|-------------------|----------------------|
| `window` | `nsf_window_t *`  | Window instance      |
| `event`  | `nsf_event_t *`   | SFML event structure |
| `game`   | `nsf_game_t *`    | Allocation context   |
| `sprite` | `nsf_sprite_t *`  | Sprite object        |
| `button` | `nsf_button_t *`  | UI button            |
| `sound`  | `nsf_sound_t *`   | Sound object         |
| `color`  | `nsf_color_t`     | RGBA color           |
| `points` | `nsf_fvector_t[]` | Vertex positions     |

---

## 🔹 Return Values

| Type      | Meaning                      |
|-----------|------------------------------|
| `pointer` | Valid object                 |
| `NULL`    | Allocation or lookup failure |
| `int`     | Success or error code        |
| `bool`    | State result                 |

---

## 🔹 Notes

* Window owns all registered elements
* All elements must be freed through window destroy logic
* SFML calls are encapsulated and should not be used directly outside module
* Element system is type-based (sprite, button, sound)

---

## 🔹 Internal Files

| File                   | Role                         |
|------------------------|------------------------------|
| `nsf_window_struct.c`  | Creation and destruction     |
| `nsf_window_manage1.c` | Event and display handling   |
| `nsf_window_manage2.c` | Sprite/button/sound registry |
| `nsf_window_manage3.c` | Audio control                |
| `nsf_window_manage4.c` | Settings and mouse utilities |
| `nsf_window_manage5.c` | Background handling          |
| `nsf_window_manage6.c` | Extended system logic        |
| `nsf_window_draw.c`    | Rendering pipeline           |

---

## 🔹 Related Submodules

* [`nsf_game` 🔗](game.md)
* [`nsf_sprite` 🔗](../graphics/sprite.md)
* [`nsf_button` 🔗](../graphics/button.md)
* [`nsf_sound` 🔗](../audios/sound.md)
* [`nsf_background` 🔗](../graphics/background.md)
* [`nsf_window_settings` 🔗](window_settings.md)

---

## 🔹 CSFML Mapping (Optional)

| NSF                    | CSFML                      |
|------------------------|----------------------------|
| `nsf_window_t`         | `sfRenderWindow`           |
| `nsf_window_get_event` | `sfRenderWindow_pollEvent` |
| `nsf_window_draw`      | `sfRenderWindow_draw*`     |
| `nsf_window_fill`      | `sfRenderWindow_clear`     |

---

## 🔹 Implementation Notes (for contributors)

* Strict separation between:

    * struct lifecycle
    * element management
    * rendering
    * audio control
* Always validate pointers before SFML usage
* Never bypass element system for rendering
* Keep SFML calls isolated inside module
* Respect Epitech C coding style (no implicit global state, clean functions)

---

## 🔹 Extension Points

* Add new element types via `nsf_window_element_t`
* Extend registry system in `elements`
* Add new draw passes (UI, overlays, debug layer)
* Add input abstraction layer over SFML events
* Improve batching for rendering optimization

---
