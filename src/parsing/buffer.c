/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 03:27:58 by lrocca            #+#    #+#             */
/*   Updated: 2021/07/03 03:41:14 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define BUFFER_SIZE 64

static char	*new_buff(char *buff)
{
	char	*new;
	size_t	len;

	if (!buff)
		buff = ft_strdup("");
	len = ft_strlen(buff) + BUFFER_SIZE;
	new = malloc(len);
	ft_bzero(new, len);
	ft_strlcpy(new, buff, len);
	free(buff);
	return (new);
}

void	char_to_buff(char **buff, char new)
{
	size_t	len;

	len = ft_strlen(*buff);
	if (len == 0 || (len + 1) % BUFFER_SIZE == 0)
		*buff = new_buff(*buff);
	(*buff)[len] = new;
}

char	*buff_to_word(char **buff, char quote)
{
	char	*word;

	if (quote && *buff)
	{
		free(*buff);
		*buff = NULL;
		// maybe throw unclosed quote error
	}
	if (!*buff)
		return (NULL);
	word = ft_strdup(*buff);
	free(*buff);
	*buff = NULL;
	return (word);
}
