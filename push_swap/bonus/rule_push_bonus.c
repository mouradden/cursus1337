/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_push_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:12:53 by mdenguir          #+#    #+#             */
/*   Updated: 2023/01/31 19:13:07 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_pa(t_stack **stack_b, t_stack **stack_a)
{
	int		v;

	if (!stack_a)
		return ;
	v = ft_pop(stack_b);
	ft_push(stack_a, v);
}

void	ft_pb(t_stack **stack_a, t_stack **stack_b)
{
	int		v;

	if (!stack_b)
		return ;
	v = ft_pop(stack_a);
	ft_push(stack_b, v);
}
