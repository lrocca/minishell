/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 14:31:00 by lrocca            #+#    #+#             */
/*   Updated: 2021/06/24 16:10:08 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_error(char *err, char opt)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putendl_fd(err, STDERR_FILENO);
	if (opt == 1)
		exit(EXIT_FAILURE);
}
