/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 19:09:18 by lrocca            #+#    #+#             */
/*   Updated: 2021/07/01 04:16:17 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	builtin_exit(t_list *av)
{
	int	status;

	status = g_ms.status;
	if (av && av->next)
		status = ft_atoi(av->next->content);
	ft_putendl_fd("exit", STDOUT_FILENO);
	exit(status); // should actually wait for other cmds
	return (0);
}
