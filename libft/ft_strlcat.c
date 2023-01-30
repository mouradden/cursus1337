/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:22:43 by mdenguir          #+#    #+#             */
/*   Updated: 2022/10/13 10:57:56 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	srclen;
	size_t	dstlen;
	size_t	len;
	size_t	j;

	srclen = ft_strlen(src);
	if (dst == NULL && size == 0)
		return (srclen);
	dstlen = ft_strlen(dst);
	if (size < dstlen)
		return (size + srclen);
	else
		len = srclen + dstlen;
	j = 0;
	while (src[j] != '\0' && dstlen + j + 1 < size)
	{
		dst[dstlen + j] = src[j];
		j++;
	}
	dst[dstlen + j] = '\0';
	return (len);
}
