/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 22:05:59 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/04/01 22:06:34 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <limits.h>

char	*getdir(void)
{
	char	*path;
	char	*cwd;

	path = (char*)malloc(sizeof(char) * (PATH_MAX + 1));
	cwd = getcwd(path, (PATH_MAX + 1));
	return (path);
}
