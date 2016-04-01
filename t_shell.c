/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_shell.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 22:06:54 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/04/01 22:06:57 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_shell	*newshell(void)
{
	t_shell	*shell;

	shell = (t_shell*)malloc(sizeof(t_shell));
	shell->env = loadenv();
	return (shell);
}
