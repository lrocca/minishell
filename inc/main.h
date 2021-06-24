/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 02:14:24 by lrocca            #+#    #+#             */
/*   Updated: 2021/06/24 20:47:18 by lrocca           ###   ########.fr       */
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

typedef struct s_var
{
	char			*name;
	char			*value;
	struct s_var	*next;
}	t_var;

typedef struct s_ms {
	int		status;
	t_var	*env;
}	t_ms;

t_ms	g_ms;

char	*ft_prompt(void);
void	ft_error(char *err);

/*
** exec
*/
int	cmd_exec(const char *cmd);

/*
** builtins
*/
char	builtin_pwd(void);
char	builtin_export(char **av);
char	builtin_env(void);
char	builtin_exit(void);

#endif
