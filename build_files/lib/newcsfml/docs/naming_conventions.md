<link rel="icon" type="image/x-icon" href="https://raw.githubusercontent.com/Jarjarbin06/Epitech_Base/refs/heads/main/docs/EpitechBaseWebIcon.png">

# 📦 Naming Conventions

This document defines the strict naming rules used across the **NewCSFML framework** to ensure consistency, readability, and maintainability.

> The goal is to keep the API predictable and close to CSFML style while enforcing a clear modular structure.

---

## 🔹 Header Naming

```text
includes/newcsfml/<module>/<submodule>.h
````

### Rules

| Element      | Convention                                          |
|--------------|-----------------------------------------------------|
| Folder       | snake_case, plural (`graphics`, `games`, `systems`) |
| File         | snake_case (`sprite.h`, `window_settings.h`)        |
| Main include | `newcsfml.h`                                        |

---

## 🔹 Source File Naming

```text
sources/<module>/<submodule>/nsf_<submodule>_<feature>.c
```

### Examples

```text
nsf_sprite_draw.c
nsf_window_manage1.c
nsf_game_struct.c
```

### Rules

| Element   | Convention                                          |
|-----------|:----------------------------------------------------|
| Prefix    | `nsf_` mandatory                                    |
| Submodule | corresponds to folder                               |
| Splitting | large modules split into `manage1`, `manage2`, etc. |
| Unique    | file name must be unique across all source files    |

---

## 🔹 Structure Naming

```c
typedef struct <optional> {
    ...
} nsf_<name>_t;
```

### Rules

| Rule       | Description                                                                       |
|------------|-----------------------------------------------------------------------------------|
| Prefix     | Always `nsf_`                                                                     |
| Suffix     | Always `_t`                                                                       |
| Style      | snake_case                                                                        |
| Name       | singular form (`sprite`, not `sprites`)                                           |
| Dependency | optional `nsf_<name>_s` to allow partial structure include for dependency ability |

### Examples

```c
nsf_sprite_t
nsf_window_t
nsf_game_t
nsf_texture_t
```

---

## 🔹 Function Naming

```c
nsf_<module>_<action>()
```

### Rules

| Rule   | Description                                 |
|--------|---------------------------------------------|
| Prefix | Always `nsf_`                               |
| Module | defines system (`sprite`, `window`, `game`) |
| Action | verb describing behavior                    |

### Examples

```c
nsf_sprite_create()
nsf_sprite_draw()
nsf_window_create()
nsf_game_update()
```

---

## 🔹 Enum Naming

```c
typedef enum {
    NSF_<MODULE>_<VALUE>
} nsf_<name>_t;
```

### Rules

| Rule   | Description                                        |
|--------|----------------------------------------------------|
| Prefix | `NSF_` uppercase                                   |
| Module | uppercase module name (3 letters only if possible) |
| Values | uppercase snake_case                               |

### Examples

```c
NSF_EVT_KEY_PRESSED
NSF_KEY_A
NSF_STT_BTN_HOVERED
```

---

## 🔹 Macro Naming

```c
#define NSF_<NAME>
```

### Rules

| Rule   | Description    |
|--------|----------------|
| Prefix | Always `NSF_`  |
| Style  | FULL UPPERCASE |

### Examples

```c
NSF_LIKELY
NSF_DEGREE
```

---

## 🔹 Type Alias Naming

```c
typedef <type> nsf_<name>_t;
```

### Rules

| Rule       | Description                          |
|------------|--------------------------------------|
| Prefix     | `nsf_`                               |
| Suffix     | `_t`                                 |
| Base type  | CSFML or custom                      |
| Dependency | newcsfml type from another submodule |

### Examples

```c
typedef sfVector2f nsf_fvector_t;
typedef struct nsf_game_s nsf_game_t;
typedef unsigned int nsf_uint_t;
```

---

## 🔹 Boolean Naming

| Rule                              | Example                  |
|-----------------------------------|--------------------------|
| Prefix with `is_`, `has_`, `can_` | `is_open`, `has_texture` |

---

## 🔹 Pointer Naming

| Rule                                                       | Example                 |
|------------------------------------------------------------|-------------------------|
| Pointer suffix not required but consistent usage preferred | `sprite`, `window`      |
| Double pointer for destroy                                 | `nsf_sprite_t **sprite` |

---

## 🔹 Event & Input Naming

```c
NSF_EVT_*
NSF_KEY_*
NSF_MSE_*
```

### Example

```c
NSF_EVT_MOUSE_BUTTON_PRESSED
NSF_KEY_SPACE
NSF_MSE_LEFT
```

---

## 🔹 Color Naming

```c
nsf_color.<name>
```

### Rules

| Rule                   | Example                 |
|------------------------|-------------------------|
| Lowercase named colors | `black`, `white`, `red` |

---

## 🔹 Consistency Rules

* Always use `nsf_` prefix for everything public
* Never mix CSFML naming directly in public API
* Keep naming descriptive, not shortened
* Prefer verbs for functions, nouns for structures
* Avoid abbreviations unless standard (fps, pos, evt)

---

## 🔹 Forbidden Patterns

| Wrong            | Correct               |
|------------------|-----------------------|
| `spriteCreate()` | `nsf_sprite_create()` |
| `WindowCreate`   | `nsf_window_create()` |
| `gameUpd()`      | `nsf_game_update()`   |

---

## 🔹 Summary Rule

> Everything in the framework must be predictable from its name:
>
> `nsf_<module>_<action>`

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
