/* ************************************************************************** */
/*                                                                            */
/*    get_shell_path.c                                                        */
/*                                                                            */
/*    By: Antoine Massias <massias.antoine.pro@gmail.com>                     */
/*                                                                            */
/*    Created: 2024/05/09 17:39:30 by Antoine Massias                         */
/*    Updated: 2024/05/09 18:00:05 by Antoine Massias                         */
/*                                                                            */
/* ************************************************************************** */

#include <pwd.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static char	*_extract_shell_path(void)
{
	const struct passwd	*user = getpwuid(getuid());

	if (user == NULL)
		return (NULL);
	return (strdup(user->pw_shell));
}

char	*get_shell_path(void)
{
	char	*shell_path;

	shell_path = getenv("SHELL");
	if (shell_path)
		shell_path = strdup(shell_path);
	else
		shell_path = _extract_shell_path();
	return (shell_path);
}
