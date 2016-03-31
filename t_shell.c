#include "minishell.h"

t_shell	*newshell(void)
{
	t_shell	*shell;

	shell = (t_shell*)malloc(sizeof(t_shell));
	shell->env = loadenv();
	return (shell);
}
