---
title: Library NewCSFML
sidebar: sidebar
permalink: lib_newcsfml_doc_best_practices.html
folder: docs
---

## 🔹 Global Best Practices (Framework-wide)

These rules apply to **all modules, functions, structures, and systems** in the framework. They are designed to ensure consistency, safety, and maintainability across the entire codebase.

---

## 🔹 Function Design Rules

### ✔ Responsibilities

* Each function must have **one clear responsibility**
* Functions should remain **small and focused**
* Any logic that can be reused must be extracted into a separate function

### ✔ Naming Convention

* Use the pattern: `nsf_<module>_<action>`
* Use verbs for actions (`create`, `set`, `get`, `update`, `destroy`, `draw`)
* Avoid ambiguous names like `handle`, `do`, `process` without context

### ❌ Avoid

* Mixing multiple responsibilities in a single function
* Overly long or deeply nested functions
* Generic names that do not describe behavior

---

## 🔹 Pointer Safety Rules

### ✔ Mandatory Checks

* Every public function must validate its pointer arguments
* Always validate before dereferencing:
  * input pointers
  * internal struct dependencies
  * optional callbacks or resources

### ✔ Safe Pattern

* Check **all required inputs at the top of the function**
* Return immediately on invalid input
* Prefer early exit instead of nested conditions

### ❌ Avoid

* Dereferencing without validation
* Assuming ownership or validity of external pointers
* Silent undefined behavior on NULL inputs

---

## 🔹 Memory Management Rules

### ✔ Allocation Rules

* All allocations must go through framework-approved allocators
* Every allocation must have a clearly defined owner
* No "floating" allocations without a destroy path

### ✔ Deallocation Rules

* Every `create` must have a matching `destroy`
* Destruction must be **idempotent when possible**
* Always clean nested or child allocations before freeing parent

### ❌ Avoid

* Double-free scenarios
* Leaking internal sub-structures
* Manual `free()` outside designated destroy functions

---

## 🔹 Error Handling Rules

### ✔ Behavior

* Functions must return explicit status when applicable:
  * `NULL` for pointers
  * `E_SUCCESS / E_FAILURE` or similar for status codes
* Fail fast: stop execution as soon as an invalid state is detected

### ✔ Consistency

* Use consistent return conventions across modules
* Do not mix boolean, integer, and pointer error styles in the same API family

### ❌ Avoid

* Ignoring return values
* Continuing execution after a failed allocation or invalid state
* Silent failure without return indication

---

## 🔹 Module Isolation Rules

### ✔ Design Principle

* Each module must remain **independent and self-contained**
* Only interact through public APIs
* Internal structures must not be accessed directly outside their module

### ✔ Allowed Interaction

* Game → owns global lifecycle
* Window → manages rendering elements
* Graphics → handles visual objects
* Systems → provide utilities only

### ❌ Avoid

* Cross-module internal struct access
* Bypassing APIs for performance shortcuts
* Circular dependencies between modules

---

## 🔹 Performance Rules

### ✔ Guidelines

* Avoid unnecessary allocations inside hot paths
* Prefer stack allocation when safe
* Reuse objects instead of recreating them repeatedly
* Use `NSF_UNLIKELY` and `NSF_LIKELY` for runtime optimization

### ✔ Rendering Context

* Minimize SFML calls per frame
* Batch operations when possible
* Avoid redundant state updates (position/scale/texture)

### ❌ Avoid

* Reallocating per frame without reason
* Recomputing unchanged values
* Excessive abstraction in performance-critical loops

---

## 🔹 API Consistency Rules

### ✔ Standard Behavior

* Setters must only modify state (no side effects unless documented)
* Getters must not modify state
* Create functions must fully initialize valid objects
* Destroy functions must fully release resources

### ❌ Avoid

* Hidden side effects in getters
* Partial initialization in create functions
* Destroy functions leaving dangling references

---

## 🔹 Debugging & Maintainability Rules

### ✔ Code Clarity

* Prefer readable code over micro-optimizations
* Keep control flow linear when possible
* Separate logic into small helper functions

### ✔ Traceability

* Every allocation path must be traceable to a destroy path
* Every struct field must have a clear ownership rule

### ❌ Avoid

* Over-engineering simple logic
* Hidden dependencies between unrelated modules
* Unclear ownership of pointers

---

## 🔹 Summary Principle

> The framework must remain predictable:
> every object has a creator, an owner, and a destroyer;
> every function has a single purpose;
> every pointer is validated before use.
