/*
** EPITECH PROJECT, 2023
** delivery
** File description:
** update
*/

#include "my.h"

static void rotate_storm(game_t *game)
{
    game->storm_zone->angle -= 0.25;
    if (game->storm_zone->angle <= 0)
        game->storm_zone->angle = 360;
    sfSprite_setRotation(game->storm_zone->sprite, game->storm_zone->angle);
}

static void move_storm(game_t *game)
{
    float centerX = 910;
    float centerY = 540;
    float my_radius = 350;
    float newX;
    float newY;
    sfVector2f stormPos;

    game->storm_zone->radius += game->storm_zone->speed;
    if (game->storm_zone->radius >= 360)
        game->storm_zone->radius = 0;
    newX = centerX + my_radius * cos(game->storm_zone->radius);
    newY = centerY + my_radius * sin(game->storm_zone->radius);
    stormPos = sfSprite_getPosition(game->storm_zone->sprite);
    game->storm_zone->area.left = stormPos.x -
        game->storm_zone->area.width / 2;
    game->storm_zone->area.top = stormPos.y -
        game->storm_zone->area.height / 2;
    sfSprite_setPosition(game->storm_zone->sprite, (sfVector2f){newX, newY});
}

static void reset_planes2(corner_t *corner)
{
    planes_t *plane;

    for (int k = 0; corner->planes[k] != NULL; k++) {
        plane = corner->planes[k];
        if (plane->etat == 2) {
            plane->start.x = rand() % 1850 + 50;
            plane->start.y = rand() % 1000 + 50;
            plane->end.x = rand() % 1850 + 50;
            plane->end.y = rand() % 1000 + 50;
            plane->position = plane->start;
            plane->speed = rand() % 2 + 1;
            plane->etat = 0;
        }
    }
}

static void resets_planes(game_t *game)
{
    for (int i = 0; i < game->rows; i++) {
        for (int j = 0; j < game->cols; j++) {
            reset_planes2(game->corners[i][j]);
        }
    }
}

static void destroy_all(list_exp *exp)
{
    sfTexture_destroy(exp->texture);
    sfSprite_destroy(exp->sprite);
    sfClock_destroy(exp->clock);
    free(exp);
}

static void delete_exp(game_t *game, list_exp *exp)
{
    list_exp *tmp = game->list_exp;

    if (tmp == exp) {
        game->list_exp = tmp->next;
        destroy_all(exp);
        return;
    }
    while (tmp->next != NULL) {
        if (tmp->next == exp) {
            tmp->next = tmp->next->next;
            destroy_all(exp);
            return;
        }
        tmp = tmp->next;
    }
}

static void set_rect(game_t *game, list_exp *exp)
{
    if (exp->rect.left + exp->offset < exp->max_value) {
        exp->rect.left += exp->offset;
        sfSprite_setTextureRect(exp->sprite, exp->rect);
        sfClock_restart(exp->clock);
    } else {
        delete_exp(game, exp);
    }
}

static void update_rects(game_t *game)
{
    list_exp *exp = game->list_exp;

    while (exp != NULL) {
        exp->time = sfClock_getElapsedTime(exp->clock);
        exp->seconds = exp->time.microseconds / 1000000.0;
        if (exp->seconds > 0.1) {
            set_rect(game, exp);
        }
        exp = exp->next;
    }
}

void update(game_t *game)
{
    check_etat(game);
    move_plane(game);
    update_nb_plane(game);
    update_area_planes(game);
    update_rects(game);
    collision(game);
    if (game->activation->storm) {
        rotate_storm(game);
        move_storm(game);
    }
    if (my_strcmp(game->phase, "game")) {
        resets_planes(game);
    } else if ((int)game->total_planes < game->scores->arrived +
        game->scores->destroyed)
        restart(game);
}
