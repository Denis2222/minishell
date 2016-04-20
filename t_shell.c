/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_shell.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 22:06:54 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/04/18 18:08:37 by dmoureu-         ###   ########.fr       */
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
