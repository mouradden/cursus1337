/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:49:47 by mdenguir          #+#    #+#             */
/*   Updated: 2023/01/31 17:39:31 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_words(char *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count + 1);
}

int	len_word(char *s, char c)
{
	int		count;

	count = 0;
	while (s[count] && s[count] != c)
	{
		count++;
	}
	return (count);
}

char	**ft_split(char *s, char c)
{
	char		**ptr;
	int			j;
	int			k;

	j = 0;
	ptr = (char **) malloc((count_words(s, c)) * sizeof(char *));
	if (!ptr)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			ptr[j] = (char *) malloc (len_word(s, c) * sizeof(char) + 1);
			if (!ptr[j])
				return (NULL);
			k = 0;
			while (*s && *s != c)
				ptr[j][k++] = *s++;
			ptr[j++][k] = '\0';
		}
	}
	ptr[j] = NULL;
	return (ptr);
}

char	*my_strjoin(char *s1, char *s2)
{
	char	*joined;
	int		index;

	if (!s1 && !s2)
		return (NULL);
	joined = (char *)malloc(my_strlen(s1) + my_strlen(s2) + 1);
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
		joined[my_strlen(s1) + index] = s2[index];
		index++;
	}
	joined[my_strlen(s1) + index] = '\0';
	free(s1);
	return (joined);
}

long	ft_atoi(char *str)
{
	int		sign;
	long	res;

	sign = 1;
	res = 0;
	while ((*str >= 9 && *str <= 13) || (*str == ' '))
	{
		str++;
	}
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str <= '9' && *str >= '0')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * sign);
}
