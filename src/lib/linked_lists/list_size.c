/*
** EPITECH PROJECT, 2025
** Minishell
** File description:
** list_size
*/

#include "linked_lists.h"

int list_size(node_t *head)
{
    int count = 0;
    node_t *current = head;

    while (current) {
        count++;
        current = current->next;
    }
    return count;
}
