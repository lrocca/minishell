/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 19:09:18 by lrocca            #+#    #+#             */
/*   Updated: 2021/07/05 20:04:28 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	builtin_exit(t_list *av)
{
	if (av && av->next)
		g_ms.status = ft_atoi(av->next->content); // TODO check numeric argument
	ft_putendl_fd("exit", STDOUT_FILENO);
	ft_lstclear(&g_ms.env, free);
	ft_paths(NULL, PATHS_FREE);
	exit(g_ms.status); //  should actually wait for other cmds
	return (0);
}
