/*
** EPITECH PROJECT, 2025
** sub_include - 2list_define.h
** File description:
** <description>
*/

// Define //
#ifndef _2LIST_D_
    #define _2LIST_D_

    #include "2list_include.h"
    #include "2list_typedef.h"
    #include "2list_prototype.h"

    #ifndef _2LIST_D_EXIT_
        #define _2LIST_D_EXIT_

        #define EXIT_SUCCESS 0
        #define EXIT_FAILURE 84

    #endif

    #ifndef _2LIST_D_COLOR_
        #define _2LIST_D_COLOR_

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
