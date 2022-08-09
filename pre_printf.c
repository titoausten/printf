#include "main.h"

void clean(va_list args, bufer_t *output);
int run_printf(const char *format, va_list args, bufer_t *output);
/**
 * clean - performs a cleaning process for _printf.
 * @args: a list of arguments.
 * @output : A bufer_t struct.
 */
void clean(va_list args, bufer_t *output)
{
	va_end(args);
	write(1, output->start, output->length);
	free_bufer(output);
}
/**
 * run_printf - reads format string for _printf.
 * @format: character string to print.
 * @args: a list of arguments.
 * @output: A bufer_t struct containing a buffer.
 * Return: number of characters stored to output.
 */
int run_printf(const char *format, va_list args, bufer_t *output)
{
	int i, width, precision, ret = 0;
	char temp;
	unsigned char flags, length;
	unsigned int (*f)(va_list, bufer_t *, unsigned char, int, int, unsigned char);

	for (i = 0; *(format + i); i++)
	{
		length = 0;
		if (*(format + i) == '%')
		{
			temp = 0;
			flags = flags_handler(format + i + 1, &temp);
			width = width_handler(args, format + i + 1, &temp);
			precision = prec_handler(args, format + i + 1, &temp);
			length = length_handler(format + i + temp + 1, &temp);
			f = specifiers_handler(format + i + temp + 1);
			if (f != NULL)
			{
				i += temp + 1;
				ret += f(args, output, flags, width, precision, length);
				continue;
			}
			else if (*(format + i + temp + 1) == '\0')
			{
				ret = -1;
				break;
			}
		}
		ret += _memcpy(output, (format + i), 1);
		i += (length != 0) ? 1 : 0;
	}
	clean(args, output);
	return (ret);
}

