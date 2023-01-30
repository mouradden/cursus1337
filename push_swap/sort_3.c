/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:40:40 by mdenguir          #+#    #+#             */
/*   Updated: 2023/01/30 20:37:30 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted_3(t_stack **stack)
{
	if (((*stack)->data < (*stack)->next->data)
		&& ((*stack)->next->data < (*stack)->next->next->data))
		return (1);
	else
		return (0);
}

void	sort_3(t_stack **stack)
{
	int		v1;
	int		v2;
	int		v3;

	v1 = (*stack)->data;
	v2 = (*stack)->next->data;
	v3 = (*stack)->next->next->data;
	if (v1 > v2 && v2 < v3 && v1 < v3)
		sa(stack);
	else if (v1 > v3 && v2 < v3 && v1 > v3)
		ra(stack);
	else if (v1 < v2 && v1 > v3 && v2 > v1)
		rra(stack);
	else if (v1 > v2 && v1 > v3 && v2 > v3)
	{
		sa(stack);
		rra(stack);
	}
	else if (v1 < v2 && v1 < v3 && v2 > v3)
	{
		sa(stack);
		ra(stack);
	}				
}

void	sort_2(t_stack **stack)
{
	if ((*stack)->data > (*stack)->next->data)
		sa(stack);
}

void	sort_4(t_stack **stack_a, t_stack **stack_b)
{
	if (index_of(stack_a, min(stack_a)) <= (stack_size(stack_b) / 2 + 1))
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
}
