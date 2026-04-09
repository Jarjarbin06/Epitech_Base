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
    nsf_vector position;
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
    nsf_vector size;
    nsf_vector position;
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

# Basic Usage

## Initialization

```c
nsf_game_t *game = nsf.game.create();

nsf_window_t *window = nsf.window.create(
    (nsf_window_settings_t[]){800, 600, 32, 60},
    "My Window",
    nsf_wdw_default_style,
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
nsf.game.destroy()
nsf.game.display()
nsf.game.is_open()
nsf.game.close()
nsf.game.get_event()
nsf.game.set_window()
nsf.game.get_window()
nsf.game.add_sprite()
nsf.game.add_button()
nsf.game.get_sprite()
nsf.game.get_button()
nsf.game.draw()
```

### Notes

* Acts as a global manager
* Stores all elements
* Handles drawing delegation

---

# Window API

```c
nsf.window.create()
nsf.window.destroy()
nsf.window.display()
nsf.window.is_open()
nsf.window.close()
nsf.window.get_event()
nsf.window.fill()
nsf.window.draw_line()
nsf.window.draw()
nsf.window.add_sprite()
nsf.window.add_button()
nsf.window.get_sprite()
nsf.window.get_button()
```

### Features

* Rendering control
* Element storage
* Drawing primitives (lines)

---

# Sprite API

```c
nsf.sprite.create()
nsf.sprite.destroy()
nsf.sprite.set_texture()
nsf.sprite.draw()
```

---

# Button API

```c
nsf.button.create()
nsf.button.destroy()
nsf.button.set_texture()
nsf.button.set_position()
nsf.button.set_size()
nsf.button.set_colors()
nsf.button.get_state()
nsf.button.draw()
```

### Button State

```c
int state = nsf.button.get_state(button, window, nsf_mouse_left);
```

Typical values:

* `0` → idle
* `1` → hover
* `2` → clicked

---

# Texture API

```c
nsf.texture.create()
nsf.texture.destroy()
```

---

# Event API

```c
nsf.event.cmp(event, nsf_evt_key_pressed);
nsf.event.cmp_key(event, nsf_key_escape);
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
    void *(*free_func)(void *);
} free_t;
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

nsf.button.set_position(btn, &(nsf_vector){100, 100});
nsf.button.set_size(btn, &(nsf_vector){200, 50});
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
