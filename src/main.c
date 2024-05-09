/* ************************************************************************** */
/*                                                                            */
/*    main.c                                                                  */
/*                                                                            */
/*    By: Antoine Massias <massias.antoine.pro@gmail.com>                     */
/*                                                                            */
/*    Created: 2024/05/09 15:24:50 by Antoine Massias                         */
/*    Updated: 2024/05/09 15:24:50 by Antoine Massias                         */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	window_t	*window;

	window = window_create(1920, 1080, "title");
	if (window == NULL)
	{
		dprintf(STDERR_FILENO, "Could not create window.\n");
		return (1);
	}
	while (!window_should_close(window))
	{
		window_update(window);
	}
	window_destroy(&window);
	return (0);
}
