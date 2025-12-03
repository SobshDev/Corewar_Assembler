/*
** EPITECH PROJECT, 2025
** B-CPE-200-MPL-2-1-robotfactory-gabriel.brument
** File description:
** my_strncpy
*/

char *my_strncpy(char *dest, char *src, int n)
{
    int i = 0;

    while (src[i] && i < n) {
        dest[i] = src[i];
        i++;
    }
    while (i < n) {
        dest[i] = '\0';
        i++;
    }
    return (dest);
}
