/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 02:14:24 by lrocca            #+#    #+#             */
/*   Updated: 2021/06/24 16:10:25 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

# include "libft.h"

void	ft_error(char *err, char opt);

/*
** exec
*/
int	cmd_exec(const char *cmd);

/*
** builtins
*/
char	builtin_pwd(void);
char	builtin_exit(void);

#endif
