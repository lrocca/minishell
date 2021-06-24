/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 15:58:22 by lrocca            #+#    #+#             */
/*   Updated: 2021/06/24 16:17:12 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	cmd_exec_from_path(char **av)
{
	char	*path;
	char	**split;

	path = getenv("PATH");
	split = ft_split(path, ':');
	(void)av;
	return (127);
}

int	cmd_exec(const char *cmd)
{
	char	**av;

	av = ft_splitspace(cmd);
	if (!ft_strcmp(av[0], "pwd"))
		return (builtin_pwd());
	else if (!ft_strcmp(av[0], "exit"))
		return (builtin_exit());
	else
		return (cmd_exec_from_path(av));
}
