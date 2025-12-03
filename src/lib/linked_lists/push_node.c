/*
** EPITECH PROJECT, 2025
** Minishell
** File description:
** push_node
*/

#include "linked_lists.h"

void push_node(node_t **head, void *data)
{
    node_t *new_node = create_node(data);

    if (new_node) {
        new_node->next = *head;
        *head = new_node;
    }
}
