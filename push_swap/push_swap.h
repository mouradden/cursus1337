/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:41:05 by mdenguir          #+#    #+#             */
/*   Updated: 2023/01/31 17:38:59 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}	t_stack;

typedef struct s_position
{
	int		idx;
	t_stack	*node;
}	t_position;

typedef struct s_actions
{
	int		ra;
	int		rra;
	int		rb;
	int		rrb;
}	t_actions;

int			check_sorted(t_stack **stack);
void		sort_3(t_stack **stack);
void		ft_push(t_stack **stack, int value);
int			ft_pop(t_stack **stack);
int			stack_size(t_stack **stack);
void		sa(t_stack **stack_a);
void		sb(t_stack **stack_b);
void		ss(t_stack **stack_a, t_stack **stack_b);
void		pa(t_stack **stack_a, t_stack **stack_b);
void		pb(t_stack **stack_b, t_stack **stack_a);
void		ra(t_stack **stack_a);
void		rb(t_stack **stack_b);
void		rr(t_stack **stack_a, t_stack **t_stack_b);
void		rra(t_stack **stack_a);
void		rrb(t_stack **stack_b);
void		rrr(t_stack **stack_a, t_stack **stack_b);
void		sort_3(t_stack **stack);
void		sort_5(t_stack **stack_a, t_stack **stack_b);
void		sort_2(t_stack **stack);
int			index_of(t_stack **stack, int v);
int			near_to(t_stack **stack, int v);
int			min(t_stack **stack);
int			max(t_stack **stack);
void		sort_4(t_stack **stack_a, t_stack **stack_b);

void		shift_up_b(t_stack **stack, int data);
t_position	*optimal(t_stack **stack_a, t_stack **stack_b);

int			count_words(char *s, char c);
int			len_word(char *s, char c);
char		**ft_split(char *s, char c);

int			my_strlen(char *s);
char		*my_strjoin(char *s1, char *s2);

long		ft_atoi(char *str);

void		move(t_stack **stack_a, t_stack **stack_b, t_actions *actions);
int			count_moves(t_stack **stack_a, t_stack **stack_b, int data);
t_actions	*get_moves(int data, t_stack **stack_a, t_stack **stack_b);
int			moves_communes(t_actions *actions);
void		count_ra_rb(int ra, int rb, int *count);
void		count_rra_rrb(int rra, int rrb, int *count);
void		move_rrr(int a, int b, t_stack **stack_a, t_stack **stack_b);
void		move_rr(int a, int b, t_stack **stack_a, t_stack **stack_b);

void		free_split(char **str);
void		free_stack(t_stack **s);

int			check_duplicate(char **args);
int			check_args(char **av);
char		**get_args(char **av, char *join);
void		are_args_valid(char **args);
void		fill_and_check_sorted(char **args, t_stack **sa);
int			check_empty(char *str);
void		push_swap_under_5(t_stack **stack_a, t_stack **stack_b);
#endif