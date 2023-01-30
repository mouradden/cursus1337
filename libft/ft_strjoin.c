/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:20:38 by mdenguir          #+#    #+#             */
/*   Updated: 2022/10/10 15:10:43 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	size_t	s1len;
	size_t	s2len;

	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	dst = malloc((s1len + s2len) * sizeof(char) + 1);
	if (!dst)
		return (NULL);
	while (*s1)
	{
		*dst++ = *s1++;
	}
	while (*s2)
	{
		*dst++ = *s2++;
	}
	*dst = '\0';
	return (dst - s2len - s1len);
}
