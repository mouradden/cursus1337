/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:10:35 by mdenguir          #+#    #+#             */
/*   Updated: 2022/10/19 13:08:50 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list		*l;
	t_list		*ltemp;

	l = *lst;
	while (l)
	{
		ltemp = l->next;
		del(l->content);
		free(l);
		l = ltemp;
	}
	*lst = NULL;
}
