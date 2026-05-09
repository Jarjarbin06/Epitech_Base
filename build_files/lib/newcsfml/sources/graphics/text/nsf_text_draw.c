/*
** EPITECH PROJECT, 2025
** NCSFML - New C Simple Fast Multimedia Library
** File description:
** •
** NSFML is a lightweight wrapper over CSFML that simplifies usage
** while reducing low-level flexibility for easier game development.
** •
** Version: ncsfml-v0.2.4
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

#include <SFML/Graphics/RenderWindow.h>

#include "newcsfml/games/window.h"
#include "newcsfml/systems/watcher.h"
#include "newcsfml/graphics/text.h"
#include "newcsfml/systems/other.h"
#include "newcsfml/systems/utils.h"

void nsf_text_draw(const nsf_text_t *text, const nsf_window_t *window)
{
    if (NSF_UNLIKELY(!text || !window))
        return;
    nsf_text_update_from_watcher((nsf_text_t *)text);
    sfRenderWindow_drawText(window->window, text->text, NULL);
}
