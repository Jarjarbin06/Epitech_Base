/*
** EPITECH PROJECT, 2025
** NCSFML - New C Simple Fast Multimedia Library
** File description:
** •
** NSFML is a lightweight wrapper over CSFML that simplifies usage
** while reducing low-level flexibility for easier game development.
** •
** Version: ncsfml-v0.2.5
** Author: Jarjarbin06
** License: GPL v3
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

#ifndef NEWCSFML_VECTOR_H
    #define NEWCSFML_VECTOR_H

    #include <SFML/System/Vector2.h>

    #include <math.h>
    #include <stdbool.h>
    #include <stddef.h>

    #ifndef EXIT_D
        #define EXIT_D

        #ifndef EXIT_SUCCESS
            #define EXIT_SUCCESS 0
        #endif

        #ifndef EXIT_ERROR
            #define EXIT_ERROR 84
        #endif

    #endif

/// MACRO ///
    #define NSF_PI M_PI
    #define NSF_RADIAN(x) ((x) * (NSF_PI / 180.0))
    #define NSF_DEGREE(x) ((x) * (180.0 / NSF_PI))

/// TYPEDEFS ///
typedef sfVector2f nsf_fvector_t;
typedef sfVector2i nsf_ivector_t;
typedef sfVector2u nsf_uvector_t;

/// PROTOTYPES ///
// MANAGE //
void nsf_fvector_empty(nsf_fvector_t *out);
void nsf_fvector_from_i(const nsf_ivector_t v[],
    nsf_fvector_t *out);
void nsf_fvector_from_u(const nsf_uvector_t v[],
    nsf_fvector_t *out);
void nsf_fvector_copy(const nsf_fvector_t v[],
    nsf_fvector_t *out);
void nsf_ivector_empty(nsf_ivector_t *out);
void nsf_ivector_from_f(const nsf_fvector_t v[],
    nsf_ivector_t *out);
void nsf_ivector_from_u(const nsf_uvector_t v[],
    nsf_ivector_t *out);
void nsf_ivector_copy(const nsf_ivector_t v[],
    nsf_ivector_t *out);
void nsf_uvector_empty(nsf_uvector_t *out);
void nsf_uvector_from_f(const nsf_fvector_t v[],
    nsf_uvector_t *out);
void nsf_uvector_from_i(const nsf_ivector_t v[],
    nsf_uvector_t *out);
void nsf_uvector_copy(const nsf_uvector_t v[],
    nsf_uvector_t *out);
void nsf_vector_add(const nsf_fvector_t a[],
    const nsf_fvector_t b[], nsf_fvector_t *out);
void nsf_vector_sub(const nsf_fvector_t a[],
    const nsf_fvector_t b[], nsf_fvector_t *out);
void nsf_vector_mul(const nsf_fvector_t v[], float scalar,
    nsf_fvector_t *out);
void nsf_vector_div(const nsf_fvector_t v[], float scalar,
    nsf_fvector_t *out);
void nsf_vector_neg(const nsf_fvector_t v[], nsf_fvector_t *out);
float nsf_vector_len(const nsf_fvector_t v[]);
void nsf_vector_norm(const nsf_fvector_t v[], nsf_fvector_t *out);
float nsf_vector_dist_to(const nsf_fvector_t a[],
    const nsf_fvector_t b[]);
void nsf_vector_dir_to(const nsf_fvector_t a[],
    const nsf_fvector_t b[], nsf_fvector_t *out);
float nsf_vector_dot(const nsf_fvector_t a[],
    const nsf_fvector_t b[]);
float nsf_vector_cross(const nsf_fvector_t a[],
    const nsf_fvector_t b[]);
float nsf_vector_get_angle(const nsf_fvector_t v[]);
void nsf_vector_rotate(const nsf_fvector_t v[], float angle,
    nsf_fvector_t *out);
void nsf_vector_clamp_x(const nsf_fvector_t v[], float min, float max,
    nsf_fvector_t out[]);
void nsf_vector_clamp_y(const nsf_fvector_t v[], float min, float max,
    nsf_fvector_t out[]);
void nsf_vector_clamp(const nsf_fvector_t v[], float min, float max,
    nsf_fvector_t out[]);
void nsf_vector_print(const nsf_fvector_t v[]);

#endif
