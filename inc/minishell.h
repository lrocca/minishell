/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 02:14:24 by lrocca            #+#    #+#             */
/*   Updated: 2021/07/08 07:24:01 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <dirent.h>
# include <fcntl.h>
# include <stdio.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# include "libft.h"

# define PATHS_GET	0
# define PATHS_FREE	1

# define CMD_GET	0
# define CMD_FREE	1
# define CMD_SET	2

# define ERR_CMD_NOT_FOUND	127
# define ERR_SIGINT			130
# define ERR_SYNTAX			258

# define WILDCARD_ENABLED		0
# define WILDCARD_DISABLED		1
# define WILDCARD_PLACEHOLDER	'\a'

typedef struct s_redir
{
	struct s_redir	*next;
	char			*value;
	char			type;
}	t_redir;

typedef struct s_cmd {
	struct s_cmd	*next;
	t_list			*av;
	t_redir			*in;
	t_redir			*out;
	int				fdin;
	int				fdout;
}	t_cmd;

typedef struct s_ms {
	t_list	*env;
	pid_t	childpid;
	int		status;
}	t_ms;

t_ms	g_ms;

void	init_env(void);
char	*ft_prompt(void);
char	ft_error(const char *s1, const char *s2);

/*
** lexer
*/
void	ms_lexer(const char *line);
void	char_to_buff(char **buff, char new);
char	*buff_to_word(char **buff, char quote);
char	*line_to_word(const char *line, int *i, char opt);
void	word_to_av(char *word);

/*
** handlers
*/
void	handle_sigint(int signum);
int		handle_redir(const char *line, int *i);
int		handle_dollar(char **buff, const char *line, int *i);

/*
** wildcard
*/
void	ft_wildcard(char *pat);

/*
** redir
*/
void	ft_redirclear(t_redir *list);

/*
** cmd
*/
t_cmd	*ft_cmdnew(void);
t_cmd	*ft_cmdlast(t_cmd *head);
void	ft_cmdadd_back(t_cmd *new);
char	ft_cmd(t_cmd **cmd, char opt);

/*
** utils
*/
char	ft_isbuiltin(const char *s);
char	ft_ismeta(const char c);
char	ft_isname_start(const char c);
char	*line_to_name(const char *line, int *i);
char	**list_to_array(t_list *head);

/*
** env
*/
char	*ft_getenv(char *name);
char	ft_setenv(char *var);

/*
** paths
*/
char	ft_paths(char ***paths, char opt);

/*
** exec
*/
void	ms_pipeline(void);
void	ms_single_builtin(t_cmd *cmd);
char	ms_builtin(t_cmd *cmd);
int		cmd_exec_from_path(t_list *av);
int		ms_setfd(t_cmd *cmd);

/*
** builtins
*/
char	builtin_pwd(void);
char	builtin_env(void);
char	builtin_cd(t_list *av);
char	builtin_exit(t_list *av);
char	builtin_echo(t_list *av);
char	builtin_unset(t_list *av);
char	builtin_export(t_list *av);

#endif
