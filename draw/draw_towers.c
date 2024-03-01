/*
** EPITECH PROJECT, 2023
** delivery
** File description:
** draw_towers
*/

#include "my.h"

void draw_towers(game_t *game)
{
    list_tower_t *tmp = game->list_towers;

    while (tmp != NULL) {
        sfRenderWindow_drawSprite(game->window, tmp->sprite, NULL);
        tmp = tmp->next;
    }
}

void draw_circles(game_t *game)
{
    list_tower_t *tmp = game->list_towers;

    while (tmp != NULL) {
        sfRenderWindow_drawCircleShape(game->window, tmp->circle, NULL);
        tmp = tmp->next;
    }
}
