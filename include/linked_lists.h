/*
** EPITECH PROJECT, 2025
** Minishell
** File description:
** linked_lists
*/

#ifndef LINKED_LISTS_H
    #define LINKED_LISTS_H
    #define NULL ((void *)0)

/*
* @brief Generic linked list node structure
*
* @param data Pointer to the data stored in the node
* @param next Pointer to the next node in the list
*/
typedef struct node_s {
    void *data;
    struct node_s *next;
} node_t;

/*
* @brief Creates a new node with the given data
*
* @param data Pointer to the data to store in the node
* @return node_t* Returns pointer to the new node or NULL if allocation fails
*/
node_t *create_node(void *data);

/*
* @brief Adds a new node at the beginning of the list
*
* @param head Pointer to the head pointer of the list
* @param data Pointer to the data to store in the new node
*/
void push_node(node_t **head, void *data);

/*
* @brief Adds a new node at the end of the list
*
* @param head Pointer to the head pointer of the list
* @param data Pointer to the data to store in the new node
*/
void append_node(node_t **head, void *data);

/*
* @brief Deletes a node containing specific data from the list
*
* @param head Pointer to the head pointer of the list
* @param data Pointer to the data to match for deletion
* @param cmp Function pointer to compare data elements
* @param free_func Function pointer to free data elements
*/
void delete_node(node_t **head, void *data, int (*cmp)(void *, void *),
    void (*free_func)(void *));

/*
* @brief Deletes a node at a specific index from the list
*
* @param head Pointer to the head pointer of the list
* @param index Index of the node to delete
* @param free_func Function pointer to free data elements
*/
void delete_node_at(node_t **head, int index, void (*free_func)(void *));

/*
* @brief Deletes the entire list and frees all memory
*
* @param head Pointer to the head pointer of the list
* @param free_func Function pointer to free data elements
*/
void delete_list(node_t **head, void (*free_func)(void *));

/*
* @brief Gets the data from a node at a specific index
*
* @param head Pointer to the head of the list
* @param index Index of the node to get data from
* @return void* Returns pointer to the data or NULL if index is invalid
*/
void *get_node_data(node_t *head, int index);

/*
* @brief Gets the number of nodes in the list
*
* @param head Pointer to the head of the list
* @return int Returns the number of nodes in the list
*/
int list_size(node_t *head);

/*
* @brief Applies a function to each node's data in the list
*
* @param head Pointer to the head of the list
* @param func Function pointer to apply to each node's data
*/
void iterate_list(node_t *head, void (*func)(void *));

/*
* @brief Finds a node in the list based on a comparison function
*
* @param head Pointer to the head of the list
* @param compare_func Function pointer to compare node data with target
* @param target Target data to search for
* @param n Additional parameter for comparison function
* @return node_t* Returns pointer to found node or NULL if not found
*/
node_t *find_node(node_t *head, int (*compare_func)(void *, void *, int),
    void *target, int n);

/*
* @brief Finds the i#ndex of a node in the list based on a comparison function
*
* @param head Pointer to the head of the list
* @param compare_func Function pointer to compare node data with target
* @param target Target data to search for
* @param n Additional parameter for comparison function
* @return int Returns index of found node or -1 if not found
*/
int find_node_index(node_t *head, int (*compare_func)(void *, void *, int),
    void *target, int n);

/*
* @brief Converts a linked list to an array of strings
*
* @param node Pointer to the head of the list
* @return char** Returns array of strings or NULL if conversion fails
*/
char **lltoa(node_t *node);

#endif //LINKED_LISTS_H
