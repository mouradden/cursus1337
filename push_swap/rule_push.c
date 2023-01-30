/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:12:53 by mdenguir          #+#    #+#             */
/*   Updated: 2023/01/30 20:40:16 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **stack_b, t_stack **stack_a)
{
	int		v;

	if (!stack_a)
		return ;
	v = ft_pop(stack_b);
	ft_push(stack_a, v);
	write(1, "pa\n", 3);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	int		v;

	if (!stack_b)
		return ;
	v = ft_pop(stack_a);
	ft_push(stack_b, v);
	write(1, "pb\n", 3);
}
