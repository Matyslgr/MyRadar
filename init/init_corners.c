/*
** EPITECH PROJECT, 2023
** delivery
** File description:
** init_corners
*/

#include "my.h"

static void get_rect(game_t *game, planes_t *plane)
{
    if (game->activation->rand_areas) {
        plane->rect = (sfIntRect){plane->position.x, plane->position.y,
        rand() % 30 + 5, rand() % 30 + 5};
    } else {
        plane->rect = (sfIntRect){plane->position.x, plane->position.y,
        285 * 0.07, 268 * 0.07};
    }
}

static planes_t *create_plane(game_t *game, sfVector2f position,
    sfVector2f end, int speed)
{
    planes_t *plane = malloc(sizeof(planes_t));
    float angle = atan2(end.y - position.y, end.x - position.x);

    plane->start = position;
    plane->position = position;
    plane->sprite = sfSprite_create();
    plane->texture = sfTexture_createFromFile("assets/plane.png", NULL);
    plane->end = end;
    plane->speed = speed;
    plane->etat = 0;
    get_rect(game, plane);
    sfSprite_setTexture(plane->sprite, plane->texture, sfTrue);
    sfSprite_setPosition(plane->sprite, plane->position);
    sfSprite_setScale(plane->sprite, (sfVector2f){0.07, 0.07});
    sfSprite_setOrigin(plane->sprite, (sfVector2f){285 / 2, 268 / 2});
    sfSprite_setRotation(plane->sprite, angle * 180.0 / PI);
    return (plane);
}

static void fill_corners2(game_t *game, list_plane_t *tmp, int j)
{
    int pos_x;
    int pos_y;

    for (int k = 0; k < game->cols; k++) {
        pos_x = tmp->start.x;
        pos_y = tmp->start.y;
        if (pos_x >= game->corners[j][k]->area.left &&
            pos_x <= game->corners[j][k]->area.left +
            game->corners[j][k]->area.width &&
            pos_y >= game->corners[j][k]->area.top &&
            pos_y <= game->corners[j][k]->area.top +
            game->corners[j][k]->area.height) {
            game->corners[j][k]->planes[game->corners[j][k]->nb_planes] =
            create_plane(game, tmp->start, tmp->end, tmp->speed);
            game->corners[j][k]->planes[game->corners[j][k]->nb_planes]->delay
            = tmp->delay;
            (game->corners[j][k]->nb_planes)++;
        }
    }
}

void fill_corners(game_t *game, list_plane_t *avions)
{
    list_plane_t *tmp = avions;

    while (tmp != NULL) {
        for (int j = 0; j < game->rows; j++) {
            fill_corners2(game, tmp, j);
        }
        tmp = tmp->next;
    }
}

static corner_t *init_my_corner(unsigned int total_planes)
{
    corner_t *my_corner = malloc(sizeof(corner_t));

    my_corner->planes = malloc(sizeof(planes_t) *
    total_planes * 2);
    memset(my_corner->planes, 0, sizeof(planes_t *) *
    total_planes * 2);
    my_corner->nb_planes = 0;
    return (my_corner);
}

corner_t ***init_corners(unsigned int total_planes, int rows, int cols)
{
    corner_t ***corners = malloc(sizeof(corner_t **) * (rows + 1));
    int i = 0;
    int j = 0;
    int num = 0;

    for (i = 0; i < rows; i++) {
        corners[i] = malloc(sizeof(corner_t *) * (cols + 1));
        for (j = 0; j < cols; j++) {
            corners[i][j] = init_my_corner(total_planes);
            corners[i][j]->area = (sfIntRect){j * WIDTH / cols, i * HEIGHT /
            rows, WIDTH / cols, HEIGHT / rows};
            corners[i][j]->num = num;
            num++;
        }
        corners[i][j] = NULL;
    }
    corners[i] = NULL;
    return (corners);
}
