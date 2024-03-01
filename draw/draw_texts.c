/*
** EPITECH PROJECT, 2023
** delivery
** File description:
** draw_texts
*/

#include "my.h"

static void draw_text_planes_destroyed(game_t *game)
{
    char *text = my_strdup(game->texts->plane_destroyed->str);

    int_to_string(game->scores->destroyed, text);
    sfText_setString(game->texts->plane_destroyed->text, text);
    sfRenderWindow_drawText(game->window, game->texts->plane_destroyed->text,
        NULL);
    free(text);
}

static void draw_text_planes_arrived(game_t *game)
{
    char *text = my_strdup(game->texts->plane_arrived->str);

    int_to_string(game->scores->arrived, text);
    sfText_setString(game->texts->plane_arrived->text, text);
    sfRenderWindow_drawText(game->window, game->texts->plane_arrived->text,
        NULL);
    free(text);
}

static void draw_text_planes_storm(game_t *game)
{
    char *text = my_strdup(game->texts->plane_storm->str);

    int_to_string(game->scores->in_storm, text);
    sfText_setString(game->texts->plane_storm->text, text);
    sfRenderWindow_drawText(game->window, game->texts->plane_storm->text,
        NULL);
    free(text);
}

static int my_strlen(char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return (i);
}

static char *my_strcat_upgrade(char *dest, char *src)
{
    int len_dest = my_strlen(dest);
    int len_src = my_strlen(src);
    int total_len = len_dest + len_src + 1;
    char *result = malloc(sizeof(char) * (total_len));
    int i = 0;

    for (; dest[i] != '\0'; i++) {
        result[i] = dest[i];
    }
    result[i] = '\0';
    my_strcat(result, src);
    return (result);
}

static void draw_text_current_filepath(game_t *game)
{
    char *text = my_strcat_upgrade(game->texts->current_filepath->str,
        game->filepath);

    sfText_setString(game->texts->current_filepath->text, text);
    sfRenderWindow_drawText(game->window, game->texts->current_filepath->text,
        NULL);
    free(text);
}

static int get_fps(void)
{
    static sfClock *clock = NULL;
    static int nb_frame = 0;
    static float time = 0;
    static int my_fps = 0;

    if (clock == NULL)
        clock = sfClock_create();
    time = sfTime_asSeconds(sfClock_getElapsedTime(clock));
    if (time >= 1) {
        my_fps = nb_frame;
        nb_frame = 0;
        sfClock_restart(clock);
    }
    nb_frame++;
    return (my_fps);
}

static void draw_text_fps(game_t *game)
{
    char *text = my_strdup(game->texts->text_fps->str);

    int_to_string(get_fps(), text);
    sfText_setString(game->texts->text_fps->text, text);
    sfRenderWindow_drawText(game->window, game->texts->text_fps->text, NULL);
    free(text);
}

static void draw_text_time(game_t *game)
{
    char *text = my_strdup(game->texts->time->str);

    int_to_string(game->myclock->seconds, text);
    sfText_setString(game->texts->time->text, text);
    sfRenderWindow_drawText(game->window, game->texts->time->text, NULL);
    free(text);
}

void draw_texts(game_t *game)
{
    if (!my_strcmp(game->phase, "game")) {
        draw_text_time(game);
        draw_text_planes_destroyed(game);
        draw_text_planes_arrived(game);
        draw_text_fps(game);
        if (game->activation->storm)
            draw_text_planes_storm(game);
    } else if (!my_strcmp(game->phase, "menu")) {
        draw_text_current_filepath(game);
    }
}
