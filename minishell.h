/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 13:41:17 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/03/29 17:14:13 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libftprintf/ft_printf.h"

extern		char **environ;

typedef struct	s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}					t_env;

void	loadenv(void);

#endif
