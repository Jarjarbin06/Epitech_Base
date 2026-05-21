/*
** EPITECH PROJECT, 2025
** sub_includes - utils_define.h
** File description:
** <description>
*/

// Define //
#ifndef UTILS_D
    #define UTILS_D

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

    #ifndef COLOR_D
        #define COLOR_D

        #define C_ERROR_TITLE "\033[41m"    // RED //
        #define C_ERROR "\033[31m"    // RED //
        #define C_WARNING_TITLE "\033[43m"  // YELLOW //
        #define C_WARNING "\033[33m"  // YELLOW //
        #define C_VALID_TITLE "\033[42m"     // GREEN //
        #define C_VALID "\033[32m"     // GREEN //
        #define C_DEBUG_TITLE "\033[44m"     // BLUE //
        #define C_DEBUG "\033[34m"     // BLUE //
        #define C_INFO "\033[7m"      // WHITE //
        #define C_ITALIC "\033[3m"    // ITALIC //
        #define C_BOLD "\033[1m"      // BOLD //
        #define C_UNDERLINE "\033[4m" // UNDERLINE //
        #define C_DIM "\033[2m"       // DIM //
        #define C_RESET "\033[0m"     // RESET //

    #endif

    #ifndef OPTIMIZATION_D
        #define OPTIMIZATION_D

        #define LIKELY(x) __builtin_expect(!!(x), 1)
        #define UNLIKELY(x) __builtin_expect(!!(x), 0)

    #endif

#endif
