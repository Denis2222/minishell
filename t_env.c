/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_env.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 15:49:06 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/04/20 13:44:15 by dmoureu-         ###   ########.fr       */
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
	t_env	*current;

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

int		listenv(t_env *env)
{
	while (env)
	{
		ft_printf("%s=%s\n", env->key, env->value);
		env = env->next;
	}
	return (1);
}

char	**genenv(t_env *env)
{
	char	**envtxt;
	int		nb;
	t_env	*c;

	c = env;
	nb = 0;
	while (env)
	{
		nb++;
		env = env->next;
	}
	envtxt = (char **)malloc(sizeof(char*) * (nb + 1));
	if (!envtxt)
		return (NULL);
	nb = 0;
	while (c)
	{
		envtxt[nb] = ft_strjoin(ft_strjoin(c->key, "="), c->value);
		c = c->next;
		nb++;
	}
	envtxt[nb] = NULL;
	return (envtxt);
}
