/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 13:41:17 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/04/23 04:57:47 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"

typedef struct		s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}					t_env;

typedef struct		s_shell
{
	t_env			*env;
	char			**envtxt;
}					t_shell;

t_shell				*newshell(char **environ);
void				shell_env_refresh(t_shell *shell);

t_env				*loadenv(char **environ);
t_env				*environtoenv(char **environ, int i);
int					envlen(t_env *env);
char				*getsyspath(void);
char				*envgetkey(t_env *env, char *key);
int					listenv(t_env *list);
char				**genenv(t_env *list);
int					envsetkey(t_env *env, char *key, char *value);
int					envdelkey(t_env **list, char *key);
t_env				*newenv(char *key, char *value);
t_env				*addenv(t_env **list, t_env *env);
void				delenv(t_env *this);

char				*getdir(void);
void				prompt(void);
int					command(t_shell *shell, char *cmd);
int					builtin(t_shell *shell, char *cmd);
int					cdcmd(t_shell *shell, char **cmds);
void				changedir(t_shell *shell, char *dir);
int					body(void);

char				*ft_replacechrbystr(char *str, char old, char *pwd);

#endif
