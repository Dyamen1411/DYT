/* ************************************************************************** */
/*                                                                            */
/*    destroy.c                                                                */
/*                                                                            */
/*    By: Antoine Massias <massias.antoine.pro@gmail.com>                     */
/*                                                                            */
/*    Created: 2024/05/09 17:22:30 by Antoine Massias                         */
/*    Updated: 2024/05/09 17:29:35 by Antoine Massias                         */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

#include <stdlib.h>

void	window_destroy(
			window_t	**window_ptr
			)
{
	window_t	*window;

	if (*window_ptr == NULL)
		return ;
	window = *window_ptr;
	if (window->handle)
		glfwDestroyWindow(window->handle);
	if (window->title)
		free(window->title);
	free(window);
	*window_ptr = NULL;
	glfwTerminate();
}
