/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fact.h                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fleonard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/17 15:26:31 by fleonard     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/17 15:26:32 by fleonard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef _FACT_H
# define _FACT_H

# include "gmp.h"

# define RHO_CONST 101359

int		prho(mpz_t n);
void	initialize_fact();
void	terminate_fact();

static	mpz_t g_n;
static	mpz_t g_x;
static	mpz_t g_y;
static	mpz_t g_d;

#endif
