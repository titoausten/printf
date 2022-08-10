#include "main.h"

unsigned int _memcpy(bufer_t *output, const char *src, unsigned int n);
void free_buffer(bufer_t *output);
bufer_t *init_buffer(void);
/**
 * _memcpy - Copies n bytes from memory area src to the buffer
 * contained in a bufer_t struct.
 * @output: A bufer_t struct.
 * @src: A pointer to the memory area to copy.
 * @n: The number of bytes to be copied.
 * Return: The number of bytes copied.
 */
unsigned int _memcpy(bufer_t *output, const char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		*(output->buffer) = *(src + i);
		(output->len)++;
		if (output->len == 1024)
		{
			write(1, output->start, output->len);
			output->buffer = output->start;
			output->len = 0;
		}
		else
			(output->buffer)++;
	}
	return (n);
}
/**
 * free_buffer - Frees a buffer_t struct.
 * @output: The bufer_t struct to be freed.
 */
void free_buffer(bufer_t *output)
{
	free(output->start);
	free(output);
}
/**
 * init_buffer - Initializes a variable of struct type bufer_t.
 * Return: A pointer to the initialized bufer_t.
 */
bufer_t *init_buffer(void)
{
	bufer_t *output;

	output = malloc(sizeof(bufer_t));
	if (output == NULL)
		return (NULL);
	output->buffer = malloc(sizeof(char) * 1024);
	if (output->buffer == NULL)
	{
		free(output);
		return (NULL);
	}
	output->start = output->buffer;
	output->len = 0;
	return (output);
}
