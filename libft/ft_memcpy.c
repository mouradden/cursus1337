/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:59:34 by mdenguir          #+#    #+#             */
/*   Updated: 2022/10/17 15:04:16 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*str;
	char		*s;
	size_t		i;

	str = (char *)dst;
	s = (char *)src;
	i = 0;
	if (str == s)
		return (dst);
	while (i < n)
	{
		*str = *s;
		str++;
		s++;
		i++;
	}
	return (dst);
}
