/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 20:28:16 by lrocca            #+#    #+#             */
/*   Updated: 2021/06/29 18:37:58 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	*ft_getenv(char *name)
{
	t_list			*curr;
	char			*ret;
	const size_t	len = ft_strlen(name) + 1;

	ret = NULL;
	curr = g_ms.env;
	name = ft_strjoin(name, "=");
	while (curr && name)
	{
		if (!ft_strncmp(curr->content, name, len))
		{
			ret = curr->content + len;
			break ;
		}
		curr = curr->next;
	}
	free(name);
	return (ret);
}
