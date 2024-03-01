/*
** EPITECH PROJECT, 2023
** delivery
** File description:
** event
*/

#include "my.h"

static bool is_button_hover(list_button_t *current)
{
    return (!my_strcmp(current->name, "simulation") ||
        !my_strcmp(current->name, "choose") ||
        !my_strcmp(current->name, "storm") ||
        !my_strcmp(current->name, "realist") ||
        !my_strcmp(current->name, "modes") ||
        !my_strcmp(current->name, "back") ||
        !my_strcmp(current->name, "100") ||
        !my_strcmp(current->name, "500") ||
        !my_strcmp(current->name, "1000") ||
        !my_strcmp(current->name, "3000") ||
        !my_strcmp(current->name, "rand") ||
        !my_strcmp(current->name, "10000"));
}

static void mouse_move(game_t *game)
{
    int x = game->event.mouseMove.x;
    int y = game->event.mouseMove.y;
    list_button_t *current = game->list_button;

    while (current != NULL) {
        if (current->etat && (x >= current->area.left && x <=
        current->area.left + current->area.width && y >=
        current->area.top && y <= current->area.top +
        current->area.height) && is_button_hover(current)) {
            current->type = "hover";
        } else
            current->type = "def";
        current = current->next;
    }
}

static void set_fps(game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyRight)) {
        game->fps += 5;
        if (game->fps > 120)
            game->fps = 120;
        sfRenderWindow_setFramerateLimit(game->window, game->fps);
    }
    if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
        game->fps -= 5;
        if (game->fps < 10)
            game->fps = 10;
        sfRenderWindow_setFramerateLimit(game->window, game->fps);
    }
}

static void key_pressed(game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyL))
        game->activation->hitbox = !game->activation->hitbox;
    if (sfKeyboard_isKeyPressed(sfKeyS))
        game->activation->disp_sprite = !game->activation->disp_sprite;
    if (sfKeyboard_isKeyPressed(sfKeyA))
        game->activation->disp_corners = !game->activation->disp_corners;
    if (sfKeyboard_isKeyPressed(sfKeySpace))
        restart(game);
    set_fps(game);
}

int event(game_t *game)
{
    if (game->event.type == sfEvtClosed ||
        sfKeyboard_isKeyPressed(sfKeyEscape))
        sfRenderWindow_close(game->window);
    if (game->event.type == sfEvtKeyPressed && !my_strcmp(game->phase, "game"))
        key_pressed(game);
    if (game->event.type == sfEvtMouseMoved)
        mouse_move(game);
    if (game->event.type == sfEvtMouseButtonPressed)
        return mouse_button(game);
    return 0;
}
