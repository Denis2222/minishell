/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 14:47:33 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/04/01 22:05:46 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <dirent.h>
#include <sys/stat.h>

static int	isdir(char *path)
{
	struct stat	filestat;

	lstat(path, &filestat);
	if ((filestat.st_mode & S_IFMT) == S_IFDIR)
		return (1);
	else
		return (0);
}

void		changedir(t_shell *shell, char *path)
{
	DIR		*directory;

	(void)shell;
	if (path)
	{
		if (access(path, F_OK) == 0)
		{
			if (isdir(path))
			{
				directory = opendir(path);
				if (directory)
					chdir(path);
				else
					ft_printf("Permission denied\n");
			}
			else
				ft_printf("Not a directory\n");
		}
		else
			ft_printf("Not file or directory\n");
	}
	else if (envgetkey(shell->env, "HOME"))
		chdir(envgetkey(shell->env, "HOME"));
	else
		chdir("/");
}
