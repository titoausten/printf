#include "main.h"
unsigned int converts(va_list args, bufer_t *output, unsigned char flags,
		int width, int precision, unsigned char length);
unsigned int convertc(va_list args, bufer_t *output, unsigned char flags,
		int width, int precision, unsigned char length);
unsigned int convertpercent(va_list args, bufer_t *output, unsigned char flags,
		int width, int precision, unsigned char length);
/**
 * converts - Converts an argument to a string and
 *             stores it to a buffer contained in a struct.
 * @args: A va_list pointing to the argument to be converted.
 * @flags: Flag modifiers.
 * @width: A width modifier.
 * @precision: A precision modifier.
 * @length: A length modifier.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int converts(va_list args, bufer_t *output, unsigned char flags,
		int width, int precision, unsigned char length)
{
	char *str, *null = "(null)";
	int size;
	unsigned int ret = 0;

	(void)flags;
	(void)length;

	str = va_arg(args, char *);
	if (str == NULL)
		return (_memcpy(output, null, 6));

	for (size = 0; *(str + size);)
		size++;

	ret += printstring_width(output, flags, width, precision, size);

	precision = (precision == -1) ? size : precision;
	while (*str != '\0' && precision > 0)
	{
		ret += _memcpy(output, str, 1);
		precision--;
		str++;
	}

	ret += printneg_width(output, ret, flags, width);

	return (ret);
}
/**
 * convertc - Converts an argument to an unsigned char and
 *             stores it to a buffer contained in a struct.
 * @args: A va_list pointing to the argument to be converted.
 * @flags: Flag modifiers.
 * @width: A width modifier.
 * @precision: A precision modifier.
 * @length: A length modifier.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int convertc(va_list args, bufer_t *output, unsigned char flags,
		int width, int precision, unsigned char length)
{
	char c;
	unsigned int ret = 0;

	(void)precision;
	(void)length;

	c = va_arg(args, int);

	ret += printwidth(output, ret, flags, width);
	ret += _memcpy(output, &c, 1);
	ret += printneg_width(output, ret, flags, width);

	return (ret);
}
/**
 * convertpercent - Stores a percent sign to a
 *                   buffer contained in a struct.
 * @args: A va_list pointing to the argument to be converted.
 * @flags: Flag modifiers.
 * @width: A width modifier.
 * @precision: A precision modifier.
 * @length: A length modifier.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer (always 1).
 */
unsigned int convertpercent(va_list args, bufer_t *output, unsigned char flags,
		int width, int precision, unsigned char length)
{
	char percent = '%';
	unsigned int ret = 0;

	(void)args;
	(void)precision,
	(void)length;

	ret += printwidth(output, ret, flags, width);
	ret += _memcpy(output, &percent, 1);
	ret += printneg_width(output, ret, flags, width);

	return (ret);
}
