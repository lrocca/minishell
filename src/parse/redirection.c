/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 20:12:30 by lrocca            #+#    #+#             */
/*   Updated: 2021/06/26 20:26:37 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	parse_redirection(const char *line, char **buff, char *quote, t_cmd *head)
{
	int		i;
	char	redir;

	i = 0;
	redir = switch_redir((char *)(line));
	i++;
	if (redir > 2)
		i++;
	while (ft_isspace(line[i]))
		i++;
	i = get_word(line, &buff, i, &quote);
	if (!buff)
		ft_error("syntax error (redir)");
	if (redir == 3)
		ft_prepend("<", &buff);
	else if (redir == 4)
		ft_prepend(">", &buff);
	if (redir % 2)
		ft_lstadd_back(&ft_cmdlast(head)->in, ft_lstnew(buff));
	else
		ft_lstadd_back(&ft_cmdlast(head)->out, ft_lstnew(buff));
	buff = NULL;
}
