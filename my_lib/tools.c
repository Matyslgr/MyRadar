/*
** EPITECH PROJECT, 2023
** delivery
** File description:
** tools
*/

#include "my.h"

list_button_t *get_elem(list_button_t **list_button, char *name)
{
    list_button_t *tmp = *list_button;

    while (tmp != NULL) {
        if (!my_strcmp(tmp->name, name))
            return (tmp);
        tmp = tmp->next;
    }
    return (NULL);
}

void desactive_elem(list_button_t **list_button, char *name)
{
    list_button_t *tmp = *list_button;

    while (tmp != NULL) {
        if (!my_strcmp(tmp->name, name))
            tmp->etat = false;
        tmp = tmp->next;
    }
}

void active_elem(list_button_t **list_button, char *name)
{
    list_button_t *tmp = *list_button;

    while (tmp != NULL) {
        if (!my_strcmp(tmp->name, name))
            tmp->etat = true;
        tmp = tmp->next;
    }
}
