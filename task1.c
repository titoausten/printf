#include "main.h"
/**
 * convertdi - Converts an argument to a signed int and
 *              stores it to a buffer contained in a struct.
 * @args: A va_list pointing to the argument to be converted.
 * @flags: Flag modifiers.
 * @width: A width modifier.
 * @precision: A precision modifier.
 * @length: A length modifier.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int convertdi(va_list args, bufer_t *output,
		unsigned char flags, int width, int precision, unsigned char length)
{
	long int d, dup;
	unsigned int ret = 0, count = 0;
	char pad, space = ' ', neg = '-', plus = '+';

	if (length == LONG)
		d = va_arg(args, long int);
	else
		d = va_arg(args, int);
	if (length == SHORT)
		d = (short)d;
	/* Handle space flag */
	if (SPACE_FLAG == 1 && d >= 0)
		ret += _memcpy(output, &space, 1);
	if (precision <= 0 && NEG_FLAG == 0) /* Handle width  */
	{
		if (d == LONG_MIN)
			count += 19;
		else
		{
			for (dup = (d < 0) ? -d : d; dup > 0; dup /= 10)
				count++;
		}
		count += (d == 0) ? 1 : 0;
		count += (d < 0) ? 1 : 0;
		count += (PLUS_FLAG == 1 && d >= 0) ? 1 : 0;
		count += (SPACE_FLAG == 1 && d >= 0) ? 1 : 0;
		/* Handle plus flag when zero flag is active */
		if (ZERO_FLAG == 1 && PLUS_FLAG == 1 && d >= 0)
			ret += _memcpy(output, &plus, 1);
		/*Print negative sign when zero flag is active */
		if (ZERO_FLAG == 1 && d < 0)
			ret += _memcpy(output, &neg, 1);
		pad = (ZERO_FLAG == 1) ? '0' : ' ';
		for (width -= count; width > 0; width--)
			ret += _memcpy(output, &pad, 1);
	}
	/* Print negative sign when zero flag is not active */
	if (ZERO_FLAG == 0 && d < 0)
		ret += _memcpy(output, &neg, 1);
	/* Handle plus flag when zero flag is not active */
	if (ZERO_FLAG == 0 && (PLUS_FLAG == 1 && d >= 0))
		ret += _memcpy(output, &plus, 1);
	if (!(d == 0 && prec == 0))
		ret += convert_sbase(output, d, "0123456789",
				flags, 0, precision);
	ret += printneg_width(output, ret, flags, width);
	return (ret);
}
