# libnewcsfml

A structured and modular wrapper around CSFML providing:
- Unified API (`nsf`)
- Simplified resource management
- Built-in game / window / UI architecture
- Automatic memory tracking

---

# Core Concept

The entire library is accessed through a single global:

```c
const nsf_nsf_functions_t nsf;
````

This provides grouped access to all subsystems:

```c
nsf.game
nsf.window
nsf.sprite
nsf.button
nsf.music
nsf.texture
nsf.color
nsf.event
```

---

# Architecture Overview

## Main Objects

### Game

```c
typedef struct {
    nsf_window_t *window;
    unsigned int allocations;
} nsf_game_t;
```

* Central manager
* Tracks allocations
* Owns window and resources

---

### Window

```c
typedef struct {
    nsf_window_settings_t *settings;
    sfRenderWindow *window;
    unsigned int fps;
    nsf_background_t *background;
    nsf_window_element_t **elements;
    char *title;
} nsf_window_t;
```

* Handles rendering
* Stores drawable elements (sprites, buttons)
* Manages events

---

### Sprite

```c
typedef struct {
    sfSprite *sprite;
    nsf_texture_t *texture;
    nsf_vector_t position;
    float rotation;
    char *name;
} nsf_sprite_t;
```

---

### Button

```c
typedef struct {
    sfRectangleShape *button;
    nsf_texture_t *texture;
    nsf_vector_t size;
    nsf_vector_t position;
    nsf_color_t fill_color;
    nsf_color_t outline_color;
    char *name;
} nsf_button_t;
```

---

### Texture

```c
typedef struct {
    sfTexture *texture;
    char *name;
} nsf_texture_t;
```

---

### Music

```c
typedef struct {
    sfMusic *music;
    str_t name;
} nsf_music_t;
```

---

# Basic Usage

## Initialization

```c
nsf_game_t *game = nsf.game.create();

nsf_window_t *window = nsf.window.create(
    (nsf_window_settings_t[]){800, 600, 32, 60},
    "My Window",
    NSF_WDW_DEFAULT_STYLE,
    game
);

nsf.game.set_window(game, window);
```

---

## Main Loop

```c
nsf_event_t event;

