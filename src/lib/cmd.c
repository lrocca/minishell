/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 18:22:38 by lrocca            #+#    #+#             */
/*   Updated: 2021/07/03 03:34:52 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*ft_cmdnew(void)
{
	t_cmd	*new;

	new = malloc(sizeof(t_cmd));
	new->next = NULL;
	new->av = NULL;
	new->in = NULL;
	new->out = NULL;
	new->fdin = STDIN_FILENO;
	new->fdout = STDOUT_FILENO;
	return (new);
}

t_cmd	*ft_cmdlast(t_cmd *head)
{
	if (!head)
		return (NULL);
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

void	ft_cmdclear(t_cmd *list)
{
	t_cmd	*prev;

	while (list)
	{
		ft_lstclear(&list->av, free);
		ft_redirclear(list->in);
		ft_redirclear(list->out);
		prev = list;
		list = list->next;
		free(prev);
	}
}

char	ft_cmd(t_cmd **cmd, char opt)
{
	static t_cmd	*ptr = NULL;

	if (opt == CMD_GET)
	{
		if (!cmd)
			return (-1);
		*cmd = ptr;
		return (0);
	}
	else if (opt == CMD_SET)
	{
		if (ptr || !cmd)
			return (-1);
		ptr = *cmd;
		return (0);
	}
	else if (opt == CMD_FREE && ptr)
	{
		ft_cmdclear(ptr);
		ptr = NULL;
	}
	return (0);
}
