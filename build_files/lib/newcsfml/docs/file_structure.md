# 📦 File Structure

Defines how the NewCSFML framework is organized across documentation, headers, and source implementation.

> The structure follows a strict modular design: each subsystem is split into headers, implementations, and documentation pages.

---

## 🔹 Root Layout

```text
.
├── docs/
├── includes/
├── sources/
└── Makefile
````

---

## 🔹 Documentation Structure

```text
docs/
├── modules/
├── template/
├── best_practices.md
├── file_structure.md
├── naming_conventions.md
├── quick_reference.md
└── README.md
```

### Modules Documentation

```text
docs/modules/
├── audios/
├── games/
├── graphics/
└── systems/
```

| Folder   | Role                          |
|----------|-------------------------------|
| audios   | Audio subsystem documentation |
| games    | Core engine documentation     |
| graphics | Rendering subsystem docs      |
| systems  | Utility / low-level docs      |

---

## 🔹 Template Structure

```text
docs/template/
├── overview.md
└── submodule.md
```

| File      | Role                          |
|-----------|-------------------------------|
| overview  | Module documentation template |
| submodule | Structure/API template        |

---

## 🔹 Includes Structure

```text
includes/
├── newcsfml.h
└── newcsfml/
```

| Module       | Role                     |
|--------------|--------------------------|
| newcsfml     | main include entry point |
| `newcsfml.h` | global module header     |

### Core Modules

```text
includes/newcsfml/
├── audios/
├── games/
├── graphics/
├── systems/
└── *.h
```

| Module   | Role                        |
|----------|-----------------------------|
| audios   | Audio API (music, sound)    |
| games    | Engine / window / events    |
| graphics | Rendering (sprite, UI, etc) |
| systems  | Utilities / math / helpers  |
| `*.h`    | global submodule header     |

---

## 🔹 Audio Headers

```text
audios/
├── music.h
└── sound.h
```

| File  | Role                   |
|-------|------------------------|
| music | Streamed audio system  |
| sound | Buffered sound effects |

---

## 🔹 Game Headers

```text
games/
├── game.h
├── window.h
├── event.h
└── window_settings.h
```

| File            | Role                    |
|-----------------|-------------------------|
| game            | Core engine controller  |
| window          | Render + event handling |
| event           | Input abstraction       |
| window_settings | Window configuration    |

---

## 🔹 Graphics Headers

```text
graphics/
├── sprite.h
├── button.h
├── texture.h
└── background.h
```

| File       | Role                   |
|------------|------------------------|
| sprite     | Drawable entity        |
| button     | UI interaction element |
| texture    | GPU resource wrapper   |
| background | Scene background       |

---

## 🔹 Systems Headers

```text
systems/
├── vector.h
├── color.h
├── utils.h
├── clock.h
└── other.h
```

| File   | Role                |
|--------|---------------------|
| vector | Math structures     |
| color  | Color utilities     |
| utils  | Generic helpers     |
| clock  | Time management     |
| other  | Other lib functions |

---

## 🔹 Source Structure

```text
sources/
├── audios/
├── games/
├── graphics/
├── systems/
└── newcsfml.c
```

---

## 🔹 Audio Implementation

```text
sources/audios/
├── music/
└── sound/
```

| Folder | Role                        |
|--------|-----------------------------|
| music  | Music system implementation |
| sound  | Sound system implementation |

---

## 🔹 Game Implementation

```text
sources/games/
├── game/
├── window/
├── event/
└── window_settings/
```

| Folder          | Role                 |
|-----------------|----------------------|
| game            | Core game logic      |
| window          | Rendering system     |
| event           | Input handling       |
| window_settings | Window configuration |

---

## 🔹 Graphics Implementation

```text
sources/graphics/
├── sprite/
├── button/
├── texture/
└── background/
```

| Folder     | Role                 |
|------------|----------------------|
| sprite     | Sprite logic         |
| button     | UI system            |
| texture    | Texture loading      |
| background | Background rendering |

---

## 🔹 Systems Implementation

```text
sources/systems/
├── vector/
├── color/
├── clock/
├── utils/
└── other/
```

| Folder | Role                     |
|--------|--------------------------|
| vector | Math operations          |
| color  | Color extern definitions |
| clock  | Time system              |
| utils  | Allocation helpers       |
| other  | String utilities         |

---

## 🔹 Build Structure

| Step    | Component      |
|---------|----------------|
| Compile | sources/       |
| Include | includes/      |
| Link    | static library |

---

## 🔹 Dependency Flow

```text
systems → graphics → games → application
```

| Layer    | Role                 |
|----------|----------------------|
| systems  | Base utilities       |
| graphics | Rendering layer      |
| games    | Engine orchestration |

---

## 🔹 Extension Rules

* New module → `includes/newcsfml/<module>/`
* Matching implementation → `sources/<module>/`
* Documentation → `docs/modules/<module>/`
* Keep strict 1:1 mapping between include and source
* Avoid deep nesting (>3 levels)

---
