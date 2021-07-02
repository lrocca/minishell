/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 15:58:22 by lrocca            #+#    #+#             */
/*   Updated: 2021/07/02 19:52:47 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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
	bin = find_bin(av->content, paths);
	if (!bin)
	{
		ft_error("command not found");
		return (127);
	}
	argv = list_to_array(av);
	envp = list_to_array(g_ms.env);
	execve(bin, argv, envp);
	return (0);
}

void	ms_exec(t_cmd *cmd)
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
		g_ms.status = cmd_exec_from_path(cmd->av);
}

void	ms_pipeline(void)
{
	t_cmd	*list;
	int		prevpipe;
	pid_t	childpid;

	list = NULL;
	ft_cmd(&list, CMD_GET);
	if (!list)
	{
		g_ms.status = ERR_SYNTAX;
		return ;
	}
	prevpipe = 0;
	while (list)
	{
		prevpipe = ms_setfd(list, prevpipe);
		if (prevpipe >= 0)
		{
			childpid = fork();
			if (childpid < 0)
				ft_error(strerror(errno));
			else if (childpid == 0)
			{
				if (dup2(list->fdin, STDIN_FILENO) < 0 \
				 || dup2(list->fdout, STDOUT_FILENO) < 0)
					ft_error(strerror(errno));
				ms_exec(list);
				_exit(EXIT_SUCCESS);
			}
			else
			{
				wait(NULL);
				if (list->fdin != STDIN_FILENO)
					close(list->fdin);
				if (list->fdout != STDOUT_FILENO)
					close(list->fdout);
			}
		}
		list = list->next;
	}
}
