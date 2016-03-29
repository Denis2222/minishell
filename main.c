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
//	int		i;
	char	*line;
	char	*buf;
	pid_t	father;

//	i = 0;
	buf = NULL;
	(void)ac;
	(void)av;
//	line = NULL;
//	ft_printf("$> ");
/*	while (environ[i])
	{
		ft_putendl(environ[i]);
		i++;
	}
*/	

	loadenv();

	while (42)
	{
		get_next_line(0, &line);
		father = fork();
		if (father > 0)
		{
			wait(&father);
			buf = (char*)malloc(sizeof(char) * 1001);
			getcwd(buf, 1000);
			ft_printf("{red}$[%s]> {eoc}", buf);
			free(buf);
			buf = NULL;
		} else if (father == 0)
		{
			execve("/bin/ls", ft_strsplit(line, ' '), environ);
			exit(EXIT_FAILURE);
		}
	}
}
