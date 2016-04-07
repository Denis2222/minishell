/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 22:05:31 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/04/07 22:34:16 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	setenvcmd(t_shell *shell, char **cmds)
{
	char *key;
	char *value;
	char **tab;

	key = NULL;
	value = NULL;
	tab = NULL;
	if (ft_tablen(cmds) == 3)
	{
		key = cmds[1];
		value = cmds[2];
	}
	if (ft_tablen(cmds) == 2 && ft_strchr(cmds[1], '='))
	{
		tab = ft_strsplit(cmds[1], '=');
		if (ft_tablen(tab) == 2)
		{
			key = tab[0];
			value = tab[1];
		}
	}
	if (key && value)
		if (ft_strlen(key) > 0 && ft_strlen(value) > 0)
			if (!ft_strchr(key, '=') && !ft_strchr(value, '='))
			{
				envsetkey(shell->env, key, value);
				return ;
			}
	ft_printf("setenv: syntax error (setenv [KEY] [VALUE] | setenv [KEY]=[VALUE])\n");
}

void	exitcmd(char **cmds)
{
	int	cmdlen;
	int	len;
	int	result;

	cmdlen = ft_tablen(cmds);
	if (cmdlen == 1)
		exit(EXIT_SUCCESS);
	else if (cmdlen == 2)
	{
		len = ft_strlen(cmds[1]);
		result = ft_atoi(cmds[1]);
		exit(result);
	}
	else
		ft_printf("exit: too many arguments\n");
}

int		builtin(t_shell *shell, char *cmd)
{
	int		result;
	char	**cmds;

	result = 0;
	cmds = ft_strsplit(cmd, ' ');
	if (ft_strequ(cmds[0], "cd"))
	{
		cdcmd(shell, cmds);
		result = 1;
	}
	if (ft_strequ(cmds[0], "exit"))
	{
		result = 1;
		exitcmd(cmds);
	}
	if (ft_strequ(cmds[0], "setenv"))
	{
		setenvcmd(shell, cmds);
		result = 1;
	}
	if (ft_strequ(cmds[0], "unsetenv"))
	{
		envdelkey(&shell->env, cmds[1]);
		result = 1;
	}
	if (ft_strequ(cmds[0], "env"))
	{
		listenv(shell->env);
		result = 1;
	}
	return (result);
}
