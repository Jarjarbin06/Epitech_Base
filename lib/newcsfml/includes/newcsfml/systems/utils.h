/*
** EPITECH PROJECT, 2025
** NCSFML - New C Simple Fast Multimedia Library
** File description:
** •
** NSFML is a lightweight wrapper over CSFML that simplifies usage
** while reducing low-level flexibility for easier game development.
** •
** Version: ncsfml-v0.2.9
** Author: Jarjarbin06
** Licence: GPL v3
** •
** This library is inspired by SFML/CSFML and is designed for
** educational and game-development purposes.
** •
** It provides higher-level abstractions over CSFML to reduce
** boilerplate code and enforce safer usage patterns.
** •
** WARNING:
** This is NOT the original SFML/CSFML library.
** It is a custom implementation layer built on top of CSFML.
*/

#ifndef NEWCSFML_UTILS_H
    #define NEWCSFML_UTILS_H

    #include <SFML/Config.h>

    #include <stdbool.h>
    #include <stddef.h>

    #ifndef EXIT_D
        #define EXIT_D

        #ifndef E_SUCCESS
            #define E_SUCCESS (0)
        #endif

        #ifndef E_ERROR
            #define E_ERROR (84)
        #endif

        #ifndef E_FAILURE
            #define E_FAILURE (-1)
        #endif

    #endif

/// MACRO ///
    #define NSF_UTILS "NSF_UTILS"
    #define SPECIAL_STR_MODULE_NSF "NSF_"
    #define NSF_TERMINAL_UNKNOWN "\x1b[38;2;255;255;255m"
    #define NSF_TERMINAL_DEBUG "\x1b[38;2;0;255;255m"
    #define NSF_TERMINAL_INFO "\x1b[38;2;0;0;255m"
    #define NSF_TERMINAL_OK "\x1b[38;2;0;255;0m"
    #define NSF_TERMINAL_WARNING "\x1b[38;2;255;255;0m"
    #define NSF_TERMINAL_FAIL "\x1b[38;2;255;255;0m"
    #define NSF_TERMINAL_ERROR "\x1b[38;2;255;0;0m"
    #define NSF_TERMINAL_CORRUPTION "\x1b[38;2;255;0;0m"
    #define NSF_TERMINAL_RESET "\x1b[0m"
    #define NSF_TEXT_UNKNOWN "UNKNOWN"
    #define NSF_TEXT_DEBUG "DEBUG"
    #define NSF_TEXT_INFO "INFO"
    #define NSF_TEXT_OK "OK"
    #define NSF_TEXT_WARNING "WARNING"
    #define NSF_TEXT_FAIL "WARNING"
    #define NSF_TEXT_ERROR "ERROR"
    #define NSF_TEXT_CORRUPTION "ERROR"
    #define NSF_LIKELY(x) __builtin_expect(!!(x), 1)
    #define NSF_UNLIKELY(x) __builtin_expect(!!(x), 0)
    #define NSF_FALSE sfFalse
    #define NSF_TRUE sfTrue

/// TMP ///
typedef struct nsf_game_s nsf_game_t;

/// TYPEDEFS ///
typedef sfBool nsf_bool_t;
typedef unsigned int nsf_uint_t;
typedef char *nsf_str_t;
typedef const char *nsf_cstr_t;
typedef void *(*nsf_free_f_t)(void *);

typedef enum {
    NSF_LOG_LVL_UNKNOWN = -1,
    NSF_LOG_LVL_DEBUG,
    NSF_LOG_LVL_INFO,
    NSF_LOG_LVL_OK,
    NSF_LOG_LVL_WARNING,
    NSF_LOG_LVL_ERROR,
    NSF_LOG_LVL_CORRUPTION,
    NSF_LOG_LVL_FAIL
} nsf_log_level_t;

typedef struct {
    const bool condition;
    void *ptr;
    void *free_func;
} nsf_free_t;

/// PROTOTYPES ///
// MANAGE //
void *nsf_utils_malloc(nsf_uint_t size, nsf_game_t *game);
void *nsf_utils_free(void *ptr, nsf_game_t *game);
int nsf_utils_free_batch(nsf_uint_t len, const nsf_free_t free_list[],
    nsf_game_t *game);
void *nsf_utils_free_array(void **array, nsf_game_t *game);
bool nsf_utils_env_check_display(const char *const *env);
void nsf_utils_log(nsf_log_level_t log_level, nsf_cstr_t module,
    nsf_cstr_t name, nsf_cstr_t message);
void *nsf_utils_log_null(nsf_log_level_t log_level,
    nsf_cstr_t module, nsf_cstr_t name, nsf_cstr_t message);
bool nsf_utils_log_false(nsf_log_level_t log_level,
    nsf_cstr_t module, nsf_cstr_t name, nsf_cstr_t message);
int nsf_utils_log_failure(nsf_log_level_t log_level,
    nsf_cstr_t module, nsf_cstr_t name, nsf_cstr_t message);
int nsf_utils_log_zero(nsf_log_level_t log_level,
    nsf_cstr_t module, nsf_cstr_t name, nsf_cstr_t message);
bool nsf_utils_logic_not(bool a);
bool nsf_utils_logic_and(bool a, bool b);
bool nsf_utils_logic_and_batch(size_t len, const bool values[]);
bool nsf_utils_logic_nand(bool a, bool b);
bool nsf_utils_logic_nand_batch(size_t len, const bool values[]);
bool nsf_utils_logic_or(bool a, bool b);
bool nsf_utils_logic_or_batch(size_t len, const bool values[]);
bool nsf_utils_logic_nor(bool a, bool b);
bool nsf_utils_logic_nor_batch(size_t len, const bool values[]);
bool nsf_utils_logic_xor(bool a, bool b);
bool nsf_utils_logic_xor_batch(size_t len, const bool values[]);
bool nsf_utils_logic_nxor(bool a, bool b);
bool nsf_utils_logic_nxor_batch(size_t len, const bool values[]);

#endif
