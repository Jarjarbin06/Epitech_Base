# 📦 `Audios`
#### part of [NewCSFML](../../README.md)

Audio module providing high-level abstractions for sound effects and streamed music playback.

> Provides unified and safe access to SFML audio systems (`sfSound`, `sfMusic`) with memory tracking and consistent API design.

---

## 🔹 Header

```c
#include <newcsfml/audios/audios.h>
```

---

## 🔹 Overview

| Submodule | Role                                  |
|-----------|---------------------------------------|
| `music`   | Handles streamed audio (long tracks)  |
| `sound`   | Manages short sound effects (buffers) |

---

## 🔹 Purpose

This module centralizes all **audio-related functionalities** of the framework.

* Abstracts SFML audio layer (`sfMusic`, `sfSound`, `sfSoundBuffer`)
* Provides a consistent API for playback control
* Handles memory safely via `nsf_game_t`
* Separates streamed audio (music) from buffered audio (sound)

It solves the complexity of handling two different SFML audio systems with different lifecycles.

---

## 🔹 Architecture

### Internal Composition

```
audios
├── music
└── sound
```

### Flow (optional)

```
User → nsf_audios API → music/sound → SFML Audio → Output device
```

---

## 🔹 Dependencies

| Module        | Usage                          |
|---------------|--------------------------------|
| `nsf_game`    | Allocation tracking            |
| `nsf_systems` | Utilities, memory helpers      |
| `CSFML`       | Audio backend (`sfMusic`, etc) |

---

## 🔹 Key Responsibilities

* Provide unified audio API for the framework
* Manage lifecycle of audio resources
* Separate use-cases:

    * **Music** → long, streamed audio
    * **Sound** → short, memory-loaded effects
* Ensure safe memory handling and tracking

**Must NOT:**

* Handle mixing logic or advanced DSP
* Manage global audio state (no central mixer yet)
* Expose raw SFML objects outside modules

---

## 🔹 Submodules

| Submodule | Description                                    |
|-----------|------------------------------------------------|
| `music`   | Streamed audio playback (background music)     |
| `sound`   | Buffered sound effects (UI, gameplay feedback) |

---

## 🔹 Public API Summary

### High-Level Functions

| Function        | Description                   |
|-----------------|-------------------------------|
| *(none global)* | Module is split per submodule |

---

### Subsystem APIs

| Subsystem | Example Function   |
|-----------|--------------------|
| `music`   | `nsf_music_play()` |
| `sound`   | `nsf_sound_play()` |

---

## 🔹 Usage Example

```c
nsf_music_t *music = nsf_music_create("bg.ogg", "main_theme", game);
nsf_sound_t *click = nsf_sound_create("click.wav", "ui_click", game);

nsf_music_play(music);
nsf_sound_play(click);
```

---

## 🔹 Data Flow

| Step | Action                           |
|------|----------------------------------|
| 1    | Load resource via `create()`     |
| 2    | Register allocation (via `game`) |
| 3    | Use playback controls            |
| 4    | Query state if needed            |
| 5    | Cleanup via `destroy()`          |

---

## 🔹 Design Constraints

* Must separate **streamed vs buffered** audio
* Must use `nsf_game_t` for allocation tracking
* Must avoid exposing SFML internals
* Must remain lightweight and modular

---

## 🔹 Common Patterns

* Load → Play → Stop → Destroy
* Name-based identification (debug / registry)
* Independent instances (no shared global audio state)

---

## 🔹 Known Limitations

* No global audio manager (volume groups, mixing)
* No built-in fade or transition system
* No async loading (blocking file load)
* No spatial/3D audio support (yet)

---

## 🔹 Documentation Index

This section provides quick access to the audio module documentation.
Detailed behavior and API are described within each submodule.

### Submodules

* [Music](music.md) — Streamed audio playback (background tracks)
* [Sound](sound.md) — Buffered sound effects (short audio)

---

## 🔹 Related Modules

* [Games](../games/overview.md)
* [Systems](../systems/overview.md)

---

## 🔹 Notes

* This module is a **thin abstraction**, not a full audio engine
* Designed for simplicity and predictability
* Keeps SFML interaction strictly encapsulated

---

## 🔹 Internal Files

| File          | Role                        |
|---------------|-----------------------------|
| `*_struct.c`  | Data structures & lifecycle |
| `*_manage*.c` | Logic and transformations   |

---

## 🔹 Extension Guidelines

* Add new audio features in submodules (`music` / `sound`)
* Keep APIs consistent (`nsf_audio_<type>_<action>`)
* Avoid merging sound/music logic
* Consider adding a future `audio_manager` layer instead of extending core

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
newcsfml   v0.2.7
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
