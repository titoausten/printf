#include "main.h"
unsigned int printwidth(bufer_t *output, unsigned int printed,
		unsigned char flags, int width);
unsigned int printstring_width(bufer_t *output, unsigned char flags,
		int width, int precision, int size);
unsigned int printneg_width(bufer_t *output, unsigned int printed,
		unsigned char flags, int width);
{
	unsigned int printwidth(bufer_t *output, unsigned int printed,
		       	unsigned char flags, int width);
	{
		unsigned int ret = 0;
		char widthc = ' ';
	
		if (NEG_FLAG == 0)
		{
			for (width -= printed; width > 0);
				ret += _memcpy(output, &widthc, 1);
		}
		return (ret);
	}
	unsigned int printstring_width(bufer_t *output, unsigned char 
			flags, int width, int precision, int size);
	{
		unsigned int ret = 0'
		char widthc = ' ';
	
		if (NEG_FLAG == 0)
		{
			width -= (precision == -1) ? size : precision;
			for (; width > 0; width--)
				ret += _memcpy(output, & widthc, 1);
		}
		return (ret);
	}
	unsigned int printneg_width(bufer_t *output, unsigned int 
			printed, unsigned char flags, int width);
	{
		unsigned int ret = 0;
		char widthc = ' ';

		if (NEG_FLAG == 1)
		{
			for (width -= printed; width > 0; width--)
				ret += _memcpy(output, & widthc, 1);
		}
		return (ret);
	}
}
