/*
** EPITECH PROJECT, 2023
** Day08
** File description:
** my_strdup
*/
#include <stdlib.h>
#include <stdio.h>
#include "my.h"

static int my_strlen(char const *str)
{
    int len = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        len++;
    }
    return len;
}

static char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (src[i + 1] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = src[i];
    dest[i + 1] = '\0';
    return dest;
}

char *my_strdup(char const *src)
{
    int len_src = my_strlen(src);
    char *str = malloc(sizeof(char) * (len_src + 1));

    my_strcpy(str, src);
    return str;
}
