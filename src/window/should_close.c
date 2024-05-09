/* ************************************************************************** */
/*                                                                            */
/*    should_close.c                                                          */
/*                                                                            */
/*    By: Antoine Massias <massias.antoine.pro@gmail.com>                     */
/*                                                                            */
/*    Created: 2024/05/09 17:30:10 by Antoine Massias                         */
/*    Updated: 2024/05/09 17:30:40 by Antoine Massias                         */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

bool		window_should_close(
				window_t *window
				)
{
	return (glfwWindowShouldClose(window->handle));
}
