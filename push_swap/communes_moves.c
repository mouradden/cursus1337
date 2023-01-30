/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   communes_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:48:59 by mdenguir          #+#    #+#             */
/*   Updated: 2023/01/30 21:57:05 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_rr(int a, int b, t_stack **stack_a, t_stack **stack_b)
{
	if (a == b)
	{
		while (a--)
			rr(stack_a, stack_b);
		b = 0;
	}
	else if (a > b)
	{
		a -= b;
		while (b--)
			rr(stack_a, stack_b);
		while (a--)
			ra(stack_a);
	}
	else
	{
		b -= a;
		while (a--)
			rr(stack_a, stack_b);
		while (b--)
			rb(stack_b);
	}
}

void	move_rrr(int a, int b, t_stack **stack_a, t_stack **stack_b)
{
	if (a == b)
	{
		while (a--)
			rrr(stack_a, stack_b);
		b = 0;
	}
	else if (a > b)
	{
		a -= b;
		while (b--)
			rrr(stack_a, stack_b);
		while (a--)
			rra(stack_a);
	}
	else
	{
		b -= a;
		while (a--)
			rrr(stack_a, stack_b);
		while (b--)
			rrb(stack_b);
	}
}

void	move(t_stack **stack_a, t_stack **stack_b, t_actions *actions)
{
	move_rr(actions->ra, actions->rb, stack_a, stack_b);
	move_rrr(actions->rra, actions->rrb, stack_a, stack_b);
}
