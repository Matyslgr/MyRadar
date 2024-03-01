/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** my_radar
*/
#pragma once

#include <SFML/Graphics.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#define WIDTH 1920
#define HEIGHT 1080
#define FPS 60
#define PI 3.14159265358979323846
#define HALF_LEFT 28.5
#define HALF_TOP 26.8
#define PREC 8.0

//liste aéroports
//Amérique du Nord
// (58, 142)
// (396, 315)
// (358, 409)
// (509, 248)
// (708, 150)
//Amérique du Sud
// (574, 793)
// (691, 635)
//Afrique
// (970, 498)
// (1120, 686)
// (1148, 363)
//Europe
// (941, 301)
// (990, 251)
// (964, 193)
// (1118, 211)
//Asie
// (1258, 415)
// (1419, 292)
// (1455, 423)
// (1625, 369)
// (1792, 317)
// (1833, 147)
//Océanie
// (1597, 563)
// (1857, 721)

typedef struct path_storm {
    int x;
    int y;
    int dx;
    int dy;
    int dest_x;
    int dest_y;
    int sx;
    int sy;
    int err;
    int err2;
} path_storm_t;

typedef struct planes {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
    sfVector2f start;
    sfVector2f end;
    sfIntRect rect;
    int speed;
    float delay;
    int etat;
    float dx;
    float dy;
} planes_t;

typedef struct list_tower {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
    float radius;
    sfCircleShape *circle;
    struct list_tower *next;
} list_tower_t;

typedef struct list_plane {
    sfVector2f start;
    sfVector2f end;
    int speed;
    float delay;

    struct list_plane *next;
} list_plane_t;

typedef struct corner {
    sfIntRect area;
    int num;
    unsigned int nb_planes;
    planes_t **planes;
} corner_t;

typedef struct {
    int row;
    int col;
} CornerCoordinates;

typedef struct Clock {
    sfClock *clock;
    sfTime time;
    float seconds;
} Clock_t;

typedef struct move {
    float dx;
    float dy;
    float distance;
    sfVector2f temp_end;
} move_t;

typedef struct storm_zone {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
    sfIntRect area;
    float angle;
    float radius;
    float speed;
} storm_zone_t;

typedef struct activation {
    bool storm;
    bool hitbox;
    bool disp_sprite;
    bool disp_corners;
    bool realist;
    bool rand_areas;
} activation_t;

typedef struct background {
    sfSprite *sprite;
    sfTexture *texture;
    sfSprite *sprite_realist;
    sfTexture *texture_realist;
} background_t;

typedef struct list_button {
    char *name;
    char *type;
    bool clic;
    sfSprite *spritedef;
    sfTexture *texturedef;
    sfSprite *spriteent;
    sfTexture *textureent;
    sfSprite *spriteclick;
    sfTexture *textureclick;
    sfSprite *spriteclickent;
    sfTexture *textureclickent;
    sfVector2f position;
    sfIntRect area;
    bool etat;
    struct list_button *next;
} list_button_t;

typedef struct text {
    sfText *text;
    sfFont *font;
    char *str;
    sfVector2f position;
} text_t;

typedef struct texts {
    text_t *plane_destroyed;
    text_t *plane_arrived;
    text_t *plane_storm;
    text_t *current_filepath;
    text_t *text_fps;
    text_t *time;
} texts_t;

typedef struct scores {
    int destroyed;
    int arrived;
    int in_storm;
} scores_t;

typedef struct list_explosion {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
    sfIntRect rect;
    sfClock *clock;
    sfTime time;
    float seconds;
    int offset;
    int max_value;
    struct list_explosion *next;
} list_exp;

typedef struct game {
    char *phase;
    int fps;
    int rows;
    int cols;
    char *filepath;
    unsigned int total_planes;
    sfEvent event;
    sfRenderWindow *window;
    corner_t ***corners;
    list_tower_t *list_towers;
    activation_t *activation;
    storm_zone_t *storm_zone;
    Clock_t *myclock;
    background_t *background;
    list_button_t *list_button;
    texts_t *texts;
    scores_t *scores;
    list_exp *list_exp;
} game_t;

