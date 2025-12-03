/*
** EPITECH PROJECT, 2025
** Minishell
** File description:
** delete_node_at
*/

#include <stdlib.h>
#include "linked_lists.h"

static node_t *find_node_at(node_t *head, int index, node_t **prev)
{
    int i = 0;

    *prev = NULL;
    while (head) {
        if (i == index)
            return head;
        *prev = head;
        head = head->next;
        i++;
    }
    return NULL;
}

void delete_node_at(node_t **head, int index, void (*free_func)(void *))
{
    node_t *prev = NULL;
    node_t *target = NULL;

    if (!head || !*head || index < 0)
        return;
    target = find_node_at(*head, index, &prev);
    if (!target)
        return;
    if (prev)
        prev->next = target->next;
    else
        *head = target->next;
    free_func(target->data);
    free(target);
}
