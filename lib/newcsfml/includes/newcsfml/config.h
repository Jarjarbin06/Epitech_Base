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

#ifndef NEWCSFML_CONFIG_H
    #define NEWCSFML_CONFIG_H

    // NewCSFML version, do not touch
    #define NCSFML_VERSION_MAJOR 0
    #define NCSFML_VERSION_MINOR 2
    #define NCSFML_VERSION_PATCH 9

    #ifndef LOG_CONFIG
        #define LOG_CONFIG

        // Uncomment the next line to disable debug logging
        #define NO_DEBUG

        // Uncomment the next line to disable info logging
        //#define NO_INFO

        // Uncomment the next line to disable warning logging
        //#define NO_WARNING

        // Uncomment the next line to disable error logging
        //#define NO_ERROR
    #endif

#endif
