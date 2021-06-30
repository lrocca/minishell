/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 20:26:44 by lrocca            #+#    #+#             */
/*   Updated: 2021/06/29 17:48:21 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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
