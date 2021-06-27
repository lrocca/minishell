/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 20:26:44 by lrocca            #+#    #+#             */
/*   Updated: 2021/06/27 03:14:20 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define RES "\e[0m"

#define PROMPT "$ "

char	*ft_prompt(int status)
{
	if (status == 0)
		return (readline(GRN PROMPT RES));
	return (readline(RED PROMPT RES));
}
