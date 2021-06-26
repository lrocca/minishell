/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 02:14:24 by lrocca            #+#    #+#             */
/*   Updated: 2021/06/26 20:19:39 by lrocca           ###   ########.fr       */
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

typedef struct s_cmd {
	char			*bin;
	t_list			*av;
	t_list			*in;
	t_list			*out;
	int				fdin;
	int				fdout;
	char			*delimiter;
	char			append;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_var {
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

t_cmd	*lexer(const char *line);
int		parse_redirection(const char *line, char **buff, char *quote, \
							t_cmd *head);

/*
** cmd
*/
t_cmd	*ft_cmdnew(void);
t_cmd	*ft_cmdlast(t_cmd *head);
void	ft_cmdadd_back(t_cmd **head, t_cmd *new);

/*
** utils
*/
void	ft_prepend(char *src, char **dst);
char	switch_redir(const char *str);
char	ft_ismeta(const char c);

/*
** exec
*/
int		cmd_exec(const char *cmd);

/*
** builtins
*/
char	builtin_pwd(void);
char	builtin_export(char **av);
char	builtin_env(void);
char	builtin_exit(void);

#endif
