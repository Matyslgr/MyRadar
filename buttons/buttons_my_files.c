/*
** EPITECH PROJECT, 2023
** delivery
** File description:
** buttons_my_files
*/

#include "my.h"

void add_100(list_button_t **list_button)
{
    list_button_t *button = malloc(sizeof(list_button_t));
    sfVector2u textureSize;

    button->type = "def";
    button->name = my_strdup("100");
    button->texturedef = sfTexture_createFromFile
        ("assets/buttons/my_files/100.png", NULL);
    button->spritedef = sfSprite_create();
    button->textureent = sfTexture_createFromFile
        ("assets/buttons/my_files/100ent.png", NULL);
    button->spriteent = sfSprite_create();
    sfSprite_setTexture(button->spritedef, button->texturedef, sfTrue);
    sfSprite_setTexture(button->spriteent, button->textureent, sfTrue);
    sfSprite_setPosition(button->spritedef, (sfVector2f){500, 450});
    sfSprite_setPosition(button->spriteent, (sfVector2f){490, 448});
    textureSize = sfTexture_getSize(button->texturedef);
    button->area = (sfIntRect){500, 450, textureSize.x, textureSize.y};
    button->etat = false;
    button->next = NULL;
    add_at_list(list_button, button);
}

void add_500(list_button_t **list_button)
{
    list_button_t *button = malloc(sizeof(list_button_t));
    sfVector2u textureSize;

    button->type = "def";
    button->name = my_strdup("500");
    button->texturedef = sfTexture_createFromFile
        ("assets/buttons/my_files/500.png", NULL);
    button->spritedef = sfSprite_create();
    button->textureent = sfTexture_createFromFile
        ("assets/buttons/my_files/500ent.png", NULL);
    button->spriteent = sfSprite_create();
    sfSprite_setTexture(button->spritedef, button->texturedef, sfTrue);
    sfSprite_setTexture(button->spriteent, button->textureent, sfTrue);
    sfSprite_setPosition(button->spritedef, (sfVector2f){1250, 450});
    sfSprite_setPosition(button->spriteent, (sfVector2f){1240, 448});
    textureSize = sfTexture_getSize(button->texturedef);
    button->area = (sfIntRect){1250, 450, textureSize.x, textureSize.y};
    button->etat = false;
    button->next = NULL;
    add_at_list(list_button, button);
}

void add_1000(list_button_t **list_button)
{
    list_button_t *button = malloc(sizeof(list_button_t));
    sfVector2u textureSize;

    button->type = "def";
    button->name = my_strdup("1000");
    button->texturedef = sfTexture_createFromFile
        ("assets/buttons/my_files/1000.png", NULL);
    button->spritedef = sfSprite_create();
    button->textureent = sfTexture_createFromFile
        ("assets/buttons/my_files/1000ent.png", NULL);
    button->spriteent = sfSprite_create();
    sfSprite_setTexture(button->spritedef, button->texturedef, sfTrue);
    sfSprite_setTexture(button->spriteent, button->textureent, sfTrue);
    sfSprite_setPosition(button->spritedef, (sfVector2f){470, 650});
    sfSprite_setPosition(button->spriteent, (sfVector2f){460, 648});
    textureSize = sfTexture_getSize(button->texturedef);
    button->area = (sfIntRect){470, 650, textureSize.x, textureSize.y};
    button->etat = false;
    button->next = NULL;
    add_at_list(list_button, button);
}

void add_3000(list_button_t **list_button)
{
    list_button_t *button = malloc(sizeof(list_button_t));
    sfVector2u textureSize;

    button->type = "def";
    button->name = my_strdup("3000");
    button->texturedef = sfTexture_createFromFile
        ("assets/buttons/my_files/3000.png", NULL);
    button->spritedef = sfSprite_create();
    button->textureent = sfTexture_createFromFile
        ("assets/buttons/my_files/3000ent.png", NULL);
    button->spriteent = sfSprite_create();
    sfSprite_setTexture(button->spritedef, button->texturedef, sfTrue);
    sfSprite_setTexture(button->spriteent, button->textureent, sfTrue);
    sfSprite_setPosition(button->spritedef, (sfVector2f){1210, 650});
    sfSprite_setPosition(button->spriteent, (sfVector2f){1200, 648});
    textureSize = sfTexture_getSize(button->texturedef);
    button->area = (sfIntRect){1210, 650, textureSize.x, textureSize.y};
    button->etat = false;
    button->next = NULL;
    add_at_list(list_button, button);
}

void add_10000(list_button_t **list_button)
{
    list_button_t *button = malloc(sizeof(list_button_t));
    sfVector2u textureSize;

    button->type = "def";
    button->name = my_strdup("10000");
    button->texturedef = sfTexture_createFromFile
        ("assets/buttons/my_files/10000.png", NULL);
    button->spritedef = sfSprite_create();
    button->textureent = sfTexture_createFromFile
        ("assets/buttons/my_files/10000ent.png", NULL);
    button->spriteent = sfSprite_create();
    sfSprite_setTexture(button->spritedef, button->texturedef, sfTrue);
    sfSprite_setTexture(button->spriteent, button->textureent, sfTrue);
    sfSprite_setPosition(button->spritedef, (sfVector2f){810, 850});
    sfSprite_setPosition(button->spriteent, (sfVector2f){800, 848});
    textureSize = sfTexture_getSize(button->texturedef);
    button->area = (sfIntRect){810, 850, textureSize.x, textureSize.y};
    button->etat = false;
    button->next = NULL;
    add_at_list(list_button, button);
}
