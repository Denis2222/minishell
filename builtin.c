/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 22:05:31 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/04/02 20:23:37 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

int	builtin(t_shell *shell, char *cmd)
{
	int		result;
	char	**cmds;

	(void)shell;
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
		envsetkey(shell->env, cmds[1], cmds[2]);
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
