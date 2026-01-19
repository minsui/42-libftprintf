/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nums.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim2 <mkim2@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:02:40 by mkim2             #+#    #+#             */
/*   Updated: 2026/01/14 16:08:50 by mkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nbr(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		len += ft_print_char('-');
		n = -n;
	}
	if (n >= 10)
		len += ft_print_nbr(n / 10);
	len += ft_print_char((n % 10) + '0');
	return (len);
}

int	ft_print_unsigned(unsigned int n)
{
	int	len;

	len = 0;
	if (n >= 10)
		len += ft_print_unsigned(n / 10);
	len += ft_print_char((n % 10) + '0');
	return (len);
}
