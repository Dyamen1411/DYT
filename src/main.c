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

#include "dyt.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	dyt_t	*dyt;

	dyt = dyt_create();
	if (dyt == NULL)
		return (1);
	printf("%s\n", dyt->shell_path);
	while (!window_should_close(dyt->window))
		window_update(dyt->window);
	dyt_destroy(&dyt);
	return (0);
}
