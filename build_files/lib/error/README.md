# liberror

A lightweight, flexible, and extensible error handling system for C.

This library provides a unified way to:
- Create structured errors
- Attach context (file, function, line)
- Print formatted debug information
- Return values (int, pointer, void) while handling errors

---

# Core Concept

The system is built around a central structure:

```c
typedef struct {
    const char *title;
    const char *msg;
    const char *file;
    const char *func;
    int line;
    bool fatal;
} err_t;
````

Errors are:

* **Structured** (not just strings)
* **Context-aware** (auto-filled with macros)
* **Composable** (can be updated dynamically)

---

# Quick Usage

## Basic Example

```c
return err.i(ERR(), 0);
```

## With Message

```c
return err.i(upt(ERR(), "Error", "Something failed"), 0);
```

## Fatal Error

```c
return err.ie(ftl(upt(ERR(), "Critical", "Fatal issue")));
```

---

# ERR Macro (Core)

```c
#define ERR() (err_t[]){{NULL, NULL, __FILE__, __FUNCTION__, __LINE__, 0}}
```

Creates an error with:

* File name
* Function name
* Line number
* Empty title/message
* Non-fatal by default

This is the **entry point of the system**.

---

# Data Management

## Update Error

```c
err_t *err_data_upt(const err_t *error, title_t title, message_t msg);
```

* Updates title and/or message
* Keeps existing data if NULL

## Set Fatal

```c
err_t *err_data_ftl(const err_t *error);
```

* Marks error as fatal
* Adds visual emphasis during printing

---

# Error Output

## Main Printer

```c
void err_print(const err_t error[]);
```

### Output Format

```
----------
 /!\ FATAL /!\        (if fatal)
 Error:
 message

 "file.c" in func() at line X
```

### Features

* Colored output (ANSI)
* Structured formatting
* Automatic context display

---

# Return-Based Error Helpers

## Integer

```c
int err_int(const err_t error[], int value);
int err_int_error(const err_t error[]);
```

* Prints error
* Returns:

    * Custom value
    * `EXIT_ERROR` (84)

### Simple Version

```c
int err_int_simple(const char *title, const char *msg, int value);
int err_int_error_simple(const char *title, const char *msg);
```

---

## Pointer

```c
void *err_pointer(const err_t error[], void *ptr);
void *err_pointer_null(const err_t error[]);
```

* Prints error
* Returns:

    * Provided pointer
    * `NULL` (via `NL`)

### Simple Version

```c
void *err_pointer_simple(const char *title, const char *msg, void *ptr);
void *err_pointer_null_simple(const char *title, const char *msg);
```

---

## Void

```c
void err_void(const err_t error[]);
```

* Prints error only

### Simple Version

```c
void err_void_simple(const char *title, const char *msg);
```

---

# Shortcut API

All functions are grouped into a single structure:

```c
const error_list_t err;
```

## Usage

```c
err.v(ERR());                  // void
err.p(ERR(), ptr);             // pointer
err.pn(ERR());                 // NULL pointer
err.i(ERR(), value);           // int
err.ie(ERR());                 // int error (84)
```

---

# Shortcuts

Direct function aliases:

```c
verror(ERR());     // void
nerror(ERR());     // NULL pointer
ierror(ERR());     // int error (84)

upt(ERR(), "title", "msg");
ftl(ERR());
```

---

# Configuration

## Exit Codes

```c
#define EXIT_SUCCESS 0
#define EXIT_ERROR 84
```

## Special Values

```c
#define NL (void *)0
#define INT_ERR EXIT_ERROR
#define ERR_FILE STDERR_FILENO
```

## Colors (ANSI)

* Error (red)
* Warning (yellow)
* Valid (green)
* Debug (blue)
* Formatting (bold, italic, underline, etc.)

---

# Design Principles

* **Minimal overhead**: stack-based error creation
* **No heap allocation**
* **Consistent API**
* **Composable errors**
* **Clear separation**:

    * Data (`err_t`)
    * Processing (`upt`, `ftl`)
    * Output (`err_print`)
    * Return helpers (`err.i`, `err.p`, ...)

---

# Best Practices

* Always start with `ERR()`
* Use `upt()` to add context
* Use `ftl()` for critical failures
* Prefer `err.*` API over simple versions
* Keep messages short and explicit

---

# Example Patterns

## Return NULL on failure

```c
return err.pn(upt(ERR(), "Malloc failed", "buffer allocation"));
```

## Return error code

```c
return err.ie(upt(ERR(), "Invalid input", "argc < 2"));
```

## Log only

```c
err.v(upt(ERR(), "Warning", "unexpected value"));
```

---

# Maintainability Notes

* Add new return types by extending `error_list_t`
* Keep `ERR()` as the single creation entry point
* Avoid duplicating logic outside helper functions
* Keep formatting centralized in `err_print`

---
