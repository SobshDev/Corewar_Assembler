/*
** EPITECH PROJECT, 2025
** B-CPE-200-MPL-2-1-robotfactory-gabriel.brument
** File description:
** asm
*/

#ifndef INCLUDED_ASM_H
    #define INCLUDED_ASM_H

typedef struct header_s header_t;
typedef struct node_s node_t;

/*
* Main assembly processor structure
* This structure holds all the necessary data for processing assembly files,
* including the file header, instructions, labels, current processing state.
* @param header Pointer to the file header information
* @param file_name Name of the assembly file being processed
* @param instructions Linked list of assembly instructions
* @param labels Linked list of labels in the assembly code
* @param current_address Current memory address during processing
* @param name_line Line number where the name directive is found
* @param comment_line Line number where the comment directive is found
* @param current_line Current line being processed
*/
typedef struct asm_s {
    header_t *header;
    char *file_name;
    node_t *instructions;
    node_t *labels;
    int current_address;
    int name_line;
    int comment_line;
    int current_line;
} asm_t;

/*
* @brief Cleans up and frees all allocated memory in the assembly structure
*
* @param data Pointer to the assembly structure to be cleaned up
*/
void cleanup(asm_t *data);

#endif
