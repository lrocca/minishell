/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 18:22:38 by lrocca            #+#    #+#             */
/*   Updated: 2021/06/26 20:25:57 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_cmd	*ft_cmdnew(void)
{
	t_cmd	*new;

	new = malloc(sizeof(t_cmd));
	new->next = NULL;
	new->av = NULL;
	new->in = NULL;
	new->out = NULL;
	return (new);
}

t_cmd	*ft_cmdlast(t_cmd *head)
{
	if (!head)
		return (ft_cmdnew()); // unsafe
	while (head->next)
		head = head->next;
	return (head);
}

void	ft_cmdadd_back(t_cmd **head, t_cmd *new)
{
	if (!*head)
	{
		*head = new;
		return ;
	}
	ft_cmdlast(*head)->next = new;
}
