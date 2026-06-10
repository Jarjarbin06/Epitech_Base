/*
** EPITECH PROJECT, 2025
** NCSFML - New C Simple Fast Multimedia Library
** File description:
** •
** NSFML is a lightweight wrapper over CSFML that simplifies usage
** while reducing low-level flexibility for easier game development.
** •
** Version: ncsfml-v0.2.10
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

#ifndef NEWCSFML_CONFIG_H
    #define NEWCSFML_CONFIG_H

    #ifndef VERSION_D
        #define VERSION_D

        // NewCSFML version, do not touch
        #define NCSFML_VERSION_MAJOR 0
        #define NCSFML_VERSION_MINOR 2
        #define NCSFML_VERSION_PATCH 10

        #endif

    #ifndef MANUAL_CONFIGS_D
        #define MANUAL_CONFIGS_D

        // Uncomment the following lines to activate them
        //#define NCSFML_INTERN_NO_DEBUG
        //#define NCSFML_INTERN_NO_INFO
        //#define NCSFML_INTERN_NO_WARNING
        //#define NCSFML_INTERN_NO_ERROR

    #endif

    #ifndef AUTO_CONFIGS_D
        #define AUTO_CONFIGS_D

        /// LOG ///
        #ifndef NCSFML_LOG_D
            #define NCSFML_LOG_D

            // Minimal logging (only warning and errors)(better for releases)
            #ifdef NCSFML_LOG_MINIMAL

                #define NCSFML_INTERN_NO_DEBUG
                #define NCSFML_INTERN_NO_INFO

            #endif

            // No logging (only warning and errors)
            #ifdef NCSFML_LOG_NONE

                #define NCSFML_INTERN_NO_DEBUG
                #define NCSFML_INTERN_NO_INFO
                #define NCSFML_INTERN_NO_WARNING
                #define NCSFML_INTERN_NO_ERROR

            #endif

            // No coloured logging (better for unit-tests)
            #ifdef NCSFML_LOG_COLOR_NONE
            #endif

            // Show timestamp logging (better for accuracy)
            #ifdef NCSFML_LOG_USE_TIMESTAMP
            #endif

            // File logging (better for log historic)
            #ifdef NCSFML_LOG_WRITE_TO_FILE
            #endif

        #endif

    #endif

#endif
