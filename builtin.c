#include "minishell.h"

int	builtin(t_shell *shell, char *cmd)
{
	int		result;
	char	**cmds;

	(void)shell;
	result = 0;
	cmds = ft_strsplit(cmd, ' ');
	if (ft_strequ(cmds[0], "cd"))
	{
		changedir(shell, cmds[1]);
		result = 1;
	}
	if (ft_strequ(cmds[0], "exit"))
	{
		exit(EXIT_SUCCESS);
	}
	if (ft_strequ(cmds[0], "setenv"))
	{
		result = 1;
	}
	if (ft_strequ(cmds[0], "unsetenv"))
	{
		result = 1;
	}
//	if (ft_strequ(cmds[0], "env"))
//	{
//		result = 1;
//	}
	return (result);
}
