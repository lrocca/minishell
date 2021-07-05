/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 15:58:22 by lrocca            #+#    #+#             */
/*   Updated: 2021/07/06 00:19:15 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*find_bin(char *token, char **paths)
{
	int		i;
	char	*ret;

	i = 0;
	ret = NULL;
	token = ft_strjoin("/", token);
	while (paths[i])
	{
		free(ret);
		ret = ft_strjoin(paths[i], token);
		if (!access(ret, X_OK))
			break ;
		i++;
	}
	free(token);
	if (!paths[i])
	{
		free(ret);
		return (NULL);
	}
	return (ret);
}

int	cmd_exec_from_path(t_list *av)
{
	char	**argv;
	char	**envp;
	char	*bin;
	char	**paths;

	if (ft_paths(&paths, PATHS_GET) < 0)
	{
		ft_error("missing PATH in env");
		return (1);
	}
	if (ft_strchr(av->content, '/'))
		bin = av->content;
	else
		bin = find_bin(av->content, paths);
	if (!bin)
	{
		ft_error("command not found");
		return (127);
	}
	argv = list_to_array(av);
	envp = list_to_array(g_ms.env);
	execve(bin, argv, envp);
	ft_error(strerror(errno));
	return (errno);
}

char	ms_builtin(t_cmd *cmd)
{
	if (ft_strchr(cmd->av->content, '='))
		;
	else if (!ft_strcmp(cmd->av->content, "cd"))
		g_ms.status = builtin_cd(cmd->av);
	else if (!ft_strcmp(cmd->av->content, "pwd"))
		g_ms.status = builtin_pwd();
	else if (!ft_strcmp(cmd->av->content, "env"))
		g_ms.status = builtin_env();
	else if (!ft_strcmp(cmd->av->content, "echo"))
		g_ms.status = builtin_echo(cmd->av);
	else if (!ft_strcmp(cmd->av->content, "exit"))
		g_ms.status = builtin_exit(cmd->av);
	else if (!ft_strcmp(cmd->av->content, "unset"))
		g_ms.status = builtin_unset(cmd->av);
	else if (!ft_strcmp(cmd->av->content, "export"))
		g_ms.status = builtin_export(cmd->av);
	else
		return (0);
	return (1);
}

void	ms_single_builtin(t_cmd *cmd)
{
	int	old_stdin;
	int	old_stdout;

	if (ms_setfd(cmd))
		return ;
	old_stdin = dup(STDIN_FILENO);
	old_stdout = dup(STDOUT_FILENO);
	if ((cmd->fdin != STDIN_FILENO && dup2(cmd->fdin, STDIN_FILENO) < 0) \
	|| (cmd->fdout != STDOUT_FILENO && dup2(cmd->fdout, STDOUT_FILENO) < 0))
		return ((void)ft_error(strerror(errno)));
	ms_builtin(cmd);
	close(cmd->fdin);
	close(cmd->fdout);
	dup2(old_stdin, STDIN_FILENO);
	dup2(old_stdout, STDOUT_FILENO);
}
