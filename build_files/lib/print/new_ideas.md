# New Ideas for libprint

---

## New Features

1. **Full Length Modifier Support**
   Implement standard length modifiers:

   ```c
   h, hh, l, ll, j, z, t, L
   ```

   *Why:* Required for full `printf` compatibility and correct handling of different integer sizes.

2. **Missing Conversions (`a`, `A`, `n`)**

    * `%a`, `%A`: hexadecimal floating-point
    * `%n`: store number of printed characters
      *Why:* Completes standard feature set and improves compatibility.

3. **Custom Conversion Registration API**

   ```c
   int p_register_conv(char spec, conv_func_t func);
   ```

   *Why:* Makes the library extensible without modifying internal tables.

4. **Buffered Output System**

    * Introduce internal buffer before writing to output.
      *Why:* Reduces system calls and improves performance significantly.

5. **Output Target Abstraction**

   ```c
   int fprint(int fd, const char *format, ...);
   int sprint(char *buffer, const char *format, ...);
   ```

   *Why:* Enables writing to files, strings, or sockets.

6. **Color / Formatting Extensions**

   ```c
   print("{red}Error{reset}\n");
   ```

   *Why:* Useful for CLI tools and debugging output.

7. **Binary Conversion (`%b`)**
   *Why:* Common extension not present in standard `printf`.

8. **Locale / Formatting Options**

    * Thousand separators, decimal formats.
      *Why:* Improves usability for internationalization.

9. **Precision for Integers**
   Fully support precision behavior for numeric types.
   *Why:* Matches standard `printf` behavior.

10. **Wide Character Support**

* `%ls`, `%lc`
  *Why:* Supports Unicode and international text.

---

## Improvements

1. **Optimize Flag Parsing**

    * Replace repeated parsing logic with a state machine.
      *Why:* Improves performance and reduces complexity.

2. **Avoid Heap Allocations in Conversions**

    * Use stack buffers where possible.
      *Why:* Reduces overhead and improves speed.

3. **Precompute Lookup Tables**

    * For digit conversions (`hex`, `octal`).
      *Why:* Faster number-to-string conversion.

4. **Reduce Function Call Overhead**

    * Inline small functions like `p_is_num`, `p_strlen`.
      *Why:* Improves performance in tight loops.

5. **Efficient Float Formatting**

    * Optimize rounding and string building.
      *Why:* Floating-point conversions are often slow.

6. **Minimize `va_list` Traversals**

    * Avoid copying or re-reading arguments unnecessarily.
      *Why:* Prevents undefined behavior and improves efficiency.

7. **Shared Formatting Core**

    * Centralize padding, alignment, and sign handling.
      *Why:* Reduces duplication across conversions.

---

## Fixes / Bug Prevention

1. **Strict Format Validation**

    * Improve `check_format()` to fully match `printf` rules.
      *Why:* Prevents undefined behavior and crashes.

2. **Width / Precision NULL Safety**

    * Replace `int *width` with direct `int width`.
      *Why:* Avoids pointer misuse and simplifies logic.

3. **Handle Edge Cases for Floats**

    * Correct rounding, negative zero, very large/small values.
      *Why:* Ensures correctness and consistency.

4. **Buffer Overflow Protection**

    * Ensure all string writes are bounded.
      *Why:* Prevents memory corruption.

5. **Consistent Return Value**

    * Ensure `print()` always returns correct character count.
      *Why:* Required for compatibility with standard `printf`.

6. **Undefined Behavior in `%n`**

    * Carefully implement with validation.
      *Why:* `%n` can be unsafe if misused.

7. **NULL String Handling**

   ```c
   print("%s", NULL) → "(null)"
   ```

   *Why:* Matches standard behavior and avoids crashes.

---

## Code Quality / Maintainability

1. **Refactor Flag Structure**

   ```c
   typedef struct {
       int width;
       int precision;
       uint8_t flags;
       char length;
   } p_flag_t;
   ```

   *Why:* Simpler, safer, and more efficient.

2. **Bitmask for Flags**

   ```c
   #define FLAG_ZERO  (1 << 0)
   ```

   *Why:* Reduces memory usage and simplifies checks.

3. **Modular File Organization**

    * `parser.c`, `flags.c`, `conversions/`, `output.c`
      *Why:* Improves readability and scalability.

4. **Separation of Concerns**

    * Parsing vs formatting vs output clearly separated.
      *Why:* Easier debugging and extension.

5. **Unit Testing per Conversion**
   *Why:* Ensures correctness and prevents regressions.

6. **Internal API Layer**

    * Prefix internal functions (`_p_*`).
      *Why:* Avoids symbol conflicts.

7. **Consistent Naming Conventions**

    * Standardize all function prefixes and verbs.
      *Why:* Improves clarity.

---

## Compatibility & Portability

1. **C Standard Compliance (C99/C11)**

    * Avoid compiler-specific behavior.
      *Why:* Ensures portability.

2. **Platform-Independent Output**

    * Abstract `write()` calls.
      *Why:* Supports Windows and embedded systems.

3. **Optional Dependency-Free Mode**

    * Avoid reliance on libc where possible.
      *Why:* Useful for embedded environments.

4. **Endianness Safety**

    * Ensure consistent behavior across architectures.
      *Why:* Important for low-level formatting.

5. **Compiler Warning Cleanliness**

    * Compile with `-Wall -Wextra -Werror`.
      *Why:* Improves robustness.

---

## Documentation & Usability

1. **Full Specifier Reference Table**

    * Include all flags, modifiers, and behaviors.
      *Why:* Makes the library easier to use correctly.

2. **Behavior Differences vs `printf`**

    * Document deviations clearly.
      *Why:* Prevents confusion.

3. **Conversion Examples per Specifier**
   *Why:* Helps users understand formatting quickly.

4. **Architecture Diagram**

    * Parsing → dispatch → conversion → output.
      *Why:* Improves comprehension.

5. **Extension Guide**

    * How to add new conversions.
      *Why:* Encourages customization.

6. **Performance Notes**

    * Explain buffering and optimizations.
      *Why:* Helps users use the library efficiently.

7. **Common Pitfalls Section**

    * Invalid formats, unsupported modifiers.
      *Why:* Reduces user errors.

8. **Test Suite Examples**

    * Provide expected outputs.
      *Why:* Helps validate correctness.

---

This roadmap will transform `libprint` into a more complete, efficient, and extensible alternative to `printf`, while maintaining clarity, modularity, and performance.
