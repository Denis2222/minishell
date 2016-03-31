/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 11:33:04 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/03/29 17:12:53 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av)
{
	char	*line;
	pid_t	father;
	t_shell	*shell;

	shell = newshell();
	(void)ac;
	(void)av;

	while (42)
	{
		prompt();
		get_next_line(0, &line);
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
}
