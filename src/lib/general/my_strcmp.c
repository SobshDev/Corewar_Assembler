/*
** EPITECH PROJECT, 2025
** Minishell
** File description:
** my_strcmp
*/

int my_strlen(char *str)
{
    int i = 0;

    while (str[i])
        i++;
    return (i);
}

int my_strcmp(char *s1, char *s2)
{
    int i = 0;

    while (s1[i] && s2[i] && (s1[i] == s2[i]))
        i++;
    return (s1[i] - s2[i]);
}

int my_strncmp(char *s1, char *s2, int n)
{
    int i = 0;

    while (i < n && s1[i] && s2[i] && s1[i] == s2[i])
        i++;
    if (i == n)
        return (0);
    return (s1[i] - s2[i]);
}
