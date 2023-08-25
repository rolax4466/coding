#include "custom_printf.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed
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

			case 'd':
			case 'i':
				int num = va_arg(args, int);
				if (num < 0)
				{
					char_count += write(1, "-", 1);
					num = -num;
				}
				char num_str[12];
				int digit_count = 0;
				do {
					num_str[digit_count++] = (num % 10) + '0';
					num /= 10;
				} while (num > 0);
				while (digit_count > 0)
				{
					char_count += write(1, &num_str[--digit_count], 1);
				}
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
		format++;
	}
	va_end(args);
	return (char_count);
}
