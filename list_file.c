#include "shell.h"

/**
 * add_separator_node - adds a separator node to the end of a separator list
 * @head: pointer to head of separator list
 * @separator: separator character to add to list
 * Return: pointer to head of separator list
 */
sep_list *add_separator_node(sep_list **head, char separator)
{
	sep_list *new_node = malloc(sizeof(sep_list));

	if (new_node == NULL)
	return (NULL);

	new_node->separator = separator;
	new_node->next = NULL;

	if (*head == NULL)
		*head = new_node;
	else
	{
		sep_list *current_node = *head;

		while (current_node->next != NULL)
		current_node = current_node->next;

		current_node->next = new_node;
	}
	return (*head);
}

/**
 * free_separator_list - function to free separator list
 * @head: pointer to head of separator list
 */
void free_separator_list(sep_list **head)
{
	if (head == NULL || *head == NULL)
	return;

	sep_list *current_node = *head;
	sep_list *next_node;

	while (current_node != NULL)
	{
		next_node = current_node->next;
		free(current_node);
		current_node = next_node;
	}

	*head = NULL;
}

/**
 * add_line_node - function to add command line to end of line list
 * @head: pointer to head of line list
 * @line: command line
 * Return: pointer to head of line list.
 */
line_list *add_line_node(line_list **head, char *line)
{
	line_list *new_node = malloc(sizeof(line_list));

	if (new_node == NULL)
	return (NULL);

	new_node->line = line;
	new_node->next = NULL;

	if (*head == NULL)
	*head = new_node;
	else
	{
		line_list *current_node = *head;

		while (current_node->next != NULL)
		current_node = current_node->next;

		current_node->next = new_node;
	}

	return (*head);
}

/**
 * free_line_list - function to free a line list
 * @head: pointer to head of line list
 */
void free_line_list(line_list **head)
{
	if (head == NULL || *head == NULL)
	return;

	line_list *current_node = *head;
	line_list *next_node;

	while (current_node != NULL)
	{
		next_node = current_node->next;
		free(current_node);
		current_node = next_node;
	}

	*head = NULL;
}
