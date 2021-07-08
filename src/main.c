/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 01:57:50 by lrocca            #+#    #+#             */
/*   Updated: 2021/07/08 06:36:58 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ms_loop(void)
{
	char	*line;

	while (1)
	{
		line = ft_prompt();
		if (line == NULL)
			break ;
		else if (ft_strlen(line) == 0)
			continue ;
		add_history(line);
		ms_lexer(line);
		ms_pipeline();
		ft_cmd(NULL, CMD_FREE);
		g_ms.childpid = 0;
	}
}

int	main(void)
{
	if (RL_READLINE_VERSION < 0x0800)
		ft_putendl_fd("minishell: old `readline\' version", STDOUT_FILENO);
	g_ms.status = 0;
	g_ms.childpid = 0;
	init_env();
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, handle_sigint);
	ms_loop();
	builtin_exit(NULL);
	return (g_ms.status);
}
