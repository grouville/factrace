/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fleonard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/17 15:24:08 by fleonard     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/17 15:24:11 by fleonard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fact.h"
#include "line.h"

void	full_lines(t_lines *lines)
{
	char	buff[BUFFER + 1];
	int		i;
	int		ret;

	i = 0;
	if ((ret = read(0, buff, BUFFER)) > 0)
	{
		buff[ret] = 0;
		while (lines->max < MAX_LINE && i < ret)
		{
			if (i >= BUFFER)
			{
				lines->max--;
				break ;
			}
			if (buff[i] == '\n')
				lines->ll[lines->max++].num = lines->max + 1;
			else
				lines->ll[lines->max].str[lines->ll[lines->max].len++] = \
														buff[i];
			i++;
		}
	}
}

int		main(void)
{
	t_lines lines;
	int		i;

	lines = (t_lines){0};
	full_lines(&lines);
	initialize_fact();
	i = lines.max - 1;
	while (i >= 0)
	{
		mpz_set_str(g_n, lines.ll[i].str, 10);
		if (prho(g_n))
			break ;
		i--;
	}
	terminate_fact();
	return (0);
}
