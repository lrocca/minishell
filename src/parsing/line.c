/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 03:40:49 by lrocca            #+#    #+#             */
/*   Updated: 2021/07/03 03:49:22 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handle_quotes(char **buff, char *quote, char new)
{
	if (!*quote)
		*quote = new;
	else if (*quote == new)
		*quote = 0;
	else
		char_to_buff(buff, new);
}

char	*line_to_word(const char *line, int *i)
{
	char	*buff;
	char	quote;

	buff = NULL;
	quote = 0;
	if (!line[*i])
		return (NULL);
	while (line[*i])
	{
		if (!buff && !quote && ft_isspace(line[*i]))
		{
			while (ft_isspace(line[*i]))
				(*i)++;
			continue ;
		}
		if (!quote && (ft_ismeta(line[*i]) || (buff && ft_isspace(line[*i]))))
			break ;
		else if (line[*i] == '\'' || line[*i] == '\"')
			handle_quotes(&buff, &quote, line[*i]);
		else if (line[*i] == '$' && quote != '\'')
			handle_dollar(&buff, line, i);
		else
			char_to_buff(&buff, line[*i]);
		(*i)++;
	}
	return (buff_to_word(&buff, quote));
}

char	*line_to_name(const char *line, int *i)
{
	char	*buff;

	buff = NULL;
	if (!line || !ft_isname_start(line[*i]))
		return (NULL);
	while (ft_isalnum(line[*i]) || line[*i] == '_')
		char_to_buff(&buff, line[(*i)++]);
	return (buff_to_word(&buff, 0));
}
