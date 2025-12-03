/*
** EPITECH PROJECT, 2025
** Minishell
** File description:
** find_node_index
*/

#include "linked_lists.h"

int find_node_index(node_t *head, int (*compare_func)(void *, void *, int),
    void *target, int n)
{
    node_t *current = head;
    int i = 0;

    while (current) {
        if (compare_func(current->data, target, n) == 0)
            return i;
        current = current->next;
        i++;
    }
    return -1;
}
