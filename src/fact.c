/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fact.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fleonard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/17 15:29:01 by fleonard     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/17 15:29:03 by fleonard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fact.h"

void	initialize_fact(void)
{
	mpz_init(g_n);
	mpz_init(g_x);
	mpz_init(g_y);
	mpz_init(g_d);
}

void	terminate_fact(void)
{
	mpz_clear(g_n);
	mpz_clear(g_x);
	mpz_clear(g_y);
	mpz_clear(g_d);
}

void	f(mpz_t g_x, mpz_t g_n)
{
	mpz_pow_ui(g_x, g_x, 2);
	mpz_add_ui(g_x, g_x, RHO_CONST);
	mpz_mod(g_x, g_x, g_n);
}

int		prho(mpz_t g_n)
{
	unsigned long ctr;

	ctr = 0;
	mpz_set_ui(g_x, 2);
	mpz_set_ui(g_y, 2);
	mpz_set_ui(g_d, 1);
	while (mpz_cmp_ui(g_d, 1) == 0 && ctr < 10000)
	{
		f(g_x, g_n);
		f(g_y, g_n);
		f(g_y, g_n);
		mpz_sub(g_d, g_x, g_y);
		mpz_abs(g_d, g_d);
		mpz_gcd(g_d, g_d, g_n);
		ctr++;
	}
	if (mpz_cmp_ui(g_d, 1) != 0)
	{
		gmp_printf("%Zd=", g_n);
		gmp_printf("%Zd", g_d);
		mpz_tdiv_q(g_n, g_n, g_d);
		gmp_printf("*%Zd\n", g_n);
		return (1);
	}
	return (0);
}
