# libstr

A lightweight, flexible, and extensible string manipulation library for C.

This library provides a unified way to:

* Handle strings safely
* Perform common string operations
* Transform, check, print, and manage strings
* Split strings into arrays and concatenate dynamically

---

# Core Concept

The system is built around a central structure:

```c
typedef struct {
    str_transform_t t;
    str_put_t p;
    str_check_t c;
    str_get_t g;
    str_manage_t m;
} str_str_t;
```

Strings operations are grouped into:

* **Transformations**: reverse, capitalize, lower/upper case, swap characters
* **Print**: print strings, characters, and integers
* **Checks**: test for alpha, numeric, printable, lower/upper case, comparisons
* **Getters**: retrieve numbers, length, or split into word arrays
* **Management**: copy, duplicate, concatenate, or partially duplicate strings

All functions use `str_t`, `cstr_t` and `cc_t` (`char *`, `const char *` and `const char`) for consistency and safety.

---

# Quick Usage

## Basic Example

```c
str_put_str("Hello World!\n");       // Prints string
str_put_nbr(42);                     // Prints integer
```

## Transform Example

```c
str_t s = str_dup("hello");
s = str_capitalize(s);               // "Hello"
s = str_upcase(s);                    // "HELLO"
s = str_reverse(s);                   // "OLLEH"
```

## Check Example

```c
if (str_is_alpha("Hello"))
    str_put_str("All letters!\n");

if (str_c_is_num('5'))
    str_put_str("Digit!\n");
```

## Split Example

```c
str_t *words = str_to_word_array("one,two,three", ',');
str_put_str(words[1]);                // Prints "two"
free_array((void **)words);
```

---

# Function Groups

## Transformations (`str_transform_t`)

* `str_reverse(str_t)`
* `str_capitalize(str_t)`
* `str_lowcase(str_t)`
* `str_upcase(str_t)`
* `str_c_swap(str_t, str_t)`

---

## Printing (`str_put_t`)

* `str_put_nbr(int)`
* `str_put_char(char)`
* `str_put_str(str_t)`

---

## Checks (`str_check_t`)

* `str_c_is_alpha(char)`, `str_is_alpha(str_t)`
* `str_c_is_num(char)`, `str_is_num(str_t)`
* `str_c_is_lower(char)`, `str_is_lower(str_t)`
* `str_c_is_upper(char)`, `str_is_upper(str_t)`
* `str_c_is_printable(char)`, `str_is_printable(str_t)`
* `str_cmp(str_t, str_t)`

---

## Getters (`str_get_t`)

* `str_get_nbr(str_t)` → int
* `str_len(str_t)` → int
* `str_to_word_array(str_t, char)` → `str_t *` array

---

## Management (`str_manage_t`)

* `str_cat(str_t, str_t)`
* `str_cpy(str_t, str_t)`
* `str_dup(str_t)`
* `str_ndup(str_t, int)`

---

# Memory Utilities

Included utilities for safer memory management:

* `malloc_any(size_t)` → allocate memory
* `free_any(void *)` → free memory
* `auto_free(len, free_t list[])` → conditional batch free
* `free_array(void **)` → free array of pointers

---

# Shortcut API

All functions are grouped into a single global structure:

```c
const str_str_t str;
```

## Usage

```c
str.t.reverse("Hello");      // Transform
str.p.str("Hello World");    // Print
str.c.alpha("Test");         // Check
str.g.word_array("a,b,c", ','); // Split
str.m.dup("Hello");          // Manage
```

---

# Best Practices

* Always free dynamic strings (`str_dup`, `str_ndup`) using `free_any` or `free_array`
* Use `str_str_t` shortcuts to avoid calling individual functions directly
* Prefer `str_to_word_array` over manual splitting for consistency
* Keep all transformations immutable unless explicitly swapped with `str_c_swap`

---

# Notes

* Functions marked `.off` in the source tree are still in development
* Library is designed to be **extensible**—new string tools can be added without breaking the API
* Works with `str_t` (`char *`) throughout for uniformity
* Integrates memory helpers for safe allocation/deallocation

---
