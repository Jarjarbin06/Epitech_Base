# libutils

A minimal utility library focused on memory management and helper functions. Currently, it provides basic allocation, deallocation, and automated freeing mechanisms.

---

# Core Concept

This library centralizes dynamic memory handling with added safety and automation features.

Main functions:

- `malloc_any` – Allocate memory safely.
- `free_any` – Free memory safely.
- `auto_free` – Conditional freeing for arrays of pointers.
- `free_array` – Free a NULL-terminated array of pointers and the array itself.

---

# Function API

## `malloc_any`

```c
void *malloc_any(unsigned size);
````

* Allocates memory of `size` bytes.
* Returns `NULL` if allocation fails.
* Simple wrapper around `malloc`.

**Example:**

```c
int *arr = malloc_any(sizeof(int) * 10);
if (!arr) {
    // handle allocation failure
}
```

---

## `free_any`

```c
void *free_any(void *ptr);
```

* Frees the memory pointed to by `ptr`.
* Returns `NULL` (useful for immediate reassignment).
* Prevents double frees if used consistently.

**Example:**

```c
arr = free_any(arr);  // arr is now NULL
```

---

## `auto_free`

```c
int auto_free(unsigned len, free_t free_list[]);
```

* Frees memory conditionally based on the `condition` field in a `free_t` array.
* Updates the pointers to `NULL` after freeing.
* Returns the number of elements successfully freed.

**Structure:**

```c
typedef struct {
    bool condition;       // Should this element be freed?
    void *ptr;            // Pointer to memory
    void_func_t free_func;// Function to call for freeing
} free_t;
```

**Example:**

```c
free_t to_free[] = {
    {true, &ptr1, (void_func_t)free_any},
    {false, &ptr2, (void_func_t)free_any}
};

int freed_count = auto_free(2, to_free); // Only ptr1 will be freed
```

---

## `free_array`

```c
void *free_array(void **array);
````

* Frees a NULL-terminated array of pointers.
* Each element is freed individually using `free_any`.
* Finally, the array itself is freed.
* Returns `NULL` for convenient pointer reassignment.

**Example:**

```c
char **lines = malloc_any(sizeof(char *) * 5);
// allocate individual lines
lines = free_array((void **)lines); // frees lines and the array itself, lines is now NULL
```


---

# Internal Flow

1. Allocate memory using `malloc_any`.
2. Track pointers and conditions in `free_t` structures.
3. Use `auto_free` for conditional and safe freeing.
4. Use `free_array` to clean up arrays of dynamically allocated pointers.

---

# Design Principles

* **Safety:** Prevents memory leaks by centralizing free operations.
* **Automation:** Supports batch freeing via `auto_free`.
* **Modularity:** Custom free function can be applied per pointer.
* **Consistency:** Always sets freed pointers to `NULL`.

---

# Limitations

* Only a subset of utility functions is implemented (focus on memory).
* Does not track memory allocations automatically beyond `free_t` arrays.
* No built-in error reporting for `malloc_any` beyond returning `NULL`.

---

# Best Practices

* Always wrap allocations with `malloc_any` for uniformity.
* Use `auto_free` or `free_array` to prevent leaks in complex data structures.
* Ensure NULL-termination for arrays passed to `free_array`.
* Maintain a consistent `free_t` list for conditionally allocated resources.

---
