/*
** EPITECH PROJECT, 2023
** delivery
** File description:
** event_mouse_button2
*/

#include "my.h"

static void get_filepath(game_t *game, char *name)
{
    if (!my_strcmp(name, "100"))
        game->filepath = my_strdup("maps/100.txt");
    if (!my_strcmp(name, "500"))
        game->filepath = my_strdup("maps/500.txt");
    if (!my_strcmp(name, "1000"))
        game->filepath = my_strdup("maps/1000.txt");
    if (!my_strcmp(name, "3000"))
        game->filepath = my_strdup("maps/3000.txt");
    if (!my_strcmp(name, "10000"))
        game->filepath = my_strdup("maps/10000.txt");
}

static void choose_to_menu(game_t *game, char *name)
{
    get_filepath(game, name);
    game->phase = my_strdup("menu");
    desactive_elem(&game->list_button, "my_files");
    desactive_elem(&game->list_button, "100");
    desactive_elem(&game->list_button, "500");
    desactive_elem(&game->list_button, "1000");
    desactive_elem(&game->list_button, "3000");
    desactive_elem(&game->list_button, "10000");
    desactive_elem(&game->list_button, "back");
    active_elem(&game->list_button, "simulation");
    active_elem(&game->list_button, "choose");
    active_elem(&game->list_button, "rect");
    active_elem(&game->list_button, "modes");
    active_elem(&game->list_button, "my_radar");
}

static void menu_to_choose(game_t *game)
{
    game->phase = my_strdup("choose_map");
    desactive_elem(&game->list_button, "simulation");
    desactive_elem(&game->list_button, "choose");
    desactive_elem(&game->list_button, "rect");
    desactive_elem(&game->list_button, "modes");
    desactive_elem(&game->list_button, "my_radar");
    active_elem(&game->list_button, "my_files");
    active_elem(&game->list_button, "100");
    active_elem(&game->list_button, "500");
    active_elem(&game->list_button, "1000");
    active_elem(&game->list_button, "3000");
    active_elem(&game->list_button, "10000");
    active_elem(&game->list_button, "back");
}

static void menu_to_modes(game_t *game)
{
    game->phase = my_strdup("modes");
    desactive_elem(&game->list_button, "simulation");
    desactive_elem(&game->list_button, "choose");
    desactive_elem(&game->list_button, "rect");
    desactive_elem(&game->list_button, "my_radar");
    desactive_elem(&game->list_button, "modes");
    active_elem(&game->list_button, "realist");
    active_elem(&game->list_button, "storm");
    active_elem(&game->list_button, "rect2");
    active_elem(&game->list_button, "mode");
    active_elem(&game->list_button, "back");
    active_elem(&game->list_button, "rand");
}

static void desactive_current_phase(game_t *game)
{
    if (!my_strcmp(game->phase, "choose_map")) {
        desactive_elem(&game->list_button, "my_files");
        desactive_elem(&game->list_button, "100");
        desactive_elem(&game->list_button, "500");
        desactive_elem(&game->list_button, "1000");
        desactive_elem(&game->list_button, "3000");
        desactive_elem(&game->list_button, "10000");
    } else if (!my_strcmp(game->phase, "modes")) {
        desactive_elem(&game->list_button, "realist");
        desactive_elem(&game->list_button, "storm");
        desactive_elem(&game->list_button, "rect2");
        desactive_elem(&game->list_button, "mode");
        desactive_elem(&game->list_button, "rand");
    }
    desactive_elem(&game->list_button, "back");
}

static void back_to_menu(game_t *game)
{
    desactive_current_phase(game);
    active_elem(&game->list_button, "simulation");
    active_elem(&game->list_button, "choose");
    active_elem(&game->list_button, "rect");
    active_elem(&game->list_button, "my_radar");
    active_elem(&game->list_button, "modes");
    game->phase = my_strdup("menu");
}

static void button_clicked2(game_t *game, list_button_t *current)
{
    if (!my_strcmp(current->name, "rand"))
        change_rand(game, current);
    if (!my_strcmp(current->name, "back"))
        back_to_menu(game);
}

int button_clicked(game_t *game, list_button_t *current)
{
    if (!my_strcmp(current->name, "100") ||
        !my_strcmp(current->name, "500") ||
        !my_strcmp(current->name, "1000") ||
        !my_strcmp(current->name, "3000") ||
        !my_strcmp(current->name, "10000"))
        choose_to_menu(game, current->name);
    if (!my_strcmp(current->name, "simulation"))
        return start_game(game);
    if (!my_strcmp(current->name, "choose"))
        menu_to_choose(game);
    if (!my_strcmp(current->name, "storm"))
        change_storm(game, current);
    if (!my_strcmp(current->name, "modes"))
        menu_to_modes(game);
    if (!my_strcmp(current->name, "realist"))
        change_realist(game, current);
    button_clicked2(game, current);
    return 0;
}
