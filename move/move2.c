/*
** EPITECH PROJECT, 2023
** delivery
** File description:
** move2
*/

#include "my.h"

static corner_t *get_corner_from_position2(game_t *game, int i, sfVector2f
    position)
{
    for (int j = 0; j < game->cols; j++) {
        if (position.x >= game->corners[i][j]->area.left &&
            position.x <= game->corners[i][j]->area.left +
            game->corners[i][j]->area.width && position.y >=
            game->corners[i][j]->area.top && position.y <=
            game->corners[i][j]->area.top +
            game->corners[i][j]->area.height) {
            return game->corners[i][j];
        }
    }
    return NULL;
}

static corner_t *get_corner_from_position(game_t *game, sfVector2f position)
{
    corner_t *my_corner;

    for (int i = 0; i < game->rows; i++) {
        my_corner = get_corner_from_position2(game, i, position);
        if (my_corner != NULL)
            return my_corner;
    }
    return NULL;
}

static void move_new_corner(game_t *game, corner_t *corner, planes_t *plane,
    sfVector2f new_pos)
{
    corner_t *new_corner;
    int nb = 0;
    int k = 0;
    int j;

    new_corner = get_corner_from_position(game, new_pos);
    if (new_corner != NULL && new_corner != corner) {
        for (; corner->planes[k] != plane; k++);
        for (j = k; corner->planes[j] != NULL; j++)
            corner->planes[j] = corner->planes[j + 1];
        corner->planes[j] = NULL;
        for (; new_corner->planes[nb] != NULL; nb++);
        new_corner->planes[nb] = plane;
    }
}

static void move_corner2(game_t *game, planes_t *plane)
{
    if ((fabs(plane->position.x - plane->end.x) > PREC) ||
        (fabs(plane->position.y - plane->end.y) > PREC)) {
        set_plane_position(game, plane);
    } else {
        game->scores->arrived++;
        plane->etat = 2;
    }
}

static void move_corner(game_t *game, corner_t *corner)
{
    planes_t *plane;

    for (int k = 0; corner->planes[k] != NULL; k++) {
        plane = corner->planes[k];
        if (plane->etat == 1) {
            move_corner2(game, plane);
            move_new_corner(game, corner, plane, plane->position);
            sfSprite_setPosition(plane->sprite, plane->position);
        }
    }
}

void move_plane(game_t *game)
{
    for (int i = 0; i < game->rows; i++) {
        for (int j = 0; j < game->cols; j++) {
            move_corner(game, game->corners[i][j]);
        }
    }
}
