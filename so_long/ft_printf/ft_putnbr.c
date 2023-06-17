/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 18:21:33 by mdenguir          #+#    #+#             */
/*   Updated: 2022/10/25 16:13:30 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long n)
{
	int		count;

	count = 0;
	if (n <= 9 && n >= 0)
		count += ft_putchar(n + '0');
	else if (n < 0)
	{
		count += ft_putchar('-');
		n *= -1;
		count += ft_putnbr(n);
	}
	else
	{
		count += ft_putnbr(n / 10);
		count += ft_putnbr(n % 10);
	}
	return (count);
}
