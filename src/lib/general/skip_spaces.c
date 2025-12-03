/*
** EPITECH PROJECT, 2025
** RobotFactory
** File description:
** skip_spaces
*/

int skip_spaces(char *str, int i)
{
    while (str[i] == ' ' || str[i] == '\t')
        i++;
    return (i);
}
