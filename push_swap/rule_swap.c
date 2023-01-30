/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:09:57 by mdenguir          #+#    #+#             */
/*   Updated: 2023/01/30 20:37:58 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **stack_a)
{
	int		v1;
	int		v2;

	if (stack_size(stack_a) < 2)
		return ;
	v1 = ft_pop(stack_a);
	v2 = ft_pop(stack_a);
	ft_push(stack_a, v1);
	ft_push(stack_a, v2);
	write(1, "sa\n", 3);
}

void	sb(t_stack **stack_b)
{
	int		v1;
	int		v2;

	if (stack_size(stack_b) < 2)
		return ;
	v1 = ft_pop(stack_b);
	v2 = ft_pop(stack_b);
	ft_push(stack_b, v1);
	ft_push(stack_b, v2);
	write(1, "sb\n", 3);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_size(stack_a) >= 2)
		sa(stack_a);
	if (stack_size(stack_b) >= 2)
		sb(stack_b);
	write(1, "ss\n", 3);
}
