# libnewcsfml

A structured and modular wrapper around CSFML providing:

* Unified global API (`nsf`)
* Game / window / entity architecture
* Sprite / button / texture / audio systems
* Event abstraction layer
* Centralized memory management
* Minimal direct CSFML exposure

---

# Core Concept

All features are accessed through a single global interface:

```c
extern const nsf_nsf_functions_t nsf;
```

This object exposes all subsystems:

```c
nsf.game
nsf.window
nsf.window_settings
nsf.sprite
nsf.button
nsf.texture
nsf.music
nsf.sound
nsf.color
nsf.event
```

No direct CSFML calls are required.

---

# Architecture Overview

## Design Principles

The library is built around:

* A **Game** owns everything
* A **Window** handles rendering + events
* Every object is registered and retrieved via the system
* Memory is tracked centrally by the game

---

# Core Structures

## Game

```c
typedef struct {
    nsf_window_t *window;
    nsf_music_t *music;
    nsf_uint_t allocations;
} nsf_game_t;
```

### Role

* Central application manager
* Owns global state
* Tracks allocations
* Controls update and render flow

---

## Window

```c
typedef struct {
    nsf_window_settings_t *settings;
    sfRenderWindow *window;
    nsf_uint_t fps;
    nsf_background_t *background;
    nsf_window_element_t **elements;
    str_t title;
} nsf_window_t;
```

### Role

* Rendering surface
* Event polling
* Stores drawable entities:

  * sprites
  * buttons
  * sounds
* Controls display cycle

---

## Background

```c
typedef struct {
    nsf_sprite_t *sprite;
    nsf_texture_t *texture;
} nsf_background_t;
```

---

## Sprite

```c
typedef struct {
    sfSprite *sprite;
    nsf_texture_t *texture;
    nsf_fvector_t scale;
    nsf_fvector_t origin;
    nsf_fvector_t position;
    float rotation;
    str_t name;
    void *data;
} nsf_sprite_t;
```

---

## Button

```c
typedef struct {
    sfRectangleShape *button;
    nsf_texture_t *texture;
    nsf_fvector_t size;
    nsf_fvector_t position;
    nsf_color_t fill_color;
    nsf_color_t outline_color;
    str_t name;
} nsf_button_t;
```

---

## Texture

```c
typedef struct {
    sfTexture *texture;
    str_t name;
} nsf_texture_t;
```

---

## Audio System

### Music (streamed)

```c
typedef struct {
    sfMusic *music;
    str_t name;
} nsf_music_t;
```

### Sound (buffered)

```c
typedef struct {
    sfSound *sound;
    sfSoundBuffer *buffer;
    str_t name;
} nsf_sound_t;
```

---

# Global API Usage

```c
nsf.game.create();
nsf.window.create(...);
nsf.sprite.create(...);
```

All modules are grouped under `nsf`.

---

# Game API

```c
// BASE //
nsf.game.create()
nsf.game.destroy()
nsf.game.display()
nsf.game.is_open()
nsf.game.close()

// EVENT //
nsf.game.get_event()

// WINDOW //
nsf.game.set_window()
nsf.game.get_window()

// ELEMENT //
nsf.game.add_sprite()
nsf.game.get_sprite()
nsf.game.add_button()
nsf.game.get_button()
nsf.game.add_sound()
nsf.game.get_sound()

// SOUND //
nsf.game.play_sound()
nsf.game.pause_sound()
nsf.game.stop_sound()
nsf.game.volume_all_sound()
nsf.game.stop_all_sound()

// MUSIC //
nsf.game.set_music()
nsf.game.get_music()
nsf.game.play_music()
nsf.game.stop_music()
nsf.game.volume_music()

// DRAW //
nsf.game.draw()

// SPECIAL //
nsf.game.update()
```

---

# Window API

```c
// BASE //
nsf.window.create()
nsf.window.destroy()
nsf.window.display()
nsf.window.is_open()
nsf.window.close()

// EVENT //
nsf.window.get_event()

// DRAW //
nsf.window.fill()
nsf.window.draw_lines()
nsf.window.draw()

// ELEMENT //
nsf.window.add_sprite()
nsf.window.get_sprite()
nsf.window.add_button()
nsf.window.get_button()
nsf.window.add_sound()
nsf.window.get_sound()

// SOUND //
nsf.window.play_sound()
nsf.window.pause_sound()
nsf.window.stop_sound()
nsf.window.volume_all_sound()
nsf.window.stop_all_sound()

// SPECIAL //
nsf.window.update_settings()
nsf.window.get_mouse()
```

---

