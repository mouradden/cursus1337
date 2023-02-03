/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:37:10 by mdenguir          #+#    #+#             */
/*   Updated: 2023/02/03 12:10:31 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	is_valid(char *str)
{
	if (my_strcmp(str, "pa\n") && my_strcmp(str, "pb\n") && my_strcmp(str, "ra\n")
		&& my_strcmp(str, "rb\n") && my_strcmp(str, "rr\n")
		&& my_strcmp(str, "rra\n") && my_strcmp(str, "rrb\n")
		&& my_strcmp(str, "rrr\n") && my_strcmp(str, "sa\n")
		&& my_strcmp(str, "sb\n") && my_strcmp(str, "ss\n"))
		return (0);
	return (1);
}

void	fill_stack(char **args, t_stack **sa)
{
	int		count;

	count = 0;
	while (args[count])
		count++;
	count--;
	while (count >= 0)
		ft_push(sa, ft_atoi(args[count--]));
	free_split(args);
}

void	action_stack(char *rule, t_stack **stack_a, t_stack **stack_b)
{
	if (!my_strcmp(rule, "pa\n"))
		ft_pa(stack_b, stack_a);
	else if (!my_strcmp(rule, "pb\n"))
		ft_pb(stack_a, stack_b);
	else if (!my_strcmp(rule, "sa\n"))
		ft_sa(stack_a);
	else if (!my_strcmp(rule, "sb\n"))
		ft_sb(stack_b);
	else if (!my_strcmp(rule, "ra\n"))
		ft_ra(stack_a);
	else if (!my_strcmp(rule, "rb\n"))
		ft_rb(stack_b);
	else if (!my_strcmp(rule, "rr\n"))
		ft_rr(stack_a, stack_b);
	else if (!my_strcmp(rule, "rra\n"))
		ft_rra(stack_a);
	else if (!my_strcmp(rule, "rrb\n"))
		ft_rrb(stack_b);
	else if (!my_strcmp(rule, "rrr\n"))
		ft_rrr(stack_a, stack_b);
}

void	check_and_action(char *string, t_stack **sa, t_stack **sb)
{
	if (!is_valid(string))
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	action_stack(string, sa, sb);
	free(string);
}

int	main(int ac, char **av)
{
	t_stack		*sa;
	t_stack		*sb;
	char		*join;
	char		**args;

	join = NULL;
	sa = NULL;
	sb = NULL;
	if (ac == 1)
		exit(0);
	args = get_args(av, join);
	are_args_valid(args);
	fill_stack(args, &sa);
	while (1)
	{
		join = get_next_line(0);
		if (!join)
			break ;
		check_and_action(join, &sa, &sb);
	}
	if (check_sorted(&sa) && !stack_size(&sb))
		write(1, "OK\n", 3);
	else
		write(2, "KO\n", 3);
	free_stack(&sa);
	free_stack(&sb);
}
