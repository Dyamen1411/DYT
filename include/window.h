/* ************************************************************************** */
/*                                                                            */
/*    window.h                                                                */
/*                                                                            */
/*    By: Antoine Massias <massias.antoine.pro@gmail.com>                     */
/*                                                                            */
/*    Created: 2024/05/09 17:09:35 by Antoine Massias                         */
/*    Updated: 2024/05/09 20:00:15 by Antoine Massias                         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include <GLFW/glfw3.h>
# include <stdbool.h>

# define WINDOW_DEFAULT_WIDTH 1920
# define WINDOW_DEFAULT_HEIGHT 1080
# define WINDOW_DEFAULT_TITLE "title"

struct window_s
{
	GLFWwindow		*handle;
	unsigned int	width;
	unsigned int	height;
	char			*title;
};

typedef struct window_s	window_t;

window_t	*window_create(
				unsigned int width,
				unsigned int height,
				const char *title
				);

bool		window_should_close(
				window_t *window
				);

void		window_update(
				window_t *window
				);

void		window_destroy(
				window_t	**window_ptr
				);

#endif