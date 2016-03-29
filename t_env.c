/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_env.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 15:49:06 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/03/29 17:14:39 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*newenv(char *key, char *value)
{
	t_env *this;

	this = (t_env*)malloc(sizeof(t_env));
	this->key = ft_strdup(key);
	this->value = ft_strdup(value);
	this->next = NULL;
	return (this);
}

void	addenv(t_env *list, t_env *env)
{
	t_env *current;

	current = list;
	if (!current)
		current = env;
	while (current->next)
	{
		current = current->next;
	}
	current->next = env;
}

void	loadenv(void)
{
	int	i;
	char	**tab;
	t_env	*line;
	t_env	*lst;

	lst = NULL;
	i = 0;
	while (environ[i])
	{
		tab = ft_strsplit(environ[i], '=');
		line = newenv(tab[0], tab[1]);
		addenv(lst, line);
		i++;
	}

	ft_printf("%s", lst->key);
}
