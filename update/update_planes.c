/*
** EPITECH PROJECT, 2023
** delivery
** File description:
** update_planes
*/

#include "my.h"

static void check_etat_2(game_t *game, corner_t *corner)
{
    planes_t *plane;

    for (int k = 0; corner->planes[k] != NULL; k++) {
        plane = corner->planes[k];
        if (plane->etat == 0 && game->myclock->seconds >=
            (float)plane->delay) {
            plane->etat = 1;
        }
    }
}

void check_etat(game_t *game)
{
    game->myclock->time = sfClock_getElapsedTime(game->myclock->clock);
    game->myclock->seconds = game->myclock->time.microseconds / 1000000.0;
    for (int i = 0; i < game->rows; i++) {
        for (int j = 0; j < game->cols; j++) {
            check_etat_2(game, game->corners[i][j]);
        }
    }
}

static void area_planes(corner_t *corner)
{
    sfVector2f pos;

    if (corner->nb_planes == 0)
        return;
    for (int k = 0; k < (int)corner->nb_planes && corner->planes[k] !=
        NULL; k++) {
        pos = sfSprite_getPosition(corner->planes[k]->sprite);
        corner->planes[k]->rect.left = pos.x - (corner->planes[k]->rect.width
        / 2);
        corner->planes[k]->rect.top = pos.y - (corner->planes[k]->rect.height
        / 2);
    }
}

void update_area_planes(game_t *game)
{
    for (int i = 0; i < game->rows; i++) {
        for (int j = 0; j < game->cols; j++) {
            area_planes(game->corners[i][j]);
        }
    }
}

static void update_nb_planes2(corner_t *corner)
{
    int k = 0;

    for (; corner->planes[k] != NULL; k++);
    corner->nb_planes = k;
}

void update_nb_plane(game_t *game)
{
    for (int i = 0; i < game->rows; i++) {
        for (int j = 0; j < game->cols; j++) {
            update_nb_planes2(game->corners[i][j]);
        }
    }
}
