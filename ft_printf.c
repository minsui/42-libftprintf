/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim2 <mkim2@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:21:47 by mkim2             #+#    #+#             */
/*   Updated: 2026/01/14 15:23:56 by mkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_type(va_list ap, char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_print_char(va_arg(ap, int));
	else if (format == 's')
		len += ft_print_str(va_arg(ap, char *));
	else if (format == 'p')
		len += ft_print_ptr(va_arg(ap, unsigned long long));
	else if (format == 'd' || format == 'i')
		len += ft_print_nbr(va_arg(ap, int));
	else if (format == 'u')
		len += ft_print_unsigned(va_arg(ap, unsigned int));
	else if (format == 'x' || format == 'X')
		len += ft_print_hex(va_arg(ap, unsigned int), format);
	else if (format == '%')
		len += ft_print_char('%');
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		total_len;

	i = 0;
	total_len = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			total_len += check_type(ap, format[i]);
		}
		else
		{
			total_len += ft_print_char(format[i]);
		}
		i++;
	}
	va_end(ap);
	return (total_len);
}
