/*
** EPITECH PROJECT, 2025
** sub_include - newcsfml_typedef.h
** File description:
** <description>
*/

// Typedef //
#ifndef NEWCSFML_T
    #define NEWCSFML_T

    #include "newcsfml_include.h"

    #include <SFML/Graphics/Sprite.h>

#ifndef NEWCSFML_T_TYPE
    #define NEWCSFML_T_TYPE

// add type typedefs here //

#endif

#ifndef NEWCSFML_T_STRUCT
    #define NEWCSFML_T_STRUCT

typedef struct free_s {
    bool condition;
    void *ptr;
} free_t;

typedef struct sprite_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f size;
    sfVector2f origin;
    sfVector2f position;
    float rotation;
} nsfSprite;

typedef struct background_s {
    sfSprite *sprite;
    sfTexture *texture;
} nsfBackground;

// add struct typedefs here //

#endif

#endif
