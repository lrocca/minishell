/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 19:22:35 by lrocca            #+#    #+#             */
/*   Updated: 2021/07/08 06:59:20 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	wildcard_star(int *i, int *j, int *index_pat, int *index_txt)
{
	*index_txt = *i;
	*index_pat = *j;
	(*j)++;
}

static void	wildcard_loop(int *i, int *j, int *index_pat, int *index_txt)
{
	*j = *index_pat + 1;
	*i = *index_txt + 1;
	(*index_txt)++;
}

static char	wildcard_algo(const char *pat, const char *txt, int i, int j)
{
	int			index_txt;
	int			index_pat;
	const int	n = ft_strlen(txt), m = ft_strlen(pat);

	index_txt = -1;
	index_pat = -1;
	while (i < n)
	{
		if (j < m && txt[i] == pat[j])
		{
			i++;
			j++;
		}
		else if (j < m && pat[j] == WILDCARD_PLACEHOLDER)
			wildcard_star(&i, &j, &index_pat, &index_txt);
		else if (index_pat != -1)
			wildcard_loop(&i, &j, &index_pat, &index_txt);
		else
			return (0);
	}
	while (j < m && pat[j] == WILDCARD_PLACEHOLDER)
		j++;
	if (j == m)
		return (1);
	return (0);
}

static void	replace_placeholder(char *pat)
{
	int	i;

	i = 0;
	while (pat[i])
	{
		if (pat[i] == WILDCARD_PLACEHOLDER)
			pat[i] = '*';
		i++;
	}
}

void	ft_wildcard(char *pat)
{
	struct dirent	*dp;
	DIR				*dirp;
	char			count;

	count = 0;
	dirp = opendir(".");
	if (dirp == NULL)
		return ((void)ft_error("wildcard", "`opendir` failed to open cwd"));
	while (1)
	{
		dp = readdir(dirp);
		if (!dp)
		{
			(void)closedir(dirp);
			if (!count)
				break ;
			free(pat);
			return ;
		}
		if ((dp->d_name[0] != '.' || pat[0] == '.') \
			&& wildcard_algo(pat, dp->d_name, 0, 0) && ++count)
			word_to_av(ft_strdup(dp->d_name));
	}
	replace_placeholder(pat);
	word_to_av(pat);
}
