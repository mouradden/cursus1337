/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:28:55 by mdenguir          #+#    #+#             */
/*   Updated: 2022/10/25 16:14:23 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexa(unsigned int n, char *base)
{
	int		count;

	count = 0;
	if (n >= 0 && n < 16)
	{
		count += ft_putchar(base[n]);
	}
	else
	{
		count += ft_print_hexa(n / 16, base);
		count += ft_print_hexa(n % 16, base);
	}
	return (count);
}
