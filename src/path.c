/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 18:44:15 by lrocca            #+#    #+#             */
/*   Updated: 2021/06/29 18:56:24 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static char	set_paths(char ***ptr)
{
	const char	*var = ft_getenv("PATH");

	if (!var)
		return (-1);
	*ptr = ft_split(var, ':');
	return (0);
}

char	ft_paths(char ***paths, char opt)
{
	static char	**ptr = NULL;
	int			i;

	if (opt == PATHS_GET && paths)
	{
		if (ptr)
		{
			*paths = ptr;
			return (0);
		}
		if (set_paths(&ptr) < 0)
			return (-1);
		return (ft_paths(paths, opt));
	}
	else if (opt == PATHS_FREE && ptr)
	{
		i = 0;
		while (ptr[i])
			free(ptr[i++]);
		free(ptr);
		return (0);
	}
	return (-1);
}
