/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:28:24 by mdenguir          #+#    #+#             */
/*   Updated: 2023/06/14 17:28:30 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_lentgh(int nb)
{
	int		count;

	count = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		count = 1;
		nb *= -1;
	}
	while (nb)
	{
		count++;
		nb = nb / 10;
	}
	return (count);
}

char	*ft_itoa(int nb)
{
	char		*buffer;
	int			len;
	long		n;

	n = nb;
	len = ft_lentgh(n);
	buffer = malloc (len + 1);
	if (!buffer)
		return (NULL);
	buffer[len] = '\0';
	if (n == 0)
		*buffer = '0';
	if (n < 0)
	{
		*buffer = '-';
		n = -n;
	}
	while (n)
	{
		buffer[len - 1] = n % 10 + '0';
		n /= 10;
		len--;
	}
	return (buffer);
}
