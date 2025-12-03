/*
** EPITECH PROJECT, 2025
** Minishell
** File description:
** lib
*/

#ifndef LIB_H
    #define LIB_H
    #define GREEN "\001\033[32m\002"
    #define BLUE "\001\033[1;34m\002"
    #define RESET "\001\033[0m\002"

/*
* @brief Compares two strings lexicographically
*
* @param s1 First string to compare
* @param s2 Second string to compare
* @return int Returns 0 if strings are equal,
* negative if s1 < s2, positive if s1 > s2
*/
int my_strcmp(char *s1, char *s2);

/*
* @brief Compares n characters of two strings
*
* @param s1 First string to compare
* @param s2 Second string to compare
* @param n Number of characters to compare
* @return int Returns 0 if strings are equal up to n chars,
* negative if s1 < s2, positive if s1 > s2
*/
int my_strncmp(char *s1, char *s2, int n);

/*
* @brief Outputs a string to standard output
*
* @param str String to output
*/
void my_putstr(char *str);

/*
* @brief Converts a string to an integer
*
* @param str String to convert
* @return int The converted integer value
*/
int my_atoi(char *str);

/*
* @brief Reads a line from standard input
*
* @return char* Returns the read line or NULL if error/EOF
*/
char *my_getline(void);

/*
* @brief Creates a duplicate of a string
*
* @param str String to duplicate
* @return char* Returns the duplicated string or NULL if allocation fails
*/
char *my_strdup(char *str);

/*
* @brief Creates a duplicate of n characters from a string
*
* @param str String to duplicate
* @param n Number of characters to duplicate
* @return char* Returns the duplicated string or NULL if allocation fails
*/
char *my_strndup(char *str, int n);

/*
* @brief Concatenates two strings
*
* @param dest Destination string
* @param src Source string to append
* @return char* Returns pointer to the resulting string
*/
char *my_strcat(char *dest, char *src);

/*
* @brief Calculates the length of a string
*
* @param str String to measure
* @return int Length of the string
*/
int my_strlen(char *str);

/*
* @brief Outputs a string to standard error
*
* @param str String to output to stderr
*/
void my_putstr_err(char *str);

/*
* @brief Copies a string to another
*
* @param dest Destination string
* @param src Source string
* @return char* Returns pointer to destination string
*/
char *my_strcpy(char *dest, char *src);

/*
* @brief Copies n characters from a string to another
*
* @param dest Destination string
* @param src Source string
* @param n Number of characters to copy
* @return char* Returns pointer to destination string
*/
char *my_strncpy(char *dest, char *src, int n);

/*
* @brief Outputs a number to standard error
*
* @param n Number to output
*/
void my_putnbr_err(int n);

/*
* @brief Skips whitespace characters in a string starting from index i
*
* @param str String to process
* @param i Starting index
* @return int Index after skipping spaces
*/
int skip_spaces(char *str, int i);

#endif //LIB_H
