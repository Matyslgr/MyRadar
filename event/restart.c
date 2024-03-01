/*
** EPITECH PROJECT, 2023
** delivery
** File description:
** restart
*/

#include "my.h"

void restart(game_t *game)
{
    game->scores->arrived = 0;
    game->scores->destroyed = 0;
    game->scores->in_storm = 0;
    game->fps = 60;
    game->phase = my_strdup("menu");
    active_elem(&game->list_button, "simulation");
    active_elem(&game->list_button, "choose");
    active_elem(&game->list_button, "rect");
    active_elem(&game->list_button, "modes");
    active_elem(&game->list_button, "my_radar");
    anime_menu(game);
}
