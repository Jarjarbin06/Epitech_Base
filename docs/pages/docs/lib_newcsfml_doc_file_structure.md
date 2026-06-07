---
title: Library NewCSFML
sidebar: sidebar
permalink: lib_newcsfml_doc_file_structure.html
folder: docs
---

# 📦 File Structure

Defines how the NewCSFML framework is organized across documentation, headers, and source implementation.

> The structure follows a strict modular design: each subsystem is split into headers, implementations, and documentation pages.

---

## 🔹 Root Layout

```text
.
├── includes/
├── sources/
└── Makefile
````

---

## 🔹 Includes Structure

```text
includes/
├── newcsfml/
└── newcsfml.h
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
* Keep strict 1:1 mapping between include and source
* Avoid deep nesting (>4 levels)
