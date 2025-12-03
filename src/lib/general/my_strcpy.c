/*
** EPITECH PROJECT, 2025
** B-CPE-200-MPL-2-1-robotfactory-gabriel.brument
** File description:
** my_strcpy
*/

#include <stddef.h>

char *my_strcpy(char *dest, char *src)
{
    char *start = dest;

    if (dest == NULL || src == NULL)
        return NULL;
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return start;
}
