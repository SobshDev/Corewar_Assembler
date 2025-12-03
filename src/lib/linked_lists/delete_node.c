/*
** EPITECH PROJECT, 2025
** Minishell
** File description:
** delete_node
*/

#include "linked_lists.h"
#include <stdlib.h>

static node_t *find_node_static(node_t *head, void *data,
    int (*cmp)(void *, void *), node_t **prev)
{
    *prev = NULL;
    while (head) {
        if (cmp(head->data, data) == 0)
            return head;
        *prev = head;
        head = head->next;
    }
    return NULL;
}

void delete_node(node_t **head, void *data,
    int (*cmp)(void *, void *), void (*free_func)(void *))
{
    node_t *prev = NULL;
    node_t *target = NULL;

    if (!head || !*head)
        return;
    target = find_node_static(*head, data, cmp, &prev);
    if (!target)
        return;
    if (prev)
        prev->next = target->next;
    else
        *head = target->next;
    free_func(target->data);
    free(target);
}
