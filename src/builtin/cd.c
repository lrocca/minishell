/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 04:19:17 by lrocca            #+#    #+#             */
/*   Updated: 2021/07/01 04:45:56 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	builtin_cd(t_list *av)
{
	char	*path;

	av = av->next;
	if (av)
		path = av->content;
	else
		path = ft_getenv("HOME");
	if (path)
		if (chdir(path) < 0)
		{
			ft_error(strerror(errno));
			return (errno);
		}
	// ft_setenv(); PWD
	return (0);
}
