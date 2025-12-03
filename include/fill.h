/*
** EPITECH PROJECT, 2025
** B-CPE-200-MPL-2-1-robotfactory-gabriel.brument
** File description:
** fill
*/

#ifndef INCLUDED_FILL_H
    #define INCLUDED_FILL_H

typedef struct asm_s asm_t;

/*
* @brief Fills the complete assembly data structure with processed information
*
* @param data Pointer to the assembly structure to fill
* @return int Returns 0 on successful fill, 84 on error
*/
int fill_data(asm_t *data);

/*
* @brief Fills the program header with name, comment, and size information
*
* @param data Pointer to the assembly structure containing header data
* @return int Returns 0 on successful fill, 84 on error
*/
int fill_header(asm_t *data);

/*
* @brief Fills the instruction list with parsed assembly instructions
*
* @param data Pointer to the assembly structure containing instructions
* @return int Returns 0 on successful fill, 84 on error
*/
int fill_instructions(asm_t *data);

#endif
