/*
** EPITECH PROJECT, 2023
** boostrap
** File description:
** my_radar
*/

#include "my.h"

static void print_usage2(void)
{
    my_putstr("   \"Cyclone\"        enable/disable the cyclone on the map\n");
    my_putstr("   \"Realist\"        enable/disable the airports\n\n");
}

static int print_usage(void)
{
    my_putstr("Air traffic simulation panel\n\n");
    my_putstr("USAGE\n");
    my_putstr("  ./my_radar [OPTIONS]\n");
    my_putstr("OPTIONS\n");
    my_putstr("   path_to_script   The path to the script file.\n");
    my_putstr("   -h               print the usage and quit.\n\n");
    my_putstr("USER INTERACTIONS\n");
    my_putstr("   'L' key          enable/disable hitboxes and areas.\n");
    my_putstr("   'S' key          enable/disable sprites.\n");
    my_putstr("   'A' key          enable/disable corners areas.\n");
    my_putstr("   ARROWS\n");
    my_putstr("   'left' key       decrease FPS\n");
    my_putstr("   'right' key      increase FPS\n\n");
    my_putstr("UTILISATION BUTTONS\n");
    my_putstr("   \"File\"           use the maps in the maps folder\n");
    my_putstr("   \"Modes\"          choose between two modes\n");
    my_putstr("   \"Simulation\"     start the simulation\n\n");
    my_putstr("MODES\n");
    print_usage2();
    return 0;
}

static int errors(int ac)
{
    my_putstr("./my_radar: bad arguments: ");
    my_putnbr(ac - 1);
    my_putstr(" given but 84 required\nretry with -h\n");
    return (84);
}

static char *get_filepath(int ac, char **av)
{
    char *filepath;

    if (ac == 1)
        filepath = my_strdup("maps/500.txt");
    else
        filepath = av[1];
    return filepath;
}

static int check_events(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (event(game) == 84)
            return 84;
    }
    return 0;
}

int main(int ac, char **av)
{
    game_t *game;
    char *filepath;

    if (ac > 2)
        return errors(ac);
    if (ac == 2 && my_strcmp(av[1], "-h") == 0)
        return print_usage();
    filepath = get_filepath(ac, av);
    game = init_game(filepath);
    while (sfRenderWindow_isOpen(game->window)) {
        if (check_events(game) == 84) {
            free_game(game);
            return 84;
        }
        update(game);
        draw(game);
    }
    free_game(game);
    return (0);
}
