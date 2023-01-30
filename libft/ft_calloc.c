/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:37:43 by mdenguir          #+#    #+#             */
/*   Updated: 2022/10/10 15:09:01 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*ptr;

	if (size >= SIZE_MAX && nitems >= SIZE_MAX)
		return (0);
	ptr = malloc (nitems * size);
	if (ptr == 0)
		return (ptr);
	ft_bzero (ptr, nitems * size);
	return (ptr);
}
