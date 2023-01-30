/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:10:41 by mdenguir          #+#    #+#             */
/*   Updated: 2023/01/30 20:38:43 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **stack_a)
{
	int			tmp;
	t_stack		*tmp_stack;

	tmp_stack = NULL;
		tmp = ft_pop(stack_a);
	while (*stack_a)
		ft_push(&tmp_stack, ft_pop(stack_a));
	ft_push(stack_a, tmp);
	while (tmp_stack)
		ft_push(stack_a, ft_pop(&tmp_stack));
	write(1, "ra\n", 3);
}

void	rb(t_stack **stack_b)
{
	int			tmp;
	t_stack		*tmp_stack;

	tmp_stack = NULL;
	tmp = ft_pop(stack_b);
	while (*stack_b)
		ft_push(&tmp_stack, ft_pop(stack_b));
	ft_push(stack_b, tmp);
	while (tmp_stack)
		ft_push(stack_b, ft_pop(&tmp_stack));
	write(1, "rb\n", 3);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	int			tmp;
	t_stack		*tmp_stack;

	tmp_stack = NULL;
	tmp = ft_pop(stack_a);
	while (*stack_a)
		ft_push(&tmp_stack, ft_pop(stack_a));
	ft_push(stack_a, tmp);
	while (tmp_stack)
		ft_push(stack_a, ft_pop(&tmp_stack));
	tmp_stack = NULL;
	tmp = ft_pop(stack_b);
	while (*stack_b)
		ft_push(&tmp_stack, ft_pop(stack_b));
	ft_push(stack_b, tmp);
	while (tmp_stack)
		ft_push(stack_b, ft_pop(&tmp_stack));
	write(1, "rr\n", 3);
}
