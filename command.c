#include "minishell.h"

int	command(t_shell *shell, char *cmd)
{
	int		result;
	char	**paths;
	char	**cmds;
	int		i;
	char	*prgtry;

	result = 0;
	cmds = ft_strsplit(cmd, ' ');
	if (!builtin(shell, cmds))
	{
		paths = ft_strsplit(envgetkey(shell->env, "PATH"), ':');
		i = 0;
		while (paths[i])
		{
			prgtry = ft_strjoin(paths[i], "/");
			prgtry = ft_strjoin(prgtry, cmds[0]);
			result = execve(prgtry, cmds, environ);
			i++;;
		}
		if (ft_strcmp(cmd, "") != 0)
			ft_printf("{red}Command not found !{eoc}\n");
	}
	return (result);
}
