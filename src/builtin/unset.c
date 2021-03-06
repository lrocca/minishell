/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 19:07:24 by lrocca            #+#    #+#             */
/*   Updated: 2021/07/03 03:34:52 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	remove_from_env(char *name)
{
	t_list	*curr;
	t_list	*prev;

	curr = g_ms.env;
	prev = NULL;
	while (curr)
	{
		if (!ft_strncmp(curr->content, name, ft_strlen(name)))
		{
			if (prev)
				prev->next = curr->next;
			else
				g_ms.env = curr->next;
			ft_lstdelone(curr, free);
			break ;
		}
		prev = curr;
		curr = curr->next;
	}
	free(name);
}

char	builtin_unset(t_list *av)
{
	int		i;
	char	*token;

	while (av)
	{
		i = 0;
		av = av->next;
		if (!av)
			break ;
		token = line_to_name(av->content, &i);
		if (!token)
			continue ;
		if (!((char *)av->content)[i])
			remove_from_env(ft_strjoin(token, "="));
		free(token);
	}
	return (0);
}
