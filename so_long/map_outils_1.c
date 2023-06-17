/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_outils_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 12:11:42 by mdenguir          #+#    #+#             */
/*   Updated: 2023/06/16 17:07:32 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_foreign_lettre(char **str)
{
	int		i;
	int		j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j] && str[i][j] != '\n')
		{
			if (str[i][j] != '1' && str[i][j] != '0'
				&& str[i][j] != 'P' && str[i][j] != 'C'
				&& str[i][j] != 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
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
