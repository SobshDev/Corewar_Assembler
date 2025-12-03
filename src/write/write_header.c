/*
** EPITECH PROJECT, 2025
** B-CPE-200-MPL-2-1-robotfactory-gabriel.brument
** File description:
** write_header
*/

#include "asm.h"
#include "op.h"
#include "lib.h"
#include <stdlib.h>
#include <stdio.h>

static void write_whitespace(FILE *file, int count)
{
    for (int i = 0; i < count; i++)
        fwrite("\0", 1, 1, file);
}

static void write_int_big_endian(FILE *file, unsigned int value, int size)
{
    unsigned char bytes[4];

    bytes[0] = (value >> 24) & 0xFF;
    bytes[1] = (value >> 16) & 0xFF;
    bytes[2] = (value >> 8) & 0xFF;
    bytes[3] = value & 0xFF;
    fwrite(bytes, sizeof(unsigned char), size, file);
}

void write_header(header_t *header, FILE *file)
{
    char prog_name_buf[PROG_NAME_LENGTH] = {0};
    char comment_buf[COMMENT_LENGTH] = {0};

    write_int_big_endian(file, header->magic, 4);
    my_strncpy(prog_name_buf, header->prog_name, PROG_NAME_LENGTH);
    fwrite(prog_name_buf, sizeof(prog_name_buf), 1, file);
    write_whitespace(file, 4);
    write_int_big_endian(file, 0, 4);
    my_strncpy(comment_buf, header->comment, COMMENT_LENGTH);
    fwrite(comment_buf, sizeof(comment_buf), 1, file);
    write_whitespace(file, 4);
}
// Bounds check 4
