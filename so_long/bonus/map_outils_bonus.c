/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_outils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:50:40 by mdenguir          #+#    #+#             */
/*   Updated: 2023/06/14 21:52:18 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_get_height(char **s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

int	ft_get_width(char **s)
{
	int		i;

	i = 0;
	while (s[0][i])
	{
		i++;
	}
	return (i);
}

int	count_lines(char *path)
{
	int		count;
	int		fd;
	char	*line;

	count = 0;
	fd = open(path, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		count++;
		free(line);
	}
	close(fd);
	return (count);
}

int	count_collect(char **str)
{
	int		i;
	int		j;
	int		count_c;

	i = 0;
	count_c = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'C')
				count_c++;
			j++;
		}
		i++;
	}
	return (count_c);
}

char	*ft_strdup(const char *s1)
{
	char	*dst;
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (s1[len])
		len++;
	dst = (char *) malloc (len * sizeof(char) + 1);
	if (!dst)
		return (NULL);
	while (s1[i] != '\0')
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
