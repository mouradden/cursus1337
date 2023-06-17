/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 18:20:07 by mdenguir          #+#    #+#             */
/*   Updated: 2022/10/25 16:13:10 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (!s)
	{
		return (ft_putstr("(null)"));
	}
	while (s[i])
	{
		count += ft_putchar(s[i]);
		i++;
	}
	return (count);
}
