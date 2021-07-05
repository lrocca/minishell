/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 00:33:52 by lrocca            #+#    #+#             */
/*   Updated: 2021/07/03 03:34:52 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	debug_lexer(t_cmd *head)
{
	t_list	*curr;
	t_redir	*curr2;

	if (!head)
		return (ft_putendl_fd("head == NULL", STDOUT_FILENO));
	while (head)
	{
		ft_putendl_fd(">>> av", STDOUT_FILENO);
		curr = head->av;
		while (curr)
		{
			ft_putchar_fd('|', STDOUT_FILENO);
			ft_putstr_fd(curr->content, STDOUT_FILENO);
			ft_putendl_fd("|", STDOUT_FILENO);
			curr = curr->next;
		}
		ft_putendl_fd(">>> in", STDOUT_FILENO);
		curr2 = head->in;
		while (curr2)
		{
			ft_putchar_fd('|', STDOUT_FILENO);
			ft_putstr_fd(curr2->value, STDOUT_FILENO);
			ft_putchar_fd('|', STDOUT_FILENO);
			ft_putnbr_fd(curr2->type, STDOUT_FILENO);
			ft_putchar_fd('\n', STDOUT_FILENO);
			curr2 = curr2->next;
		}
		ft_putendl_fd(">>> out", STDOUT_FILENO);
		curr2 = head->out;
		while (curr2)
		{
			ft_putchar_fd('|', STDOUT_FILENO);
			ft_putstr_fd(curr2->value, STDOUT_FILENO);
			ft_putchar_fd('|', STDOUT_FILENO);
			ft_putnbr_fd(curr2->type, STDOUT_FILENO);
			ft_putchar_fd('\n', STDOUT_FILENO);
			curr2 = curr2->next;
		}
		head = head->next;
	}
}
