/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_outils_1_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:01:46 by mdenguir          #+#    #+#             */
/*   Updated: 2023/06/16 17:37:38 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
				&& str[i][j] != 'E' && str[i][j] != 'X')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
