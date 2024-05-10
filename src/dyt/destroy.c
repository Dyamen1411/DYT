/* ************************************************************************** */
/*                                                                            */
/*    destroy.c                                                               */
/*                                                                            */
/*    By: Antoine Massias <massias.antoine.pro@gmail.com>                     */
/*                                                                            */
/*    Created: 2024/05/09 20:10:35 by Antoine Massias                         */
/*    Updated: 2024/05/09 20:10:35 by Antoine Massias                         */
/*                                                                            */
/* ************************************************************************** */

#include "dyt.h"

#include <stdlib.h>

void	dyt_destroy(
			dyt_t **dyt_ptr
			)
{
	dyt_t	*dyt;

	if (*dyt_ptr == NULL)
		return ;
	dyt = *dyt_ptr;
	if (dyt->window)
		window_destroy(&dyt->window);
	if (dyt->shell_path)
		free(dyt->shell_path);
	free(dyt);
	*dyt_ptr = NULL;
}
