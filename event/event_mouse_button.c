/*
** EPITECH PROJECT, 2023
** delivery
** File description:
** event_mouse_button
*/

#include "my.h"

void free_list_plane(list_plane_t *list_planes)
{
    list_plane_t *tmp = list_planes;

    while (tmp != NULL) {
        list_planes = list_planes->next;
        free(tmp);
        tmp = list_planes;
    }
}

static void display_load(game_t *game)
{
    sfRenderWindow_clear(game->window, sfBlack);
    sfRenderWindow_drawSprite(game->window, game->background->sprite, NULL);
    sfRenderWindow_drawSprite(game->window,
        get_elem(&game->list_button, "load")->spritedef, NULL);
    sfRenderWindow_display(game->window);
}

static int normal(game_t *game)
{
    list_plane_t *list_planes = NULL;
    list_tower_t *list_towers = NULL;
    unsigned int total_planes = parse_file(game->filepath, &list_planes,
        &list_towers);

    if ((int)total_planes == -1)
        return 84;
    game->total_planes = total_planes;
    game->list_towers = list_towers;
    game->corners = init_corners(total_planes, game->rows, game->cols);
    fill_corners(game, list_planes);
    free_list_plane(list_planes);
    return 0;
}

int start_game(game_t *game)
{
    display_load(game);
    game->phase = my_strdup("game");
    sfClock_restart(game->myclock->clock);
    game->myclock->seconds = 0;
    game->scores->destroyed = 0;
    game->scores->arrived = 0;
    desactive_elem(&game->list_button, "simulation");
    desactive_elem(&game->list_button, "choose");
    desactive_elem(&game->list_button, "rect");
    desactive_elem(&game->list_button, "modes");
    desactive_elem(&game->list_button, "my_radar");
    if (game->activation->realist)
        return realist_mode(game);
    else
        return normal(game);
}

int mouse_button(game_t *game)
{
    list_button_t *current = game->list_button;
    int x = game->event.mouseButton.x;
    int y = game->event.mouseButton.y;

    while (current != NULL) {
        if (current->etat && x >= current->area.left && x <=
        current->area.left + current->area.width && y >=
        current->area.top && y <=
        current->area.top + current->area.height) {
            return button_clicked(game, current);
        }
        current = current->next;
    }
    return 0;
}
