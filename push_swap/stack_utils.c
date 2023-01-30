/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:09:04 by mdenguir          #+#    #+#             */
/*   Updated: 2023/01/30 21:55:32 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_under_5(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_size(stack_a) == 2)
		sort_2(stack_a);
	else if (stack_size(stack_a) == 3)
		sort_3(stack_a);
	else if (stack_size(stack_a) == 4)
		sort_4(stack_a, stack_b);
	else if (stack_size(stack_a) == 5)
		sort_5(stack_a, stack_b);
}

void	ft_push(t_stack **stack, int value)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	new_node->data = value;
	new_node->next = *stack;
	*stack = new_node;
}

int	stack_size(t_stack **stack)
{
	int		count;
	t_stack	*current;

	count = 0;
	current = *stack;
	while (current)
	{
		count++;
		current = current->next;
	}
	return (count);
}

int	ft_pop(t_stack **stack)
{
	t_stack	*tmp;
	int		val;

	val = (*stack)->data;
	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);
	return (val);
}

int	ft_strlen(char *s)
{
	int		i;

	i = 0;
	if (!s || !*s)
		return (0);
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
