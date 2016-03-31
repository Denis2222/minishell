#include "minishell.h"
#include <limits.h>


char	*getdir(void)
{
	char	*path;
	char	*cwd;

	path = (char*)malloc(sizeof(char) * (PATH_MAX + 1));
	cwd = getcwd(path, (PATH_MAX + 1));
	return (path);
}
