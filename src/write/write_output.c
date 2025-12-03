/*
** EPITECH PROJECT, 2025
** B-CPE-200-MPL-2-1-robotfactory-gabriel.brument
** File description:
** write_output
*/
#include "asm.h"
#include "instructions.h"
#include "lib.h"
#include "op.h"
#include "linked_lists.h"
#include "error_handling.h"
#include "write.h"
#include "instructions.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>

static char *get_basename(char *file_name)
{
    char *base = file_name;

    for (int i = 0; file_name[i] != '\0'; i++) {
        if (file_name[i] == '/')
            base = file_name + i + 1;
    }
    return base;
}

static char *build_formatted_filename(char *base)
{
    int base_len = my_strlen(base);
    int final_size = 2 + base_len + 1;
    char *new_name = NULL;
    int len = 0;

    if (base_len >= 2 && base[base_len - 2] == '.' &&
        base[base_len - 1] == 's')
        final_size = 2 + (base_len - 1) + 3 + 1;
    new_name = malloc(sizeof(char) * final_size);
    my_strcpy(new_name, "./");
    my_strcat(new_name, base);
    len = my_strlen(new_name);
    if (len >= 2 && new_name[len - 2] == '.' &&
        new_name[len - 1] == 's') {
        new_name[len - 1] = '\0';
        my_strcat(new_name, "cor");
    }
    return new_name;
}

int check_overwrite(char *filename)
{
    struct stat st;

    if (stat(filename, &st) == 0)
        print_error(ERR_FILE_OVERWRITE, 0, filename);
    return (0);
}

static int check_single_label(asm_t *data, instruction_t *instruction,
    param_t *param)
{
    if (!param->label)
        return 0;
    if (get_label_address(data, param->label, instruction->address) == -1) {
        print_error(ERR_LABEL_NOT_FOUND, -1, data->file_name);
        return 84;
    }
    return 0;
}

static int check_instruction_labels(asm_t *data, instruction_t *instruction)
{
    for (int i = 0; i < instruction->param_count; i++) {
        if (check_single_label(data, instruction,
            &instruction->params[i]) == 84)
            return 84;
    }
    return 0;
}

static int check_for_errors(asm_t *data)
{
    node_t *current = data->instructions;
    instruction_t *instruction = NULL;

    while (current) {
        instruction = current->data;
        if (check_instruction_labels(data, instruction) == 84)
            return 84;
        current = current->next;
    }
    return 0;
}

int write_output(asm_t *data)
{
    char *base = get_basename(data->file_name);
    char *file_name = build_formatted_filename(base);
    int overwrite = check_overwrite(file_name);
    FILE *file = NULL;

    if (check_for_errors(data) == 84) {
        free(file_name);
        return 84;
    }
    file = fopen(file_name, "w");
    write_header(data->header, file);
    if (write_data(data, file) == 84) {
        fclose(file);
        free(file_name);
        return 84;
    }
    fclose(file);
    write_program_size(file_name);
    free(file_name);
    return overwrite;
}