while (nsf.game.is_open(game)) {
    while (nsf.game.get_event(game, &event)) {
        // handle events
    }

    nsf.window.fill(window, &nsf.color.black);
    nsf.game.draw(game);
    nsf.window.display(window);
}
```

---

# Game API

```c
nsf.game.create()
nsf.game.destroy(<*game>)
nsf.game.display(<game>)
nsf.game.is_open(<game>)
nsf.game.close(<game>)
nsf.game.get_event(<game>, <event>)
nsf.game.set_window(<game>, <window>)
nsf.game.get_window(<game>)
nsf.game.add_sprite(<game>, <sprite>)
nsf.game.add_button(<game>, <button>)
nsf.game.add_sound(<game>, <sound>)
nsf.game.get_sprite(<game>, <name>)
nsf.game.get_button(<game>, <name>)
nsf.game.get_sound(<game>, <name>)
nsf.game.draw(<game>)
nsf.game.set_music(<game>, <music>)
nsf.game.play_music(<game>)
nsf.game.stop_music(<game>)
nsf.game.volume_music(<game>, <volume>)
```

### Notes

* Acts as a global manager
* Stores all elements
* Handles drawing delegation

---

# Window API

```c
nsf.window.create(<setting>, <name>, <style>, <game>)
nsf.window.destroy(<*window>, <game>)
nsf.window.display(<window>)
nsf.window.is_open(<window>)
nsf.window.close(<window>)
nsf.window.get_event(<window>, <event>)
nsf.window.fill(<window>, <color>)
nsf.window.draw_line(<window>, <pos1>, <pos2>, <color>)
nsf.window.draw(<window>)
nsf.window.add_sprite(<window>, <sprite>, <game>)
nsf.window.add_button(<window>, <button>, <game>)
nsf.window.add_sound(<window>, <sound>, <game>)
nsf.window.get_sprite(<window>, <name>)
nsf.window.get_button(<window>, <name>)
nsf.window.get_sound(<window>, <name>)
```

### Features

* Rendering control
* Element storage
* Drawing primitives (lines)

---

# Sprite API

```c
nsf.sprite.create(<name>, <game>)
nsf.sprite.destroy(<*sprite>, <game>)
nsf.sprite.set_texture(<sprite>, <texture>)
nsf.sprite.draw(<sprite>, <window>)
```

---

# Button API

```c
nsf.button.create(<name>, <game>)
nsf.button.destroy(<*button>, <game>)
nsf.button.set_texture(<button>, <texture>)
nsf.button.set_position(<button>, <pos>)
nsf.button.set_size(<button>, <size>)
nsf.button.set_colors(<button>, <color>)
nsf.button.get_state(<button>, <window>, <wanted mouse key>)
nsf.button.draw(<button>, <window>)
```

### Button State

```c
nsf_button_status_t state = nsf.button.get_state(button, window, NSF_MOUSE_LEFT);
```

Typical values:

* `NSF_STT_BTN_NONE`
* `NSF_STT_BTN_HOVERED`
* `NSF_STT_BTN_PRESSED`

---

# Texture API

```c
nsf.texture.create(<path>, <name>, <game>)
nsf.texture.destroy(<*texture>, <game>)
```

---

# Music API

```c
nsf.music.create(<path>, <name>, <game>)
nsf.music.destroy(<*music>, <game>)
nsf.music.play(<music>)
nsf.music.pause(<music>)
nsf.music.stop(<music>)
nsf.music.looping(<music>, <loop>)
nsf.music.volume(<music>, <volume>)
nsf.music.get_status(<music>)
```

---

# Sound API

```c
nsf.sound.create(<path>, <name>, <game>)
nsf.sound.destroy(<*sound>, <game>)
nsf.sound.play(<sound>)
nsf.sound.pause(<sound>)
nsf.sound.stop(<sound>)
nsf.sound.looping(<sound>, <loop>)
nsf.sound.volume(<sound>, <volume>)
nsf.sound.get_status(<sound>)
```

---

# Event API

```c
nsf.event.cmp(<event>, <wanted event>);
nsf.event.cmp_key(<event>, <wanted key>);
```

### Supported Types

* Window events
* Keyboard input
* Mouse input
* Joystick / touch

---

# Colors

Predefined colors:

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
void *nsf_malloc_any(size, game);
```

## Free

```c
nsf_free_any(ptr, game);
```

## Batch Free

```c
nsf_auto_free(len, free_list, game);
```

```c
typedef struct {
    bool condition;
    void *ptr;
    void *(*nsf_free_func)(void *);
} nsf_free_t;
```

### Features

* Tracks allocations inside `game`
* Simplifies cleanup
* Reduces leaks

---

# Drawing System

## Global Draw

```c
nsf.game.draw(game);
```

Draws:

* All sprites
* All buttons

## Manual Draw

```c
nsf.sprite.draw(sprite, window);
nsf.button.draw(button, window);
```

---

# Utilities

## Window Fill

```c
nsf.window.fill(window, &nsf.color.black);
```

## Draw Line

```c
nsf.window.draw_line(window, &a, &b, &color);
```

---

# Design Principles

* **Single entry point (`nsf`)**
* **Modular subsystems**
* **Consistent function naming**
* **Minimal boilerplate**
* **Centralized memory tracking**
* **Extensible architecture**

---

# Best Practices

* Always create a `game` first
* Use `nsf` API instead of raw CSFML
* Let the game manage allocations
* Use names to retrieve elements
* Keep rendering inside the main loop
* Use `nsf.event` helpers for cleaner input handling

---

# Example Pattern

## Create and Use a Button

```c
nsf_button_t *btn = nsf.button.create("my_button", game);

nsf.button.set_position(btn, &(nsf_vector_t){100, 100});
nsf.button.set_size(btn, &(nsf_vector_t){200, 50});
nsf.button.set_colors(btn, &nsf.color.white, &nsf.color.black, 2);

nsf.game.add_button(game, btn);
```

---

# Maintainability Notes

* All features are grouped inside `nsf`
* Add new modules by extending `nsf_nsf_functions_t`
* Keep naming consistent: `nsf_<module>_<action>`
* Avoid direct CSFML usage outside the library
* Centralize memory handling through `game`

---
