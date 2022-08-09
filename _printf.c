#include "main.h"

/**
 * _printf - outputs a formatted string.
 * @format: string to print.
 * Return: number of characters printed.
 */
int _printf(const char *format, ...)
{
	bufer_t *output;
	va_list args;
	int ret;

	if (format == NULL)
		return (-1);
	output = init_buffer();
	if (output == NULL)
		return (-1);

	va_start(args, format);
	ret = run_printf(format. args, output);
	return (ret);
}
