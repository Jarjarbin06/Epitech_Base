/*
** EPITECH PROJECT, 2025
** NCSFML - New C Simple Fast Multimedia Library
** File description:
** •
** NSFML is a lightweight wrapper over CSFML that simplifies usage
** while reducing low-level flexibility for easier game development.
** •
** Version: ncsfml-v0.2.8
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

#ifndef NEWCSFML_SPRITE_H
    #define NEWCSFML_SPRITE_H

    #include <SFML/Graphics/Sprite.h>
    #include <SFML/System/Vector2.h>

    #include <stdbool.h>
    #include <stddef.h>

    #ifndef EXIT_D
        #define EXIT_D

        #ifndef E_SUCCESS
            #define E_SUCCESS (0)
        #endif

        #ifndef E_ERROR
            #define E_ERROR (84)
        #endif

        #ifndef E_FAILURE
            #define E_FAILURE (-1)
        #endif

    #endif

/// MACRO ///
    #define NSF_SPRITE "NSF_SPRITE"

/// TMP ///
typedef const char *nsf_cstr_t;
typedef const char *cstr_t;
typedef sfVector2u nsf_uvector_t;
typedef sfVector2f nsf_fvector_t;
typedef const char *nsf_cstr_t;
typedef struct nsf_texture_s nsf_texture_t;
typedef struct nsf_animation_s nsf_animation_t;
typedef struct nsf_game_s nsf_game_t;
typedef struct nsf_window_s nsf_window_t;

/// TYPEDEFS ///
typedef enum {
    NSF_TXR_NONE,
    NSF_TXR_TEXTURE,
    NSF_TXR_ANIMATION
} nsf_texture_type_t;

typedef union {
    nsf_texture_t *texture;
    nsf_animation_t *animation;
} nsf_texture_union_t;

typedef struct nsf_sprite_s {
    sfSprite *sprite;
    nsf_texture_union_t texture;
    nsf_texture_type_t texture_type;
    nsf_fvector_t scale;
    nsf_fvector_t origin;
    nsf_fvector_t position;
    float rotation;
    nsf_cstr_t name;
    void *data;
    // add effects
} nsf_sprite_t;

/// PROTOTYPES ///
// SPRITE //
nsf_sprite_t *nsf_sprite_create(const char name[], nsf_game_t *game);
int nsf_sprite_destroy(nsf_sprite_t **sprite, nsf_game_t *game);

// MANAGE //
void nsf_sprite_set_texture(nsf_sprite_t *sprite, nsf_texture_t *texture);
void nsf_sprite_set_animation(nsf_sprite_t *sprite, nsf_animation_t *animation);
nsf_texture_t *nsf_sprite_get_texture(const nsf_sprite_t *sprite);
nsf_animation_t *nsf_sprite_get_animation(const nsf_sprite_t *sprite);
sfTexture *nsf_sprite_get_deep_texture(const nsf_sprite_t *sprite);
void nsf_sprite_set_scale(nsf_sprite_t *sprite, const nsf_fvector_t scale[]);
void nsf_sprite_set_size(nsf_sprite_t *sprite, const nsf_uvector_t size[]);
void nsf_sprite_set_position(nsf_sprite_t *sprite,
    const nsf_fvector_t position[]);
void nsf_sprite_set_origin(nsf_sprite_t *sprite, const nsf_fvector_t origin[]);
void nsf_sprite_get_scale(const nsf_sprite_t *sprite, nsf_fvector_t *out);
void nsf_sprite_get_size(const nsf_sprite_t *sprite, nsf_uvector_t *out);
void nsf_sprite_get_position(const nsf_sprite_t *sprite, nsf_fvector_t *out);
void nsf_sprite_get_origin(const nsf_sprite_t *sprite, nsf_fvector_t *out);
void nsf_sprite_update(nsf_sprite_t *sprite);

// DRAW //
void nsf_sprite_draw(const nsf_sprite_t *sprite, const nsf_window_t *window);

#endif
