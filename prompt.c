#include "minishell.h"

void	prompt(void)
{
	char	*buf;

	buf = getdir();
	ft_printf("{blue}$[%s]> {eoc}", buf);
	free(buf);
}
