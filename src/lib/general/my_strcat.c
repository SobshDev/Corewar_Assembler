/*
** EPITECH PROJECT, 2025
** Minishell
** File description:
** my_strcat
*/

char *my_strcat(char *dest, char *src)
{
    char *ptr = dest;

    while (*ptr != '\0')
        ptr++;
    while (*src != '\0') {
        *ptr = *src;
        ptr++;
        src++;
    }
    *ptr = '\0';
    return dest;
}
