/*
** EPITECH PROJECT, 2025
** Minishell
** File description:
** my_strdup
*/

#include <stdlib.h>

char *my_strdup(char *str)
{
    char *newstr = 0;
    int length = 0;

    while (str[length])
        length++;
    newstr = malloc(sizeof(char) * (length + 1));
    length = 0;
    while (str[length]) {
        newstr[length] = str[length];
        length++;
    }
    newstr[length] = '\0';
    return (newstr);
}

char *my_strndup(char *str, int n)
{
    char *newstr = 0;
    int length = 0;

    while (str[length] && length < n)
        length++;
    newstr = malloc(sizeof(char) * (length + 1));
    length = 0;
    while (str[length] && length < n) {
        newstr[length] = str[length];
        length++;
    }
    return (newstr);
}
// Performance 2
