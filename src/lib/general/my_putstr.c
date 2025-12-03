/*
** EPITECH PROJECT, 2025
** Minishell
** File description:
** my_putstr
*/

#include <unistd.h>

void my_putstr(char *str)
{
    int len = 0;

    while (str[len])
        len++;
    write(1, str, len);
}
