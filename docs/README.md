# 📦 Epitech Base

> Centralized repository of reusable C libraries, build tools, and project templates designed for EPITECH development workflows.

---

## 🔹 Short Description

**Epitech Base is a structured repository that provides a complete ecosystem for C development, including reusable libraries, an advanced Makefile system, and a ready-to-use project template.**

It is designed to **accelerate development**, **standardize project architecture**, and **reduce code duplication** across projects.

---

## 🔹 Authors

* Nathan (Jarjarbin06)
* EPITECH Project

---

## 🔹 Licence

GPL v3

---

## 🔹 Target Audience

This repository is designed for:

* EPITECH students
* C developers building modular projects
* Developers needing reusable libraries
* Users of structured build systems and automation tools

---

## 🔹 Purpose

Epitech Base aims to:

* Centralize reusable C libraries
* Provide a powerful and automated Makefile system
* Standardize project structure across repositories
* Simplify library integration and reuse
* Offer a scalable development environment

---

## 🔹 Repository Architecture

```

.
├── build_files/      → Core libraries, template, and builder system
├── docs/             → Global documentation (libs + Makefile)
├── Makefile          → Main project controller
├── Licence
└── ForTheComminity

```

---

## 🔹 Core Components

### 🧱 Libraries System

All reusable libraries are located in:

```

build_files/lib/

```

Includes:

* Utility libraries (`utils`, `flag`, `str`, `print`, `newerror`)
* Data structures (`llist`, `twodlist`)
* File handling (`file`)
* Framework (`newcsfml`)
* Libraries tests (`test_lib`)

📖 Full documentation:  
→ [Libraries Documentation](lib.md)

---

### ⚙️ Makefile System

The repository includes an advanced Makefile that manages:

* Compilation
* Library linking
* Testing
* Git automation
* Project initialization
* Library import system

📖 Full documentation:  
→ [Makefile Documentation](makefile.md)

---

### 🏗️ Project Template

Located in:

```

build_files/tree/

```

Provides a ready-to-use project structure:

```

includes/
sources/
lib/
tests/
bonus/

````

Used by the Makefile `build` rule to initialize new projects.

---

### 🔧 Builder Script

```bash
build_files/builder.sh
````

* Automates repository setup
* Can be used for quick initialization or scripting workflows

---

## 🔹 Development Workflow

### 1. Initialize Project

```bash
make build
```

* Copies template structure
* Sets up base environment

---

### 2. Import Libraries

```bash
make import_str
make import_utils
make import_all
```

---

### 3. Develop

* Write code in `sources/`
* Use headers from `includes/`

---

### 4. Compile

```bash
make
```

---

### 5. Test

```bash
make test_run
make test_valgrind
```

---

## 🔹 Documentation System

All global documentation is located in:

```
docs/
```

### Main Entries

* → [Libraries Documentation](lib.md)
* → [Makefile Documentation](makefile.md)

Each library may also contain its own README or `docs/` folder.

---

## 🔹 Key Features

* 📦 Modular library system
* ⚙️ Advanced Makefile automation
* 🔁 Automatic library import/update
* 🧪 Integrated testing tools
* 🏗️ Project template system
* 🔄 Git workflow integration
* 🧱 Scalable architecture

---

## 🔹 Design Philosophy

* Modular and reusable components
* Clear separation of responsibilities
* Minimal manual configuration
* Automation-first workflow
* EPITECH-compatible standards

---

## 🔹 Current State

⚠️ Repository is **actively evolving**

Status:

* Core libraries implemented and stable
* Makefile system advanced and functional
* Documentation expanding
* New features and libraries in progress

---

## 🔹 Notes

* Designed for productivity and consistency
* Libraries are independent but interoperable
* Not a monolithic framework, but a toolbox
* Encourages clean and scalable project design

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
