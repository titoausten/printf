#include "main.h"
int precision_handler(va_list args, const char *modifier, char *index);
unsigned int (*specifiers_handler(const char *specifier))(va_list,
			bufer_t *, unsigned char, int, int, unsigned char);
/**
 * precision_handler - Matches a precision modifier with its
 * corresponding value.
 * @args: A va_list of arguments.
 * @modifier: A pointer to a potential precision modifier.
 * @index: An index counter for the original format string.
 * Return: If a precision modifier is matched - its value.
 *         If the precision modifier is empty, zero, or
 * negative - 0. Otherwise - -1.
 */
int precision_handler(va_list args, const char *modifier, char *index)
{
	int value = 0;

	if (*modifier != '.')
		return (-1);
	modifier++;
	(*index)++;

	if ((*modifier <= '0' || *modifier > '9') && *modifier != '*')
	{
		if (*modifier == '0')
			(*index)++;
		return (0);
	}
	while ((*modifier >= '0' && *modifier <= '9') || *modifier == '*')
	{
		(*index)++;
		if (*modifier == '*')
		{
			value = va_arg(args, int);
			if (value <= 0)
				return (0);
			return (value);
		}
		value *= 10;
		value += (*modifier - '0');
		modifier++;
	}
	return (value);
}
/**
 * @specifiers_handler: Matches a conversion specifier with
 *                     a corresponding conversion function.
 * @specifier: A pointer to a potential conversion specifier.
 * Return: If a conversion function is matched - a pointer to the function.
 *         Otherwise - NULL.
 */
unsigned int (*specifiers_handler(const char *specifier))(va_list, bufer_t *,
		unsigned char, int, int, unsigned char)
{
	int i;
	converter_t converters[] = {
		{'c', convertc},
		{'s', converts},
		{'d', convertdi},
		{'i', convertdi},
		{'%', convertpercent},
		{'b', convertb},
		{'u', convertu},
		{'o', converto},
		{'x', convertx},
		{'X', convertX},
		{'S', convertS},
		{'p', convertp},
		{'r', convertr},
		{'R', convertR},
		{0, NULL}
	};
	for (i = 0; converters[i].f; i++)
	{
		if (converters[i].specifier == *specifier)
			return (converters[i].f);
	}
	return (NULL);
}
