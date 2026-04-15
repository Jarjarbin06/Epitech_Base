/*
** EPITECH PROJECT, 2025
** sub_includes - newcsfml_prototype.h
** File description:
** <description>
*/

// Prototype //
#ifndef NEWCSFML_MANAGE
    #define NEWCSFML_MANAGE

    #include "newcsfml_typedef.h"

    #ifndef P_NSF_CMP_EVENT
        #define P_NSF_CMP_EVENT
bool nsf_cmp_event(const nsf_event_t *event, nsf_event_type_t event_type);
    #endif

    #ifndef P_NSF_CMP_KEY
        #define P_NSF_CMP_KEY
bool nsf_cmp_key(const nsf_event_t *event, nsf_key_code_t key_code);
    #endif

    #ifndef P_NSF_GAME_DISPLAY
        #define P_NSF_GAME_DISPLAY
int nsf_game_display(nsf_game_t *game);
    #endif

    #ifndef P_NSF_GAME_ISOPEN
        #define P_NSF_GAME_ISOPEN
bool nsf_game_isopen(nsf_game_t *game);
    #endif

    #ifndef P_NSF_GAME_CLOSE
        #define P_NSF_GAME_CLOSE
void nsf_game_close(nsf_game_t *game);
    #endif

    #ifndef P_NSF_GAME_GET_EVENT
        #define P_NSF_GAME_GET_EVENT
bool nsf_game_get_event(nsf_game_t *game, nsf_event_t *event);
    #endif

    #ifndef P_NSF_GAME_SET_WINDOW
        #define  P_NSF_GAME_SET_WINDOW
void nsf_game_set_window(nsf_game_t *game, nsf_window_t *window);
    #endif

    #ifndef P_NSF_GAME_GET_WINDOW
        #define  P_NSF_GAME_GET_WINDOW
nsf_window_t *nsf_game_get_window(nsf_game_t *game);
    #endif

    #ifndef P_NSF_GAME_ADD_SPRITE
        #define  P_NSF_GAME_ADD_SPRITE
void nsf_game_add_sprite(nsf_game_t *game, nsf_sprite_t *sprite);
    #endif

    #ifndef P_NSF_GAME_ADD_BUTTON
        #define  P_NSF_GAME_ADD_BUTTON
void nsf_game_add_button(nsf_game_t *game, nsf_button_t *button);
    #endif

    #ifndef P_NSF_GAME_ADD_SOUND
        #define  P_NSF_GAME_ADD_SOUND
void nsf_game_add_sound(nsf_game_t *game, nsf_sound_t *sound);
    #endif

    #ifndef P_NSF_GAME_GET_SPRITE
        #define  P_NSF_GAME_GET_SPRITE
nsf_sprite_t *nsf_game_get_sprite(nsf_game_t *game, const char sprite_name[]);
    #endif

    #ifndef P_NSF_GAME_GET_BUTTON
        #define  P_NSF_GAME_GET_BUTTON
nsf_button_t *nsf_game_get_button(nsf_game_t *game, const char button_name[]);
    #endif

    #ifndef P_NSF_GAME_GET_SOUND
        #define  P_NSF_GAME_GET_SOUND
nsf_sound_t *nsf_game_get_sound(nsf_game_t *game, const char sound_name[]);
    #endif

    #ifndef P_NSF_GAME_SET_MUSIC
        #define  P_NSF_GAME_SET_MUSIC
void nsf_game_set_music(nsf_game_t *game, nsf_music_t *music);
    #endif

    #ifndef P_NSF_GAME_GET_MUSIC
        #define  P_NSF_GAME_GET_MUSIC
nsf_music_t *nsf_game_get_music(nsf_game_t *game);
    #endif

    #ifndef P_NSF_GAME_PLAY_MUSIC
        #define  P_NSF_GAME_PLAY_MUSIC
void nsf_game_play_music(nsf_game_t *game);
    #endif

    #ifndef P_NSF_GAME_STOP_MUSIC
        #define  P_NSF_GAME_PLAY_MUSIC
void nsf_game_stop_music(nsf_game_t *game);
    #endif

    #ifndef P_NSF_GAME_SET_MUSIC_VOLUME
        #define  P_NSF_GAME_SET_MUSIC_VOLUME
void nsf_game_set_music_volume(nsf_game_t *game, float volume);
    #endif

    #ifndef P_NSF_GAME_PLAY_SOUND
        #define P_NSF_GAME_PLAY_SOUND