# Background API

```c
// BASE //
nsf.background.create()
nsf.background.destroy()

// DRAW //
nsf.background.draw()
```

---

# Sprite API

```c
// BASE //
nsf.sprite.create()
nsf.sprite.destroy()

// MANAGE //
nsf.sprite.set_texture()
nsf.sprite.get_texture()
nsf.sprite.set_scale()
nsf.sprite.get_scale()
nsf.sprite.set_size()
nsf.sprite.get_size()
nsf.sprite.set_position()
nsf.sprite.get_position()
nsf.sprite.set_origin()
nsf.sprite.get_origin()

// DRAW //
nsf.sprite.draw()

// SPECIAL //
nsf.sprite.update()
```

---

# Button API

```c
// BASE //
nsf.button.create()
nsf.button.destroy()

// MANAGE //
nsf.button.set_texture()
nsf.button.set_position()
nsf.button.set_size()
nsf.button.set_colors()
nsf.button.get_state()

// DRAW //
nsf.button.draw()
```

### States

* `NSF_STT_BTN_NONE`
* `NSF_STT_BTN_HOVERED`
* `NSF_STT_BTN_PRESSED`

---

# Texture API

```c
// BASE //
nsf.texture.create()
nsf.texture.destroy()
```

---

# Music API

```c
// BASE //
nsf.music.create()
nsf.music.destroy()

// MANAGE //
nsf.music.play()
nsf.music.pause()
nsf.music.stop()
nsf.music.looping()
nsf.music.volume()
nsf.music.get_status()
```

---

# Sound API

```c
// BASE //
nsf.sound.create()
nsf.sound.destroy()

// MANAGE //
nsf.sound.play()
nsf.sound.pause()
nsf.sound.stop()
nsf.sound.looping()
nsf.sound.volume()
nsf.sound.get_status()
```

---

# Event API

```c
// MANAGE //
nsf.event.cmp()
nsf.event.cmp_key()
nsf.event.get_mouse()
nsf.event.get_mouse_wheel()
```

### Supported Inputs

* Keyboard
* Mouse
* Window events
* Joystick / touch (depending CSFML backend)

---

# Window Settings API

```c
// BASE //
nsf.window_settings.setting_create()
nsf.window_settings.setting_destroy()
```

---

# Colors

```c
nsf.color.black
nsf.color.white
nsf.color.red
nsf.color.green
nsf.color.blue
nsf.color.yellow
nsf.color.magenta
nsf.color.cyan
nsf.color.grey
nsf.color.transparent
```

---

# Memory Management

## Allocation

```c
void *nsf_malloc_any(nsf_uint_t size, nsf_game_t *game);
```

## Free

```c
void *nsf_free_any(void *ptr, nsf_game_t *game);
```

## Batch Free

```c
int nsf_auto_free(nsf_uint_t len, const nsf_free_t free_list[], nsf_game_t *game);
```

---

# Drawing System

## Global Draw

```c
nsf.game.draw(game);
```

Draws all registered elements:

* sprites
* buttons
* UI objects

## Manual Draw

```c
nsf.sprite.draw()
nsf.button.draw()
```

---

# Utilities

## Fill Window

```c
nsf.window.fill(window, color);
```

## Draw Lines

```c
nsf.window.draw_lines(window, count, positions, colors);
```

## Mouse Helper

```c
nsf.window.get_mouse(window, coords);
```

---

# Design Principles

* Single entry point (`nsf`)
* Modular subsystems
* Consistent naming: `nsf_<module>_<action>`
* Centralized memory tracking
* Game-owned lifecycle
* Minimal CSFML exposure

---

# Best Practices

* Always initialize `game` first
* Use `nsf` API instead of raw CSFML
* Register all objects through `game` or `window`
* Keep rendering inside the main loop
* Use `event.cmp()` helpers for input handling
* Avoid manual memory management when possible

---

# Example Pattern

## Button Creation

```c
nsf_button_t *btn = nsf.button.create("play", game);

nsf.button.set_position(btn, (nsf_fvector_t[]){100, 100});
nsf.button.set_size(btn, (nsf_fvector_t[]){200, 50});

nsf.button.set_colors(
    btn,
    (nsf_color_t[]){nsf.color.white},
    (nsf_color_t[]){nsf.color.black},
    2
);

nsf.game.add_button(game, btn);
```

---

# Maintainability Notes

* Extend `nsf_nsf_functions_t` to add modules
* Keep all APIs prefixed with `nsf`
* Avoid exposing CSFML directly
* Keep ownership inside `game`
* Maintain strict module separation

---
