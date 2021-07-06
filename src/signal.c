/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 19:00:25 by lrocca            #+#    #+#             */
/*   Updated: 2021/07/06 00:36:44 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_sigint(int signum)
{
	(void)signum;
	if (g_ms.childpid)
	{
		if (kill(g_ms.childpid, SIGINT) < 0)
			ft_error("kill", strerror(errno));
		else
			g_ms.status = 130;
	}
	else
		g_ms.status = 1;
	ft_putchar_fd('\n', STDOUT_FILENO);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}
