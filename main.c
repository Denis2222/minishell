/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 11:33:04 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/04/20 14:23:11 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <signal.h>

void	sig_handler(int echo)
{
	if (echo == SIGINT)
	{
		exit(0);
	}
}

void	ft_signal(void)
{
	int		i;

	i = 0;
	while (i < 33)
	{
		if (i == SIGINT)
			signal(i, sig_handler);
		i++;
	}
}

void	treatment(char *line, t_shell *shell)
{
	pid_t	father;

	if (!builtin(shell, line))
	{
		father = fork();
		if (father > 0)
		{
			wait(&father);
		}
		else if (father == 0)
		{
			command(shell, line);
		}
	}
}

int		main(void)
{
	char	*line;
	t_shell	*shell;

	ft_signal();
	shell = newshell();
	while (42)
	{
		prompt();
		if (!get_next_line(0, &line))
		{
			ft_printf("\n");
			exit(EXIT_SUCCESS);
		}
		line = ft_strrepchr(line, '\t', ' ');
		if (line)
			treatment(line, shell);
		else
			exit(EXIT_FAILURE);
	}
}
