/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 05:15:02 by lrocca            #+#    #+#             */
/*   Updated: 2021/06/30 05:42:29 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	builtin_echo(t_list *av)
{
	char	end;

	end = '\n';
	av = av->next;
	if (!ft_strcmp(av->content, "-n"))
	{
		end = '\0';
		av = av->next;
	}
	while (av)
	{
		ft_putstr_fd(av->content, STDOUT_FILENO);
		if (av->next)
			ft_putchar_fd(' ', STDOUT_FILENO);
		av = av->next;
	}
	ft_putchar_fd(end, STDOUT_FILENO);
	return (0);
}
