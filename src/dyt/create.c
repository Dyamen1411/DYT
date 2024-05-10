/* ************************************************************************** */
/*                                                                            */
/*    create.c                                                                */
/*                                                                            */
/*    By: Antoine Massias <massias.antoine.pro@gmail.com>                     */
/*                                                                            */
/*    Created: 2024/05/09 19:58:00 by Antoine Massias                         */
/*    Updated: 2024/05/09 20:09:35 by Antoine Massias                         */
/*                                                                            */
/* ************************************************************************** */

#include "dyt.h"

#include <pty.h>
#include <pwd.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define SHELL_ENVIRONEMENT_VARIABLE_NAME "SHELL"

static char	*_get_shell_path(void);

dyt_t	*dyt_create(void)
{
	dyt_t	*dyt;

	dyt = (dyt_t *) calloc(1, sizeof(dyt_t));
	if (dyt == NULL)
		goto ____error;
	dyt->shell_path = _get_shell_path();
	if (dyt->shell_path == NULL)
		goto ____error;
	dyt->window = window_create(
			WINDOW_DEFAULT_WIDTH,
			WINDOW_DEFAULT_HEIGHT,
			WINDOW_DEFAULT_TITLE
			);
	if (dyt->window == NULL)
		goto ____error;
	dyt->pty.name[PATH_MAX] = '\0';
	if (openpty(&dyt->pty.master, &dyt->pty.slave, dyt->pty.name, NULL, NULL))
		goto ____error;
	goto ____end;
____error:
	dyt_destroy(&dyt);
____end:
	return (dyt);
}

static char	*_get_shell_path(void)
{
	struct passwd	*user;
	char			*shell_path;

	shell_path = getenv(SHELL_ENVIRONEMENT_VARIABLE_NAME);
	if (shell_path)
		return (strdup(shell_path));
	user = getpwuid(getuid());
	if (user)
		return (strdup(user->pw_shell));
	return (NULL);
}
