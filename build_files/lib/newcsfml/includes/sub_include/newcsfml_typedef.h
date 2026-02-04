/*
** EPITECH PROJECT, 2025
** sub_includes - newcsfml_typedef.h
** File description:
** <description>
*/

// Typedef //
#ifndef NEWCSFML_T
    #define NEWCSFML_T

    #include <SFML/Graphics/Sprite.h>

    #include "newcsfml_include.h"

#ifndef NEWCSFML_T_TYPE
    #define NEWCSFML_T_TYPE

typedef void *(*vf)(void *);

// add type typedefs here //

#endif

#ifndef NEWCSFML_T_STRUCT
    #define NEWCSFML_T_STRUCT

typedef struct free_s {
    bool condition;
    void *ptr;
    vf free_func;
} free_t;

typedef struct nsf_sprite_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f size;
    sfVector2f origin;
    sfVector2f position;
    float rotation;
} nsf_sprite;

typedef struct nsf_background_s {
    sfSprite *sprite;
    sfTexture *texture;
} nsf_background;

// add struct typedefs here //

#endif

#endif
