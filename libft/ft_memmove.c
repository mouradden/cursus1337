/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:18:39 by mdenguir          #+#    #+#             */
/*   Updated: 2022/10/05 11:05:54 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if ((char *)dst > (char *)src)
	{
		while (len--)
		{
			*(char *)(dst + len) = *(char *)(src + len);
		}
	}
	else
	{
		ft_memcpy(dst, src, len);
	}
	return (dst);
}
