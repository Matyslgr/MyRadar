/*
** EPITECH PROJECT, 2023
** Day07
** File description:
** Put_nbr
*/
#include <unistd.h>

static void my_putchar(char c)
{
    write(1, &c, 1);
}

static int rec_putnbr(long int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb < 10) {
        my_putchar(nb + 48);
    } else {
        rec_putnbr(nb / 10);
        rec_putnbr(nb % 10);
    }
    return 0;
}

int my_putnbr(int nb)
{
    return rec_putnbr(nb);
}
