/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:07:09 by mdenguir          #+#    #+#             */
/*   Updated: 2022/10/20 11:56:06 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*dst;
	size_t		i;
	size_t		dstlen;

	if (!s)
		return (0);
	dstlen = ft_strlen(s);
	i = 0;
	if (dstlen < len)
		dst = malloc(dstlen * sizeof(char) + 1);
	else
		dst = malloc(len * sizeof(char) + 1);
	if (!dst)
		return (NULL);
	if (start < ft_strlen(s))
	{
		while (i < len && *(s + start + i))
		{
			*(dst + i) = *(s + start + i);
			i++;
		}
	}
	*(dst + i) = '\0';
	return (dst);
}
