/*
** EPITECH PROJECT, 2025
** sub_includes - newcsfml_define.h
** File description:
** <description>
*/

// Define //
#ifndef NEWCSFML_D
    #define NEWCSFML_D

    #include <SFML/Window/Event.h>
    #include <math.h>

    #ifndef EXIT_D
        #define EXIT_D

        #ifndef EXIT_SUCCESS
            #define EXIT_SUCCESS 0
        #endif

        #ifndef EXIT_ERROR
            #define EXIT_ERROR 84
        #endif

    #endif

    #ifndef COLOR_D
        #define COLOR_D

        #define C_ERROR_TITLE "\033[41m"    // RED TITLE //
        #define C_ERROR "\033[31m"          // RED //
        #define C_WARNING_TITLE "\033[43m"  // YELLOW TITLE //
        #define C_WARNING "\033[33m"        // YELLOW //
        #define C_VALID_TITLE "\033[42m"    // GREEN TITLE //
        #define C_VALID "\033[32m"          // GREEN //
        #define C_DEBUG_TITLE "\033[44m"    // BLUE TITLE //
        #define C_DEBUG "\033[34m"          // BLUE //
        #define C_INFO "\033[7m"            // WHITE //
        #define C_ITALIC "\033[3m"          // ITALIC //
        #define C_BOLD "\033[1m"            // BOLD //
        #define C_UNDERLINE "\033[4m"       // UNDERLINE //
        #define C_DIM "\033[2m"             // DIM //
        #define C_RESET "\033[0m"           // RESET //

    #endif

    #define NSF_PI M_PI
    #define NSF_RADIAN(x) ((x) * (NSF_PI / 180.0))
    #define NSF_DEGREE(x) ((x) * (180.0 / NSF_PI))

#endif
