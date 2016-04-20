/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 14:47:33 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/04/18 17:26:34 by dmoureu-         ###   ########.fr       */
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

int			cdcmd(t_shell *shell, char **cmds)
{
	(void)shell;
	if (ft_tablen(cmds) > 2)
	{
		ft_printf("cd: Too many arguments\n");
		return (1);
	}
	if (cmds[1])
		changedir(shell, cmds[1]);
	else if (envgetkey(shell->env, "HOME"))
		changedir(shell, envgetkey(shell->env, "HOME"));
	else
		changedir(shell, "/");
	return (1);
}

void		changedir(t_shell *shell, char *path)
{
	DIR		*directory;
	char	*newpwd;

	if (access(path, F_OK) == 0)
	{
		if (isdir(path))
		{
			directory = opendir(path);
			if (directory)
			{
				chdir(path);
				if (envgetkey(shell->env, "PWD"))
					envsetkey(shell->env, "OLDPWD",
					envgetkey(shell->env, "PWD"));
				newpwd = getdir();
				envsetkey(shell->env, "PWD", newpwd);
			}
			else
				ft_printf("Permission denied\n");
		}
		else
			ft_printf("Not a directory\n");
	}
	else
		ft_printf("Not file or directory\n");
}
