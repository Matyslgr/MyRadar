/*
** EPITECH PROJECT, 2023
** delivery
** File description:
** list_towers
*/

#include "my.h"


static list_tower_t *create_tower(sfVector2f pos, float radius)
{
    list_tower_t *tower = malloc(sizeof(list_tower_t));
    sfCircleShape *circle = sfCircleShape_create();

    sfCircleShape_setRadius(circle, radius);
    sfCircleShape_setFillColor(circle, sfColor_fromRGBA(255, 255, 255, 30));
    sfCircleShape_setOutlineThickness(circle, 1);
    sfCircleShape_setOutlineColor(circle, sfWhite);
    sfCircleShape_setPosition(circle, (sfVector2f){pos.x - radius,
    pos.y - radius});
    tower->circle = circle;
    tower->position = pos;
    tower->radius = radius;
    tower->sprite = sfSprite_create();
    tower->texture = sfTexture_createFromFile("assets/tour.png", NULL);
    tower->next = NULL;
    sfSprite_setTexture(tower->sprite, tower->texture, sfTrue);
    sfSprite_setOrigin(tower->sprite, (sfVector2f){40, 60});
    sfSprite_setPosition(tower->sprite, pos);
    return (tower);
}

static void add_new(list_tower_t *tmp, list_tower_t *new,
    list_tower_t *new_new)
{
    for (; tmp->next != NULL; tmp = tmp->next);
    tmp->next = new;
    if (new_new != NULL)
        tmp->next->next = new_new;
}

static void list_towers_push(list_tower_t **list,
    sfVector2f pos, float radius)
{
    list_tower_t *new = create_tower(pos, radius);
    list_tower_t *tmp = *list;
    list_tower_t *new_new = NULL;

    if (new->position.x + new->radius > 1920) {
        new_new = create_tower((sfVector2f){new->position.x - 1920,
        new->position.y}, new->radius);
    }
    if (new->position.x - new->radius < 0) {
        new_new = create_tower(
        (sfVector2f){new->position.x + 1920,
        new->position.y}, new->radius);
    }
    if (*list == NULL) {
        *list = new;
        return;
    }
    add_new(tmp, new, new_new);
}

int is_tower(char *str, int i, list_tower_t **list)
{
    sfVector2f pos = {0, 0};
    float radius = 0;

    skip_esp(str, &i);
    pos.x = get_nbr(str, &i);
    skip_esp(str, &i);
    pos.y = get_nbr(str, &i);
    skip_esp(str, &i);
    radius = get_nbr(str, &i);
    list_towers_push(list, pos, radius);
    return 0;
}
