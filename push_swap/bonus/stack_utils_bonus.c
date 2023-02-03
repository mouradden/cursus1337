/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:03:44 by mdenguir          #+#    #+#             */
/*   Updated: 2023/01/31 20:34:58 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

int	my_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		++i;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	my_strlen(char *s)
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
