/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 22:05:59 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/04/23 03:18:07 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <limits.h>

char	*getdir(void)
{
	char	*path;

	path = (char*)malloc(sizeof(char) * (PATH_MAX + 1));
	if (!path)
		return (NULL);
	path = getcwd(path, (PATH_MAX + 1));
	return (path);
}
