/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 10:02:49 by mdenguir          #+#    #+#             */
/*   Updated: 2023/06/20 10:18:01 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *buffer)
{
	char	*buf;
	int		count_read;

	count_read = 1;
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (!(ft_strchr(buffer, '\n')) && count_read != 0)
	{
		count_read = read(fd, buf, BUFFER_SIZE);
		if (count_read == 0)
			break ;
		if (count_read == -1)
		{
			free(buffer);
			free(buf);
			exit(1);
			return (NULL);
		}
		buf[count_read] = '\0';
		buffer = ft_strjoin(buffer, buf);
	}
	free(buf);
	return (buffer);
}

char	*ft_read_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		i++;
	}
	line = malloc(i * sizeof(char) + 2);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		line[i++] = '\n';
	}
	line[i] = '\0';
	return (line);
}

char	*free_buf(char *buffer)
{
	int		len;
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	len = ft_strlen(buffer);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i] || (buffer[i] == '\n' && buffer[i + 1] == '\0'))
	{
		free(buffer);
		return (NULL);
	}
	str = malloc(len - i + 1);
	i++;
	while (buffer[i])
	{
		str[j++] = buffer[i++];
	}
	str[j] = '\0';
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	static int	i;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		close(fd);
		return (0);
	}	
	buffer = ft_read(fd, buffer);
	if (!buffer)
	{
		close(fd);
		return (NULL);
	}
	line = ft_read_line(buffer);
	buffer = free_buf(buffer);
	i++;
	return (line);
}
