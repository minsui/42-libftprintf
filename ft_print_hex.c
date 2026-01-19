/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim2 <mkim2@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:04:50 by mkim2             #+#    #+#             */
/*   Updated: 2026/01/16 16:15:41 by mkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_hex(unsigned long long n, char *base)
{
	int	len;

	len = 0;
	if (n >= 16)
		len += ft_put_hex(n / 16, base);
	len += ft_print_char(base[n % 16]);
	return (len);
}

int	ft_print_hex(unsigned int n, char format)
{
	if (format == 'x')
		return (ft_put_hex((unsigned long long)n, "0123456789abcdef"));
	else
		return (ft_put_hex((unsigned long long)n, "0123456789ABCDEF"));
}

int	ft_print_ptr(unsigned long long ptr)
{
	int	len;

	len = 0;
	if (ptr == 0)
		return (write(1, "(nil)", 5));
	len += write(1, "0x", 2);
	len += ft_put_hex(ptr, "0123456789abcdef");
	return (len);
}