int nsf_game_play_sound(nsf_game_t *game, const char sound_name[]);
    #endif

    #ifndef P_NSF_GAME_PAUSE_SOUND
        #define P_NSF_GAME_PAUSE_SOUND
int nsf_game_pause_sound(nsf_game_t *game, const char sound_name[]);
    #endif

    #ifndef P_NSF_GAME_STOP_SOUND
        #define P_NSF_GAME_STOP_SOUND
int nsf_game_stop_sound(nsf_game_t *game, const char sound_name[]);
    #endif

    #ifndef P_NSF_GAME_ALL_SOUND_VOLUME
        #define P_NSF_GAME_ALL_SOUND_VOLUME
int nsf_game_all_sound_volume(nsf_game_t *game, float volume);
    #endif

    #ifndef P_NSF_GAME_STOP_ALL_SOUND
        #define P_NSF_GAME_STOP_ALL_SOUND
int nsf_game_stop_all_sound(nsf_game_t *game);
    #endif

    #ifndef P_NSF_GAME_UPDATE
        #define P_NSF_GAME_UPDATE
int nsf_game_update(nsf_game_t *game);
    #endif

    #ifndef P_NSF_WINDOW_DISPLAY
        #define P_NSF_WINDOW_DISPLAY
int nsf_window_display(nsf_window_t *window);
    #endif

    #ifndef P_NSF_WINDOW_ISOPEN
        #define P_NSF_WINDOW_ISOPEN
bool nsf_window_isopen(nsf_window_t *window);
    #endif

    #ifndef P_NSF_WINDOW_CLOSE
        #define P_NSF_WINDOW_CLOSE
void nsf_window_close(nsf_window_t *window);
    #endif

    #ifndef P_NSF_WINDOW_GET_EVENT
        #define P_NSF_WINDOW_GET_EVENT
bool nsf_window_get_event(nsf_window_t *window, nsf_event_t *event);
    #endif

    #ifndef P_NSF_WINDOW_ADD_SPRITE
        #define P_NSF_WINDOW_ADD_SPRITE
void nsf_window_add_sprite(nsf_window_t *window, nsf_sprite_t *sprite,
    nsf_game_t *game);
    #endif

    #ifndef P_NSF_WINDOW_ADD_BUTTON
        #define P_NSF_WINDOW_ADD_BUTTON
void nsf_window_add_button(nsf_window_t *window, nsf_button_t *button,
    nsf_game_t *game);
    #endif

    #ifndef P_NSF_WINDOW_ADD_SOUND
        #define P_NSF_WINDOW_ADD_SOUND
void nsf_window_add_sound(nsf_window_t *window, nsf_sound_t *sound,
    nsf_game_t *game);
    #endif

    #ifndef P_NSF_WINDOW_GET_SPRITE
        #define P_NSF_WINDOW_GET_SPRITE
nsf_sprite_t *nsf_window_get_sprite(nsf_window_t *window,
    const char sprite_name[]);
    #endif

    #ifndef P_NSF_WINDOW_GET_BUTTON
        #define P_NSF_WINDOW_GET_BUTTON
nsf_button_t *nsf_window_get_button(nsf_window_t *window,
    const char button_name[]);
    #endif

    #ifndef P_NSF_WINDOW_GET_SOUND
        #define P_NSF_WINDOW_GET_SOUND
nsf_sound_t *nsf_window_get_sound(nsf_window_t *window,
    const char sound_name[]);
    #endif

    #ifndef P_NSF_WINDOW_PLAY_SOUND
        #define P_NSF_WINDOW_PLAY_SOUND
int nsf_window_play_sound(nsf_window_t *window, const char sound_name[]);
    #endif

    #ifndef P_NSF_WINDOW_PAUSE_SOUND
        #define P_NSF_WINDOW_PAUSE_SOUND
int nsf_window_pause_sound(nsf_window_t *window, const char sound_name[]);
    #endif

    #ifndef P_NSF_WINDOW_STOP_SOUND
        #define P_NSF_WINDOW_STOP_SOUND
int nsf_window_stop_sound(nsf_window_t *window, const char sound_name[]);
    #endif

    #ifndef P_NSF_WINDOW_ALL_SOUND_VOLUME
        #define P_NSF_WINDOW_ALL_SOUND_VOLUME
