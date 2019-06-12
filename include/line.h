/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   line.h                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fleonard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/17 15:26:37 by fleonard     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/17 15:26:38 by fleonard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LINE_H
# define LINE_H

# include <unistd.h>

# define MAX_LINE 5000
# define MAX_LEN_LINE 500
# define BUFFER 42000

typedef struct s_line	t_line;

struct	s_line
{
	char	str[MAX_LEN_LINE];
	int		num;
	int		len;
};

typedef struct s_lines	t_lines;

struct	s_lines
{
	t_line	ll[MAX_LINE];
	int		max;
};

#endif
