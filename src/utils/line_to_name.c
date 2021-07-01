/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_to_name.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 03:27:58 by lrocca            #+#    #+#             */
/*   Updated: 2021/07/01 20:30:07 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	*line_to_name(const char *line, int *i)
{
	char	*buff;

	buff = NULL;
	if (!line || !ft_isname_start(line[*i]))
		return (NULL);
	while (ft_isalnum(line[*i]) || line[*i] == '_')
		char_to_buff(&buff, line[(*i)++]);
	return (buff_to_word(&buff, 0));
}
