/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 20:12:30 by lrocca            #+#    #+#             */
/*   Updated: 2021/07/03 03:34:52 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	set_redir_type(const char c1, const char c2)
{
	char	type;

	type = c1;
	if (c2 == c1)
		type += c2;
	return (type);
}

static t_redir	*ft_redirnew(char *word, char type)
{
	t_redir	*new;

	new = malloc(sizeof(t_redir));
	new->value = word;
	new->type = type;
	new->next = NULL;
	return (new);
}

void	ft_rediradd_back(t_cmd **head, t_redir *new, char type)
{
	t_cmd	*cmd;
	t_redir	*last;

	if (!*head)
	{
		cmd = ft_cmdnew();
		*head = cmd;
	}
	else
		cmd = ft_cmdlast(*head);
	if (type % '<' == 0 && !cmd->in)
		cmd->in = new;
	else if (type % '>' == 0 && !cmd->out)
		cmd->out = new;
	else
	{
		if (type % '<' == 0)
			last = cmd->in;
		else
			last = cmd->out;
		while (last && last->next)
			last = last->next;
		last->next = new;
	}
}

int	handle_redir(t_cmd **head, const char *line, int *i)
{
	char	type;
	char	*word;
	t_redir	*new;

	type = set_redir_type(line[*i], line[*i + 1]);
	*i += 1 + (type > '>');
	word = line_to_word(line, i);
	if (!word)
		return (-1);
	new = ft_redirnew(word, type > '>');
	ft_rediradd_back(head, new, type);
	return (0);
}
