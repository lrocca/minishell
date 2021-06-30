/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpolation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 04:48:18 by lrocca            #+#    #+#             */
/*   Updated: 2021/06/30 05:39:54 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static char	*line_to_name(const char *line, int *i)
{
	char	*buff;

	buff = NULL;
	while (ft_isalnum(line[*i]) || line[*i] == '_')
		char_to_buff(&buff, line[(*i)++]);
	return (buff_to_word(&buff, 0));
}

int	handle_dollar(char **buff, const char *line, int *i)
{
	const char	*var;
	char		*name;
	int			j;

	if (!(ft_isalpha(line[*i + 1]) || line[*i + 1] == '_'))
		return (0);
	(*i)++;
	name = line_to_name(line, i);
	var = ft_getenv(name);
	j = 0;
	if (!var)
		while (name[j])
			char_to_buff(buff, name[j++]);
	else
		while (var[j])
			char_to_buff(buff, var[j++]);
	free(name);
	return (0);
}
