/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 01:57:50 by lrocca            #+#    #+#             */
/*   Updated: 2021/06/24 20:48:48 by lrocca           ###   ########.fr       */
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

int	main(void)
{
	char	*cmd;

	g_ms.env = NULL;
	g_ms.status = 0;
	// parse_env();
	while (1)
	{
		cmd = ft_prompt();
		cmd = cmd_pre(cmd);
		if (cmd == NULL)
		{
			ft_putchar_fd('\n', STDOUT_FILENO);
			return (0);
		}
		else if (ft_strlen(cmd) == 0)
		{
			g_ms.status = 0;
			continue ;
		}
		g_ms.status = cmd_exec(cmd);
	}
	return (0);
}
