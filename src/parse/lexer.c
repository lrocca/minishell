/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 03:12:19 by lrocca            #+#    #+#             */
/*   Updated: 2021/06/27 04:23:39 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

#define BUFFER_SIZE 64

static char	*new_buff(char *buff)
{
	char	*new;
	size_t	len;

	if (!buff)
		buff = ft_strdup("");
	len = ft_strlen(buff) + BUFFER_SIZE;
	new = malloc(len);
	ft_bzero(new, len);
	ft_strlcpy(new, buff, len);
	free(buff);
	return (new);
}

static void	char_to_buff(char **buff, char new)
{
	size_t	len;

	len = ft_strlen(*buff);
	if (len == 0 || (len + 1) % BUFFER_SIZE == 0)
		*buff = new_buff(*buff);
	(*buff)[len] = new;
}

static char	*buff_to_word(char **buff, char quote)
{
	char	*word;

	if (quote && *buff)
	{
		free(*buff);
		*buff = NULL;
		// maybe throw unclosed quote error
	}
	if (!*buff)
		return (NULL);
	word = ft_strdup(*buff);
	free(*buff);
	*buff = NULL;
	return (word);
}

void	word_to_av(t_cmd **head, char *word)
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
			; // expand variable
		else
			char_to_buff(&buff, line[*i]);
		(*i)++;
	}
	return (buff_to_word(&buff, quote));
}

t_cmd	*lexer(const char *line)
{
	int		i;
	t_cmd	*head;
	char	*word;

	i = 0;
	head = NULL;
	while (1)
	{
		word = line_to_word(line, &i);
		if (!word)
		{
			if (!line[i])
				break ;
			else if (line[i] == '|')
			{
				if (!head)
				{
					ft_error("syntax error (pipe left)");
					return (NULL);
				}
				i++;
				word = line_to_word(line, &i);
				if (!word)
				{
					ft_error("syntax error (pipe right)");
					return (NULL);
				}
				ft_cmdadd_back(&head, ft_cmdnew());
				word_to_av(&head, word);
			}
			else
				if (handle_redir(&head, line, &i) == -1)
				{
					ft_error("syntax error (redirection)");
					return (NULL);
				}
		}
		else
			word_to_av(&head, word);
	}
	return (head);
}

// parser
// {
// 	if token contains equal sign & bin == NULL
// 		ignore
// 	elif redirection
// 		set filename/delimiter & options
// 	elif bin == NULL
// 		bin = builtin or find path for token
// 	elif av == NULL
// 		ERROR!
// }

// main
// {
// 	line = prompt
// 	fork
// 		...child
// 		lexer
// 		parser
// 		fd
// 		if pipe
// 			pipe
// 			fork again
// 		find exec
// 		exec
// }
