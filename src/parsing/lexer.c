/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 03:12:19 by lrocca            #+#    #+#             */
/*   Updated: 2021/07/03 03:49:13 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
		if (!word)
		{
			if (!line[i])
				break ;
			else if (line[i] == '|')
			{
				if (!head)
				{
					ft_error("syntax error (pipe left)");
					ft_cmdclear(head);
					return (NULL);
				}
				i++;
				word = line_to_word(line, &i);
				if (!word)
				{
					ft_error("syntax error (pipe right)");
					ft_cmdclear(head);
					return (NULL);
				}
				ft_cmdadd_back(&head, ft_cmdnew());
				word_to_av(&head, word);
			}
			else
				if (handle_redir(&head, line, &i) == -1)
				{
					ft_error("syntax error (redirection)");
					ft_cmdclear(head);
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
