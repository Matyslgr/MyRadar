/*
** EPITECH PROJECT, 2023
** delivery
** File description:
** init_button
*/
#include "my.h"

void add_at_list(list_button_t **list_button, list_button_t *new)
{
    new->clic = false;
    if (*list_button == NULL)
        new->next = NULL;
    else
        new->next = *list_button;
    *list_button = new;
}

static void add_load(list_button_t **list_button)
{
    list_button_t *load = malloc(sizeof(list_button_t));
    sfVector2u textureSize;

    load->type = "def";
    load->texturedef = sfTexture_createFromFile
        ("assets/buttons/Load.png", NULL);
    load->spritedef = sfSprite_create();
    sfSprite_setTexture(load->spritedef, load->texturedef, sfTrue);
    sfSprite_setPosition(load->spritedef, (sfVector2f){400, 500});
    textureSize = sfTexture_getSize(load->texturedef);
    load->area = (sfIntRect){400, 500, textureSize.x, textureSize.y};
    load->name = my_strdup("load");
    load->etat = false;
    load->next = NULL;
    add_at_list(list_button, load);
}

static void add_my_files(list_button_t **list_button)
{
    list_button_t *my_files = malloc(sizeof(list_button_t));

    my_files->type = "def";
    my_files->texturedef = sfTexture_createFromFile
        ("assets/buttons/my_files/My files.png", NULL);
    my_files->spritedef = sfSprite_create();
    sfSprite_setTexture(my_files->spritedef, my_files->texturedef, sfTrue);
    sfSprite_setPosition(my_files->spritedef, (sfVector2f){700, 150});
    my_files->name = my_strdup("my_files");
    my_files->etat = false;
    my_files->next = NULL;
    add_at_list(list_button, my_files);
}

void add_back(list_button_t **list_button)
{
    list_button_t *back = malloc(sizeof(list_button_t));
    sfVector2u textureSize;

    back->type = "def";
    back->texturedef = sfTexture_createFromFile
        ("assets/buttons/Backdef.png", NULL);
    back->textureent = sfTexture_createFromFile
        ("assets/buttons/Backent.png", NULL);
    back->spriteent = sfSprite_create();
    back->spritedef = sfSprite_create();
    sfSprite_setTexture(back->spritedef, back->texturedef, sfTrue);
    sfSprite_setTexture(back->spriteent, back->textureent, sfTrue);
    sfSprite_setPosition(back->spritedef, (sfVector2f){50, 900});
    sfSprite_setPosition(back->spriteent, (sfVector2f){50, 900});
    back->name = my_strdup("back");
    back->etat = false;
    back->next = NULL;
    textureSize = sfTexture_getSize(back->texturedef);
    back->area = (sfIntRect){50, 900, textureSize.x, textureSize.y};
    add_at_list(list_button, back);
}

static void init_list_button2(list_button_t **list_button)
{
    add_button_realist(list_button);
    add_rand(list_button);
}

list_button_t *init_list_button(void)
{
    list_button_t *list_button = NULL;

    add_button_simulation(&list_button);
    add_button_storm(&list_button);
    add_modes(&list_button);
    add_choose(&list_button);
    add_load(&list_button);
    add_my_radar(&list_button);
    add_mode(&list_button);
    add_back(&list_button);
    add_100(&list_button);
    add_500(&list_button);
    add_1000(&list_button);
    add_3000(&list_button);
    add_10000(&list_button);
    add_my_files(&list_button);
    add_rect(&list_button);
    add_rect2(&list_button);
    init_list_button2(&list_button);
    return (list_button);
}
