/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 11:33:04 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/04/05 20:04:02 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <signal.h>

void	sig_handler(int echo)
{

	//ft_printf("Signal receive %d \n", echo);
	
	if (echo == SIGINT)
	{
		return ;
		ft_putchar('\n');
		prompt();
		//ft_printf("SIGINT");
	}
	if (echo == SIGCHLD)
	{
//		kill(3);
	//	exit(EXIT_SUCCESS);
		return ;
	}
}

static void ft_signal(void)
{
	int		i;

	i = 0;
	while (i < 33)
	{
		signal(i, sig_handler);
		i++;
	}
}

int	main(void)
{
	char	*line;
	pid_t	father;
	t_shell	*shell;

	ft_signal();
	shell = newshell();
	while (42)
	{
		prompt();
		get_next_line(0, &line);
		line = ft_strrepchr(line, '\t', ' ');
		if (line)
		{
			if (!builtin(shell, line))
			{
				father = fork();
				if (father > 0)
				{
					wait(&father);
				}
				else if (father == 0)
				{
					if (command(shell, line))
					{
						exit(EXIT_FAILURE);
					}
					else
						exit(EXIT_FAILURE);
				}
			}
		}
		else
			exit(EXIT_FAILURE);
	}
}
