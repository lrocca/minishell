/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 01:57:50 by lrocca            #+#    #+#             */
/*   Updated: 2021/06/24 16:16:45 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	*cmd_pre(char *cmd)
{
	char	*ret;

	ret = ft_strtrim(cmd, " \t\v\f\r");
	free(cmd);
	return (ret);
}

int	main(void)
{
	int		status;
	char	*cmd;

	status = 0;
	while (1)
	{
		ft_putchar_fd('[', STDOUT_FILENO);
		ft_putnbr_fd(status, STDOUT_FILENO);
		ft_putchar_fd(']', STDOUT_FILENO);
		cmd = readline("ms > ");
		cmd = cmd_pre(cmd);
		if (cmd == NULL)
		{
			ft_putchar_fd('\n', STDOUT_FILENO);
			return (0);
		}
		else if (ft_strlen(cmd) == 0)
			continue ;
		status = cmd_exec(cmd);
	}
	return (0);
}
