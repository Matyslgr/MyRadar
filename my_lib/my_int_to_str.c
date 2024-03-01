/*
** EPITECH PROJECT, 2023
** delivery
** File description:
** my_int_to_str
*/

#include "my.h"

static void reverse(char *str_nbr, int length, char *str)
{
    int start = 0;
    int end = length - 1;
    char temp;

    while (start < end) {
        temp = str_nbr[start];
        str_nbr[start] = str_nbr[end];
        str_nbr[end] = temp;
        start++;
        end--;
    }
    my_strcat(str, str_nbr);
}

static void int_in_string(int num, char *str_nbr, int *i, int isNegative)
{
    if (num == 0) {
        str_nbr[*i] = '0';
        *i = *i + 1;
    }
    while (num != 0) {
        str_nbr[*i] = num % 10 + '0';
        *i = *i + 1;
        num = num / 10;
    }
    if (isNegative) {
        str_nbr[*i] = '-';
        *i = *i + 1;
    }
}

void int_to_string(int num, char *str)
{
    int i = 0;
    int isNegative = 0;
    char *str_nbr;
    int temp;
    int cpt = 0;

    if (num < 0) {
        isNegative = 1;
        num = -num;
    }
    temp = num;
    while (temp != 0) {
        temp /= 10;
        cpt++;
    }
    str_nbr = malloc((cpt + isNegative + 1) * sizeof(char));
    int_in_string(num, str_nbr, &i, isNegative);
    str_nbr[i] = '\0';
    reverse(str_nbr, i, str);
    free(str_nbr);
}
