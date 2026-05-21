# 📦 Music Module (`nsf_music`)
#### part of [Audios](overview.md)

Audio streaming module based on SFML `sfMusic`, providing controlled playback of long audio tracks (background music, ambience, etc.).

> Example:
> Handles streamed music playback, volume control, looping, and status querying.

---

## 🔹 Header

```c
#include <newcsfml/audios/music.h>
````

---

## 🔹 Structure

```c
typedef struct {
    sfMusic *music;
    nsf_cstr_t name;
} nsf_music_t;
```

### Description

| Field   | Type         | Description                     |
|---------|--------------|---------------------------------|
| `music` | `sfMusic *`  | SFML music stream instance      |
| `name`  | `nsf_cstr_t` | Identifier string for the music |

---

## 🔹 Purpose

The music module is responsible for managing **streamed audio playback** using SFML.

* Handles long audio files (unlike sound buffers)
* Provides playback control (play/pause/stop)
* Manages looping and volume
* Tracks a simple identifier for debugging or registry purposes

It abstracts SFML `sfMusic` into a safer and more consistent framework API.

---

## 🔹 Dependencies

| Module       | Usage                         |
|--------------|-------------------------------|
| `nsf_game`   | Memory tracking / allocations |
| `nsf_utils`  | Safe allocation checks        |
| `nsf_other`  | String duplication utilities  |
| `SFML Audio` | Core audio backend            |

---

## 🔹 API

### Creation / Destruction

| Function                             | Description         |
|--------------------------------------|---------------------|
| `nsf_music_create(path, name, game)` | Load a music stream |
| `nsf_music_destroy(&music, game)`    | Free music instance |

---

### Core Functions

| Function                             | Description            |
|--------------------------------------|------------------------|
| `nsf_music_play(music)`              | Start playback         |
| `nsf_music_pause(music)`             | Pause playback         |
| `nsf_music_stop(music)`              | Stop playback          |
| `nsf_music_set_volume(music, vol)`   | Set volume (0–100)     |
| `nsf_music_set_looping(music, bool)` | Enable/disable looping |

---

### Advanced / Optional

| Function                      | Description        |
|-------------------------------|--------------------|
| `nsf_music_get_status(music)` | Get playback state |

---

## 🔹 Parameters Reference

| Name      | Type            | Description         |
|-----------|-----------------|---------------------|
| `path`    | `const char[]`  | Path to audio file  |
| `name`    | `const char[]`  | Internal identifier |
| `music`   | `nsf_music_t *` | Music instance      |
| `volume`  | `float`         | Volume level        |
| `looping` | `bool`          | Loop state          |
| `game`    | `nsf_game_t *`  | Allocation context  |

---

## 🔹 Return Values

| Type                 | Meaning                       |
|----------------------|-------------------------------|
| `nsf_music_t *`      | Successfully created music    |
| `NULL`               | Allocation or loading failure |
| `E_SUCCESS`          | Successful destruction        |
| `E_ERROR`            | Invalid pointer / failure     |
| `nsf_sound_status_t` | Playback state                |

---

## 🔹 Notes

* Music is streamed (not fully loaded into memory)
* Requires valid file path supported by SFML
* Ownership of memory is handled via `nsf_game_t` when provided
* Name field is duplicated internally and must be freed properly
* Do not mix raw SFML calls outside implementation files

---

## 🔹 Internal Files

| File                       | Role                   |
|----------------------------|------------------------|
| `nsf_music_struct.c`       | Creation & destruction |
| `nsf_music_manage_set.c`   | Playback controls      |
| `nsf_music_manage_state.c` | Getters                |

---

## 🔹 Related Submodules

* [`nsf_sound` 🔗](sound.md)
* [`nsf_game` 🔗](../games/game.md)
* [`nsf_utils` 🔗](../systems/utils.md)

---

## 🔹 CSFML Mapping

| NSF Function           | CSFML Equivalent    |
|------------------------|---------------------|
| `nsf_music_play`       | `sfMusic_play`      |
| `nsf_music_pause`      | `sfMusic_pause`     |
| `nsf_music_stop`       | `sfMusic_stop`      |
| `nsf_music_volume`     | `sfMusic_setVolume` |
| `nsf_music_looping`    | `sfMusic_setLoop`   |
| `nsf_music_get_status` | `sfMusic_getStatus` |
| `nsf_music_t`          | `sfMusic`           |

---

## 🔹 Implementation Notes (for contributors)

* Always validate pointers before SFML calls
* Ensure correct allocation accounting via `nsf_game_t`
* Separate creation/destruction from runtime control
* Keep SFML interaction isolated to implementation layer
* Avoid direct access to `sfMusic` outside this module

---

## 🔹 Extension Points

* Add fade-in / fade-out system in manage layer
* Support playlist management via wrapper layer
* Extend metadata fields (artist, duration, tags)
* Add async loading system for large audio assets

---
