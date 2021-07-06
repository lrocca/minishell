/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 19:09:18 by lrocca            #+#    #+#             */
/*   Updated: 2021/07/06 02:33:29 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	builtin_exit(t_list *av)
{
	if (av && av->next && ft_isdigit(((char *)av->next->content)[0]))
		g_ms.status = ft_atoi(av->next->content);
	ft_putendl_fd("exit", STDOUT_FILENO);
	ft_lstclear(&g_ms.env, free);
	ft_paths(NULL, PATHS_FREE);
	exit(g_ms.status);
	return (0);
}
