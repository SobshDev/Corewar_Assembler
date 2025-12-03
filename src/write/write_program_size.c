/*
** EPITECH PROJECT, 2025
** B-CPE-200-MPL-2-1-robotfactory-gabriel.brument
** File description:
** write_program_size
*/

#include "asm.h"
#include "op.h"
#include "write.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

static int get_file_size(char *file_name)
{
    int size = 0;
    char buffer[4096];
    int bytes_read;
    int fd = open(file_name, O_RDONLY);
    long current_pos = lseek(fd, 0, SEEK_CUR);

    lseek(fd, 0, SEEK_SET);
    bytes_read = read(fd, buffer, sizeof(buffer));
    while (bytes_read > 0) {
        size += bytes_read;
        bytes_read = read(fd, buffer, sizeof(buffer));
    }
    lseek(fd, current_pos, SEEK_SET);
    return size;
}

static int get_program_size(char *file_name)
{
    int header_size = (4 + PROG_NAME_LENGTH + 4 + 4 + COMMENT_LENGTH + 4);
    int file_size = get_file_size(file_name);

    return file_size - header_size;
}

void write_program_size(char *file_name)
{
    FILE *file = fopen(file_name, "r+b");
    int program_size = get_program_size(file_name);
    int prog_size_pos = 4 + PROG_NAME_LENGTH + 4;
    unsigned char bytes[4];

    bytes[0] = (program_size >> 24) & 0xFF;
    bytes[1] = (program_size >> 16) & 0xFF;
    bytes[2] = (program_size >> 8) & 0xFF;
    bytes[3] = program_size & 0xFF;
    fseek(file, prog_size_pos, SEEK_SET);
    fwrite(bytes, 1, 4, file);
    fclose(file);
}
