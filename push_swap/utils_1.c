/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 12:15:46 by mdenguir          #+#    #+#             */
/*   Updated: 2023/01/30 20:21:17 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min(t_stack **stack)
{
	t_stack		*current;
	int			min;

	current = *stack;
	min = current->data;
	while (current)
	{
		if (current->data < min)
			min = current->data;
		current = current->next;
	}
	return (min);
}

int	max(t_stack **stack)
{
	t_stack		*current;
	int			max;

	current = *stack;
	max = current->data;
	while (current)
	{
		if (current->data > max)
			max = current->data;
		current = current->next;
	}
	return (max);
}

int	index_of(t_stack **stack, int v)
{
	t_stack		*current;
	int			count;

	current = *stack;
	count = 1;
	while (current)
	{
		if (current->data != v)
			count++;
		else
			break ;
		current = current->next;
	}
	return (count);
}

int	near_to(t_stack **stack, int v)
{
	t_stack		*current;
	int			n;

	n = 0;
	current = *stack;
	while (current)
	{
		if (current->data < v)
		{
			n = current->data;
			while (current)
			{
				if (current->data > n && current->data < v)
					n = current->data;
				current = current->next;
			}
			return (n);
		}
		current = current->next;
	}
	return (max(stack));
}

void	shift_up_b(t_stack **stack, int data)
{
	if (index_of(stack, data) <= (stack_size(stack) / 2 + 1))
	{
		while (data != (*stack)->data)
			rb(stack);
	}
	else
	{
		while (data != (*stack)->data)
			rrb(stack);
	}
}
