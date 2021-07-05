/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isbuiltin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 23:17:20 by lrocca            #+#    #+#             */
/*   Updated: 2021/07/05 23:37:03 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	ft_isbuiltin(const char *s)
{
	if (!ft_strcmp(s, "cd") \
	|| !ft_strcmp(s, "env") \
	|| !ft_strcmp(s, "pwd") \
	|| !ft_strcmp(s, "echo") \
	|| !ft_strcmp(s, "exit") \
	|| !ft_strcmp(s, "unset") \
	|| !ft_strcmp(s, "export"))
		return (1);
	return (0);
}
