/*
** EPITECH PROJECT, 2025
** Minishell
** File description:
** find_node
*/

#include "linked_lists.h"

node_t *find_node(node_t *head, int (*compare_func)(void *, void *, int),
    void *target, int n)
{
    node_t *current = head;

    while (current) {
        if (compare_func(current->data, target, n) == 0)
            return current;
        current = current->next;
    }
    return NULL;
}
// Optimized list operations
