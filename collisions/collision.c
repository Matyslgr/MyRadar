/*
** EPITECH PROJECT, 2023
** delivery
** File description:
** collision
*/

#include "my.h"

static void collision2(game_t *game, corner_t *corner)
{
    for (int k = 0; corner->planes[k] != NULL; k++) {
        if (is_secured(corner->planes[k], game))
            continue;
        if (corner->planes[k]->etat == 1)
            check_collision_in_corner(game, corner, corner->planes[k]);
    }
}

void collision(game_t *game)
{
    for (int i = 0; i < game->rows; i++) {
        for (int j = 0; j < game->cols; j++) {
            collision2(game, game->corners[i][j]);
        }
    }
}

// static void other_corner(game_t *game, corner_t *corner, planes_t *my_plane)
// {
//     int line = get_corner_line(game, corner->num);
//     int col = get_corner_col(game, corner->num);

//     if (line > 0 && col > 0)
//         check_corner(game->corners[line - 1][col - 1], my_plane, game);
//     if (line > 0 && col < game->cols - 1)
//         check_corner(game->corners[line - 1][col + 1], my_plane, game);
//     if (line < game->rows - 1 && col > 0)
//         check_corner(game->corners[line + 1][col - 1], my_plane, game);
//     if (line < game->rows - 1 && col < game->cols - 1)
//         check_corner(game->corners[line + 1][col + 1], my_plane, game);
//     if (line > 0)
//         check_corner(game->corners[line - 1][col], my_plane, game);
//     if (line < game->rows - 1)
//         check_corner(game->corners[line + 1][col], my_plane, game);
//     if (col > 0)
//         check_corner(game->corners[line][col - 1], my_plane, game);
//     if (col < game->cols - 1)
//         check_corner(game->corners[line][col + 1], my_plane, game);
// }
