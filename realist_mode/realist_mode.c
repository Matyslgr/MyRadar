/*
** EPITECH PROJECT, 2023
** delivery
** File description:
** realist_mode
*/

#include "my.h"

static sfVector2f *init_pos2(sfVector2f *pos)
{
    pos[17] = (sfVector2f){1625, 369};
    pos[18] = (sfVector2f){1792, 317};
    pos[19] = (sfVector2f){1833, 147};
    pos[20] = (sfVector2f){1597, 563};
    pos[21] = (sfVector2f){1857, 721};
    return pos;
}

static sfVector2f *init_pos(void)
{
    sfVector2f *pos = malloc(sizeof(sfVector2f) * 22);

    pos[0] = (sfVector2f){58, 142};
    pos[1] = (sfVector2f){396, 315};
    pos[2] = (sfVector2f){358, 409};
    pos[3] = (sfVector2f){509, 248};
    pos[4] = (sfVector2f){708, 150};
    pos[5] = (sfVector2f){574, 793};
    pos[6] = (sfVector2f){691, 635};
    pos[7] = (sfVector2f){970, 498};
    pos[8] = (sfVector2f){1120, 686};
    pos[9] = (sfVector2f){1148, 363};
    pos[10] = (sfVector2f){941, 301};
    pos[11] = (sfVector2f){990, 251};
    pos[12] = (sfVector2f){964, 193};
    pos[13] = (sfVector2f){1118, 211};
    pos[14] = (sfVector2f){1258, 415};
    pos[15] = (sfVector2f){1419, 292};
    pos[16] = (sfVector2f){1455, 423};
    return init_pos2(pos);
}

static void init_game_start(game_t *game, list_plane_t *list_planes,
    list_tower_t *list_towers, unsigned int total_planes)
{
    game->list_towers = list_towers;
    game->total_planes = total_planes;
    game->corners = init_corners(total_planes, game->rows, game->cols);
    fill_corners(game, list_planes);
    free_list_plane(list_planes);
}

int realist_mode(game_t *game)
{
    sfVector2f *pos = init_pos();
    list_plane_t *list_planes = NULL;
    list_tower_t *list_towers = NULL;
    unsigned int total_planes = parse_file(game->filepath, &list_planes,
        &list_towers);
    list_plane_t *tmp = list_planes;

    if ((int)total_planes == -1)
        return 84;
    while (tmp != NULL) {
        tmp->start = pos[rand() % 22];
        tmp->end = pos[rand() % 22];
        while (tmp->start.x == tmp->end.x && tmp->start.y == tmp->end.y)
            tmp->end = pos[rand() % 22];
        tmp = tmp->next;
    }
    init_game_start(game, list_planes, list_towers, total_planes);
    return 0;
}
