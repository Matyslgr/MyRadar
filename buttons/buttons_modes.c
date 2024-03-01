/*
** EPITECH PROJECT, 2023
** delivery
** File description:
** buttons_modes
*/

#include "my.h"

static void button_storm2(list_button_t *storm)
{
    sfVector2u textureSize;

    sfSprite_setTexture(storm->spriteent, storm->textureent, sfTrue);
    sfSprite_setTexture(storm->spritedef, storm->texturedef, sfTrue);
    sfSprite_setTexture(storm->spriteclick, storm->textureclick, sfTrue);
    sfSprite_setTexture(storm->spriteclickent, storm->textureclickent, sfTrue);
    textureSize = sfTexture_getSize(storm->texturedef);
    storm->area = (sfIntRect){300, 400, textureSize.x, textureSize.y};
    storm->etat = false;
    storm->next = NULL;
    sfSprite_setPosition(storm->spritedef, (sfVector2f){300, 400});
    sfSprite_setPosition(storm->spriteent, (sfVector2f){290, 398});
    sfSprite_setPosition(storm->spriteclick, (sfVector2f){295, 398});
    sfSprite_setPosition(storm->spriteclickent, (sfVector2f){295, 398});
}

void add_button_storm(list_button_t **list_button)
{
    list_button_t *storm = malloc(sizeof(list_button_t));

    storm->type = "def";
    storm->texturedef = sfTexture_createFromFile
        ("assets/buttons/modes/Cyclonedef.png", NULL);
    storm->name = my_strdup("storm");
    storm->textureent = sfTexture_createFromFile
        ("assets/buttons/modes/Cycloneent.png", NULL);
    storm->textureclick = sfTexture_createFromFile
        ("assets/buttons/modes/Cycloneclic.png", NULL);
    storm->textureclickent = sfTexture_createFromFile
        ("assets/buttons/modes/Cycloneclicent.png", NULL);
    storm->spritedef = sfSprite_create();
    storm->spriteent = sfSprite_create();
    storm->spriteclick = sfSprite_create();
    storm->spriteclickent = sfSprite_create();
    button_storm2(storm);
    add_at_list(list_button, storm);
}

static void add_button_realist2(list_button_t *realist)
{
    sfVector2u textureSize;

    sfSprite_setTexture(realist->spriteent, realist->textureent, sfTrue);
    sfSprite_setTexture(realist->spritedef, realist->texturedef, sfTrue);
    sfSprite_setTexture(realist->spriteclick, realist->textureclick, sfTrue);
    sfSprite_setTexture(realist->spriteclickent, realist->textureclickent,
        sfTrue);
    sfSprite_setPosition(realist->spritedef, (sfVector2f){1050, 400});
    sfSprite_setPosition(realist->spriteent, (sfVector2f){1100, 430});
    sfSprite_setPosition(realist->spriteclick, (sfVector2f){1035, 400});
    sfSprite_setPosition(realist->spriteclickent, (sfVector2f){1035, 400});
    textureSize = sfTexture_getSize(realist->texturedef);
    realist->area = (sfIntRect){1050, 400, textureSize.x, textureSize.y};
    realist->etat = false;
    realist->next = NULL;
}

void add_button_realist(list_button_t **list_button)
{
    list_button_t *realist = malloc(sizeof(list_button_t));

    realist->type = "def";
    realist->name = my_strdup("realist");
    realist->texturedef = sfTexture_createFromFile
        ("assets/buttons/modes/Realistdef.png", NULL);
    realist->name = my_strdup("realist");
    realist->textureent = sfTexture_createFromFile
        ("assets/buttons/modes/Realistent.png", NULL);
    realist->textureclick = sfTexture_createFromFile
        ("assets/buttons/modes/Realistclic.png", NULL);
    realist->textureclickent = sfTexture_createFromFile
        ("assets/buttons/modes/Realistclicent.png", NULL);
    realist->spritedef = sfSprite_create();
    realist->spriteent = sfSprite_create();
    realist->spriteclick = sfSprite_create();
    realist->spriteclickent = sfSprite_create();
    add_button_realist2(realist);
    add_at_list(list_button, realist);
}

void add_rect2(list_button_t **list_button)
{
    list_button_t *rect = malloc(sizeof(list_button_t));

    rect->type = "def";
    rect->name = my_strdup("rect2");
    rect->texturedef = sfTexture_createFromFile
        ("assets/buttons/modes/Rectangle 2.png", NULL);
    rect->spritedef = sfSprite_create();
    sfSprite_setTexture(rect->spritedef, rect->texturedef, sfTrue);
    sfSprite_setPosition(rect->spritedef, (sfVector2f){140, 350});
    rect->etat = false;
    rect->next = NULL;
    add_at_list(list_button, rect);
}

static void add_rand2(list_button_t *rand)
{
    sfVector2u textureSize;

    sfSprite_setTexture(rand->spriteent, rand->textureent, sfTrue);
    sfSprite_setTexture(rand->spritedef, rand->texturedef, sfTrue);
    sfSprite_setTexture(rand->spriteclick, rand->textureclick, sfTrue);
    sfSprite_setTexture(rand->spriteclickent, rand->textureclickent, sfTrue);
    sfSprite_setPosition(rand->spritedef, (sfVector2f){550, 620});
    sfSprite_setPosition(rand->spriteent, (sfVector2f){520, 620});
    sfSprite_setPosition(rand->spriteclick, (sfVector2f){540, 620});
    sfSprite_setPosition(rand->spriteclickent, (sfVector2f){495, 620});
    textureSize = sfTexture_getSize(rand->texturedef);
    rand->area = (sfIntRect){550, 620, textureSize.x, textureSize.y};
    rand->etat = false;
    rand->next = NULL;
}

void add_rand(list_button_t **list_button)
{
    list_button_t *rand = malloc(sizeof(list_button_t));

    rand->type = "def";
    rand->name = my_strdup("rand");
    rand->texturedef = sfTexture_createFromFile
        ("assets/buttons/modes/Randdef.png", NULL);
    rand->textureent = sfTexture_createFromFile
        ("assets/buttons/modes/Randent.png", NULL);
    rand->textureclick = sfTexture_createFromFile
        ("assets/buttons/modes/Randclic.png", NULL);
    rand->textureclickent = sfTexture_createFromFile
        ("assets/buttons/modes/Randclicent.png", NULL);
    rand->spritedef = sfSprite_create();
    rand->spriteent = sfSprite_create();
    rand->spriteclick = sfSprite_create();
    rand->spriteclickent = sfSprite_create();
    add_rand2(rand);
    add_at_list(list_button, rand);
}

void add_mode(list_button_t **list_button)
{
    list_button_t *mode = malloc(sizeof(list_button_t));

    mode->type = "def";
    mode->texturedef = sfTexture_createFromFile
        ("assets/buttons/modes/Modedef.png", NULL);
    mode->spritedef = sfSprite_create();
    sfSprite_setTexture(mode->spritedef, mode->texturedef, sfTrue);
    sfSprite_setPosition(mode->spritedef, (sfVector2f){750, 100});
    mode->name = my_strdup("mode");
    mode->etat = false;
    mode->next = NULL;
    add_at_list(list_button, mode);
}
