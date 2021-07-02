/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 18:12:33 by lrocca            #+#    #+#             */
/*   Updated: 2021/07/02 20:45:04 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	ms_heredoc(const char *delimiter)
{
	char	*line;
	int		fd[2];

	if (pipe(fd) < 0)
		return (-1);
	line = NULL;
	while (1)
	{
		line = readline("> ");
		if (!line || !ft_strcmp(delimiter, line))
			break ;
		ft_putendl_fd(line, fd[1]);
		free(line);
	}
	free(line);
	close(fd[1]);
	return (fd[0]);
}

static char	set_fdin(t_cmd *cmd, int prevpipe)
{
	int		fd;
	t_redir	*curr;

	if (cmd->in)
	{
		if (prevpipe != STDIN_FILENO)
			close(prevpipe);
		curr = cmd->in;
		while (curr)
		{
			if (curr->type)
				fd = ms_heredoc(curr->value);
			else
				fd = open(curr->value, O_RDONLY);
			if (fd < 0)
			{
				ft_error(strerror(errno));
				return (-1);
			}
			if (curr->next)
				close(fd);
			curr = curr->next;
		}
		// if (cmd->fdin != STDIN_FILENO)
		// 	close(cmd->fdin);
		cmd->fdin = fd;
	}
	else
		cmd->fdin = prevpipe;
	return (0);
}

static char	set_fdout(t_cmd *cmd, int *ret)
{
	int		pipefd[2];
	int		fd;
	t_redir	*curr;
	int		flags;

	if (!cmd->out && cmd->next)
	{
		if (pipe(pipefd) < 0)
		{
			ft_error("pipe failed");
			return (-1);
		}
		if (cmd->fdout != STDOUT_FILENO)
			close(cmd->fdout);
		cmd->fdout = pipefd[1];
		*ret = pipefd[0];
	}
	else
	{
		curr = cmd->out;
		while (curr)
		{
			flags = O_WRONLY | O_CREAT;
			if (curr->type)
				flags |= O_APPEND;
			else
				flags |= O_TRUNC;
			fd = open(curr->value, flags, S_IRUSR | S_IWUSR);
			if (fd < 0)
			{
				ft_error(strerror(errno));
				return (-1);
			}
			if (cmd->fdout != STDOUT_FILENO)
				close(cmd->fdout);
			cmd->fdout = fd;
			curr = curr->next;
		}
	}
	return (0);
}

int	ms_setfd(t_cmd *cmd, int prevpipe)
{
	int	ret;

	ret = 0;
	if (set_fdin(cmd, prevpipe) < 0)
		return (-1);
	if (set_fdout(cmd, &ret) < 0)
		return (-1);
	return (ret);
}
