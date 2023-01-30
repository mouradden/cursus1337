/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 10:21:33 by mdenguir          #+#    #+#             */
/*   Updated: 2022/10/02 15:19:16 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	char		*dest;

	dest = (char *)s;
	while (len > 0)
	{
		*dest = (char) c;
		dest++;
		len--;
	}
	return (s);
}
