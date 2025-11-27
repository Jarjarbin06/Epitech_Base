/*
** EPITECH PROJECT, 2025
** sub_include - str_define.h
** File description:
** <description>
*/

// Define //
#ifndef _STR_D_
    #define _STR_D_

    #include "str_include.h"
    #include "str_typedef.h"
    #include "str_prototype.h"

    #ifndef _STR_D_EXIT_
        #define _STR_D_EXIT_

        #define EXIT_SUCCESS 0
        #define EXIT_FAILURE 84

    #endif

    #ifndef _STR_D_COLOR_
        #define _STR_D_D_COLOR_

        #define C_ERROR "\033[41m"    // RED //
        #define C_WARNING "\033[43m"  // YELLOW //
        #define C_VALID "\033[42m"     // GREEN //
        #define C_INFO "\033[7m"      // WHITE //
        #define C_ITALIC "\033[3m"    // ITALIC //
        #define C_BOLD "\033[1m"      // BOLD //
        #define C_UNDERLINE "\033[4m" // UNDERLINE //
        #define C_DIM "\033[2m"       // DIM //
        #define C_RESET "\033[0m"     // RESET //

    #endif

#endif
