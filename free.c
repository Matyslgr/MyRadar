/*
** EPITECH PROJECT, 2023
** delivery
** File description:
** free
*/

#include "my.h"

static void free_planes(corner_t *corner)
{
    for (int i = 0; corner->planes[i] != NULL; i++) {
        sfSprite_destroy(corner->planes[i]->sprite);
        sfTexture_destroy(corner->planes[i]->texture);
        free(corner->planes[i]);
    }
    free(corner->planes);
}

void free_corners(corner_t ***corners, int rows, int cols)
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            free_planes(corners[i][j]);
            free(corners[i][j]);
        }
        free(corners[i]);
    }
    free(corners);
}

static void free_list_tower(list_tower_t *list_towers)
{
    list_tower_t *tmp = list_towers;

    while (tmp != NULL) {
        list_towers = list_towers->next;
        free(tmp);
        tmp = list_towers;
    }
}

static void free_list_button(list_button_t *list_button)
{
    list_button_t *tmp = list_button;

    while (tmp != NULL) {
        list_button = list_button->next;
        free(tmp);
        tmp = list_button;
    }
}

static void free_texts(texts_t *texts)
{
    sfText_destroy(texts->plane_destroyed->text);
    sfFont_destroy(texts->plane_destroyed->font);
    sfText_destroy(texts->plane_arrived->text);
    sfFont_destroy(texts->plane_arrived->font);
    sfText_destroy(texts->plane_storm->text);
    sfFont_destroy(texts->plane_storm->font);
    free(texts);
}

void free_game(game_t *game)
{
    if (game->activation != NULL)
        free(game->activation);
    if (game->background != NULL) {
        sfSprite_destroy(game->background->sprite);
        sfTexture_destroy(game->background->texture);
        free(game->background);
    }
    if (game->corners != NULL)
        free_corners(game->corners, game->rows, game->cols);
    if (game->list_towers != NULL)
        free_list_tower(game->list_towers);
    if (game->texts != NULL)
        free_texts(game->texts);
    if (game->list_button != NULL)
        free_list_button(game->list_button);
    free(game->scores);
    sfClock_destroy(game->myclock->clock);
    free(game->myclock);
    sfRenderWindow_destroy(game->window);
    free(game);
}
