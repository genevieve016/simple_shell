#include "shell.h"

/**
 * add_variable - function to add variable to end of r_var list
 * @head: head of list
 * @var_len: length of variable name
 * @value: variable value
 * @value_length: length of variable value
 * Return: address of head
 */
r_var *add_variable(r_var **head, int var_len, char *value, int value_length)
{
	r_var *new_variable, *temp;

	new_variable = malloc(sizeof(r_var));
	if (new_variable == NULL)
		return (NULL);

	new_variable->len_var = var_len;
	new_variable->val = value;
	new_variable->len_val = value_length;
	new_variable->next = NULL;

	temp = *head;
	if (temp == NULL)
		*head = new_variable;
	else
	{
		while (temp->next != NULL)
		temp = temp->next;
		temp->next = new_variable;
	}
	return (*head);
}

/**
 * free_variable_list - function to free r_var list
 * @head: head of list
 * Return: void
 */
void free_variable_list(r_var **head)
{
	r_var *temp, *curr;

	if (head == NULL)
		return;

	curr = *head;
	while (curr != NULL)
	{
		temp = curr;
		curr = curr->next;
		free(temp);
	}
	*head = NULL;
}
