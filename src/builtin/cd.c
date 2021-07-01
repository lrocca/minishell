/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 04:19:17 by lrocca            #+#    #+#             */
/*   Updated: 2021/07/01 20:30:38 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

#define SET_ENV_PWD		0
#define SET_ENV_OLDPWD	1

static void	set_pwd(char *value, char type)
{
	char	*var;

	var = NULL;
	if (type == SET_ENV_PWD)
		var = ft_strjoin("PWD=", value);
	else if (type == SET_ENV_OLDPWD)
		var = ft_strjoin("OLDPWD=", value);
	ft_setenv(var);
	free(var);
}

char	builtin_cd(t_list *av)
{
	char	*path;
	char	*pwd;
	char	*oldpwd;

	av = av->next;
	oldpwd = getcwd(NULL, 42);
	if (av)
		path = av->content;
	else
		path = ft_getenv("HOME");
	if (path)
		if (chdir(path) < 0)
		{
			free(oldpwd);
			ft_error(strerror(errno));
			return (errno);
		}
	set_pwd(oldpwd, SET_ENV_OLDPWD);
	pwd = getcwd(NULL, 42);
	set_pwd(pwd, SET_ENV_PWD);
	return (0);
}
