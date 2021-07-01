/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 20:28:16 by lrocca            #+#    #+#             */
/*   Updated: 2021/07/01 20:30:18 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static t_list	*find_env(char *name)
{
	t_list			*curr;
	t_list			*ret;
	const size_t	len = ft_strlen(name) + 1;

	ret = NULL;
	curr = g_ms.env;
	name = ft_strjoin(name, "=");
	while (curr && name)
	{
		if (!ft_strncmp(curr->content, name, len))
		{
			ret = curr;
			break ;
		}
		curr = curr->next;
	}
	free(name);
	return (ret);
}

char	ft_setenv(char *var)
{
	int		i;
	char	*token;
	t_list	*new;

	i = 0;
	token = line_to_name(var, &i);
	if (!token || var[i] != '=')
	{
		free(token);
		return (-1);
	}
	new = find_env(token);
	if (new)
	{
		free(new->content);
		new->content = ft_strdup(var);
	}
	else
		ft_lstadd_back(&g_ms.env, ft_lstnew(ft_strdup(var)));
	free(token);
	return (0);
}

char	*ft_getenv(char *name)
{
	const size_t	len = ft_strlen(name) + 1;
	t_list			*ret;

	ret = find_env(name);
	if (ret)
		return (ret->content + len);
	return (NULL);
}
