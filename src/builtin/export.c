/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 19:08:55 by lrocca            #+#    #+#             */
/*   Updated: 2021/07/03 03:34:52 by lrocca           ###   ########.fr       */
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
	t_list	*first;
	int		len;

	len = ft_lstsize(g_ms.env) - 1;
	first = g_ms.env;
	curr = g_ms.env;
	while (curr)
	{
		if (ft_strcmp(curr->content, first->content) < 0)
			first = curr;
		curr = curr->next;
	}
	print_var(first->content);
	prev = first;
	// min = prev;
	while (len--)
	{
		curr = g_ms.env;
		min = g_ms.env;
		while (min == prev)
			min = min->next;
		while (curr)
		{
			if (ft_strcmp(curr->content, min->content) < 0 \
				&& ft_strcmp(curr->content, prev->content) > 0)
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
		{
			ft_error("export: invalid identifier");
			return (1);
		}
		av = av->next;
	}
	return (0);
}
