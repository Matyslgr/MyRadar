/*
** EPITECH PROJECT, 2023
** delivery
** File description:
** draw_corners
*/

#include "my.h"

void display_storm(game_t *game)
{
    sfRenderWindow_drawSprite(game->window, game->storm_zone->sprite, NULL);
}

void draw_hitbox_storm(game_t *game)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setFillColor(rect, sfTransparent);
    sfRectangleShape_setOutlineThickness(rect, 1);
    sfRectangleShape_setOutlineColor(rect, sfBlue);
    sfRectangleShape_setSize(rect, (sfVector2f){game->storm_zone->area.width,
    game->storm_zone->area.height});
    sfRectangleShape_setPosition(rect, (sfVector2f){game->storm_zone->area.
    left, game->storm_zone->area.top});
    sfRenderWindow_drawRectangleShape(game->window, rect, NULL);
    sfRectangleShape_destroy(rect);
}

void draw_corner_areas(game_t *game)
{
    sfRectangleShape *rect = sfRectangleShape_create();
    sfVector2f size = {0, 0};
    sfVector2f position = {0, 0};

    sfRectangleShape_setFillColor(rect, sfTransparent);
    sfRectangleShape_setOutlineThickness(rect, 1);
    sfRectangleShape_setOutlineColor(rect, sfWhite);
    for (int i = 0; i < game->rows; i++) {
        for (int j = 0; j < game->cols; j++) {
            size.x = game->corners[i][j]->area.width;
            size.y = game->corners[i][j]->area.height;
            position.x = game->corners[i][j]->area.left;
            position.y = game->corners[i][j]->area.top;
            sfRectangleShape_setSize(rect, size);
            sfRectangleShape_setPosition(rect, position);
            sfRenderWindow_drawRectangleShape(game->window, rect, NULL);
        }
    }
    sfRectangleShape_destroy(rect);
}
