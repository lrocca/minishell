/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 01:57:50 by lrocca            #+#    #+#             */
/*   Updated: 2021/06/27 04:17:37 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

// static void	parse_env(void)
// {
// 	extern char	**environ;
// 	int			i;
// 	t_var		*new;
// 	t_var		*curr;
// 	char		**split;

// 	i = 0;
// 	while (environ[i])
// 	{
// 		split = ft_split(environ[i], '=');
// 		if (!split || !split[0])
// 			ft_error("env split failed");
// 		new = malloc(sizeof(t_var));
// 		if (!new)
// 			ft_error("var allocation failed");
// 		new->name = split[0];
// 		new->next = NULL;
// 		if (split[1])
// 			new->value = split[1];
// 		else
// 			new->value = ft_strdup("");
// 		curr = g_ms.env;
// 		while (curr->next)
// 			curr = curr->next;
// 		curr->next = new;
// 		i++;
// 	}
// }

static void	debug_lexer(t_cmd *head)
{
	t_list	*curr;
	t_redir	*curr2;

	if (!head)
		return (ft_putendl_fd("head == NULL", STDOUT_FILENO));
	while (head)
	{
		ft_putendl_fd(">>> av", STDOUT_FILENO);
		curr = head->av;
		while (curr)
		{
			ft_putchar_fd('|', STDOUT_FILENO);
			ft_putstr_fd(curr->content, STDOUT_FILENO);
			ft_putendl_fd("|", STDOUT_FILENO);
			curr = curr->next;
		}
		ft_putendl_fd(">>> in", STDOUT_FILENO);
		curr2 = head->in;
		while (curr2)
		{
			ft_putchar_fd('|', STDOUT_FILENO);
			ft_putstr_fd(curr2->value, STDOUT_FILENO);
			ft_putendl_fd("|", STDOUT_FILENO);
			curr2 = curr2->next;
		}
		ft_putendl_fd(">>> out", STDOUT_FILENO);
		curr2 = head->out;
		while (curr2)
		{
			ft_putchar_fd('|', STDOUT_FILENO);
			ft_putstr_fd(curr2->value, STDOUT_FILENO);
			ft_putendl_fd("|", STDOUT_FILENO);
			curr2 = curr2->next;
		}
		head = head->next;
	}
}

int	main(void)
{
	char	*line;
	t_cmd	*head;
	int		status;

	// parse_env();
	status = 0;
	while (1)
	{
		line = ft_prompt(status);
		if (line == NULL)
		{
			ft_putendl_fd("\b\bexit", STDOUT_FILENO);
			break ;
		}
		else if (ft_strlen(line) == 0)
			continue ;
		head = lexer(line);
		if (!head)
			status = 258;
		else
			status = 0;
		debug_lexer(head);
		// g_ms.status = cmd_exec(line);
	}
	return (status);
}
