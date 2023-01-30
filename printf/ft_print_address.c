/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 10:17:20 by mdenguir          #+#    #+#             */
/*   Updated: 2022/10/25 16:13:54 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_address(unsigned long n, char *base)
{
	int		count;

	count = 0;
	if (n >= 0 && n < 16)
	{
		count += ft_putchar(base[n]);
	}
	else
	{
		count += ft_print_address(n / 16, base);
		count += ft_print_address(n % 16, base);
	}
	return (count);
}
