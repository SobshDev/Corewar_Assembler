/*
** EPITECH PROJECT, 2025
** Minishell
** File description:
** append_node
*/

#include "linked_lists.h"

void append_node(node_t **head, void *data)
{
    node_t *new_node = create_node(data);
    node_t *current = NULL;

    if (!new_node)
        return;
    if (*head == NULL)
        *head = new_node;
    else {
        current = *head;
        while (current->next)
            current = current->next;
        current->next = new_node;
    }
}