//tools
list_button_t *get_elem(list_button_t **list_button, char *name);
void desactive_elem(list_button_t **list_button, char *name);
void active_elem(list_button_t **list_button, char *name);

//init
game_t *init_game(char *filepath);
void anime_menu(game_t *game);

//init_corners
corner_t ***init_corners(unsigned int total_planes, int rows, int cols);
void fill_corners(game_t *game, list_plane_t *avions);

//init buttons
void add_at_list(list_button_t **list_button, list_button_t *new);
list_button_t *init_list_button(void);
void add_back(list_button_t **list_button);

//buttons menu
void add_choose(list_button_t **list_button);
void add_my_radar(list_button_t **list_button);
void add_modes(list_button_t **list_button);
void add_rect(list_button_t **list_button);
void add_button_simulation(list_button_t **list_button);

//buttons modes
void add_button_storm(list_button_t **list_button);
void add_button_realist(list_button_t **list_button);
void add_rect2(list_button_t **list_button);
void add_mode(list_button_t **list_button);
void add_rand(list_button_t **list_button);

//buttons_my_files
void add_10000(list_button_t **list_button);
void add_3000(list_button_t **list_button);
void add_1000(list_button_t **list_button);
void add_500(list_button_t **list_button);
void add_100(list_button_t **list_button);

//texts
texts_t *init_texts(void);

//parsing
unsigned int parse_file(char *filepath, list_plane_t **list_planes,
    list_tower_t **list_towers);
void skip_esp(char *str, int *i);
int get_nbr(char const *str, int *i);
void list_planes_push(list_plane_t **list, sfVector2f *coords,
    int speed, float delay);

//list_towers
int is_tower(char *str, int i, list_tower_t **list);

//move
void set_plane_position(game_t *game, planes_t *plane);

//move2
void move_plane(game_t *game);

//move_storm
bool path_in_storm_zone(game_t *game, sfVector2f start,
    sfVector2f destination);
void get_best_path(game_t *game, planes_t *plane, move_t *move);

//update
void update(game_t *game);

//update_planes
void check_etat(game_t *game);
void update_area_planes(game_t *game);
void update_nb_plane(game_t *game);

//draw
void draw(game_t *game);

//draw_texts
void draw_texts(game_t *game);

//draw_planes
void draw_planes(game_t *game);
void draw_hitbox(game_t *game);

//draw_towers
void draw_towers(game_t *game);
void draw_circles(game_t *game);

//draw_storm
void display_storm(game_t *game);
void draw_hitbox_storm(game_t *game);
void draw_corner_areas(game_t *game);

//collision
void collision(game_t *game);

//collision2
void check_collision_in_corner(game_t *game, corner_t *corner,
    planes_t *my_plane);
bool is_secured(planes_t *plane, game_t *game);

//restart
void restart(game_t *game);

//event
int event(game_t *game);

//event_mouse_button
void free_list_plane(list_plane_t *list_planes);
int mouse_button(game_t *game);
int start_game(game_t *game);

//event_mouse_button2
int button_clicked(game_t *game, list_button_t *current);

//change_activation
void change_rand(game_t *game, list_button_t *rand);
void change_realist(game_t *game, list_button_t *realist);
void change_storm(game_t *game, list_button_t *storm);

//realist_mode
int realist_mode(game_t *game);

//free
void free_corners(corner_t ***corners, int rows, int cols);
void free_game(game_t *game);

//lib
int my_strcmp(char const *s1, char const *s2);
int my_putnbr(int nb);
int my_putstr(char const *str);
char *my_strdup(char const *src);
char *my_strcat(char *dest, char const *src);
void int_to_string(int num, char *str);
