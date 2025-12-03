/*
** EPITECH PROJECT, 2025
** Minishell
** File description:
** lltoa
*/

#include "linked_lists.h"
#include <stdlib.h>

char **lltoa(node_t *node)
{
    int size = list_size(node);
    char **array = malloc(sizeof(char *) * (size + 1));
    int i = 0;

    for (node_t *tmp = node; tmp; tmp = tmp->next) {
        array[i] = tmp->data;
        i++;
    }
    array[i] = NULL;
    return array;
}
