/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 14:26:39 by lrocca            #+#    #+#             */
/*   Updated: 2021/06/24 16:11:52 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	builtin_pwd(void)
{
	char	*pwd;

	pwd = getcwd(NULL, 42);
	if (!pwd)
	{
		ft_error("`getcwd` failed", 0);
		return (errno);
	}
	ft_putendl_fd(pwd, STDOUT_FILENO);
	free(pwd);
	return (0);
}

char	builtin_exit(void)
{
	exit(EXIT_SUCCESS);
	return (0);
}
