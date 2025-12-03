/*
** EPITECH PROJECT, 2025
** Minishell
** File description:
** iterate_list
*/

#include "linked_lists.h"

void iterate_list(node_t *head, void (*func)(void *))
{
    node_t *current = head;

    while (current) {
        func(current->data);
        current = current->next;
    }
}
// Enhancement 4
// Enhancement 9
