/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 19:08:38 by lrocca            #+#    #+#             */
/*   Updated: 2021/06/29 17:54:26 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	builtin_env(void)
{
	t_list	*curr;

	curr = g_ms.env;
	while (curr)
	{
		ft_putendl_fd(curr->content, STDOUT_FILENO);
		curr = curr->next;
	}
	return (0);
}
