/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 01:57:50 by lrocca            #+#    #+#             */
/*   Updated: 2021/06/26 19:49:36 by lrocca           ###   ########.fr       */
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

static char	*cmd_pre(char *cmd)
{
	char	*ret;

	ret = ft_strtrim(cmd, " \t\v\f\r");
	free(cmd);
	return (ret);
}

static void	debug_lexer(t_cmd *head)
{
	t_list	*curr;

	if (!head)
		return (ft_putendl_fd("head == NULL", STDOUT_FILENO));
	while (head)
	{
		ft_putendl_fd(">>> av", STDOUT_FILENO);
		curr = head->av;
		while (curr)
		{
			ft_putendl_fd(curr->content, STDOUT_FILENO);
			curr = curr->next;
		}
		ft_putendl_fd(">>> in", STDOUT_FILENO);
		curr = head->in;
		while (curr)
		{
			ft_putendl_fd(curr->content, STDOUT_FILENO);
			curr = curr->next;
		}
		ft_putendl_fd(">>> out", STDOUT_FILENO);
		curr = head->out;
		while (curr)
		{
			ft_putendl_fd(curr->content, STDOUT_FILENO);
			curr = curr->next;
		}
		head = head->next;
	}
}

int	main(void)
{
	char	*line;
	t_cmd	*head;

	g_ms.env = NULL;
	g_ms.status = 0;
	// parse_env();
	while (1)
	{
		line = ft_prompt();
		line = cmd_pre(line);
		if (line == NULL)
		{
			ft_putchar_fd('\n', STDOUT_FILENO);
			return (0);
		}
		else if (ft_strlen(line) == 0)
		{
			g_ms.status = 0;
			continue ;
		}
		head = lexer(line);
		debug_lexer(head);
		// g_ms.status = cmd_exec(line);
	}
	return (0);
}
