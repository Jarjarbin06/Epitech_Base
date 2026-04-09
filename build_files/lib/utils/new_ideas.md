# New Ideas for libutils

---

## New Features

1. **Custom Allocator System**

   ```c
   void utils_set_allocator(void *(*malloc_fn)(size_t), void (*free_fn)(void *));
   ```

   *Why:* Allows integration with custom memory managers (game engines, embedded systems, debugging allocators).

2. **Memory Tracking / Debug Mode**

   ```c
   void utils_mem_debug_enable();
   void utils_mem_report();
   ```

   *Why:* Track allocations, detect leaks, and provide reports for debugging.

3. **Reallocation Wrapper**

   ```c
   void *realloc_any(void *ptr, size_t size);
   ```

   *Why:* Completes the allocation API and simplifies resizing buffers safely.

4. **Safe Free Macro**

   ```c
   #define SAFE_FREE(ptr) ((ptr) = free_any(ptr))
   ```

   *Why:* Reduces boilerplate and enforces correct usage.

5. **Scoped Cleanup System (RAII-like)**

   ```c
   utils_scope_begin();
   utils_scope_add(ptr, free_any);
   utils_scope_end();
   ```

   *Why:* Automatically frees resources at scope exit, reducing manual cleanup.

6. **Memory Pool / Arena Allocator**

   ```c
   utils_pool_t *pool_create(size_t size);
   void *pool_alloc(utils_pool_t *, size_t size);
   void pool_destroy(utils_pool_t *);
   ```

   *Why:* Improves performance for many small allocations.

7. **Zero-Initialized Allocation**

   ```c
   void *calloc_any(size_t count, size_t size);
   ```

   *Why:* Common use case, avoids manual initialization.

8. **Pointer Array Utilities**

   ```c
   void **array_create(size_t size);
   ```

   *Why:* Simplifies dynamic array handling beyond `free_array`.

9. **Error Callback System**

   ```c
   void utils_set_error_handler(void (*handler)(const char *msg));
   ```

   *Why:* Allows custom handling of allocation failures.

10. **Bulk Allocation / Free Helpers**

```c
void utils_free_all(void **ptrs, size_t count);
```

*Why:* Simplifies freeing multiple pointers without `free_t`.

---

## Improvements

1. **Use `size_t` Instead of `unsigned`**

   ```c
   void *malloc_any(size_t size);
   ```

   *Why:* Ensures correctness across platforms and large allocations.

2. **Optimize `auto_free` Structure**

    * Store direct pointers instead of pointer-to-pointer when possible.
      *Why:* Reduces indirection and improves performance.

3. **Inline Small Functions**

    * `free_any`, simple wrappers.
      *Why:* Reduces function call overhead.

4. **Batch Free Optimization**

    * Loop unrolling or grouping frees.
      *Why:* Improves performance for large arrays.

5. **Avoid Redundant NULL Assignments**

    * Only assign NULL if pointer is non-null.
      *Why:* Minor performance and clarity improvement.

6. **Improve `free_array` Efficiency**

    * Pre-check for NULL array.
      *Why:* Avoid unnecessary operations.

7. **Reduce Function Pointer Overhead in `auto_free`**

    * Provide default fast path for `free_any`.
      *Why:* Improves speed in common cases.

---

## Fixes / Bug Prevention

1. **NULL Safety Everywhere**

    * Ensure all functions handle NULL gracefully.
      *Why:* Prevents segmentation faults.

2. **Double Free Protection**

    * Check pointer before freeing.
      *Why:* Avoids undefined behavior.

3. **Invalid Pointer Detection (Debug Mode)**

    * Track allocated pointers and validate before freeing.
      *Why:* Helps detect misuse.

4. **Overflow Checks in Allocation**

   ```c
   if (size > SIZE_MAX / count) return NULL;
   ```

   *Why:* Prevents integer overflow vulnerabilities.

5. **Consistent Return Values**

    * Ensure all free functions return NULL reliably.
      *Why:* Prevents inconsistent usage.

6. **Safe `free_array` Termination**

    * Validate NULL termination.
      *Why:* Prevents out-of-bounds access.

7. **Thread Safety Considerations**

    * Protect shared state in debug/tracking mode.
      *Why:* Prevents race conditions.

---

## Code Quality / Maintainability

1. **Modular File Structure**

    * `alloc.c`, `free.c`, `auto_free.c`, `debug.c`.
      *Why:* Improves readability and separation of concerns.

2. **Internal vs Public API Separation**

    * Hide internal helpers.
      *Why:* Prevents misuse and simplifies interface.

3. **Consistent Naming Convention**

    * Prefix all functions with `utils_`.
      *Why:* Avoids symbol conflicts.

4. **Refactor `free_t` Design**

   ```c
   typedef struct {
       void **ptr;
       void (*free_func)(void *);
       bool condition;
   } free_t;
   ```

   *Why:* Clearer ownership and pointer handling.

5. **Macro Helpers for `free_t` Initialization**

   ```c
   #define FREE_ITEM(cond, p, f) {cond, p, f}
   ```

   *Why:* Reduces boilerplate and errors.

6. **Unit Testing**

    * Test allocation failures, edge cases.
      *Why:* Ensures reliability.

7. **Optional Debug Compilation Flag**

   ```c
   #ifdef UTILS_DEBUG
   ```

   *Why:* Enables extra checks without impacting release builds.

---

## Compatibility & Portability

1. **Strict C Standard Compliance (C99/C11)**
   *Why:* Ensures portability across compilers.

2. **Cross-Platform Compatibility**

    * Avoid platform-specific assumptions.
      *Why:* Works on Windows, Linux, embedded systems.

3. **Custom Allocator Hooks**
   *Why:* Integrates with external systems.

4. **Static and Shared Library Support**
   *Why:* Flexible integration in projects.

5. **Compiler Warning Cleanliness**

    * Compile with strict flags.
      *Why:* Improves code robustness.

---

## Documentation & Usability

1. **Memory Lifecycle Guide**

    * Explain allocation → usage → freeing patterns.
      *Why:* Prevents misuse.

2. **Examples for Complex Cases**

    * Nested allocations, partial failures.
      *Why:* Helps real-world usage.

3. **Clear Ownership Rules**

    * Define who frees what.
      *Why:* Avoids confusion.

4. **Function Behavior Table**

    * Inputs, outputs, side effects.
      *Why:* Quick reference.

5. **Common Pitfalls Section**

    * Double free, missing NULL termination.
      *Why:* Reduces bugs.

6. **Debug Mode Documentation**

    * How to enable and interpret reports.
      *Why:* Helps debugging.

7. **Changelog & Versioning**
   *Why:* Tracks improvements and changes.

---

This roadmap will evolve `libutils` into a robust, flexible, and production-ready utility library, improving safety, extensibility, and performance while keeping its minimalist philosophy.
