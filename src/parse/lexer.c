/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 03:12:19 by lrocca            #+#    #+#             */
/*   Updated: 2021/06/27 00:46:19 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

#define BUFFER_SIZE 256

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

static void	buff_to_word(t_cmd **head, char **buff)
{
	t_cmd	*curr;

	if (!*buff)
		return ;
	if (!*head)
		*head = ft_cmdnew();
	curr = ft_cmdlast(*head);
	ft_lstadd_back(&(curr->av), ft_lstnew(*buff));
	*buff = NULL;
}

int	get_word(const char *line, char **buff, int i, char *quote)
{
	while (line[i] && !ft_ismeta(line[i]))
	{
		if (line[i] == '$')
		{
			if (*quote == '\'')
				char_to_buff(buff, line[i]);
			else
				;
				// expand variable
		}
		else if (line[i] == '\'' || line[i] == '\"')
		{
			if (*quote == line[i])
				*quote = 0;
			else if (!*quote)
				*quote = line[i];
			else
				char_to_buff(buff, line[i]);
		}
		else
			char_to_buff(buff, line[i]);
		i++;
	}
	if (line[i] != '\0')
		i--;
	return (i);
}

void	handle_quotes(char **buff, char *quote, char new)
{
	if (!*quote)
		*quote = new;
	else if (*quote == new)
		*quote = 0;
	else
		char_to_buff(buff, new);
}

char	*line_to_word(const char *line)
{
	static int	i = 0;
	char		*buff;
	char		quote;

	buff = NULL;
	quote = 0;
	if (!line[i])
		return (NULL);
	while (line[i])
	{
		if (ft_ismeta(line[i]) && !quote)
			break ;
		if (line[i] == '\'' || line[i] == '\"')
			handle_quotes(&buff, &quote, line[i]);
		else if (ft_ismeta(line[i]))
			char_to_buff(&buff, line[i]);
		else if ()
	}
	if (quote && buff)
	{
		free(buff);
		buff = NULL;
	}
	return (buff);
}

t_cmd	*lexer(const char *line)
{
	int		i;
	char	*buff;
	t_cmd	*head;
	char	quote;
	char	redir;

	i = 0;
	quote = 0;
	redir = 0;
	buff = NULL;
	head = NULL;
	while (line[i])
	{
		if (quote)
		{

		}
		else
		{
			if (line[i] == '|')
			{
				i++;
				while (line[i] && ft_isspace(line[i + 1]))
					i++;
				if (line[i] == '\0')
					ft_error("syntax error (pipe right)");
				else
				{
					buff_to_word(&head, &buff);
					if (!head)
						ft_error("syntax error (pipe left)");
					else
						ft_cmdadd_back(&head, ft_cmdnew());
				}
			}
			else if (line[i] == '<' || line[i] == '>')
			{
				if (quote)
					char_to_buff(&buff, line[i]);
				else
				{
					buff_to_word(&head, &buff);
					i += parse_redirection(line, &buff, &quote, head);
				}
			}
			else if (ft_isspace(line[i]))
			{
				if (quote)
					char_to_buff(&buff, line[i]);
				else
					buff_to_word(&head, &buff);
			}
			else
				i = get_word(line, &buff, i, &quote);
		}
		i++;
	}
	if (quote)
	{
		free(buff);
		buff = NULL;
	}
	buff_to_word(&head, &buff);
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
