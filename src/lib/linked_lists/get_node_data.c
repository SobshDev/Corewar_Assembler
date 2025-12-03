/*
** EPITECH PROJECT, 2025
** Minishell
** File description:
** get_node_data
*/

#include "linked_lists.h"

void *get_node_data(node_t *head, int index)
{
    int i = 0;
    node_t *current = head;

    while (current) {
        if (i == index)
            return current->data;
        current = current->next;
        i++;
    }
    return NULL;
}
