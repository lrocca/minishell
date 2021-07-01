/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 01:57:50 by lrocca            #+#    #+#             */
/*   Updated: 2021/07/01 04:13:55 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(void)
{
	char	*line;
	t_cmd	*head;

	init_env();
	g_ms.status = 0;
	while (1)
	{
		line = ft_prompt();
		if (line == NULL)
			break ;
		else if (ft_strlen(line) == 0)
			continue ;
		add_history(line);
		head = lexer(line);
		if (!head)
			g_ms.status = ERR_SYNTAX;
		else
			cmd_exec(head);
		// free cmd
	}
	ft_paths(NULL, PATHS_FREE);
	builtin_exit(NULL);
	return (g_ms.status);
}
