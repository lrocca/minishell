/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replacechar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 07:50:59 by lrocca            #+#    #+#             */
/*   Updated: 2021/07/08 07:51:47 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_replacechar(char *s, char old, char new)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == old)
			s[i] = new;
		i++;
	}
}