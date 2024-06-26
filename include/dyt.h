/* ************************************************************************** */
/*                                                                            */
/*    dyt.h                                                                   */
/*                                                                            */
/*    By: Antoine Massias <massias.antoine.pro@gmail.com>                     */
/*                                                                            */
/*    Created: 2024/05/09 17:38:20 by Antoine Massias                         */
/*    Updated: 2024/05/09 19:54:20 by Antoine Massias                         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DYT_H
# define DYT_H

# include "window.h"

# include <limits.h>

struct	dyt_s
{
	struct pty_s
	{
		int			master;
		int			slave;
		char		name[PATH_MAX + 1];
	}			pty;
	char		*shell_path;
	window_t	*window;
};

typedef struct dyt_s	dyt_t;

dyt_t	*dyt_create(void);

void	dyt_destroy(
			dyt_t **dyt_ptr
			);

#endif
