/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 19:08:55 by lrocca            #+#    #+#             */
/*   Updated: 2021/06/30 05:56:57 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/*static char	print_env(void)
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
}*/

char	builtin_export(t_list *av)
{
	int	i;

	i = 0;
	if (!av->next)
		return (0); // return (print_env());
	while (av)
	{
		if (!ft_strchr(av->content, '='))
			continue ;
		ft_split(av->content, '=');
		//
	}
	return (0);
}
