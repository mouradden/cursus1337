/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:38:01 by mdenguir          #+#    #+#             */
/*   Updated: 2023/01/30 21:56:10 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_position	*optimal(t_stack **stack_a, t_stack **stack_b)
{
	t_stack		*current;
	t_position	*pos;
	int			count;

	pos = malloc(sizeof(t_position));
	pos->idx = 2147483647;
	pos->node = NULL;
	if (!stack_a)
	{
		pos->node = NULL;
		return (pos);
	}
	current = *stack_a;
	while (current)
	{
		count = 0;
		count = count_moves(stack_a, stack_b, current->data);
		if (pos->idx > count)
		{
			pos->idx = count;
			pos->node = current;
		}
		current = current->next;
	}
	return (pos);
}

t_actions	*get_moves(int data, t_stack **stack_a, t_stack **stack_b)
{
	t_actions	*actions;
	int			near;

	actions = malloc(sizeof(t_actions));
	actions->ra = 0;
	actions->rb = 0;
	actions->rra = 0;
	actions->rrb = 0;
	near = index_of(stack_b, near_to(stack_b, data));
	if (index_of(stack_a, data) <= (stack_size(stack_a) / 2 + 1))
			actions->ra = index_of(stack_a, data) - 1;
	else
			actions->rra = stack_size(stack_a) - index_of(stack_a, data) + 1;
	if (near <= (stack_size(stack_b) / 2 + 1))
			actions->rb = index_of(stack_b, near_to(stack_b, data)) - 1;
	else
			actions->rrb = stack_size(stack_b) - near + 1;
	return (actions);
}

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	t_actions	*actions;
	t_position	*pos;
	int			len;

	len = stack_size(stack_a);
	if (len <= 5)
		push_swap_under_5(stack_a, stack_b);
	else
	{
		pb(stack_a, stack_b);
		len = stack_size(stack_a);
		while (len)
		{
			pos = optimal(stack_a, stack_b);
			actions = get_moves(pos->node->data, stack_a, stack_b);
			move(stack_a, stack_b, actions);
			pb(stack_a, stack_b);
			len--;
			free(pos);
			free(actions);
		}
		shift_up_b(stack_b, max(stack_b));
		while (*stack_b)
			pa(stack_b, stack_a);
	}
}

int	check_sorted(t_stack **stack)
{
	t_stack		*current;

	current = *stack;
	while (current->next)
	{
		if (current->data > current->next->data)
			return (0);
		current = current->next;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_stack		*sa;
	t_stack		*sb;
	char		*join;
	char		**args;

	sa = NULL;
	sb = NULL;
	join = NULL;
	args = NULL;
	if (ac == 1)
		exit(0);
	args = get_args(av, join);
	are_args_valid(args);
	fill_and_check_sorted(args, &sa);
	push_swap(&sa, &sb);
	free_stack(&sa);
}
