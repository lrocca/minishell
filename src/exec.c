/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 15:58:22 by lrocca            #+#    #+#             */
/*   Updated: 2021/07/01 04:14:35 by lrocca           ###   ########.fr       */
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
	char	**paths;
	char	*bin;

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
	ft_putendl_fd(bin, STDOUT_FILENO);
	return (0);
}

void	cmd_exec(const t_cmd *head)
{
	if (ft_strchr(head->av->content, '='))
		;
	else if (!ft_strcmp(head->av->content, "pwd"))
		g_ms.status = builtin_pwd();
	else if (!ft_strcmp(head->av->content, "env"))
		g_ms.status = builtin_env();
	else if (!ft_strcmp(head->av->content, "echo"))
		g_ms.status = builtin_echo(head->av);
	else if (!ft_strcmp(head->av->content, "exit"))
		g_ms.status = builtin_exit(head->av);
	else if (!ft_strcmp(head->av->content, "unset"))
		g_ms.status = builtin_unset(head->av);
	else if (!ft_strcmp(head->av->content, "export"))
		g_ms.status = builtin_export(head->av);
	else
		g_ms.status = cmd_exec_from_path(head->av);
}
