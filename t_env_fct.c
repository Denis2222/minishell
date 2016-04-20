/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_env_fct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 22:34:37 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/04/18 18:23:47 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		fun(void)
{
	int		fd;
	char	*buffer;

	buffer = NULL;
	fd = open("./test.c", O_RDONLY);
	while (get_next_line(fd, &buffer))
	{
		ft_printf("%s\n", buffer);
		free(buffer);
	}
	return (1);
}

char	*forcepath(void)
{
	char	*buffer;
	char	*path;
	int		fd;
	int		first;
	char	*oldpath;

	buffer = NULL;
	first = 1;
	fd = open("/etc/paths", O_RDONLY);
	while (get_next_line(fd, &buffer))
	{
		if (!first)
		{
			oldpath = path;
			path = ft_strjoin(path, ":");
			free(oldpath);
			path = ft_strjoin(path, buffer);
		}
		else
			path = ft_strdup(buffer);
		free(buffer);
		buffer = NULL;
		first = 0;
	}
	return (path);
}

t_env	*loadenv(void)
{
	int		i;
	char	**tab;
	t_env	*new;
	t_env	*lst;
	t_env	*current;

	lst = NULL;
	i = 0;
	while (environ[i])
	{
		tab = ft_strsplit(environ[i], '=');
		if (ft_strequ(tab[0], "SHLVL"))
		{
			tab[1] = ft_itoa(ft_atoi(tab[1])+1);
		}
		new = newenv(tab[0], tab[1]);
		if (!lst)
		{
			lst = new;
			current = lst;
		}
		else
		{
			while (lst->next)
				lst = lst->next;
			lst->next = new;
		}
		i++;
	}
	if (!environ[0])
		return (newenv("PATH", forcepath()));
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

int		envsetkey(t_env *env, char *key, char *value)
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
		init = addenv(&init, newenv(key, value));
	return (1);
}

void	whileenvdelkey(t_env *env, t_env *last, t_env **list)
{
	t_env	*tmp;

	tmp = env;
	if (last)
	{
		last->next = env->next;
		delenv(tmp);
	}
	else
	{
		tmp = env;
		*list = env->next;
	}
}

int		envdelkey(t_env **list, char *key)
{
	int		keyfound;
	t_env	*env;
	t_env	*last;

	if (ft_strequ(key, "PATH"))
		return (envsetkey(*list, "PATH", forcepath()));
	env = *list;
	last = NULL;
	keyfound = 0;
	while (env && !keyfound)
	{
		if (ft_strequ(env->key, key))
		{
			keyfound = 1;
			whileenvdelkey(env, last, list);
		}
		else
		{
			last = env;
			env = env->next;
		}
	}
	return (1);
}
