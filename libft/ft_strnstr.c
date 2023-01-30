/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 12:31:07 by mdenguir          #+#    #+#             */
/*   Updated: 2022/10/11 15:43:18 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t		i;
	size_t		j;
	size_t		idx;

	i = 0;
	idx = 0;
	if (len == 0 && str == NULL)
		return (NULL);
	if (*find == '\0')
		return ((char *)str);
	while (*(str + i) != '\0')
	{
		j = 0;
		while ((*(str + i + j) == *(find + j)
				&& *(str + i + j) != '\0') && (i + j < len))
		{
			if (*(find + j + 1) == '\0')
				return ((char *)(str + i));
			else
				j++;
		}
		i++;
	}
	return (0);
}
