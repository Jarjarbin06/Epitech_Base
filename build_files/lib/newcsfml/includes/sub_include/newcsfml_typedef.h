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

#ifndef T_VOID_FUNC
    #define T_VOID_FUNC
typedef void *(*void_func)(void *);
#endif

// add type typedefs here //

#endif

#ifndef NEWCSFML_T_STRUCT
    #define NEWCSFML_T_STRUCT

#ifndef T_NSF_SPRITE
    #define T_NSF_SPRITE
typedef struct nsf_sprite_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f size;
    sfVector2f origin;
    sfVector2f position;
    float rotation;
} nsf_sprite;
#endif

#ifndef T_NSF_BACKGROUND
    #define T_NSF_BACKGROUND
typedef struct nsf_background_s {
    sfSprite *sprite;
    sfTexture *texture;
} nsf_background;
#endif

#ifndef T_FREE
    #define T_FREE
typedef struct free_s {
    bool condition;
    void *ptr;
    void_func free_func;
} free_t;
#endif

// add struct typedefs here //

#endif

#endif
