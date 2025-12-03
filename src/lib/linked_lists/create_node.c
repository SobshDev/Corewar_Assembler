/*
** EPITECH PROJECT, 2025
** Minishell
** File description:
** create_node
*/

#include <stdlib.h>
#include "linked_lists.h"

node_t *create_node(void *data)
{
    node_t *node = malloc(sizeof(node_t));

    if (node) {
        node->data = data;
        node->next = NULL;
    }
    return node;
}
