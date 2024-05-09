/* ************************************************************************** */
/*                                                                            */
/*    create.c                                                                */
/*                                                                            */
/*    By: Antoine Massias <massias.antoine.pro@gmail.com>                     */
/*                                                                            */
/*    Created: 2024/05/09 17:14:40 by Antoine Massias                         */
/*    Updated: 2024/05/09 17:27:45 by Antoine Massias                         */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

#include <stdlib.h>
#include <string.h>

window_t	*window_create(
				unsigned int width,
				unsigned int height,
				const char *title
				)
{
	window_t	*window;

	if (!glfwInit())
		return (NULL);
	window = (window_t *) malloc(sizeof(window_t));
	if (window == NULL)
		return (NULL);
	*window = (window_t){
		.width = width,
		.height = height,
		.title = strdup(title),
		.handle = NULL,
	};
	if (window->title == NULL)
		goto ____error;
	window->handle = glfwCreateWindow(width, height, window->title, NULL, NULL);
	if (window->handle == NULL)
		goto ____error;
	goto ____end;
____error:
	window_destroy(&window);
____end:
	return (window);
}
