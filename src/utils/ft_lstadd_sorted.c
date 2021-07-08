/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_sorted.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 08:01:43 by lrocca            #+#    #+#             */
/*   Updated: 2021/07/08 08:12:12 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lstadd_sorted(t_list **head, t_list *new)
{
	t_list	*curr;

	if (!*head)
	{
		*head = new;
		return ;
	}
	curr = *head;
	if (ft_strcmp(curr->content, new->content) > 0)
	{
		*head = new;
		new->next = curr;
		return ;
	}
	while (curr->next && ft_strcmp(curr->content, new->content) < 0)
		curr = curr->next;
	new->next = curr->next;
	curr->next = new;
}
