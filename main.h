#ifndef MAIN_H
#define MAIN_H
#include <limits.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/* Flag Modifier Macros */
#define PLUS 1
#define SPACE 2
#define HASH 4
#define ZERO 8
#define NEG 16
#define PLUS_FLAG (flags & 1)
#define SPACE_FLAG ((flags >> 1) & 1)
#define HASH_FLAG ((flags >> 2) & 1)
#define ZERO_FLAG ((flags >> 3) & 1)
#define NEG_FLAG ((flags >> 4) & 1)

/* Length Modifier Macros */
#define SHORT 1
#define LONG 2

/**
 * struct bufer_s - A new type defining a bufer struct.
 * @buffer: A pointer to a character array.
 * @start: A pointer to the start of bufer.
 * @len: The length of the string stored in bufer.
*/
typedef struct bufer_s
{
	char *buffer;
	char *start;
	unsigned int len;
} bufer_t;

/**
 * struct converter_s - A new type defining a converter struct.
 * @specifier: A character representing a conversion specifier.
 * @f: A pointer to a conversion function corresponding to specifier.
*/
typedef struct converter_s
{
	unsigned char specifier;
	unsigned int (*f)(va_list, bufer_t *, unsigned char, int, int, unsigned char);
} converter_t;

/**
 * struct flag_s - A new type defining a flags struct.
 * @flag: A character representing a flag.
 * @value: The integer value of the flag.
*/
typedef struct flag_s
{
	unsigned char flag;
	unsigned char value;
} flag_t;

int _printf(const char *format, ...);
void clean(va_list args, bufer_t *output);
int run_printf(const char *format, va_list args, bufer_t *output);
unsigned int _memcpy(bufer_t *output, const char *src, unsigned int n);
void free_buffer(bufer_t *output);
bufer_t *init_buffer(void);
int width_handler(va_list arts, const char *modifier, char *index);
unsigned char length_handler(const char *modifier, char *index);
unsigned char flags_handler(const char *flag, char *index);
int precision_handler(va_list args, const char *modifier, char *index);
unsigned int (*specifiers_handler(const char *specifier))(va_list,
		bufer_t *, unsigned char, int, int, unsigned char);

unsigned int printwidth(bufer_t *output, unsigned int printed,
		unsigned char flags, int width);
unsigned int printstring_width(bufer_t *output, unsigned char flags,
		int width, int precision, int size);
unsigned int printneg_width(bufer_t *output, unsigned int printed,
		unsigned char flags, int width);

unsigned int convert_sbase(buffer_t *output, long int num, char *base,
		unsigned char flags, int wid, int prec);
unsigned int convert_ubase(buffer_t *output,
		unsigned long int num, char *base,
		unsigned char flags, int wid, int prec);

unsigned int convertc(va_list args, bufer_t *output,
		unsigned char flags, int width, int precision, unsigned char length);
unsigned int convertpercent(va_list args, bufer_t *output,
		unsigned char flags, int width, int precision, unsigned char length);
unsigned int converts(va_list args, bufer_t *output,
		unsigned char flags, int width, int precision, unsigned char length);
unsigned int convertdi(va_list args, bufer_t *output,
		unsigned char flags, int width, int precision, unsigned char length);
unsigned int convertb(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len);
#endif
