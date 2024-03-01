/*
** EPITECH PROJECT, 2023
** Day06
** File description:
** Task06
*/
#include <unistd.h>

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    write(1, str, i);
    return 0;
}

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0') {
        i++;
    }
    if (s1[i] == '\0' && s2[i] != '\0')
        return -s2[i];
    else
        return s1[i] - s2[i];
}
