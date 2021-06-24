/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 20:26:44 by lrocca            #+#    #+#             */
/*   Updated: 2021/06/24 20:46:38 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	*ft_prompt(void)
{
	ft_putchar_fd('[', STDOUT_FILENO);
	ft_putnbr_fd(g_ms.status, STDOUT_FILENO);
	ft_putstr_fd("] ", STDOUT_FILENO);
	return (readline("ms > "));
}
