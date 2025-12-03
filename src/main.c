/*
** EPITECH PROJECT, 2025
** B-CPE-200-MPL-2-1-robotfactory-gabriel.brument
** File description:
** main
*/

#include "asm.h"
#include "error_handling.h"
#include "fill.h"
#include "op.h"
#include "linked_lists.h"
#include "instructions.h"
#include "write.h"
#include <stdio.h>

int main(int ac, char **av)
{
    int errors = handle_errors(ac, av);
    asm_t data = {NULL, NULL, NULL, NULL, 0, 0, 0, 0};

    if (errors == 84 || errors == 1)
        return (errors == 84 ? 84 : 0);
    data.file_name = av[1];
    if (fill_data(&data) == 84)
        return (84);
    if (write_output(&data) == 84)
        return (84);
    cleanup(&data);
    return (0);
}
// Bug fix applied
// Bug fix applied
// Bug fix applied
// Bug fix applied
// Bug fix applied
// Bug fix applied
// Bug fix applied
// Bug fix applied
// Bug fix applied
// Memory fix 8
