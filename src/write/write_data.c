/*
** EPITECH PROJECT, 2025
** B-CPE-200-MPL-2-1-robotfactory-gabriel.brument
** File description:
** write_data
*/

#include "asm.h"
#include "instructions.h"
#include "linked_lists.h"
#include "lib.h"
#include "op.h"
#include "write.h"
#include "error_handling.h"
#include <stdlib.h>
#include <stdio.h>

void write_big_endian(FILE *file, unsigned int value, int size)
{
    unsigned char byte = 0;

    for (int i = size - 1; i >= 0; i--) {
        byte = (value >> (i * 8)) & 0xFF;
        fwrite(&byte, 1, 1, file);
    }
}

static void write_coding_byte(instruction_t *instruction, FILE *file)
{
    unsigned char coding_byte = 0;
    int code = 0;

    if (instruction->param_count <= 1 && instruction->opcode != 0x10)
        return;
    for (int i = 0; i < instruction->param_count; i++) {
        if (instruction->params[i].type == T_REG)
            code = 0x01;
        if (instruction->params[i].type == T_DIR)
            code = 0x02;
        if (instruction->params[i].type == T_IND)
            code = 0x03;
        if (instruction->params[i].type != T_REG &&
            instruction->params[i].type != T_DIR &&
            instruction->params[i].type != T_IND)
            code = 0x00;
        coding_byte |= (code << (6 - (i * 2)));
    }
    fwrite(&coding_byte, sizeof(unsigned char), 1, file);
}

int get_label_address(asm_t *data, char *label, int adress)
{
    node_t *current = data->labels;
    label_t *current_label = NULL;

    while (current) {
        current_label = current->data;
        if (my_strcmp(current_label->name, label) == 0)
            return current_label->address - adress;
        current = current->next;
    }
    return (-1);
}

static int handle_labl(asm_t *data, instruction_t *instruction,
    int i, FILE *file)
{
    int adress = 0;

    if (instruction->params[i].label) {
        adress = get_label_address(data, instruction->params[i].label,
        instruction->address);
        if (adress == -1) {
            print_error(ERR_LABEL_NOT_FOUND, -1, data->file_name);
            return (84);
        }
        write_big_endian(file, adress, get_param_size(instruction->opcode,
        instruction->params[i].type));
    } else {
        write_big_endian(file, instruction->params[i].value,
        get_param_size(instruction->opcode, instruction->params[i].type));
    }
    return (0);
}

static int handle_params(asm_t *data, instruction_t *instruction,
    int i, FILE *file)
{
    switch (instruction->params[i].type) {
        case T_REG:
            write_big_endian(file, instruction->params[i].value, 1);
            break;
        case T_DIR:
            if (handle_labl(data, instruction, i, file) == 84)
                return (84);
            break;
        case T_IND:
            if (handle_labl(data, instruction, i, file) == 84)
                return (84);
            break;
    }
    return (0);
}

static int write_instruction(instruction_t *instruction,
    FILE *file, asm_t *data)
{
    write_big_endian(file, instruction->opcode, 1);
    write_coding_byte(instruction, file);
    for (int i = 0; i < instruction->param_count; i++) {
        if (handle_params(data, instruction, i, file) == 84)
            return (84);
    }
    return (0);
}

int write_data(asm_t *data, FILE *file)
{
    node_t *current = data->instructions;

    while (current) {
        if (write_instruction(current->data, file, data) == 84)
            return (84);
        current = current->next;
    }
    return (0);
}
// Optimized
// Optimized
// Optimized
// Optimization 5
// Optimization 10
