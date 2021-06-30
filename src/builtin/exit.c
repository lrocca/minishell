/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 19:09:18 by lrocca            #+#    #+#             */
/*   Updated: 2021/06/30 05:44:00 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	builtin_exit(void)
{
	ft_putendl_fd("exit", STDOUT_FILENO);
	exit(g_ms.status); // should actually wait for other cmds
	return (0);
}
