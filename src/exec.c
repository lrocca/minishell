/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 15:58:22 by lrocca            #+#    #+#             */
/*   Updated: 2021/06/24 20:47:52 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static char	*find_exec(char *cmd, char **paths)
{
	int		i;
	char	*ret;

	i = 0;
	ret = NULL;
	while (paths[i])
	{
		free(ret);
		ret = ft_strjoin(paths[i], cmd);
		if (!access(ret, X_OK))
			break ;
		i++;
	}
	if (!paths[i])
		return (NULL);
	return (ret);
}

int	cmd_exec_from_path(char **av)
{
	char	*cmd;
	// t_pid	childpid;

	cmd = find_exec(ft_strjoin("/", av[0]), ft_split(getenv("PATH"), ':'));
	if (!cmd)
	{
		ft_error("command not found");
		return (127);
	}
	//
	return (0);
}

int	cmd_exec(const char *cmd)
{
	char	**av;

	av = ft_splitspace(cmd);
	if (ft_strchr(av[0], '='))
		return (builtin_pwd());
	else if (!ft_strcmp(av[0], "pwd"))
		return (builtin_pwd());
	else if (!ft_strcmp(av[0], "export"))
		return (builtin_export(av));
	else if (!ft_strcmp(av[0], "env"))
		return (builtin_env());
	else if (!ft_strcmp(av[0], "exit"))
		return (builtin_exit());
	else
		return (cmd_exec_from_path(av));
}
