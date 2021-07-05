/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 05:19:57 by lrocca            #+#    #+#             */
/*   Updated: 2021/07/03 03:34:52 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**list_to_array(t_list *head)
{
	const int	len = ft_lstsize(head);
	char		**ret;
	int			i;
	t_list		*curr;

	ret = malloc(sizeof(char *) * (len + 1));
	if (!ret)
		return (NULL);
	i = 0;
	curr = head;
	ret[len] = NULL;
	while (curr && i < len)
	{
		ret[i++] = curr->content;
		curr = curr->next;
	}
	return (ret);
}
