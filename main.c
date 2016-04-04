/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 11:33:04 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/04/01 22:05:17 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *ft_strrepchr(char *str, char c, char n)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			str[i] = n;
		i++;
	}
	return (str);
}

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
