/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devjorginho <devjorginho@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 12:37:44 by jde-carv          #+#    #+#             */
/*   Updated: 2025/10/08 19:35:27 by devjorginho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	push_elements(int *src, int *dst, int *len_src, int *len_dst)
{
	int	i;

	if (*len_src <= 0)
		return ;
	i = *len_dst;
	while (i > 0)
	{
		dst[i] = dst[i - 1];
		i--;
	}
	dst[0] = src[0];
	(*len_dst)++;
	(*len_src)--;
	i = 0;
	while (i < *len_src)
	{
		src[i] = src[i + 1];
		i++;
	}
}

void	pa(t_stacks *stacks)
{
	push_elements(stacks->stack_b, stacks->stack_a,
		&stacks->len_stack_b, &stacks->len_stack_a);
	write(1, "pa\n", 3);
}

void	pb(t_stacks *stacks)
{
	push_elements(stacks->stack_a, stacks->stack_b,
		&stacks->len_stack_a, &stacks->len_stack_b);
	write(1, "pb\n", 3);
}
