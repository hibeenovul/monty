#include "monty.h"
/**
 * _calloc - function to concatenate two strings specially
 * @nmemb: number of elements
 * @size: type of elements
 * Return: nothing
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *p = NULL;
	unsigned int j;

	if (nmemb == 0 || size == 0)
	{
		return (NULL);
	}
	p = malloc(nmemb * size);
	if (p == NULL)
	{
		return (NULL);
	}
	for (j = 0; j < (nmemb * size); j++)
	{
		*((char *)(p) + j) = 0;
	}
	return (p);
}
/**
 * _realloc - To change the size and copy the content
 * @ptr: malloc pointer to reallocate
 * @old_size: old number of bytes
 * @new_size: new number of Bytes
 * Return: nothing
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p = NULL;
	unsigned int j;

	if (new_size == old_size)
		return (ptr);
	if (ptr == NULL)
	{
		p = malloc(new_size);
		if (!p)
			return (NULL);
		return (p);
	}
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size > old_size)
	{
		p = malloc(new_size);
		if (!p)
			return (NULL);
		for (j = 0; j < old_size; j++)
			p[j] = *((char *)ptr + j);
		free(ptr);
	}
	else
	{
		p = malloc(new_size);
		if (!p)
			return (NULL);
		for (j = 0; j < new_size; j++)
			p[j] = *((char *)ptr + j);
		free(ptr);
	}
	return (p);
}