int nsf_window_all_sound_volume(nsf_window_t *window, float volume);
    #endif

    #ifndef P_NSF_WINDOW_STOP_ALL_SOUND
        #define P_NSF_WINDOW_STOP_ALL_SOUND
int nsf_window_stop_all_sound(nsf_window_t *window);
    #endif

    #ifndef P_NSF_WINDOW_UPDATE_SETTINGS
        #define P_NSF_WINDOW_UPDATE_SETTINGS
int nsf_window_update_settings(nsf_window_t *window);
    #endif

    #ifndef P_NSF_SPRITE_SET_TEXTURE
        #define P_NSF_SPRITE_SET_TEXTURE
void nsf_sprite_set_texture(nsf_sprite_t *sprite, nsf_texture_t *texture);
    #endif

    #ifndef P_NSF_BUTTON_SET_TEXTURE
        #define P_NSF_BUTTON_SET_TEXTURE
void nsf_button_set_texture(nsf_button_t *button, nsf_texture_t *texture);
    #endif

    #ifndef P_NSF_BUTTON_SET_POSITION
        #define P_NSF_BUTTON_SET_POSITION
void nsf_button_set_position(nsf_button_t *button,
    const nsf_vector_t position[]);
    #endif

    #ifndef P_NSF_BUTTON_SET_SIZE
        #define P_NSF_BUTTON_SET_SIZE
void nsf_button_set_size(nsf_button_t *button, const nsf_vector_t size[]);
    #endif

    #ifndef P_NSF_BUTTON_SET_COLORS
        #define P_NSF_BUTTON_SET_COLORS
void nsf_button_set_colors(nsf_button_t *button,
    const nsf_color_t fill_color[], const nsf_color_t outline_color[],
    nsf_uint_t outline_thickness);
    #endif

    #ifndef P_NSF_BUTTON_CHECK_CLICK
        #define P_NSF_BUTTON_CHECK_CLICK
nsf_button_status_t nsf_button_get_state(nsf_button_t *button,
    nsf_window_t *window, nsf_mouse_t mouse_button);
    #endif

    #ifndef P_NSF_MUSIC_PLAY
        #define P_NSF_MUSIC_PLAY
void nsf_music_play(nsf_music_t *music);
    #endif

    #ifndef P_NSF_MUSIC_PAUSE
        #define P_NSF_MUSIC_PAUSE
void nsf_music_pause(nsf_music_t *music);
    #endif

    #ifndef P_NSF_MUSIC_STOP
        #define P_NSF_MUSIC_STOP
void nsf_music_stop(nsf_music_t *music);
    #endif

    #ifndef P_NSF_MUSIC_LOOPING
        #define P_NSF_MUSIC_LOOPING
void nsf_music_looping(nsf_music_t *music, bool looping);
    #endif

    #ifndef P_NSF_MUSIC_VOLUME
        #define P_NSF_MUSIC_VOLUME
void nsf_music_volume(nsf_music_t *music, float volume);
    #endif

    #ifndef P_NSF_MUSIC_GET_STATUS
        #define P_NSF_MUSIC_GET_STATUS
nsf_sound_status_t nsf_music_get_status(nsf_music_t *music);
    #endif

    #ifndef P_NSF_SOUND_PLAY
        #define P_NSF_SOUND_PLAY
void nsf_sound_play(nsf_sound_t *sound);
    #endif

    #ifndef P_NSF_SOUND_PAUSE
        #define P_NSF_SOUND_PAUSE
void nsf_sound_pause(nsf_sound_t *sound);
    #endif

    #ifndef P_NSF_SOUND_STOP
        #define P_NSF_SOUND_STOP
void nsf_sound_stop(nsf_sound_t *sound);
    #endif

    #ifndef P_NSF_SOUND_LOOPING
        #define P_NSF_SOUND_LOOPING
void nsf_sound_looping(nsf_sound_t *sound, bool looping);
    #endif

    #ifndef P_NSF_SOUND_VOLUME
        #define P_NSF_SOUND_VOLUME
void nsf_sound_volume(nsf_sound_t *sound, float volume);
    #endif

    #ifndef P_NSF_SOUND_GET_STATUS
        #define P_NSF_SOUND_GET_STATUS
nsf_sound_status_t nsf_sound_get_status(nsf_sound_t *sound);
    #endif

#endif
