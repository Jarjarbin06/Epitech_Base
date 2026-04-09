# libprint

A custom implementation of `printf`, designed to replicate and extend parts of the standard `<stdio.h>` behavior.

This library provides:
- Formatted output with variadic arguments
- Flag parsing system
- Multiple numeric and string conversions
- Modular and extensible conversion handling

---

# Core Concept

The main entry point:

```c
int print(const char *format, ...);
````

* Parses the format string
* Handles flags, width, precision
* Dispatches conversions dynamically
* Returns the number of printed characters

---

# Supported Conversions

| Specifier     | Description                   |
|---------------|-------------------------------|
| `d`, `i`      | Signed integer                |
| `u`           | Unsigned integer              |
| `o`           | Octal                         |
| `x`, `X`      | Hexadecimal                   |
| `f`, `F`      | Floating point                |
| `e`, `E`      | Scientific notation           |
| `g`, `G`      | Shortest float representation |
| `c`           | Character                     |
| `s`           | String                        |
| `p`           | Pointer                       |
| `%`           | Literal `%`                   |
| `\n`          | New line                      |
| `m`           | Custom stderr output          |
| `a`, `A`, `n` | Error (not implemented)       |

---

# Basic Usage

```c
print("Value: %d\n", 42);
```

```c
print("Hex: %x | Float: %.2f\n", 255, 3.14);
```

---

# Internal Architecture

## 1. Format Validation

```c
static int check_format(const char *format);
```

* Ensures format string is valid
* Prevents malformed `%` sequences
* Verifies conversion correctness

Returns:

* `1` → valid
* `0` → invalid

---

## 2. Parsing & Display

```c
static void display(va_list list, p_display_param_t *Disp);
```

* Extracts flags and modifiers
* Determines conversion type
* Calls the appropriate handler

---

## 3. Conversion Dispatch

```c
void p_display_conv(char conv, va_list list, int *c_tt, p_flag_t *Flag);
```

Uses a lookup table:

```c
static const p_list_t Conv[];
```

Each conversion is mapped to a function pointer.

---

# Flag System

## Structure

```c
typedef struct {
    bool is_hashtag;
    bool is_zero;
    bool is_dash;
    bool is_space;
    bool is_plus;
    int *width;
    int *precision;
    char *length_mod;
} p_flag_t;
```

---

## Supported Flags

| Flag | Description      |
|------|------------------|
| `#`  | Alternative form |
| `0`  | Zero padding     |
| `-`  | Left alignment   |
| ` `  | Space prefix     |
| `+`  | Force sign       |
| `.`  | Precision        |

---

## Parsing

```c
int p_get_flag(const char *format, int idx, p_flag_t *Flag);
```

Handles:

* Precision (`.`)
* Space
* Plus
* Hashtag

Example:

```c
int p_get_precision(const char *format, int idx, p_flag_t *Flag);
```

---

# Conversion System

Each conversion is handled by a dedicated function.

## Examples

```c
p_conv_to_dec()
p_conv_to_hex()
p_conv_put_float()
p_conv_put_str()
p_conv_put_pointer()
```

---

## Base Conversion

```c
void p_put_nbr_base(p_lli_t nb, const char *base, int *c_tt, p_flag_t *Flag);
```

Used for:

* Binary
* Octal
* Hexadecimal

---

## Floating Point

```c
void p_put_float(p_ld_t nb, int *char_total, p_flag_t *Flag);
```

Supports:

* Precision handling
* Scientific notation
* `g` / `G` formatting

---

## Special Cases

```c
int p_is_inf_or_nan(...)
```

Handles:

* `inf`
* `nan`

---

# Output System

## Character Output

```c
void p_put_char(char c, int *char_total);
```

## String Output

```c
void p_put_str(const char *str, int *char_total);
```

* Updates printed character count
* Used across all conversions

---

# Error Handling

## Invalid Conversions

```c
void p_conv_err(...)
```

* Used for unsupported specifiers (`a`, `A`, `n`)

## Length Modifiers

```c
void p_len_mod_err(...)
```

* Currently not implemented
* Outputs:

```
[err]
```

---

# Utility Functions

```c
bool p_is_num(char c);
int p_get_nbr(const char *str);
int p_strlen(const char *str);
```

---

# Internal Flow

1. Validate format (`check_format`)
2. Iterate through string
3. Detect `%`
4. Parse flags
5. Identify conversion
6. Dispatch handler
7. Print result
8. Update character count

---

# Design Principles

* **Modular conversion system**
* **Function pointer dispatch**
* **Custom flag parsing**
* **Minimal dependencies**
* **Extendable architecture**

---

# Limitations

* Length modifiers are not implemented
* Some conversions (`a`, `A`, `n`) are not supported
* Behavior may differ from standard `printf`

---

# Best Practices

* Always validate format strings
* Prefer supported conversions only
* Avoid using unsupported length modifiers
* Keep format strings simple for reliability

---

# Example Patterns

## Multiple Conversions

```c
print("Int: %d | Hex: %x | Float: %.2f\n", 42, 42, 3.14);
```

## Flags Usage

```c
print("Value: %+08d\n", 42);
```

---

# Maintainability Notes

* Add new conversions in `Conv[]`
* Keep flag parsing centralized
* Extend `p_flag_t` if needed
* Keep conversion functions isolated
* Maintain consistent naming: `p_conv_*`

---
