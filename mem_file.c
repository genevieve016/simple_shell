#include "shell.h"

/**
 * _realloc - reallocate mem block
 * @ptr: pointer to previous memory
 * @old_size: old size
 * @new_size: new size
 *
 * Return: ptr if success, else NULL
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new_ptr;

	if (new_size == old_size)
		return (ptr);

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (ptr == NULL)
		return (malloc(new_size));

	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);

	if (old_size > new_size)
		copy_data(new_ptr, ptr, new_size);
	else
		copy_data(new_ptr, ptr, old_size);

	free(ptr);
	return (new_ptr);
}

/**
 * _realloc_dp - realocate mem block to douple pointer dp
 * @ptr: dp to previous memory
 * @old_size: old size
 * @new_size: new size
 *
 * Return: ptr if success, else NULL
 */
char **_realloc_dp(char **ptr, unsigned int old_size, unsigned int new_size)
{
	char **new_ptr;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
		return (malloc(sizeof(char *) * new_size));

	new_ptr = malloc(sizeof(char *) * new_size);
	if (new_ptr == NULL)
		return (NULL);

	for (i = 0; i < old_size; i++)
		new_ptr[i] = ptr[i];

	free(ptr);

	return (new_ptr);
}

/**
 * copy_data - cp information between pointers that are void
 * @new_ptr: destination of pointer
 * @ptr: origin of pointer
 * @size: new pointer size
 *
 * Return: void
 */
void copy_data(void *new_ptr, const void *ptr, unsigned int size)
{
	char *char_ptr = (char *)ptr;
	char *char_new_ptr = (char *)new_ptr;
	unsigned int i;

	for (i = 0; i < size; i++)
		char_new_ptr[i] = char_ptr[i];
}
