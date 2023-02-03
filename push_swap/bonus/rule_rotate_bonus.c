/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_rotate_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:10:41 by mdenguir          #+#    #+#             */
/*   Updated: 2023/01/31 19:13:34 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_ra(t_stack **stack_a)
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
}

void	ft_rb(t_stack **stack_b)
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
}

void	ft_rr(t_stack **stack_a, t_stack **stack_b)
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
}
