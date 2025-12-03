/*
** EPITECH PROJECT, 2025
** B-CPE-200-MPL-2-1-robotfactory-gabriel.brument
** File description:
** instructions
*/

#ifndef INCLUDED_INSTRUCTIONS_H
    #define INCLUDED_INSTRUCTIONS_H

/*
* @brief Parameter structure for instruction arguments
*
* @param type Type of the parameter (register, direct, indirect)
* @param value Numeric value of the parameter
* @param label Label name if the parameter is a label reference
*/
typedef struct param_s {
    int type;
    int value;
    char *label;
} param_t;

/*
* @brief Instruction structure representing a single assembly instruction
*
* @param address Memory address where the instruction is located
* @param opcode Operation code of the instruction
* @param param_count Number of parameters for this instruction
* @param params Array of parameters for the instruction
*/
typedef struct instruction_s {
    int address;
    int opcode;
    int param_count;
    param_t params[3];
} instruction_t;

/*
* @brief Label structure for storing label definitions
*
* @param name Name of the label
* @param address Memory address where the label is defined
*/
typedef struct label_s {
    char *name;
    int address;
} label_t;

typedef struct asm_s asm_t;

/*
* @brief Parses a label from a line of assembly code
*
* @param data Pointer to the assembly structure
* @param line Line of code to parse
* @return char* Returns the parsed label name or NULL if no label found
*/
char *parse_label(asm_t *data, char *line);

/*
* @brief Parses all lines in the assembly file
*
* @param data Pointer to the assembly structure
* @return int Returns 0 on success, non-zero on failure
*/
int parse_lines(asm_t *data);

/*
* @brief Parses a single instruction from a line of assembly code
*
* @param data Pointer to the assembly structure
* @param line Line of code to parse
* @param line_number Current line number for error reporting
* @return int Returns 0 on success, non-zero on failure
*/
int parse_instruction(asm_t *data, char *line, int line_number);

/*
* @brief Handles parameter parsing for an instruction
*
* @param data Pointer to the assembly structure
* @param line Line containing the parameter
* @param i Current parameter index
* @param j Current position in the line
* @return int Returns 0 on success, non-zero on failure
*/
int handle_param(asm_t *data, char *line, int i, int j);

/*
* @brief Handles instruction parsing
*
* @param line Line containing the instruction
* @param i Pointer to current position in the line
* @return int Returns 0 on success, non-zero on failure
*/
int handle_instruction(char *line, int *i);

/*
* @brief Checks if a line contains a valid instruction
*
* @param line Line to check
* @return int Returns 1 if line contains instruction, 0 otherwise
*/
int is_instruction(char *line);

/*
* @brief Gets the opcode for an instruction
*
* @param line Line containing the instruction
* @return int Returns the opcode value or -1 if invalid
*/
int get_opcode(char *line);

/*
* @brief Gets the number of parameters for an instruction
*
* @param line Line containing the instruction
* @return int Returns the parameter count or -1 if invalid
*/
int get_param_count(char *line);

/*
* @brief Gets the type of a parameter
*
* @param line Line containing the parameter
* @param i Index of the parameter
* @return int Returns the parameter type or -1 if invalid
*/
int get_param_type(char *line, int i);

/*
* @brief Parses a single parameter
*
* @param line Line containing the parameter
* @param param Pointer to parameter structure to fill
* @return char* Returns pointer to next position in line after parameter
*/
char *parse_parameter(char *line, param_t *param);

/*
* @brief Gets the size in bytes of a parameter
*
* @param opcode Instruction opcode
* @param param_type Type of the parameter
* @return int Returns the size in bytes or -1 if invalid
*/
int get_param_size(int opcode, int param_type);

/*
* @brief Parses all parameters for an instruction
*
* @param line Line containing the parameters
* @param params Array of parameter structures to fill
* @param opcode Instruction opcode
* @return int Returns 0 on success, non-zero on failure
*/
int parse_all_parameters(char *line, param_t *params, int opcode);

/*
* @brief Counts the number of parameters in an instruction
*
* @param line Line containing the instruction
* @return int Returns the number of parameters or -1 if invalid
*/
int count_actual_parameters(char *line);

#endif
