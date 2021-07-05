/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpolation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 04:48:18 by lrocca            #+#    #+#             */
/*   Updated: 2021/07/03 03:34:52 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	handle_dollar(char **buff, const char *line, int *i)
{
	const char	*var;
	char		*name;
	int			j;

	var = NULL;
	if (!(ft_isname_start(line[*i + 1]) || line[*i + 1] == '?'))
		return (0);
	(*i)++;
	if (line[*i] == '?')
		var = ft_itoa(g_ms.status);
	else
	{
		name = line_to_name(line, i);
		(*i)--;
		if (!name)
			return (0);
		var = ft_getenv(name);
		free(name);
	}
	j = 0;
	while (var && var[j])
		char_to_buff(buff, var[j++]);
	return (0);
}
