/*
** EPITECH PROJECT, 2023
** delivery
** File description:
** change_activation
*/

#include "my.h"

void change_storm(game_t *game, list_button_t *storm)
{
    if (storm->clic) {
        storm->clic = false;
        game->activation->storm = false;
    } else {
        storm->clic = true;
        game->activation->storm = true;
    }
}

void change_realist(game_t *game, list_button_t *realist)
{
    if (realist->clic) {
        realist->clic = false;
        game->activation->realist = false;
    } else {
        realist->clic = true;
        game->activation->realist = true;
    }
}

void change_rand(game_t *game, list_button_t *rand)
{
    if (rand->clic) {
        rand->clic = false;
        game->activation->rand_areas = false;
    } else {
        rand->clic = true;
        game->activation->rand_areas = true;
    }
}
