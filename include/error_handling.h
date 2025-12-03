/*
** EPITECH PROJECT, 2025
** B-CPE-200-MPL-2-1-robotfactory-gabriel.brument
** File description:
** error_handling
*/

#ifndef INCLUDED_ERROR_HANDLING_H
    #define INCLUDED_ERROR_HANDLING_H

/*
* @brief Enumeration of all possible error codes in the assembler
*
* @param ERR_NO_NAME_SPECIFIED No program name specified
* @param ERR_NO_COMMENT_SPECIFIED No program comment specified
* @param ERR_COMMENT_AFTER_NAME Comment directive after name directive
* @param ERR_NO_FILE_SPECIFIED No input file specified
* @param ERR_INVALID_FILE_EXTENSION Invalid file extension
* @param ERR_FILE_DOESNT_EXIST File does not exist
* @param ERR_FILE_OVERWRITE File overwrite error
* @param ERR_LABEL_NOT_FOUND Referenced label not found
* @param ERR_INVALID_INSTRUCTION Invalid instruction syntax
* @param ERR_NAME_NOT_ENDED Name string not properly terminated
* @param ERR_COMMENT_NOT_ENDED Comment string not properly terminated
* @param ERR_COMMENT_TOO_LONG Comment exceeds maximum length
* @param ERR_DOUBLE_LABEL_DEFINITION Label defined multiple times
* @param ERR_DOUBLE_NAME_DECLARATION Multiple name declarations
* @param ERR_DOUBLE_COMMENT_DECLARATION Multiple comment declarations
* @param ERR_INVALID_PARAMETER_TYPE Invalid parameter type for instruction
* @param ERR_NAME_TOO_LONG Name exceeds maximum length
* @param ERR_INVALID_PARAMETER_COUNT Wrong number of parameters
* @param ERR_INVALID_REGISTER_NUMBER Invalid register number
*/
enum errors {
    ERR_NO_NAME_SPECIFIED,
    ERR_NO_COMMENT_SPECIFIED,
    ERR_COMMENT_AFTER_NAME,
    ERR_NO_FILE_SPECIFIED,
    ERR_INVALID_FILE_EXTENSION,
    ERR_FILE_DOESNT_EXIST,
    ERR_FILE_OVERWRITE,
    ERR_LABEL_NOT_FOUND,
    ERR_INVALID_INSTRUCTION,
    ERR_NAME_NOT_ENDED,
    ERR_COMMENT_NOT_ENDED,
    ERR_COMMENT_TOO_LONG,
    ERR_DOUBLE_LABEL_DEFINITION,
    ERR_DOUBLE_NAME_DECLARATION,
    ERR_DOUBLE_COMMENT_DECLARATION,
    ERR_INVALID_PARAMETER_TYPE,
    ERR_NAME_TOO_LONG,
    ERR_INVALID_PARAMETER_COUNT,
    ERR_INVALID_REGISTER_NUMBER,
};

/*
* @brief Enumeration of message types for error reporting
*
* @param WARNING_TYPE Warning message (non-fatal)
* @param ERROR_TYPE Error message (fatal)
* @param INFO_TYPE Informational message
*/
enum warning_type {
    WARNING_TYPE = 0,
    ERROR_TYPE = 1,
    INFO_TYPE = 2
};

    #define YELLOW_BOLD "\033[1;33m"
    #define RED_BOLD "\033[1;31m"
    #define BLUE_BOLD "\033[1;34m"
    #define WHITE_BOLD "\033[1;37m"

/*
* @brief Displays program usage information and help
*/
void print_help(void);

/*
* @brief Validates command line arguments and checks for basic errors
*
* @param ac Number of command line arguments
* @param av Array of command line argument strings
* @return int Returns 0 if no errors, 84 if errors found
*/
int handle_errors(int ac, char **av);

/*
* @brief Prints an error message with context information
*
* @param code Error code from the errors enum
* @param line Line number where the error occurred
* @param file Name of the file where the error occurred
*/
void print_error(int code, int line, char *file);

/*
* @brief Structure for storing error message information
*
* @param message Error message text
* @param code Error code from the errors enum
* @param type Message type from warning_type enum
*/
typedef struct error_s {
    char *message;
    int code;
    int type;
} error_t;

/*
* @brief Checks for errors in directive declarations
*
* @param line Current line being processed
* @param name Name of the directive being checked
* @param file Name of the file being processed
* @param i Current line number
*/
void check_for_declaration_errors(char *line, char *name, char *file, int i);

#endif // INCLUDED_ERROR_HANDLING_H
