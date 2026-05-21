# 📦 Sound Module (`nsf_sound`)
#### part of [Audios](overview.md)

The Sound module provides a lightweight audio system for short sound effects using SFML.  
It handles buffer management, playback control, and sound state abstraction.

> Example:
> Used for UI clicks, effects, and non-streamed audio playback.

---

## 🔹 Header

```c
#include <newcsfml/audios/sound.h>
````

---

## 🔹 Structure

```c
typedef struct {
    sfSound *sound;
    sfSoundBuffer *buffer;
    nsf_cstr_t name;
} nsf_sound_t;
```

### Description

| Field  | Type            | Description                           |
|--------|-----------------|---------------------------------------|
| sound  | sfSound *       | SFML sound instance used for playback |
| buffer | sfSoundBuffer * | Audio data loaded from file           |
| name   | nsf_cstr_t      | Identifier name of the sound          |

---

## 🔹 Purpose

This module is responsible for managing short audio effects.

* Wraps SFML sound + buffer lifecycle
* Provides controlled playback API (play/pause/stop)
* Abstracts raw SFML audio handling into a safer structure
* Integrates with `nsf_game_t` for allocation tracking

It corresponds to SFML `sfSound` and `sfSoundBuffer`.

---

## 🔹 Dependencies

| Module          | Usage                  |
|-----------------|------------------------|
| `nsf_game`      | Allocation tracking    |
| `systems/utils` | Safe checks and macros |
| `systems/other` | String duplication     |
| SFML Audio      | Core sound backend     |

---

## 🔹 API

### Creation / Destruction

| Function                             | Description               |
|--------------------------------------|---------------------------|
| `nsf_sound_create(path, name, game)` | Load sound and initialize |
| `nsf_sound_destroy(sound, game)`     | Free sound and buffer     |

---

### Core Functions

| Function                             | Description            |
|--------------------------------------|------------------------|
| `nsf_sound_play(sound)`              | Start playback         |
| `nsf_sound_pause(sound)`             | Pause playback         |
| `nsf_sound_stop(sound)`              | Stop playback          |
| `nsf_sound_set_looping(sound, bool)` | Enable/disable looping |
| `nsf_sound_set_volume(sound, float)` | Set volume             |
| `nsf_sound_get_status(sound)`        | Get playback state     |

---

## 🔹 Parameters Reference

| Name    | Type          | Description          |
|---------|---------------|----------------------|
| path    | const char *  | Audio file path      |
| name    | const char *  | Sound identifier     |
| sound   | nsf_sound_t * | Sound instance       |
| game    | nsf_game_t *  | Allocation context   |
| volume  | float         | Volume level (0–100) |
| looping | bool          | Loop state           |

---

## 🔹 Return Values

| Type    | Meaning                               |
|---------|---------------------------------------|
| pointer | Valid sound object                    |
| NULL    | Allocation or loading failure         |
| int     | Status code (success/error)           |
| enum    | Playback state (`nsf_sound_status_t`) |

---

## 🔹 Notes

* Sound buffer must remain valid while sound is used
* Always use `nsf_sound_destroy()` for cleanup
* Game allocation tracking increases by 4 units per sound
* Avoid direct SFML sound manipulation outside module

---

## 🔹 Internal Files

| File                       | Role                   |
|----------------------------|------------------------|
| `nsf_sound_struct.c`       | Creation & destruction |
| `nsf_sound_manage_set.c`   | Playback controls      |
| `nsf_sound_manage_state.c` | Getters                |

---

## 🔹 Related Submodules

* [`nsf_game` 🔗](../games/game.md)
* [`nsf_music` 🔗](music.md)
* [`nsf_utils` 🔗](../systems/utils.md)

---

## 🔹 CSFML Mapping

| NSF             | CSFML Equivalent   |
|-----------------|--------------------|
| nsf_sound_t     | sfSound + sfBuffer |
| nsf_sound_play  | sfSound_play       |
| nsf_sound_stop  | sfSound_stop       |
| nsf_sound_pause | sfSound_pause      |

---

## 🔹 Implementation Notes (for contributors)

* Always validate pointers before SFML calls
* Buffer must be set before playback
* Keep ownership clear: sound owns buffer lifecycle
* Follow strict separation between struct / manage logic
* Avoid leaking SFML objects on early returns

---

## 🔹 Extension Points

* Add 3D spatial sound support (future)
* Add sound pooling system for performance
* Extend status enum if SFML updates states

---

<div align="center">

## 📦 Epitech Base — Footer

</div>
<div align="center">

<img src="https://raw.githubusercontent.com/Jarjarbin06/Epitech_Base/refs/heads/main/docs/EpitechBaseLogo.png" width="120"  alt="Epitech Base Logo"/>

Epitech Base • Modular C Ecosystem

Libraries:<br>
• `file` - `v0.1.2`<br>
• `flag` - `v0.1.1`<br>
• `llist` - `v0.0.0`<br>
• `newcsfml` - `v0.2.7`<br>
• `newerror` - `v0.1.1`<br>
• `print` - `v0.1.5`<br>
• `str` - `v0.1.5`<br>
• `print` - `v0.0.0`<br>
• `twodlist` - `v0.1.5`<br>
• `utils` - `v0.1.5`<br>

Author: Nathan (Jarjarbin06) • EPITECH<br>
Licence: GPL v3<br>
Repository: [Epitech Base](https://github.com/Jarjarbin06/Epitech_Base)
</div>

---
