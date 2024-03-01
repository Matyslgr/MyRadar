/*
** EPITECH PROJECT, 2023
** boostrap
** File description:
** my_radar
*/

#include "my.h"

static storm_zone_t *init_storm_zone(void)
{
    storm_zone_t *storm_zone = malloc(sizeof(storm_zone_t));

    storm_zone->sprite = sfSprite_create();
    storm_zone->texture = sfTexture_createFromFile("assets/cyclone.png", NULL);
    storm_zone->angle = 0;
    storm_zone->area = (sfIntRect){500, 400, 320, 300};
    storm_zone->radius = rand() % 260 + 100;
    storm_zone->speed = 0.0005;
    sfSprite_setTexture(storm_zone->sprite, storm_zone->texture, sfTrue);
    sfSprite_setPosition(storm_zone->sprite, (sfVector2f){810, 540});
    sfSprite_setOrigin(storm_zone->sprite, (sfVector2f){200, 170});
    return (storm_zone);
}

static activation_t *init_activation(void)
{
    activation_t *activation = malloc(sizeof(activation_t));

    activation->hitbox = false;
    activation->disp_sprite = true;
    activation->storm = false;
    activation->disp_corners = false;
    activation->realist = false;
    activation->rand_areas = false;
    return (activation);
}

static background_t *init_background(void)
{
    background_t *background = malloc(sizeof(background_t));

    background->texture = sfTexture_createFromFile(
        "assets/carte.jpg", NULL);
    background->sprite = sfSprite_create();
    sfSprite_setTexture(background->sprite, background->texture, sfTrue);
    background->texture_realist = sfTexture_createFromFile(
        "assets/map_mode_realist.jpg", NULL);
    background->sprite_realist = sfSprite_create();
    sfSprite_setTexture(background->sprite_realist,
        background->texture_realist, sfTrue);
    return (background);
}

static scores_t *init_scores(void)
{
    scores_t *scores = malloc(sizeof(scores_t));

    scores->destroyed = 0;
    scores->arrived = 0;
    scores->in_storm = 0;
    return (scores);
}

void anime_menu(game_t *game)
{
    list_plane_t *list_planes = NULL;
    sfVector2f start;
    sfVector2f end;
    int speed;
    float delay;
    unsigned int nb_planes = 25;

    for (int i = 0; i < (int)nb_planes; i++) {
        start.x = rand() % 1850 + 50;
        start.y = rand() % 1000 + 50;
        end.x = rand() % 1850 + 50;
        end.y = rand() % 1000 + 50;
        speed = rand() % 2 + 1;
        delay = rand() % 10;
        list_planes_push(&list_planes, (sfVector2f[2]){start, end}, speed,
            delay);
    }
    game->corners = init_corners(nb_planes, game->rows, game->cols);
    fill_corners(game, list_planes);
    free_list_plane(list_planes);
}

static void create_clock(Clock_t *clock)
{
    clock->clock = sfClock_create();
    clock->seconds = 0;
}

static void init_game2(game_t *game)
{
    Clock_t *myclock = malloc(sizeof(Clock_t));

    game->texts = init_texts();
    game->scores = init_scores();
    create_clock(myclock);
    game->myclock = myclock;
    game->event = (sfEvent){0};
    game->list_exp = NULL;
    anime_menu(game);
}

game_t *init_game(char *filepath)
{
    game_t *game = malloc(sizeof(game_t));
    int rows = 16;
    int cols = 20;
    sfVideoMode mode = {WIDTH, HEIGHT, 32};

    srand((unsigned int)time(NULL));
    game->window = sfRenderWindow_create(mode, "My Radar", sfClose, NULL);
    game->fps = 60;
    sfRenderWindow_setFramerateLimit(game->window, game->fps);
    game->phase = my_strdup("menu");
    game->rows = rows;
    game->cols = cols;
    game->activation = init_activation();
    game->filepath = filepath;
    game->storm_zone = init_storm_zone();
    game->background = init_background();
    game->list_button = init_list_button();
    init_game2(game);
    return (game);
}
