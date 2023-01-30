/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 15:49:01 by mdenguir          #+#    #+#             */
/*   Updated: 2022/10/26 14:58:58 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *ptr, ...)
{
	va_list	args;
	int		i;
	int		count;

	count = 0;
	i = 0;
	va_start(args, ptr);
	while (ptr[i])
	{
		if (ptr[i] == '%')
		{
			if (ptr[i + 1] == '%')
			{
				count += ft_putchar('%');
				i++;
			}
			else
				count += ft_print(args, ptr[++i]);
		}
		else
			count += ft_putchar(ptr[i]);
		i++;
	}
	va_end(args);
	return (count);
}
