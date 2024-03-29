/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 18:25:39 by mdenguir          #+#    #+#             */
/*   Updated: 2023/08/16 12:31:36 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*extract_word(char *input, int *index, int len)
{
	char	*word;
	int		i;

	if (len == 0)
		return (NULL);
	word = malloc (len + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (input[*index] && i < len)
	{
		word[i] = input[*index];
		i++;
		(*index)++;
	}
	word[i] = '\0';
	return (word);
}

int	add_back(t_elem **elem, t_elem *new)
{
	t_elem		*cursor;

	if (*elem == NULL)
	{
		*elem = new;
		return (1);
	}
	else
	{
		cursor = *elem;
		while (cursor->next)
			cursor = cursor->next;
		// new->prev = cursor;
		cursor->next = new;
		// free(new);
		return (1);
	}
}

int	check_dollar(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
			return (i);
		i++;
	}
	return (-1);
}

t_elem	*new_elem(char *content, int *index, int len, enum e_token token)
{
	t_elem	*new;
	char	*s;

	new = malloc(sizeof(t_elem));
	s = extract_word(content, index, len);
	if (!s)
		return (NULL);
	new->content = s;
	// free(s);
	new->len = len;
	new->next = NULL;
	// new->prev = NULL;
	new->type = token;
	new->state = NORMAL;
	return (new);
}