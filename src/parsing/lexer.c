/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 03:12:19 by lrocca            #+#    #+#             */
/*   Updated: 2021/07/08 07:35:39 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	lexer_error(const char c)
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
	ft_cmd(NULL, CMD_FREE);
	return (-1);
}

void	word_to_av(char *word)
{
	t_cmd	*cmd;

	ft_cmd(&cmd, CMD_GET);
	if (!cmd)
	{
		cmd = ft_cmdnew();
		ft_cmd(&cmd, CMD_SET);
	}
	else
		cmd = ft_cmdlast(cmd);
	ft_lstadd_back(&cmd->av, ft_lstnew(word));
}

static char	handle_pipe(const char *line, int *i)
{
	char	*word;
	t_cmd	*head;

	if (ft_cmd(&head, CMD_GET) || !head)
		return (lexer_error(line[*i]));
	(*i)++;
	word = line_to_word(line, i, WILDCARD_DISABLED);
	if (!word && !line[*i])
		return (lexer_error(line[*i]));
	ft_cmdadd_back(ft_cmdnew());
	if (word)
		word_to_av(word);
	else if (line[*i] == '<' || line[*i] == '>')
		if (handle_redir(line, i) < 0)
			return (-1);
	return (0);
}

void	ms_lexer(const char *line)
{
	int		i;
	char	*word;

	i = 0;
	word = line_to_word(line, &i, WILDCARD_DISABLED);
	while (1)
	{
		if (word)
			word_to_av(word);
		else if (!line[i])
			break ;
		else if (line[i] == '|')
		{
			if (handle_pipe(line, &i) == -1)
				return ;
		}
		else if (handle_redir(line, &i) == -1)
			return ((void)lexer_error(line[i]));
		word = line_to_word(line, &i, WILDCARD_ENABLED);
	}
}
