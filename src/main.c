/* ************************************************************************** */
/*                                                                            */
/*    main.c                                                                  */
/*                                                                            */
/*    By: Antoine Massias <massias.antoine.pro@gmail.com>                     */
/*                                                                            */
/*    Created: 2024/05/09 15:24:50 by Antoine Massias                         */
/*    Updated: 2024/05/09 18:02:10 by Antoine Massias                         */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"
#include "dyt.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	window_t	*window;
	char *shell_path;

	shell_path = get_shell_path();
	printf("%s\n", shell_path);
	free((void *)shell_path);
	window = window_create(1920, 1080, "title");
	if (window == NULL)
	{
		dprintf(STDERR_FILENO, "Could not create window.\n");
		return (1);
	}
	while (!window_should_close(window))
		window_update(window);
	window_destroy(&window);
	return (0);
}
