/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 19:08:38 by lrocca            #+#    #+#             */
/*   Updated: 2021/06/24 20:39:06 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	builtin_env(void)
{
	t_var	*curr;

	curr = g_ms.env;
	while (curr)
	{
		ft_putstr_fd(curr->name, STDOUT_FILENO);
		ft_putchar_fd('=', STDOUT_FILENO);
		ft_putendl_fd(curr->value, STDOUT_FILENO);
		curr = curr->next;
	}
	return (0);
}
