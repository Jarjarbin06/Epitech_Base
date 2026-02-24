/*
** EPITECH PROJECT, 2025
** sub_includes - newcsfml_prototype.h
** File description:
** <description>
*/

// Prototype //
#ifndef NEWCSFML_P
    #define NEWCSFML_P

    #include "newcsfml_include.h"
    #include "newcsfml_typedef.h"

    #ifndef NEWCSFML_P_BASE
        #define NEWCSFML_P_BASE
void newcsfml_show_macro(void);
void newcsfml_exist(void);
    #endif

    #ifndef P_NSF_MALLOC_ANY
        #define P_NSF_MALLOC_ANY
void *nsf_malloc_any(nsf_uint size, nsf_game *game);
    #endif

    #ifndef P_NSF_FREE_ANY
        #define P_NSF_FREE_ANY
void *nsf_free_any(void *ptr, nsf_game *game);
    #endif

    #ifndef P_NSF_AUTO_FREE
        #define P_NSF_AUTO_FREE
int nsf_auto_free(nsf_uint len, free_t free_list[], nsf_game *game);
    #endif

/* STRUCT */
    #ifndef P_NSF_GAME_CREATE
        #define P_NSF_GAME_CREATE
nsf_game *nsf_game_create(void);
    #endif

    #ifndef P_NSF_GAME_DESTROY
        #define P_NSF_GAME_DESTROY
int nsf_game_destroy(nsf_game **nsf_game);
    #endif

    #ifndef P_NSF_WINDOW_CREATE
        #define P_NSF_WINDOW_CREATE
nsf_window *nsf_window_create(nsf_window_settings settings,
    char title[], nsf_window_style window_style, nsf_game *game);
    #endif

    #ifndef P_NSF_WINDOW_DESTROY
        #define P_NSF_WINDOW_DESTROY
int nsf_window_destroy(nsf_window **nsf_window, nsf_game *game);
    #endif

    #ifndef P_NSF_SPRITE_CREATE
        #define P_NSF_SPRITE_CREATE
nsf_sprite *nsf_sprite_create(const char name[], nsf_game *game);
    #endif

    #ifndef P_NSF_SPRITE_DESTROY
        #define P_NSF_SPRITE_DESTROY
int nsf_sprite_destroy(nsf_sprite **nsf_sprite, nsf_game *game);
    #endif

/* MANAGE */
    #ifndef P_NSF_CMP_EVENT
        #define P_NSF_CMP_EVENT
bool nsf_cmp_event(const nsf_event *event, nsf_event_type event_type);
    #endif

    #ifndef P_NSF_GAME_DISPLAY
        #define P_NSF_GAME_DISPLAY
int nsf_game_display(nsf_game *game);
    #endif

    #ifndef P_NSF_GAME_ISOPEN
        #define P_NSF_GAME_ISOPEN
bool nsf_game_isopen(nsf_game *game);
    #endif

    #ifndef P_NSF_GAME_CLOSE
        #define P_NSF_GAME_CLOSE
void nsf_game_close(nsf_game *game);
    #endif

    #ifndef P_NSF_GAME_GET_EVENT
        #define P_NSF_GAME_GET_EVENT
bool nsf_game_get_event(nsf_game *game, nsf_event *event);
    #endif

    #ifndef P_NSF_GAME_SET_WINDOW
        #define  P_NSF_GAME_SET_WINDOW
void nsf_game_set_window(nsf_game *game, nsf_window *window);
    #endif

    #ifndef P_NSF_WINDOW_DISPLAY
        #define P_NSF_WINDOW_DISPLAY
int nsf_window_display(nsf_window *nsf_window);
    #endif

    #ifndef P_NSF_WINDOW_ISOPEN
        #define P_NSF_WINDOW_ISOPEN
bool nsf_window_isopen(nsf_window *nsf_window);
    #endif

    #ifndef P_NSF_WINDOW_CLOSE
        #define P_NSF_WINDOW_CLOSE
void nsf_window_close(nsf_window *nsf_window);
    #endif

    #ifndef P_NSF_WINDOW_GET_EVENT
        #define P_NSF_WINDOW_GET_EVENT
bool nsf_window_get_event(nsf_window *nsf_window, nsf_event *event);
    #endif

/* OTHER LIB */
    #ifndef P_MALLOC_ANY
        #define P_MALLOC_ANY
void *malloc_any(unsigned size);
    #endif

    #ifndef P_FREE_ANY
        #define P_FREE_ANY
void *free_any(void *ptr);
    #endif

    #ifndef P_AUTO_FREE
        #define P_AUTO_FREE
int auto_free(unsigned len, free_t free_list[]);
    #endif

    #ifndef P_FREE_ARRAY
        #define P_FREE_ARRAY
void free_array(void **array);
    #endif

    #ifndef P_MY_STRDUP
        #define P_MY_STRDUP
char *my_strdup(const char *src);
    #endif

    #ifndef P_MY_STRLEN
        #define P_MY_STRLEN
int my_strlen(const char *str);
    #endif

#endif
