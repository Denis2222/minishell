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

t_env	*addenv(t_env **list, t_env *env)
{
	t_env *current;

	ft_printf("addenv");
	current = *list;
	if (!current)
		current = env;
	while (current->next)
	{
		current = current->next;
	}
	current->next = env;
	return (*list);
}

t_env	*loadenv(void)
{
	int	i;
	char	**tab;
	t_env	*new;
	t_env	*lst;
	t_env	*current;

	lst = NULL;
	i = 0;
	while (environ[i])
	{
		tab = ft_strsplit(environ[i], '=');
		new = newenv(tab[0], tab[1]);
		if (!lst)
		{
			lst = new;
			current = lst;
		}
		else
		{
			while(lst->next)
				lst = lst->next;
			lst->next = new;
		}
		i++;
	}
	return (current);
}

char	*envgetkey(t_env *env, char *key)
{
	while (env)
	{
		if (ft_strcmp(env->key, key) == 0)
			return (env->value);
		else
			env = env->next;
	}
	return (NULL);
}
