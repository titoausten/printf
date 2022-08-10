#include "main.h"
unsigned int printwidth(bufer_t *output, unsigned int printed,
		unsigned char flags, int width);
unsigned int printstring_width(bufer_t *output, unsigned char flags,
		int width, int precision, int size);
unsigned int printneg_width(bufer_t *output, unsigned int printed,
		unsigned char flags, int width);
/**
 * printwidth - Stores leading spaces to a buffer for a width modifier.
 * @output: A bufer_t struct containing a character array.
 * @printed: The current number of characters already printed to output
 *           for a given number specifier.
 * @flags: Flag modifiers.
 * @width: A width modifier.
 * Return: The number of bytes stored to the buffer.
 */
unsigned int printwidth(bufer_t *output, unsigned int printed,
		unsigned char flags, int width)
{
	unsigned int ret = 0;
	char widthc = ' ';

	if (NEG_FLAG == 0)
	{
		for (width -= printed; width > 0)
			ret += _memcpy(output, &widthc, 1);
	}
	return (ret);
}
/**
 * printstring_width - Stores leading spaces to a buffer for a width modifier.
 * @output: A buffer_t struct containing a character array.
 * @flags: Flag modifiers.
 * @width: A width modifier.
 * @precision: A precision modifier.
 * @size: The size of the string.
 * Return: The number of bytes stored to the buffer.
 */
unsigned int printstring_width(bufer_t *output, unsigned char
		flags, int width, int precision, int size)
{
	unsigned int ret = 0;
	char widthc = ' ';

	if (NEG_FLAG == 0)
	{
		width -= (precision == -1) ? size : precision;
		for (; width > 0; width--)
			ret += _memcpy(output, &widthc, 1);
	}
	return (ret);
}
/**
 * printneg_width - Stores trailing spaces to a buffer for a '-' flag.
 * @output: A buffer_t struct containing a character array.
 * @printed: The current number of bytes already stored to output
 *           for a given specifier.
 * @flags: Flag modifiers.
 * @width: A width modifier.
 * Return: The number of bytes stored to the buffer.
 */
unsigned int printneg_width(bufer_t *output, unsigned int printed,
		unsigned char flags, int width)
{
	unsigned int ret = 0;
	char widthc = ' ';

	if (NEG_FLAG == 1)
	{
		for (width -= printed; width > 0; width--)
			ret += _memcpy(output, &widthc, 1);
	}
	return (ret);
}
