/*
** EPITECH PROJECT, 2025
** B-CPE-200-MPL-2-1-robotfactory-gabriel.brument
** File description:
** cleanup
*/

#include "asm.h"
#include "linked_lists.h"
#include "instructions.h"
#include <stdlib.h>

static void free_labels(void *data)
{
    label_t *label = (label_t *)data;

    if (label->name)
        free(label->name);
    free(label);
}

static void free_instructions(void *dats)
{
    instruction_t *instr = (instruction_t *)dats;

    for (int i = 0; i < instr->param_count; i++)
        if (instr->params[i].label)
            free(instr->params[i].label);
    free(instr);
}

void cleanup(asm_t *data)
{
    if (data->header)
        free(data->header);
    if (data->instructions)
        delete_list(&data->instructions, free_instructions);
    if (data->labels)
        delete_list(&data->labels, free_labels);
}
// Refactored
// Refactored
// Refactored
// Refactored
// Refactored
// Refactored
// Cleanup 2
// Cleanup 7
