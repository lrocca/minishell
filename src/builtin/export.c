/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 19:08:55 by lrocca            #+#    #+#             */
/*   Updated: 2021/07/01 05:02:51 by lrocca           ###   ########.fr       */
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
	int		i;
	char	*token;

	if (!av->next)
		return (0); // return (print_env());
	while (av)
	{
		i = 0;
		token = line_to_name(av->content, &i);
		// TODO add error management
		if (token && ((char *)av->content)[i] == '=')
			ft_lstadd_back(&g_ms.env, ft_lstnew(ft_strdup(av->content)));
		free(token);
		av = av->next;
	}
	return (0);
}
