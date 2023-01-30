/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 12:05:48 by mdenguir          #+#    #+#             */
/*   Updated: 2023/01/30 21:56:24 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_moves(t_stack **stack_a, t_stack **stack_b, int data)
{
	int			count;
	t_actions	*actions;

	count = 0;
	actions = get_moves(data, stack_a, stack_b);
	count = moves_communes(actions);
	return (count);
}

int	moves_communes(t_actions *actions)
{
	int		count;

	count = 0;
	count_ra_rb(actions->ra, actions->rb, &count);
	count_rra_rrb(actions->rra, actions->rrb, &count);
	free(actions);
	return (count);
}

void	count_ra_rb(int ra, int rb, int *count)
{
	if (ra == rb)
	{
		while (ra--)
			(*count)++;
		rb = 0;
	}
	else if (ra > rb)
	{
		ra -= rb;
		while (rb--)
			(*count)++;
		while (ra--)
			(*count)++;
	}
	else
	{
		rb -= ra;
		while (ra--)
			(*count)++;
		while (rb--)
			(*count)++;
	}
}

void	count_rra_rrb(int rra, int rrb, int *count)
{
	if (rra == rrb)
	{
		while (rra--)
			(*count)++;
		rrb = 0;
	}
	else if (rra > rrb)
	{
		rra -= rrb;
		while (rrb--)
			(*count)++;
		while (rra--)
			(*count)++;
	}
	else
	{
		rrb -= rra;
		while (rra--)
			(*count)++;
		while (rrb--)
			(*count)++;
	}
}
