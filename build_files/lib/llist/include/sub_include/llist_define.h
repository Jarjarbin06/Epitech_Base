/*
** EPITECH PROJECT, 2025
** sub_include - llist_define.h
** File description:
** <description>
*/

// Define //
#ifndef LLIST_D
    #define LLIST_D

    #include "llist_include.h"
    #include "llist_typedef.h"
    #include "llist_prototype.h"

#ifndef LLIST_D_EXIT
    #define LLIST_D_EXIT

#ifndef EXIT_SUCCESS
    #define EXIT_SUCCESS 0
#endif

#ifndef EXIT_FAILURE
    #define EXIT_FAILURE 84
#endif

#endif

#ifndef LLIST_D_COLOR
    #define LLIST_D_COLOR

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
