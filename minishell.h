/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 13:41:17 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/04/02 19:57:32 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"

extern		char **environ;

typedef struct	s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}					t_env;

typedef struct		s_shell
{
	t_env			*env;
}					t_shell;

t_shell				*newshell(void);

t_env				*loadenv(void);
t_env				*forcepath(void);
char				*envgetkey(t_env *env, char *key);
void				listenv(t_env *list);
void				envsetkey(t_env *env, char *key, char *value);
void				envdelkey(t_env **list, char *key);

char				*getdir(void);
void				prompt(void);
int					command(t_shell *shell, char *cmd);
int					builtin(t_shell *shell, char *cmd);
void				cdcmd(t_shell *shell, char **cmds);
void				changedir(t_shell *shell, char *dir);

#endif
