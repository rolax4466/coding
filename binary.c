#include "custom_printf.h"
#include <stdarg.h>
#include <unistd.h>

/**
 *_printf : custom_printf
 *
 * @format : Format string
 *
 * Return : Binary
 */

int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    int c = 0;

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (*format == '\0')
                break;
            switch (*format)
            {
                case 'c': c += write(1, &va_arg(args, int), 1); break;
                case 's': c += write(1, va_arg(args, char *), 1); break;
                case 'd': case 'i': // Handle printing integers
                    int n = va_arg(args, int), dc = 0;
                    if (n < 0) { c += write(1, "-", 1); n = -n; }
                    char ns[12]; do { ns[dc++] = (n % 10) + '0'; n /= 10; } while (n > 0);
                    while (dc > 0) { dc--; c += write(1, &ns[dc], 1); } break;
                case 'b': // Handle printing binary
                    { unsigned int num = va_arg(args, unsigned int);
                    char bs[33]; bs[32] = '\0';
                    for (int i = 31; i >= 0; i--) { bs[i] = (num & 1) + '0'; num >>= 1; }
                    c += write(1, bs, 32); } break;
                case '%': c += write(1, "%", 1); break;
            }
        }
        else c += write(1, format, 1);
        format++;
    }

    va_end(args);
    return (c);
}

