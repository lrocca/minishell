/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 17:58:28 by lrocca            #+#    #+#             */
/*   Updated: 2021/07/02 18:00:23 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_redirclear(t_redir *list)
{
	t_redir	*prev;

	while (list)
	{
		free(list->value);
		prev = list;
		list = list->next;
		free(prev);
	}
}
