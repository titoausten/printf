#include "main.h"
unsigned int converts(va_list args, bufer_t *output, unsigned char        
                flags, int width, int precision, unsigned char length)
unsigned int convertc(va_list args, bufer_t *output, unsigned char                                                            
                flags, int width, int precision, unsigned char length) 
unsigned int convertpercent(va_list args, bufer_t *output, unsigned char                                                      
                flags, int width, int precision, unsigned char length)

unsigned int converts(va_list args, bufer_t *output, unsigned char
		flags, int width, int precision, unsigned char length)
{
	char *str, *null = "(null);

	int size;
	unsigned int ret = 0;
	(void)flags;
	(void)len;

	str = va_arg(args, char*);
	
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
unsigned int convertc(va_list args, bufer_t *output, unsigned char      
                flags, int width, int precision, unsigned char length)
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
unsigned int convertpercent(va_list args, bufer_t *output, unsigned char 
		flags, int width, int precision, unsigned char length)
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

