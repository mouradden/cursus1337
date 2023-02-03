/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:57:47 by mdenguir          #+#    #+#             */
/*   Updated: 2022/11/12 10:58:12 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*joined;
	int		index;
	int		s1_len;

	s1_len = ft_strlen(s1);
	if (!s1 && !s2)
		return (NULL);
	joined = (char *)malloc(s1_len + ft_strlen(s2) + 1);
	if (!joined)
		return (NULL);
	index = 0;
	while (s1 && s1[index])
	{
		joined[index] = s1[index];
		index++;
	}
	index = 0;
	while (s2 && s2[index])
	{
		joined[ft_strlen(s1) + index] = s2[index];
		index++;
	}
	joined[s1_len + index] = '\0';
	free(s1);
	return (joined);
}

int	ft_strlen(const char *s)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*s1;
	int		len;

	s1 = (char *)s;
	i = 0;
	if (!s)
		return (0);
	len = ft_strlen(s1);
	while (s[i] != '\0')
	{
		if (s1[i] == (char)c)
		{
			return (&s1[i]);
		}
		i++;
	}
	return (0);
}
