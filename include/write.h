/*
** EPITECH PROJECT, 2025
** B-CPE-200-MPL-2-1-robotfactory-gabriel.brument
** File description:
** write
*/

#ifndef INCLUDED_WRITE_H
    #define INCLUDED_WRITE_H
    #include <stdio.h>

typedef struct asm_s asm_t;
typedef struct header_s header_t;
typedef struct instruction_s instruction_t;

/*
* @brief Writes the complete assembled output to a file
*
* @param data Pointer to the assembly structure containing all data
* @return int Returns 0 on success, non-zero on failure
*/
int write_output(asm_t *data);

/*
* @brief Writes the header information to the output file
*
* @param header Pointer to the header structure
* @param file File pointer to write to
*/
void write_header(header_t *header, FILE *file);

/*
* @brief Writes the program data section to the output file
*
* @param data Pointer to the assembly structure
* @param file File pointer to write to
* @return int Returns 0 on success, non-zero on failure
*/
int write_data(asm_t *data, FILE *file);

/*
* @brief Updates the program size in the output file
*
* @param file_name Name of the output file to update
*/
void write_program_size(char *file_name);

/*
* @brief Writes a value in big-endian format to the file
*
* @param file File pointer to write to
* @param value Value to write
* @param size Number of bytes to write
*/
void write_big_endian(FILE *file, unsigned int value, int size);

/*
* @brief Gets the address associated with a label
*
* @param data Pointer to the assembly structure
* @param label Label name to look up
* @param address Current instruction address for relative addressing
* @return int Returns the label's address or -1 if not found
*/
int get_label_address(asm_t *data, char *label, int address);

#endif
