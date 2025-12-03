/*
** EPITECH PROJECT, 2025
** Minishell
** File description:
** my_putstr
*/

#include <unistd.h>

void my_putstr_err(char *str)
{
    int len = 0;

    while (str[len])
        len++;
    write(2, str, len);
}
