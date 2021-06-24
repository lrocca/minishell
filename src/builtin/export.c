/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 19:08:55 by lrocca            #+#    #+#             */
/*   Updated: 2021/06/24 19:51:13 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static char	print_env(void)
{
	extern char	**environ;
	int			i;

	i = 0;
	while (environ[i])
	{
		ft_putstr_fd("declare -x ", STDOUT_FILENO);
		ft_putendl_fd(environ[i++], STDOUT_FILENO);
	}
	return (0);
}

char	builtin_export(char **av)
{
	int	i;

	i = 0;
	if (!av[1])
		return (print_env());
	while (av[++i])
	{
		if (!ft_strchr(av[i], '='))
			continue ;
		ft_split(av[i], '=');
		//
	}
	return (0);
}
