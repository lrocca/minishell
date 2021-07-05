/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 20:26:44 by lrocca            #+#    #+#             */
/*   Updated: 2021/07/03 06:00:47 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define RED "\1\e[31m\2"
#define GRN "\1\e[32m\2"
#define RES "\1\e[0m\2"

#define PROMPT "$ "

char	*ft_prompt(void)
{
	if (g_ms.status == 0)
		return (readline(GRN PROMPT RES));
	return (readline(RED PROMPT RES));
}

// SIGINT not red?
