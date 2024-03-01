/*
** EPITECH PROJECT, 2023
** delivery
** File description:
** move
*/
#include "my.h"

static bool if_in_storm(game_t *game, planes_t *plane)
{
    if (plane->etat == 1 && game->activation->storm && plane->position.x
        > game->storm_zone->area.left && plane->position.x <
        game->storm_zone->area.left + game->storm_zone->area.width &&
        plane->position.y > game->storm_zone->area.top && plane->position.y <
        game->storm_zone->area.top + game->storm_zone->area.height) {
        plane->etat = 2;
        game->scores->destroyed++;
        game->scores->in_storm++;
        return true;
    } else {
        return false;
    }
}

static void get_distance2(game_t *game, move_t **move, planes_t *plane, int i)
{
    if (if_in_storm(game, plane)) {
        return;
    } else if (game->activation->storm && path_in_storm_zone(game,
        plane->position, move[i]->temp_end) &&
        (plane->end.x < game->storm_zone->area.left || plane->end.x >
        game->storm_zone->area.left + game->storm_zone->area.width ||
        plane->end.y < game->storm_zone->area.top || plane->end.y >
        game->storm_zone->area.top + game->storm_zone->area.height)) {
        get_best_path(game, plane, move[i]);
    } else {
        move[i]->dx = move[i]->temp_end.x - plane->position.x;
        move[i]->dy = move[i]->temp_end.y - plane->position.y;
        move[i]->distance = sqrt(move[i]->dx * move[i]->dx + move[i]->dy *
        move[i]->dy);
    }
}

static void get_distance(game_t *game, move_t **move, planes_t *plane)
{
    for (int i = 0; i < 3; i++) {
        get_distance2(game, move, plane, i);
    }
}

static int get_index(move_t **move)
{
    int index = 0;
    float min = 1000000;

    for (int i = 0; i < 3; i++) {
        if (move[i]->distance < min) {
            min = move[i]->distance;
            index = i;
        }
    }
    return index;
}

static void set_angle(planes_t *plane, move_t **move, int index)
{
    float angle = atan2(move[index]->dy, move[index]->dx) * 180 / M_PI;
    float my_angle = sfSprite_getRotation(plane->sprite);

    if (angle != my_angle) {
        sfSprite_setRotation(plane->sprite, angle);
    }
}

static void adjust_position(planes_t *plane, float direction,
    float distance)
{
    float radians = direction * (M_PI / 180.0f);

    plane->position.x += distance * cos(radians);
    plane->position.y += distance * sin(radians);
}

static void set_position(planes_t *plane, move_t **move, int index)
{
    float angle;

    if (move[index]->distance > 0) {
        angle = atan2(move[index]->dy, move[index]->dx) * 180 / M_PI;
        adjust_position(plane, angle, plane->speed);
    }
    if (plane->position.x < 0)
        plane->position.x += 1920;
    if (plane->position.x > 1920)
        plane->position.x -= 1920;
}

void set_plane_position(game_t *game, planes_t *plane)
{
    move_t *move[3];
    int index;

    for (int i = 0; i < 3; i++)
        move[i] = malloc(sizeof(move_t));
    move[0]->temp_end = plane->end;
    move[1]->temp_end = (sfVector2f){plane->end.x - 1920, plane->end.y};
    move[2]->temp_end = (sfVector2f){plane->end.x + 1920, plane->end.y};
    get_distance(game, move, plane);
    index = get_index(move);
    set_position(plane, move, index);
    set_angle(plane, move, index);
    free(move[0]);
    free(move[1]);
    free(move[2]);
}
