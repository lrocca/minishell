/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 14:31:00 by lrocca            #+#    #+#             */
/*   Updated: 2021/07/06 00:58:10 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	ft_error(const char *s1, const char *s2)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd((char *)s1, STDERR_FILENO);
	if (s2)
	{
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putstr_fd((char *)s2, STDERR_FILENO);
	}
	ft_putchar_fd('\n', STDERR_FILENO);
	return (-1);
}
