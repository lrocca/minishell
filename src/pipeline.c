/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 23:30:05 by lrocca            #+#    #+#             */
/*   Updated: 2021/07/08 06:37:09 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ms_child(t_cmd *cmd)
{
	if (cmd->av)
	{
		g_ms.childpid = fork();
		if (g_ms.childpid < 0)
			ft_error("fork", strerror(errno));
		else if (g_ms.childpid == 0)
		{
			if (dup2(cmd->fdin, STDIN_FILENO) < 0 \
				|| dup2(cmd->fdout, STDOUT_FILENO) < 0)
				ft_error("dup2", strerror(errno));
			if (!ms_builtin(cmd))
				g_ms.status = cmd_exec_from_path(cmd->av);
			exit(g_ms.status);
		}
		else
			waitpid(g_ms.childpid, &g_ms.status, 0);
	}
	if (cmd->fdin != STDIN_FILENO)
		close(cmd->fdin);
	if (cmd->fdout != STDOUT_FILENO)
		close(cmd->fdout);
}

void	ms_pipeline(void)
{
	t_cmd	*cmd;

	ft_cmd(&cmd, CMD_GET);
	if (!cmd)
	{
		g_ms.status = ERR_SYNTAX;
		return ;
	}
	if (!cmd->next && cmd->av && ft_isbuiltin(cmd->av->content))
		return (ms_single_builtin(cmd));
	while (cmd)
	{
		if (ms_setfd(cmd) == 0)
			ms_child(cmd);
		cmd = cmd->next;
	}
}
