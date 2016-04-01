/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 22:05:31 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/04/01 22:05:40 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin(t_shell *shell, char *cmd)
{
	int		result;
	char	**cmds;

	(void)shell;
	result = 0;
	cmds = ft_strsplit(cmd, ' ');
	if (ft_strequ(cmds[0], "cd"))
	{
		changedir(shell, cmds[1]);
		result = 1;
	}
	if (ft_strequ(cmds[0], "exit"))
		exit(EXIT_SUCCESS);
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
