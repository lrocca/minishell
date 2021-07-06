/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 03:12:19 by lrocca            #+#    #+#             */
/*   Updated: 2021/07/06 03:09:14 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_cmd	*lexer_error(t_cmd *head, const char c)
{
	char	near[3];
	char	*error;
	char	*syntax;

	syntax = ft_strdup("syntax error near unexpected token `");
	if (!c)
		error = ft_strjoin(syntax, "newline\'");
	else
	{
		near[0] = c;
		near[1] = '\'';
		near[2] = '\0';
		error = ft_strjoin(syntax, near);
	}
	ft_error(error, NULL);
	free(syntax);
	free(error);
	ft_cmdclear(head);
	return (NULL);
}

static void	word_to_av(t_cmd **head, char *word)
{
	t_cmd	*cmd;

	if (!*head)
	{
		cmd = ft_cmdnew();
		*head = cmd;
	}
	else
		cmd = ft_cmdlast(*head);
	ft_lstadd_back(&cmd->av, ft_lstnew(word));
}

static char	handle_pipe(t_cmd **head, const char *line, int *i)
{
	char	*word;

	if (!head)
	{
		lexer_error(*head, line[*i]);
		return (-1);
	}
	i++;
	word = line_to_word(line, i);
	if (!word)
	{
		lexer_error(*head, line[*i]);
		return (-1);
	}
	ft_cmdadd_back(head, ft_cmdnew());
	word_to_av(head, word);
	return (0);
}

t_cmd	*ms_lexer(const char *line)
{
	int		i;
	t_cmd	*head;
	char	*word;

	i = 0;
	head = NULL;
	while (1)
	{
		word = line_to_word(line, &i);
		if (word)
		{
			word_to_av(&head, word);
			continue ;
		}
		if (!line[i])
			break ;
		else if (line[i] == '|')
		{
			if (handle_pipe(&head, line, &i) != 0)
				return (NULL);
		}
		else if (handle_redir(&head, line, &i) == -1)
			return (lexer_error(head, line[i]));
	}
	return (head);
}
