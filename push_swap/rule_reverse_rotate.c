/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_reverse_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:11:44 by mdenguir          #+#    #+#             */
/*   Updated: 2023/01/30 20:39:49 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **stack_a)
{
	int			tmp;
	t_stack		*tmp_stack;

	tmp_stack = NULL;
	while ((*stack_a)->next)
		ft_push(&tmp_stack, ft_pop(stack_a));
	tmp = ft_pop(stack_a);
	while (tmp_stack)
		ft_push(stack_a, ft_pop(&tmp_stack));
	ft_push(stack_a, tmp);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **stack_b)
{
	int			tmp;
	t_stack		*tmp_stack;

	tmp_stack = NULL;
	while ((*stack_b)->next)
		ft_push(&tmp_stack, ft_pop(stack_b));
	tmp = ft_pop(stack_b);
	while (tmp_stack)
		ft_push(stack_b, ft_pop(&tmp_stack));
	ft_push(stack_b, tmp);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	int			tmp;
	t_stack		*tmp_stack;

	tmp_stack = NULL;
	while ((*stack_a)->next)
		ft_push(&tmp_stack, ft_pop(stack_a));
	tmp = ft_pop(stack_a);
	while (tmp_stack)
		ft_push(stack_a, ft_pop(&tmp_stack));
	ft_push(stack_a, tmp);
	tmp_stack = NULL;
	while ((*stack_b)->next)
		ft_push(&tmp_stack, ft_pop(stack_b));
	tmp = ft_pop(stack_b);
	while (tmp_stack)
		ft_push(stack_b, ft_pop(&tmp_stack));
	ft_push(stack_b, tmp);
	write(1, "rrr\n", 4);
}
