/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:43:21 by mdenguir          #+#    #+#             */
/*   Updated: 2022/10/25 16:21:54 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print(va_list args, char c)
{
	int		count;

	count = 0;
	if (c == 'd' || c == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (c == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (c == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (c == 'x')
		count += ft_print_hexa(va_arg(args, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		count += ft_print_hexa(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (c == 'p')
		count += ft_putstr("0x")
			+ ft_print_address(va_arg(args, unsigned long), "0123456789abcdef");
	else if (c == 'u')
		count += ft_print_unsigned(va_arg(args, unsigned int));
	return (count);
}
