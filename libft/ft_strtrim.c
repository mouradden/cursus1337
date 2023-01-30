/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:59:50 by mdenguir          #+#    #+#             */
/*   Updated: 2022/10/20 09:44:15 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	search(const char *set, char c)
{
	int		i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	char	*trimed;

	if (!s1)
		return (NULL);
	while (*s1 && search(set, *s1))
	{
		s1++;
	}
	len = ft_strlen(s1);
	while (len > 0 && search(set, s1[len - 1]))
	{
		len--;
	}
	trimed = ft_substr(s1, 0, len);
	return (trimed);
}
