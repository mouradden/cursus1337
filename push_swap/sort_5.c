/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:41:47 by mdenguir          #+#    #+#             */
/*   Updated: 2023/01/30 20:33:59 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_5(t_stack **stack_a, t_stack **stack_b)
{
	if (index_of(stack_a, min(stack_a)) <= (stack_size(stack_a) / 2 + 1))
	{
		while ((*stack_a)->data != min(stack_a))
			ra(stack_a);
	}
	else
	{
		while ((*stack_a)->data != min(stack_a))
			rra(stack_a);
	}
	pb(stack_a, stack_b);
	if (index_of(stack_a, min(stack_a)) <= (stack_size(stack_a) / 2 + 1))
	{
		while ((*stack_a)->data != min(stack_a))
			ra(stack_a);
	}
	else
	{
		while ((*stack_a)->data != min(stack_a))
			rra(stack_a);
	}
	pb(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_b, stack_a);
	pa(stack_b, stack_a);
}
