/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 20:28:16 by lrocca            #+#    #+#             */
/*   Updated: 2021/06/24 20:32:41 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	*ft_getenv(char *name)
{
	t_list	*curr;

	curr = g_ms.env;
	while (curr)
	{
		if (!ft_strcmp(((t_var *)(curr->content))->name, name))
			return (((t_var *)(curr->content))->value);
		curr = curr->next;
	}
	return (NULL);
}
