/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 11:33:04 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/04/23 06:10:30 by dmoureu-         ###   ########.fr       */
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

void	execcommand(char *line, t_shell *shell)
{
	pid_t	father;
	char	*tmp;

	if (ft_strchr(line, '~'))
	{
		line = ft_strrepchrbystr(line, '~', envgetkey(shell->env, "HOME"));
	}
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
			exit(EXIT_SUCCESS);
		}
	}
}

int		main(int ac, char **argv, char **environ)
{
	char	*line;
	t_shell	*shell;

	ft_signal();
	shell = newshell(environ);
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
		{
			execcommand(line, shell);
			free(line);
			line = NULL;
		}
		else
			exit(EXIT_FAILURE);
	}
}
