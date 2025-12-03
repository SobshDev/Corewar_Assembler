/*
** EPITECH PROJECT, 2025
** Minishell
** File description:
** delete_list
*/

#include "linked_lists.h"
#include <stdlib.h>

void delete_list(node_t **head, void (*free_func)(void *))
{
    node_t *current = *head;
    node_t *next = NULL;

    while (current) {
        next = current->next;
        if (current->data) {
            free_func(current->data);
            current->data = NULL;
        }
        free(current);
        current = next;
    }
    *head = NULL;
}
// Null check 5
