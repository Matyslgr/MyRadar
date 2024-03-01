/*
** EPITECH PROJECT, 2023
** delivery
** File description:
** draw
*/

#include "my.h"

static void draw_game(game_t *game)
{
    if (game->activation->disp_corners)
        draw_corner_areas(game);
    if (game->activation->disp_sprite) {
        if (game->activation->storm)
            display_storm(game);
        draw_planes(game);
        if (!my_strcmp(game->phase, "game"))
            draw_towers(game);
    }
    if (!my_strcmp(game->phase, "game") && game->activation->hitbox) {
        draw_hitbox(game);
        if (game->activation->storm)
            draw_hitbox_storm(game);
    }
    if (!my_strcmp(game->phase, "game"))
        draw_circles(game);
}

static void draw_correct_sprite(game_t *game, list_button_t *current)
{
    if (!my_strcmp(current->type, "def") && !current->clic)
        sfRenderWindow_drawSprite(game->window, current->spritedef, NULL);
    if (!my_strcmp(current->type, "hover") && !current->clic)
        sfRenderWindow_drawSprite(game->window, current->spriteent, NULL);
    if (!my_strcmp(current->type, "def") && current->clic)
        sfRenderWindow_drawSprite(game->window, current->spriteclick, NULL);
    if (!my_strcmp(current->type, "hover") && current->clic)
        sfRenderWindow_drawSprite(game->window, current->spriteclickent, NULL);
}

static void draw_background(game_t *game)
{
    if (game->activation->realist)
        sfRenderWindow_drawSprite(game->window,
            game->background->sprite_realist, NULL);
    else
        sfRenderWindow_drawSprite(game->window,
            game->background->sprite, NULL);
}

static void draw_explosion(game_t *game)
{
    list_exp *tmp = game->list_exp;

    while (tmp != NULL) {
        sfRenderWindow_drawSprite(game->window, tmp->sprite, NULL);
        tmp = tmp->next;
    }
}

void draw(game_t *game)
{
    list_button_t *current = game->list_button;

    sfRenderWindow_clear(game->window, sfBlack);
    draw_background(game);
    draw_game(game);
    while (current != NULL) {
        if (current->etat) {
            draw_correct_sprite(game, current);
        }
        current = current->next;
    }
    if (!my_strcmp(game->phase, "game"))
        draw_explosion(game);
    draw_texts(game);
    sfRenderWindow_display(game->window);
}
