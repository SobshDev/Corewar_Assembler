/*
** EPITECH PROJECT, 2025
** B-CPE-200-MPL-2-1-robotfactory-gabriel.brument
** File description:
** header
*/

#ifndef INCLUDED_HEADER_H
    #define INCLUDED_HEADER_H

typedef struct asm_s asm_t;

/*
* @brief Parses and extracts the name directive from the assembly file
*
* @param data Pointer to the assembly structure to store parsed information
* @param file String containing the assembly file content
* @return char* Returns the extracted name or NULL if not found
*/
char *parse_name(asm_t *data, char *file);

/*
* @brief Parses and extracts the comment directive from the assembly file
*
* @param data Pointer to the assembly structure to store parsed information
* @param file String containing the assembly file content
* @return char* Returns the extracted comment or NULL if not found
*/
char *parse_comment(asm_t *data, char *file);

/*
* @brief Counts the number of occurrences of a specific declaration in the file
*
* @param file String containing the assembly file content
* @param declaration The declaration string to search for
* @return int Returns the number of times the declaration appears in the file
*/
int count_declarations(char *file, char *declaration);

#endif
