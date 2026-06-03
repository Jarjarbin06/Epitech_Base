# 📦 Vector Module (`nsf_vector`)
#### part of [Systems](overview.md)

Mathematical vector utility module for 2D operations and conversions.

> Provides a complete set of tools for vector manipulation, conversion, and geometric computations.

---

## 🔹 Header

```c
#include <newcsfml/systems/vector.h>
```

---

## 🔹 Structure

```c
typedef struct {
    // Uses SFML native vector types
} nsf_<type>vector_t;
```

### Description

| Field    | Type    | Description                                    |
|----------|---------|------------------------------------------------|
| *(none)* | *(n/a)* | This module does not define a custom structure |

---

## 🔹 Purpose

This module provides all fundamental operations related to 2D vectors.

* Main responsibility: vector math operations and type conversions
* Abstracts: `sfVector2f`, `sfVector2i`, `sfVector2u`
* Architecture role: low-level math system used across graphics, physics, and logic modules

---

## 🔹 Dependencies

| Module      | Usage                               |
|-------------|-------------------------------------|
| `nsf_utils` | Safety checks (`NSF_UNLIKELY`)      |
| *(math.h)*  | Trigonometry and numeric operations |

---

## 🔹 API

### Creation / Destruction

| Function | Description           |
|----------|-----------------------|
| *(none)* | No dynamic allocation |

---

### Core Functions

| Function                    | Description                      |
|-----------------------------|----------------------------------|
| `nsf_fvector_copy(...)`     | Copy float vector                |
| `nsf_ivector_copy(...)`     | Copy int vector                  |
| `nsf_uvector_copy(...)`     | Copy unsigned vector             |
| `nsf_vector_add(...)`       | Add two vectors                  |
| `nsf_vector_sub(...)`       | Subtract two vectors             |
| `nsf_vector_mul(...)`       | Multiply by scalar               |
| `nsf_vector_div(...)`       | Divide by scalar                 |
| `nsf_vector_len(...)`       | Compute vector length            |
| `nsf_vector_norm(...)`      | Normalize vector                 |
| `nsf_vector_dist_to(...)`   | Distance between two points      |
| `nsf_vector_dir_to(...)`    | Direction vector between points  |
| `nsf_vector_dot(...)`       | Dot product                      |
| `nsf_vector_cross(...)`     | Cross product (2D scalar result) |
| `nsf_vector_get_angle(...)` | Angle in degrees                 |
| `nsf_vector_rotate(...)`    | Rotate vector                    |

---

### Advanced / Optional

| Function                  | Description              |
|---------------------------|--------------------------|
| `nsf_vector_clamp(...)`   | Clamp both axes          |
| `nsf_vector_clamp_x(...)` | Clamp X axis             |
| `nsf_vector_clamp_y(...)` | Clamp Y axis             |
| `nsf_vector_print(...)`   | Debug print              |
| `nsf_fvector_from_i(...)` | Convert int → float      |
| `nsf_fvector_from_u(...)` | Convert unsigned → float |
| `nsf_ivector_from_f(...)` | Convert float → int      |
| `nsf_uvector_from_f(...)` | Convert float → unsigned |
| `nsf_fvector_empty(...)`  | Initialize to zero       |
| `nsf_ivector_empty(...)`  | Initialize to zero       |
| `nsf_uvector_empty(...)`  | Initialize to zero       |

---

## 🔹 Parameters Reference

| Name     | Type              | Description         |
|----------|-------------------|---------------------|
| `a`      | `nsf_fvector_t *` | First vector        |
| `b`      | `nsf_fvector_t *` | Second vector       |
| `v`      | `nsf_fvector_t *` | Input vector        |
| `out`    | `nsf_fvector_t *` | Output vector       |
| `scalar` | `float`           | Scalar value        |
| `min`    | `float`           | Minimum clamp value |
| `max`    | `float`           | Maximum clamp value |

---

## 🔹 Return Values

| Type    | Meaning                         |
|---------|---------------------------------|
| `float` | Computed value (length, angle…) |
| `void`  | Result written in `out`         |
| `0/-1`  | Error fallback (invalid input)  |

---

## 🔹 Notes

* No dynamic allocation → safe and fast
* Heavy use of output parameters (`out`) to avoid copies
* Uses defensive programming (`NSF_UNLIKELY`)
* Custom square root approximation in `nsf_vector_len`
* Angles are in **degrees**, not radians
* Macros provided:

    * `NSF_PI`
    * `NSF_RADIAN(x)`
    * `NSF_DEGREE(x)`

---

## 🔹 Internal Files

| File                           | Role                      |
|--------------------------------|---------------------------|
| `nsf_vector_manage_f.c`        | Float vector utilities    |
| `nsf_vector_manage_i.c`        | Integer vector utilities  |
| `nsf_vector_manage_u.c`        | Unsigned vector utilities |
| `nsf_vector_manage_angle.c`    | Angle utilities           |
| `nsf_vector_manage_clamp.c`    | Clamp utilities           |
| `nsf_vector_manage_relative.c` | Comparission utilities    |
| `nsf_vector_manage_special.c`  | Special utilities         |
| `nsf_vector_debug.c`           | Debug                     |

---

## 🔹 Related Submodules

* [`nsf_sprite` 🔗](../graphics/sprite.md) 
* [`nsf_button` 🔗](../graphics/button.md)

---

## 🔹 CSFML Mapping (Optional)

| NSF             | CSFML        |
|-----------------|--------------|
| `nsf_fvector_t` | `sfVector2f` |
| `nsf_ivector_t` | `sfVector2i` |
| `nsf_uvector_t` | `sfVector2u` |

---

## 🔹 Implementation Notes (for contributors)

* Always validate pointers (`NSF_UNLIKELY`)
* Prefer stack allocation over heap
* Keep functions pure (no side effects)
* Maintain consistent `out` parameter usage
* Follow Epitech C coding style

---

## 🔹 Extension Points

* Add interpolation functions (lerp, slerp)
* Add matrix support for transformations
* SIMD optimization for vector math
* Extend to 3D vectors if needed

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
