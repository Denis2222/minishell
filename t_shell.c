/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_shell.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 22:06:54 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/04/20 14:16:15 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_shell	*newshell(void)
{
	t_shell	*shell;

	shell = (t_shell*)malloc(sizeof(t_shell));
	shell->env = loadenv();
	shell->envtxt = genenv(shell->env);
	return (shell);
}

void	shell_env_refresh(t_shell *shell)
{
	int	i;

	i = 0;
	while (shell->envtxt[i])
	{
		free(shell->envtxt[i]);
		i++;
	}
	free(shell->envtxt);
	shell->envtxt = genenv(shell->env);
}

char	*getsyspath(void)
{
	char	*buffer;
	char	*path;
	int		fd;
	int		first;
	char	*oldpath;

	buffer = NULL;
	first = 1;
	fd = open("/etc/paths", O_RDONLY);
	while (get_next_line(fd, &buffer))
	{
		if (!first)
		{
			oldpath = path;
			path = ft_strjoin(path, ":");
			free(oldpath);
			path = ft_strjoin(path, buffer);
		}
		else
			path = ft_strdup(buffer);
		free(buffer);
		buffer = NULL;
		first = 0;
	}
	return (path);
}

t_env	*environtoenv(int i)
{
	t_env	*env;
	char	**tab;

	tab = ft_strsplit(environ[i], '=');
	if (ft_strequ(tab[0], "SHLVL"))
	{
		tab[1] = ft_itoa(ft_atoi(tab[1]) + 1);
	}
	return (newenv(tab[0], tab[1]));
}
