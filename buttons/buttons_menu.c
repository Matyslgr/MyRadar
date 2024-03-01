/*
** EPITECH PROJECT, 2023
** delivery
** File description:
** buttons_menu
*/

#include "my.h"

void add_button_simulation(list_button_t **list_button)
{
    list_button_t *sim = malloc(sizeof(list_button_t));
    sfVector2u textureSize;

    sim->type = "def";
    sim->texturedef = sfTexture_createFromFile
        ("assets/buttons/menu/Simulationdef.png", NULL);
    sim->spritedef = sfSprite_create();
    sim->textureent = sfTexture_createFromFile
        ("assets/buttons/menu/Simulationent.png", NULL);
    sim->spriteent = sfSprite_create();
    sfSprite_setTexture(sim->spriteent, sim->textureent, sfTrue);
    sfSprite_setTexture(sim->spritedef, sim->texturedef, sfTrue);
    sim->name = my_strdup("simulation");
    textureSize = sfTexture_getSize(sim->texturedef);
    sim->area = (sfIntRect){1140, 750, textureSize.x, textureSize.y};
    sim->etat = true;
    sim->next = NULL;
    sfSprite_setPosition(sim->spritedef, (sfVector2f){1140, 750});
    sfSprite_setPosition(sim->spriteent, (sfVector2f){1120, 748});
    add_at_list(list_button, sim);
}

void add_rect(list_button_t **list_button)
{
    list_button_t *rect = malloc(sizeof(list_button_t));

    rect->type = "def";
    rect->name = my_strdup("rect");
    rect->texturedef = sfTexture_createFromFile
        ("assets/buttons/menu/Rectangle 1.png", NULL);
    rect->spritedef = sfSprite_create();
    sfSprite_setTexture(rect->spritedef, rect->texturedef, sfTrue);
    sfSprite_setPosition(rect->spritedef, (sfVector2f){1075, 70});
    rect->etat = true;
    rect->next = NULL;
    add_at_list(list_button, rect);
}

void add_my_radar(list_button_t **list_button)
{
    list_button_t *my_radar = malloc(sizeof(list_button_t));

    my_radar->type = "def";
    my_radar->texturedef = sfTexture_createFromFile
        ("assets/buttons/menu/My Radar.png", NULL);
    my_radar->spritedef = sfSprite_create();
    sfSprite_setTexture(my_radar->spritedef, my_radar->texturedef, sfTrue);
    sfSprite_setPosition(my_radar->spritedef, (sfVector2f){100, 150});
    my_radar->name = my_strdup("my_radar");
    my_radar->etat = true;
    my_radar->next = NULL;
    add_at_list(list_button, my_radar);
}

void add_modes(list_button_t **list_button)
{
    list_button_t *modes = malloc(sizeof(list_button_t));
    sfVector2u textureSize;

    modes->type = "def";
    modes->texturedef = sfTexture_createFromFile
        ("assets/buttons/menu/Modesdef.png", NULL);
    modes->spritedef = sfSprite_create();
    sfSprite_setTexture(modes->spritedef, modes->texturedef, sfTrue);
    modes->textureent = sfTexture_createFromFile
        ("assets/buttons/menu/Modesent.png", NULL);
    modes->spriteent = sfSprite_create();
    sfSprite_setTexture(modes->spriteent, modes->textureent, sfTrue);
    modes->name = my_strdup("modes");
    sfSprite_setPosition(modes->spritedef, (sfVector2f){1250, 250});
    sfSprite_setPosition(modes->spriteent, (sfVector2f){1230, 248});
    textureSize = sfTexture_getSize(modes->texturedef);
    modes->area = (sfIntRect){1250, 250, textureSize.x, textureSize.y};
    modes->etat = true;
    modes->next = NULL;
    add_at_list(list_button, modes);
}

void add_choose(list_button_t **list_button)
{
    list_button_t *choose = malloc(sizeof(list_button_t));
    sfVector2u textureSize;

    choose->type = "def";
    choose->texturedef = sfTexture_createFromFile
        ("assets/buttons/menu/Filedef.png", NULL);
    choose->textureent = sfTexture_createFromFile
        ("assets/buttons/menu/Fileent.png", NULL);
    choose->spritedef = sfSprite_create();
    choose->spriteent = sfSprite_create();
    choose->name = my_strdup("choose");
    sfSprite_setTexture(choose->spritedef, choose->texturedef, sfTrue);
    sfSprite_setTexture(choose->spriteent, choose->textureent, sfTrue);
    sfSprite_setPosition(choose->spritedef, (sfVector2f){1350, 500});
    sfSprite_setPosition(choose->spriteent, (sfVector2f){1330, 490});
    textureSize = sfTexture_getSize(choose->texturedef);
    choose->area = (sfIntRect){1350, 500, textureSize.x, textureSize.y};
    choose->etat = true;
    choose->next = NULL;
    add_at_list(list_button, choose);
}
