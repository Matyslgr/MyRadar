/*
** EPITECH PROJECT, 2023
** delivery
** File description:
** draw_planes
*/

#include "my.h"

static void draw_rect(game_t *game, planes_t *plane)
{
    sfRectangleShape *rect = sfRectangleShape_create();
    sfVector2f size = {0, 0};
    sfVector2f position = {0, 0};

    sfRectangleShape_setFillColor(rect, sfTransparent);
    sfRectangleShape_setOutlineThickness(rect, 1);
    sfRectangleShape_setOutlineColor(rect, sfRed);
    size.x = plane->rect.width;
    size.y = plane->rect.height;
    position.x = plane->rect.left;
    position.y = plane->rect.top;
    sfRectangleShape_setSize(rect, size);
    sfRectangleShape_setPosition(rect, position);
    sfRenderWindow_drawRectangleShape(game->window, rect, NULL);
    sfRectangleShape_destroy(rect);
}

static void draw_hitbox_planes(game_t *game, int i, int j)
{
    planes_t *plane;

    if (game->corners[i][j]->nb_planes == 0)
        return;
    for (int k = 0; game->corners[i][j]->planes[k] != NULL; k++) {
        plane = game->corners[i][j]->planes[k];
        if (plane->etat == 1) {
            draw_rect(game, plane);
        }
    }
}

void draw_hitbox(game_t *game)
{
    for (int i = 0; i < game->rows; i++) {
        for (int j = 0; j < game->cols; j++) {
            draw_hitbox_planes(game, i, j);
        }
    }
}

static void draw_planes2(game_t *game, corner_t *corner)
{
    planes_t *plane;

    if (corner->nb_planes == 0)
        return;
    for (int k = 0; corner->planes[k] != NULL; k++) {
        plane = corner->planes[k];
        if (plane->etat == 1)
            sfRenderWindow_drawSprite(game->window, plane->sprite, NULL);
    }
}

void draw_planes(game_t *game)
{
    for (int i = 0; i < game->rows; i++) {
        for (int j = 0; j < game->cols; j++) {
            draw_planes2(game, game->corners[i][j]);
        }
    }
}
