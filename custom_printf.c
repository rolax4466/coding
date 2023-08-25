#include "custom_printf.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * custom_printf - the printf function
 * @format : the format
 * Return : The printed characters
 *
 */


int _printf(const char *format, ...);
{
	va_list args;

	va_start(args, format);

	int char_count = 0;

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				break;
		switch (*format)
		{
			case 'c':
				char_count += write(1, &va_arg(args, int), 1);
				break;

			case 's':
				char_count += write(1, va_arg(args, char *), 1);
				break;
			case '%':
				char_count += write(1, "%", 1);
				break;
		}
		}
	else
	{
		char_count += write(1, format, 1);
	}
	foramt++;
	}

	va_end(args);
	return (char_count);

}
