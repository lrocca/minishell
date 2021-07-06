/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 19:08:55 by lrocca            #+#    #+#             */
/*   Updated: 2021/07/06 16:12:22 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_var(char *var)
{
	ft_putstr_fd("declare -x ", STDOUT_FILENO);
	ft_putendl_fd(var, STDOUT_FILENO);
}

static char	print_env(void)
{
	t_list	*min;
	t_list	*curr;
	t_list	*prev;
	int		len;

	prev = NULL;
	len = ft_lstsize(g_ms.env);
	while (len--)
	{
		curr = g_ms.env;
		min = NULL;
		while (curr)
		{
			if ((!min || ft_strcmp(curr->content, min->content) < 0) \
				&& (!prev || ft_strcmp(curr->content, prev->content) > 0))
				min = curr;
			curr = curr->next;
		}
		print_var(min->content);
		prev = min;
	}
	return (0);
}

char	builtin_export(t_list *av)
{
	if (!av->next)
		return (print_env());
	av = av->next;
	while (av)
	{
		if (ft_setenv(av->content) < 0)
			return (-ft_error("export: invalid identifier", av->content));
		av = av->next;
	}
	return (0);
}
