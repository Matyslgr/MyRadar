/*
** EPITECH PROJECT, 2023
** delivery
** File description:
** texts
*/

#include "my.h"

static text_t *create_text_destroyed(void)
{
    text_t *text = malloc(sizeof(text_t));

    text->font = sfFont_createFromFile("font/Clone Age.ttf");
    text->text = sfText_create();
    text->str = my_strdup("Planes destroyed : ");
    sfText_setFont(text->text, text->font);
    sfText_setCharacterSize(text->text, 20);
    sfText_setColor(text->text, sfRed);
    sfText_setPosition(text->text, (sfVector2f){1460, 80});
    return (text);
}

static text_t *create_text_fps(void)
{
    text_t *text = malloc(sizeof(text_t));

    text->font = sfFont_createFromFile("font/Clone Age.ttf");
    text->text = sfText_create();
    text->str = my_strdup("FPS : ");
    sfText_setFont(text->text, text->font);
    sfText_setCharacterSize(text->text, 20);
    sfText_setColor(text->text, sfWhite);
    sfText_setPosition(text->text, (sfVector2f){30, 70});
    return (text);
}

static text_t *create_text_planes_arrived(void)
{
    text_t *text = malloc(sizeof(text_t));

    text->font = sfFont_createFromFile("font/Clone Age.ttf");
    text->text = sfText_create();
    text->str = my_strdup("Planes arrived : ");
    sfText_setFont(text->text, text->font);
    sfText_setCharacterSize(text->text, 20);
    sfText_setColor(text->text, sfGreen);
    sfText_setPosition(text->text, (sfVector2f){1510, 30});
    return (text);
}

static text_t *create_text_planes_storm(void)
{
    text_t *text = malloc(sizeof(text_t));

    text->font = sfFont_createFromFile("font/Clone Age.ttf");
    text->text = sfText_create();
    text->str = my_strdup("Planes in storm : ");
    sfText_setFont(text->text, text->font);
    sfText_setCharacterSize(text->text, 20);
    sfText_setColor(text->text, sfBlue);
    sfText_setPosition(text->text, (sfVector2f){1500, 130});
    return (text);
}

static text_t *current_filepath(void)
{
    text_t *text = malloc(sizeof(text_t));

    text->font = sfFont_createFromFile("font/Clone Age.ttf");
    text->text = sfText_create();
    text->str = my_strdup("Current map : ");
    sfText_setFont(text->text, text->font);
    sfText_setCharacterSize(text->text, 20);
    sfText_setColor(text->text, sfBlack);
    sfText_setPosition(text->text, (sfVector2f){30, 1020});
    return (text);
}

static text_t *time_text(void)
{
    text_t *text = malloc(sizeof(text_t));

    text->font = sfFont_createFromFile("font/Clone Age.ttf");
    text->text = sfText_create();
    text->str = my_strdup("Time : ");
    sfText_setFont(text->text, text->font);
    sfText_setCharacterSize(text->text, 20);
    sfText_setColor(text->text, sfWhite);
    sfText_setPosition(text->text, (sfVector2f){30, 30});
    return (text);
}

texts_t *init_texts(void)
{
    texts_t *my_texts = malloc(sizeof(texts_t));

    my_texts->plane_destroyed = create_text_destroyed();
    my_texts->plane_arrived = create_text_planes_arrived();
    my_texts->plane_storm = create_text_planes_storm();
    my_texts->current_filepath = current_filepath();
    my_texts->text_fps = create_text_fps();
    my_texts->time = time_text();
    return (my_texts);
}
