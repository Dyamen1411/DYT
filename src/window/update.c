/* ************************************************************************** */
/*                                                                            */
/*    update.c                                                                */
/*                                                                            */
/*    By: Antoine Massias <massias.antoine.pro@gmail.com>                     */
/*                                                                            */
/*    Created: 2024/05/09 17:28:20 by Antoine Massias                         */
/*    Updated: 2024/05/09 17:29:10 by Antoine Massias                         */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

void	window_update(
			window_t *window
			)
{
	glfwPollEvents();
	glfwSwapBuffers(window->handle);
}
