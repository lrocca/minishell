/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 17:43:24 by lrocca            #+#    #+#             */
/*   Updated: 2021/06/29 19:07:57 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	init_env(void)
{
	extern const char	**environ;
	int					i;

	i = 0;
	g_ms.env = NULL;
	if (!environ)
		return ;
	while (environ[i])
		ft_lstadd_back(&g_ms.env, ft_lstnew(ft_strdup(environ[i++])));
}
