/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:50:33 by mdenguir          #+#    #+#             */
/*   Updated: 2023/06/20 12:05:22 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_wall_map(char **str)
{
	int		i;
	int		j;

	j = 0;
	while (str[0][j])
	{
		if (str[0][j] != '1' && str[0][j] != '\n')
			return (0);
		j++;
	}
	i = 1;
	while (str[i] && i < ft_strlength(str) - 1)
	{
		if (str[i][0] != '1' || str[i][ft_strlen(str[i]) - 2] != '1')
			return (0);
		i++;
	}
	j = 0;
	while (str[ft_strlength(str) - 1][j])
	{
		if (str[ft_strlength(str) - 1][j] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	check_rectangle_map(char **str)
{
	int		i;
	int		j;
	int		len;

	i = 1;
	len = 0;
	while (str[0][len] && str[0][len] != '\n')
		len++;
	while (str[i])
	{
		j = 0;
		while (str[i][j] && str[i][j] != '\n')
			j++;
		if (len != j)
			return (0);
		i++;
	}
	return (1);
}

int	check_unique_p_e_c(char **str)
{
	int		i;
	int		j;
	int		count_p;
	int		count_e;
	int		count_c;

	i = 0;
	j = 0;
	count_p = 0;
	count_c = 0;
	count_e = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			check_pce(str[i][j], &count_p, &count_e, &count_c);
			j++;
		}
		i++;
	}
	if (count_e != 1 || count_c < 1 || count_p != 1)
		return (0);
	return (1);
}

void	check_pce(int c, int *count_p, int *count_e, int *count_c)
{
	if (c == 'P')
		(*count_p)++;
	else if (c == 'C')
		(*count_c)++;
	else if (c == 'E')
		(*count_e)++;
}

void	valid_map(char **str)
{
	if (!check_rectangle_map(str) || !check_wall_map(str)
		|| !check_unique_p_e_c(str) || !check_foreign_lettre(str))
	{
		ft_printf("ERROR \n Check the map's format.\n");
		if (!check_rectangle_map(str))
			ft_printf(" -->The map is not rectangle\n");
		if (!check_wall_map(str))
			ft_printf(" -->The map does not have a complete wall\n");
		if (!check_unique_p_e_c(str))
			ft_printf(" -->The map must have one P, one E and at least one C\n");
		if (!check_foreign_lettre(str))
			ft_printf(" -->The map must contain just P, E, C, 0 and 1\n");
		free_2_dimensions(str);
		exit(1);
	}
}
