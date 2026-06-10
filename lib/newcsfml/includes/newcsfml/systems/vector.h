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

#ifndef NEWCSFML_VECTOR_H
    #define NEWCSFML_VECTOR_H

    #include <SFML/System/Vector2.h>

    #include <math.h>
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
    #define NSF_VECTOR "NSF_VECTOR"
    #define NSF_PI M_PI
    #define NSF_RADIAN(x) ((x) * (NSF_PI / 180.0))
    #define NSF_DEGREE(x) ((x) * (180.0 / NSF_PI))
    #define F_TO_PTR(v) (nsf_fvector_t[]){{v.x, v.y}}
    #define I_TO_PTR(v) (nsf_ivector_t[]){{v.x, v.y}}
    #define U_TO_PTR(v) (nsf_uvector_t[]){{v.x, v.y}}

/// TYPEDEFS ///
typedef sfVector2f nsf_fvector_t;
typedef sfVector2i nsf_ivector_t;
typedef sfVector2u nsf_uvector_t;

/// PROTOTYPES ///
// MANAGE //
nsf_fvector_t nsf_fvector_empty(void);
nsf_fvector_t nsf_fvector_from_i(const nsf_ivector_t v[]);
nsf_fvector_t nsf_fvector_from_u(const nsf_uvector_t v[]);
nsf_fvector_t nsf_fvector_copy(const nsf_fvector_t v[]);
nsf_ivector_t nsf_ivector_empty(void);
nsf_ivector_t nsf_ivector_from_f(const nsf_fvector_t v[]);
nsf_ivector_t nsf_ivector_from_u(const nsf_uvector_t v[]);
nsf_ivector_t nsf_ivector_copy(const nsf_ivector_t v[]);
nsf_uvector_t nsf_uvector_empty(void);
nsf_uvector_t nsf_uvector_from_f(const nsf_fvector_t v[]);
nsf_uvector_t nsf_uvector_from_i(const nsf_ivector_t v[]);
nsf_uvector_t nsf_uvector_copy(const nsf_uvector_t v[]);
nsf_fvector_t nsf_vector_add(const nsf_fvector_t a[], const nsf_fvector_t b[]);
nsf_fvector_t nsf_vector_sub(const nsf_fvector_t a[], const nsf_fvector_t b[]);
nsf_fvector_t nsf_vector_mul(const nsf_fvector_t v[], float scalar);
nsf_fvector_t nsf_vector_div(const nsf_fvector_t v[], float scalar);
nsf_fvector_t nsf_vector_neg(const nsf_fvector_t v[]);
float nsf_vector_len(const nsf_fvector_t v[]);
nsf_fvector_t nsf_vector_norm(const nsf_fvector_t v[]);
float nsf_vector_dist_to(const nsf_fvector_t a[], const nsf_fvector_t b[]);
nsf_fvector_t nsf_vector_dir_to(const nsf_fvector_t a[],
    const nsf_fvector_t b[]);
float nsf_vector_dot(const nsf_fvector_t a[], const nsf_fvector_t b[]);
float nsf_vector_cross(const nsf_fvector_t a[], const nsf_fvector_t b[]);
float nsf_vector_get_angle(const nsf_fvector_t v[]);
nsf_fvector_t nsf_vector_rotate(const nsf_fvector_t v[], float angle);
nsf_fvector_t nsf_vector_clamp_x(const nsf_fvector_t v[], float min, float max);
nsf_fvector_t nsf_vector_clamp_y(const nsf_fvector_t v[], float min, float max);
nsf_fvector_t nsf_vector_clamp(const nsf_fvector_t v[], float min, float max);

#endif
