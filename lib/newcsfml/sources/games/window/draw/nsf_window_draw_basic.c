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

#include <SFML/Graphics/RenderWindow.h>

#include "newcsfml/games/window.h"
#include "newcsfml/graphics/background.h"
#include "newcsfml/graphics/button.h"
#include "newcsfml/graphics/particle.h"
#include "newcsfml/graphics/text.h"
#include "newcsfml/graphics/sprite.h"
#include "newcsfml/graphics/view.h"
#include "newcsfml/systems/other.h"
#include "newcsfml/systems/utils.h"

void nsf_window_fill(const nsf_window_t *window, const nsf_color_t color[])
{
    if (NSF_UNLIKELY(!window || !color))
        return nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_WINDOW, __FUNCTION__,
            "pointer corrupted");
    sfRenderWindow_clear(window->window, *color);
}

static bool is_ui(const nsf_cstr_t name)
{
    if (NSF_UNLIKELY(!name)) {
        nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_WINDOW,
            __FUNCTION__, "pointer corrupted");
        return true;
    }
    for (size_t idx = 0; name[idx] != '\0' &&
        SPECIAL_STR_UI[idx] != '\0'; idx++)
        if (name[idx] != SPECIAL_STR_UI[idx])
            return false;
    return true;
}

static bool is_universal(nsf_cstr_t name)
{
    if (NSF_UNLIKELY(!name)) {
        nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_WINDOW,
            __FUNCTION__, "pointer corrupted");
        return true;
    }
    if (is_ui(name))
        name = &name[str_len(SPECIAL_STR_UI)];
    for (size_t idx = 0; name[idx] != '\0' &&
        SPECIAL_STR_UNIVERSAL[idx] != '\0'; idx++)
        if (name[idx] != SPECIAL_STR_UNIVERSAL[idx])
            return false;
    return true;
}

static bool is_correct_screen(const nsf_window_t *window, nsf_cstr_t name)
{
    if (NSF_UNLIKELY(!window || !name)) {
        nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_WINDOW,
            __FUNCTION__, "pointer corrupted");
        return true;
    }
    if (window->current_screen == -1 || is_universal(name))
        return true;
    if (is_ui(name))
        name = &name[str_len(SPECIAL_STR_UI)];
    for (size_t idx = 0; name[idx] != '\0' &&
        window->screens[window->current_screen][idx] != '\0'; idx++)
        if (name[idx] != window->screens[window->current_screen][idx])
            return false;
    return true;
}

static void draw_sprites(const nsf_window_t *window, const bool must_be_ui)
{
    const nsf_elements_t *element = NULL;
    nsf_cstr_t name = NULL;

    if (NSF_UNLIKELY(!window || !window->elements.elements))
        return nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_WINDOW, __FUNCTION__,
            "pointer corrupted");
    for (size_t idx = 0; idx < window->elements.amount; idx++) {
        element = window->elements.elements[idx];
        name = element->name;
        if (element->element_type == NSF_SPRITE_ELEMENT &&
            is_ui(name) == must_be_ui && is_correct_screen(window, name))
            nsf_sprite_draw((nsf_sprite_t *)(element->ptr), window);
    }
}

static void draw_particles(const nsf_window_t *window, const bool must_be_ui)
{
    const nsf_elements_t *element = NULL;
    nsf_cstr_t name = NULL;

    if (NSF_UNLIKELY(!window || !window->elements.elements))
        return nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_WINDOW, __FUNCTION__,
            "pointer corrupted");
    for (size_t idx = 0; idx < window->elements.amount; idx++) {
        element = window->elements.elements[idx];
        name = element->name;
        if (element->element_type == NSF_PARTICLE_ELEMENT &&
            is_ui(name) == must_be_ui && is_correct_screen(window, name))
            nsf_particle_draw((nsf_particle_t *)(element->ptr), window);
    }
}

static void draw_button(const nsf_window_t *window, const bool must_be_ui)
{
    const nsf_elements_t *element = NULL;
    nsf_cstr_t name = NULL;

    if (NSF_UNLIKELY(!window || !window->elements.elements))
        return nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_WINDOW, __FUNCTION__,
            "pointer corrupted");
    for (size_t idx = 0; idx < window->elements.amount; idx++) {
        element = window->elements.elements[idx];
        name = element->name;
        if (element->element_type == NSF_BUTTON_ELEMENT &&
            is_ui(name) == must_be_ui && is_correct_screen(window, name))
            nsf_button_draw((nsf_button_t *)(element->ptr), window);
    }
}

static void draw_text(const nsf_window_t *window, const bool must_be_ui)
{
    const nsf_elements_t *element = NULL;
    nsf_cstr_t name = NULL;

    if (NSF_UNLIKELY(!window || !window->elements.elements))
        return nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_WINDOW, __FUNCTION__,
            "pointer corrupted");
    for (size_t idx = 0; idx < window->elements.amount; idx++) {
        element = window->elements.elements[idx];
        name = element->name;
        if (element->element_type == NSF_TEXT_ELEMENT &&
            is_ui(name) == must_be_ui && is_correct_screen(window, name))
            nsf_text_draw((nsf_text_t *)(element->ptr), window);
    }
}

void nsf_window_draw(const nsf_window_t *window)
{
    if (NSF_UNLIKELY(!window || !window->elements.elements))
        return nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_WINDOW, __FUNCTION__,
            "pointer corrupted");
    nsf_window_set_view(window, window->element_view);
    if (window->background)
        nsf_background_draw(window->background, window);
    draw_sprites(window, false);
    draw_particles(window, false);
    draw_button(window, false);
    draw_text(window, false);
    nsf_window_set_view(window, window->ui_view);
    draw_sprites(window, true);
    draw_particles(window, true);
    draw_button(window, true);
    draw_text(window, true);
    nsf_window_set_view(window, window->element_view);
}
