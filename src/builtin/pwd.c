/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 19:09:38 by lrocca            #+#    #+#             */
/*   Updated: 2021/07/06 00:38:00 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	builtin_pwd(void)
{
	char	*pwd;

	pwd = getcwd(NULL, 42);
	if (!pwd)
	{
		ft_error("getcwd", strerror(errno));
		return (errno);
	}
	ft_putendl_fd(pwd, STDOUT_FILENO);
	free(pwd);
	return (0);
}
