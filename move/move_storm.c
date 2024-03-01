/*
** EPITECH PROJECT, 2023
** delivery
** File description:
** move_storm
*/

#include "my.h"

static sfVector2f *get_sommets(game_t *game)
{
    sfVector2f storm_topleft = {game->storm_zone->area.left,
    game->storm_zone->area.top};
    sfVector2f storm_topright = {game->storm_zone->area.left +
    game->storm_zone->area.width, game->storm_zone->area.top};
    sfVector2f storm_bottomright = {game->storm_zone->area.left +
    game->storm_zone->area.width, game->storm_zone->area.top +
    game->storm_zone->area.height};
    sfVector2f storm_bottomleft = {game->storm_zone->area.left,
    game->storm_zone->area.top + game->storm_zone->area.height};
    sfVector2f *sommets = malloc(sizeof(sfVector2f) * 4);

    sommets[0] = storm_topleft;
    sommets[1] = storm_topright;
    sommets[2] = storm_bottomright;
    sommets[3] = storm_bottomleft;
    return sommets;
}

static bool is_in_storm_zone(sfVector2f position, game_t *game)
{
    storm_zone_t *storm = game->storm_zone;

    if (position.x >= storm->area.left && position.x <=
        storm->area.left + storm->area.width &&
        position.y >= storm->area.top && position.y <=
        storm->area.top + storm->area.height) {
        return true;
    }
    return false;
}

static bool get_path(path_storm_t *path, game_t *game)
{
    sfVector2f current_position;

    while (path->x != path->dest_x || path->y != path->dest_y) {
        current_position = (sfVector2f){path->x, path->y};
        if (is_in_storm_zone(current_position, game)) {
            free(path);
            return true;
        }
        path->err2 = 2 * path->err;
        if (path->err2 > -path->dy) {
            path->err -= path->dy;
            path->x += path->sx;
        }
        if (path->err2 < path->dx) {
            path->err += path->dx;
            path->y += path->sy;
        }
    }
    free(path);
    return false;
}

bool path_in_storm_zone(game_t *game, sfVector2f start, sfVector2f destination)
{
    path_storm_t *path = malloc(sizeof(path_storm_t));

    path->x = (int)start.x;
    path->y = (int)start.y;
    path->dest_x = (int)destination.x;
    path->dest_y = (int)destination.y;
    path->dx = abs(path->dest_x - path->x);
    path->dy = abs(path->dest_y - path->y);
    path->sx = (path->x < path->dest_x) ? 1 : -1;
    path->sy = (path->y < path->dest_y) ? 1 : -1;
    path->err = path->dx - path->dy;
    return get_path(path, game);
}

static sfVector2f get_my_sommet(int i, sfVector2f sommets[])
{
    sfVector2f my_sommet;

    if (i == 0) {
        my_sommet.x = sommets[i].x - 1;
        my_sommet.y = sommets[i].y - 1;
    }
    if (i == 1) {
        my_sommet.x = sommets[i].x + 1;
        my_sommet.y = sommets[i].y - 1;
    }
    if (i == 2) {
        my_sommet.x = sommets[i].x + 1;
        my_sommet.y = sommets[i].y + 1;
    }
    if (i == 3) {
        my_sommet.x = sommets[i].x - 1;
        my_sommet.y = sommets[i].y + 1;
    }
    return my_sommet;
}

static float distance_between_points(sfVector2f point1, sfVector2f point2)
{
    float dx = point2.x - point1.x;
    float dy = point2.y - point1.y;

    return sqrt(dx * dx + dy * dy);
}

// si le point d'arrivé est dans la zone de tempete
static void check_min(float min, planes_t *plane, move_t *move)
{
    if (min == 1000000) {
        move->dx = move->temp_end.x - plane->position.x;
        move->dy = move->temp_end.y - plane->position.y;
        move->distance = 1000000;
    }
}

static void is_min_dist(float my_dist, planes_t *plane, move_t *move,
    sfVector2f my_sommet)
{
    move->dx = my_sommet.x - plane->position.x;
    move->dy = my_sommet.y - plane->position.y;
    move->distance = my_dist;
}

void get_best_path(game_t *game, planes_t *plane, move_t *move)
{
    sfVector2f *sommets = get_sommets(game);
    sfVector2f my_sommet;
    float min = 1000000;
    float my_dist;

    for (int i = 0; i < 4; i++) {
        my_sommet = get_my_sommet(i, sommets);
        my_dist = distance_between_points(plane->position, my_sommet) +
        distance_between_points(my_sommet, move->temp_end);
        if (min > my_dist && !path_in_storm_zone(game, plane->position,
            my_sommet) && !path_in_storm_zone(game, my_sommet,
            move->temp_end)) {
            is_min_dist(my_dist, plane, move, my_sommet);
            min = my_dist;
        }
    }
    check_min(min, plane, move);
    free(sommets);
}
