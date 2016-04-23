/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_shell.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 22:06:54 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/04/23 03:18:12 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_shell	*newshell(char **environ)
{
	t_shell	*shell;

	shell = (t_shell*)malloc(sizeof(t_shell));
	shell->env = loadenv(environ);
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

t_env	*environtoenv(char **environ, int i)
{
	t_env	*env;
	char	**tab;
	char	*shlvl;

	tab = ft_strsplit(environ[i], '=');
	if (ft_strequ(tab[0], "SHLVL"))
	{
		free(tab[1]);
		tab[1] = ft_itoa(ft_atoi(tab[1]) + 1);
	}
	env = newenv(tab[0], tab[1]);
	free(tab[0]);
	free(tab[1]);
	free(tab);
	return (env);
}

int		envlen(t_env *env)
{
	int nb;

	nb = 0;
	while (env)
	{
		nb++;
		env = env->next;
	}
	return (nb);
}
