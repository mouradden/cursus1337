/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:09:57 by mdenguir          #+#    #+#             */
/*   Updated: 2023/01/31 19:49:57 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_sa(t_stack **stack_a)
{
	int		v1;
	int		v2;

	if (stack_size(stack_a) < 2)
		return ;
	v1 = ft_pop(stack_a);
	v2 = ft_pop(stack_a);
	ft_push(stack_a, v1);
	ft_push(stack_a, v2);
}

void	ft_sb(t_stack **stack_b)
{
	int		v1;
	int		v2;

	if (stack_size(stack_b) < 2)
		return ;
	v1 = ft_pop(stack_b);
	v2 = ft_pop(stack_b);
	ft_push(stack_b, v1);
	ft_push(stack_b, v2);
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_size(stack_a) >= 2)
		ft_sa(stack_a);
	if (stack_size(stack_b) >= 2)
		ft_sb(stack_b);
}
