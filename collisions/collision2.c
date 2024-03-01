/*
** EPITECH PROJECT, 2023
** delivery
** File description:
** collision2
*/

#include "my.h"

static int is_intersecting_planes(planes_t *p1, planes_t *p2)
{
    sfIntRect p1_rect = p1->rect;
    sfIntRect p2_rect = p2->rect;

    if (p1_rect.left + p1_rect.width < p2_rect.left ||
        p1_rect.left > p2_rect.left + p2_rect.width ||
        p1_rect.top + p1_rect.height < p2_rect.top ||
        p1_rect.top > p2_rect.top + p2_rect.height) {
        return false;
    } else {
        return true;
    }
}

static bool circle_rectangle(list_tower_t *tower, planes_t *plane)
{
    float cx = tower->position.x;
    float cy = tower->position.y;
    float r = tower->radius;
    float rx = plane->rect.left;
    float ry = plane->rect.top;
    float w = plane->rect.width;
    float h = plane->rect.height;
    float closestX = fmaxf(rx, fminf(cx, rx + w));
    float closestY = fmaxf(ry, fminf(cy, ry + h));
    float distance = sqrtf((cx - closestX) * (cx - closestX) + (cy - closestY)
        * (cy - closestY));

    if (distance <= r)
        return true;
    else
        return false;
}

bool is_secured(planes_t *plane, game_t *game)
{
    list_tower_t *tmp = game->list_towers;

    while (tmp != NULL) {
        if (circle_rectangle(tmp, plane))
            return true;
        tmp = tmp->next;
    }
    return false;
}

static void add_exp(game_t *game, planes_t *plane)
{
    list_exp *new = malloc(sizeof(list_exp));
    sfVector2f pos = {plane->position.x, plane->position.y};

    new->sprite = sfSprite_create();
    new->texture = sfTexture_createFromFile("assets/explosion.png", NULL);
    sfSprite_setTexture(new->sprite, new->texture, sfTrue);
    new->rect = (sfIntRect){0, 0, 140, 139};
    sfSprite_setTextureRect(new->sprite, new->rect);
    sfSprite_setScale(new->sprite, (sfVector2f){0.3, 0.3});
    sfSprite_setOrigin(new->sprite, (sfVector2f){70, 70});
    sfSprite_setPosition(new->sprite, pos);
    new->position = pos;
    new->clock = sfClock_create();
    new->time = (sfTime){0};
    new->seconds = 0;
    new->offset = 140;
    new->max_value = 140 * 7;
    new->next = game->list_exp;
    game->list_exp = new;
}

static void check_corner(corner_t *otherCorner, planes_t *my_plane,
    game_t *game)
{
    planes_t *other_plane;

    for (int i = 0; otherCorner->planes[i] != NULL; i++) {
        other_plane = otherCorner->planes[i];
        if (other_plane->etat == 1 && my_plane->etat == 1 &&
            !is_secured(my_plane, game) && !is_secured(other_plane, game) &&
            is_intersecting_planes(my_plane, other_plane)) {
            my_plane->etat = 2;
            other_plane->etat = 2;
            add_exp(game, other_plane);
            add_exp(game, my_plane);
            game->scores->destroyed += 2;
        }
    }
}

static int get_corner_line(game_t *game, int num)
{
    return num / game->cols;
}

static int get_corner_col(game_t *game, int num)
{
    return num % game->cols;
}

static void other_plane2(game_t *game, corner_t *corner, planes_t *my_plane)
{
    int line = get_corner_line(game, corner->num);
    int col = get_corner_col(game, corner->num);

    if ((line > 0) && my_plane->position.x <= corner->area.left)
        check_corner(game->corners[line - 1][col], my_plane, game);
    if ((line < game->rows - 1) && my_plane->position.x >= corner->area.left
        + corner->area.width)
        check_corner(game->corners[line + 1][col], my_plane, game);
    if ((col > 0) && my_plane->position.y <= corner->area.top)
        check_corner(game->corners[line][col - 1], my_plane, game);
    if ((col < game->cols - 1) && my_plane->position.y >= corner->area.top
        + corner->area.height)
        check_corner(game->corners[line][col + 1], my_plane, game);
}

static void other_corner(game_t *game, corner_t *corner, planes_t *my_plane)
{
    int line = get_corner_line(game, corner->num);
    int col = get_corner_col(game, corner->num);

    if ((line > 0 && col > 0) && my_plane->position.x <= corner->area.left
        && my_plane->position.y <= corner->area.top)
        check_corner(game->corners[line - 1][col - 1], my_plane, game);
    if ((line > 0 && col < game->cols - 1) && my_plane->position.x >=
        corner->area.left + corner->area.width && my_plane->position.y
        <= corner->area.top)
        check_corner(game->corners[line - 1][col + 1], my_plane, game);
    if ((line < game->rows - 1 && col > 0) && my_plane->position.x <=
        corner->area.left && my_plane->position.y >= corner->area.top +
        corner->area.height)
        check_corner(game->corners[line + 1][col - 1], my_plane, game);
    if ((line < game->rows - 1 && col < game->cols - 1) &&
        my_plane->position.x >= corner->area.left + corner->area.width &&
        my_plane->position.y >= corner->area.top + corner->area.height)
        check_corner(game->corners[line + 1][col + 1], my_plane, game);
    other_plane2(game, corner, my_plane);
}

void check_collision_in_corner(game_t *game, corner_t *corner,
    planes_t *my_plane)
{
    planes_t *other_plane;

    for (int j = 0; corner->planes[j] != NULL; j++) {
        other_plane = corner->planes[j];
        if (other_plane->etat == 1 && my_plane->etat == 1 && other_plane !=
            my_plane && !is_secured(my_plane, game) &&
            !is_secured(other_plane, game) &&
            is_intersecting_planes(my_plane, other_plane)) {
            my_plane->etat = 2;
            add_exp(game, other_plane);
            add_exp(game, my_plane);
            other_plane->etat = 2;
            game->scores->destroyed += 2;
            break;
        }
    }
    if (my_plane->etat == 1)
        other_corner(game, corner, my_plane);
}
