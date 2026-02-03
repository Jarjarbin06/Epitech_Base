/*
** EPITECH PROJECT, 2025
** sub_include - newcsfml_define.h
** File description:
** <description>
*/

// Define //
#ifndef NEWCSFML_D
    #define NEWCSFML_D

    #include "newcsfml_include.h"
    #include "newcsfml_typedef.h"
    #include "newcsfml_prototype.h"

#ifndef NEWCSFML_D_EXIT
    #define NEWCSFML_D_EXIT

#ifndef EXIT_SUCCESS
    #define EXIT_SUCCESS 0
#endif

#ifndef EXIT_FAILURE
    #define EXIT_FAILURE 84
#endif

#endif

#ifndef NEWCSFML_COLOR
    #define NEWCSFML_COLOR

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
