/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 02:14:24 by lrocca            #+#    #+#             */
/*   Updated: 2021/06/30 05:32:33 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <readline/history.h>
# include <readline/readline.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# include "libft.h"

# define PATHS_GET	0
# define PATHS_FREE	1

# define ERR_CMD_NOT_FOUND	127
# define ERR_SYNTAX			258

typedef struct s_redir
{
	char			*value;
	char			type;
	struct s_redir	*next;
}	t_redir;

typedef struct s_cmd {
	char			*bin;
	t_list			*av;
	t_redir			*in;
	t_redir			*out;
	int				fdin;
	int				fdout;
	char			*delimiter;
	char			append;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_ms {
	int		status;
	t_list	*env;
}	t_ms;

t_ms	g_ms;

void	init_env(void);
char	*ft_prompt(void);
void	ft_error(char *err);

/*
** lexer
*/
t_cmd	*lexer(const char *line);
char	*line_to_word(const char *line, int *i);

/*
** handlers
*/
int		handle_redir(t_cmd **head, const char *line, int *i);

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
** env
*/
char	*ft_getenv(char *name);

/*
** paths
*/
char	ft_paths(char ***paths, char opt);

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
