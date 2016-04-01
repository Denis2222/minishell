/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_env.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 15:49:06 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/04/01 17:01:25 by dmoureu-         ###   ########.fr       */
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

void	delenv(t_env *this)
{
	free(this->key);
	this->key = NULL;
	free(this->value);
	this->value = NULL;
	this->next = NULL;
	free(this);
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

void	envsetkey(t_env *env, char *key, char *value)
{
	int		keyfound;
	t_env	*init;

	init = env;
	keyfound = 0;
	while (env && !keyfound)
	{
		if (ft_strequ(env->key, key))
		{
			keyfound = 1;
			free(env->value);
			env->value = NULL;
			env->value = ft_strdup(value);
		}
		else
			env = env->next;
	}
	if (!keyfound)
	{
		addenv(&init, newenv(key, value));
	}
}

void	envdelkey(t_env *env, char *key)
{
	int		keyfound;
	t_env	*tmp;

	keyfound = 0;
	while (env && !keyfound)
	{
		if (ft_strequ(env->key, key))
		{
			keyfound = 1;
			tmp = env;
			ft_printf("tmpkey:[%s]", tmp->key);
			//delenv(env);
			env = tmp;
		}
		else
			env = env->next;
	}
}

void	listenv(t_env *env)
{
	while (env)
	{
		ft_printf("%s=%s\n", env->key, env->value);
		env = env->next;
	}
}
