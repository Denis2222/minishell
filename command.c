/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 22:05:54 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/04/07 22:32:46 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	command(t_shell *shell, char *cmd)
{
	int		result;
	char	**paths;
	char	**cmds;
	int		i;
	char	*prgtry;

	result = 0;
	cmds = ft_strsplit(cmd, ' ');
	paths = ft_strsplit(envgetkey(shell->env, "PATH"), ':');
	i = 0;
	while (paths[i])
	{
		prgtry = ft_strjoin(paths[i], "/");
		prgtry = ft_strjoin(prgtry, cmds[0]);
		result = execve(prgtry, cmds, environ);
		i++;
	}
	result = execve(cmds[0], cmds, environ);
	if (ft_strcmp(cmd, "") != 0)
		ft_printf("{red}Command not found !{eoc}\n");
	return (result);
}
