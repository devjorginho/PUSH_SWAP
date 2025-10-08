/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devjorginho <devjorginho@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 18:14:31 by jde-carv          #+#    #+#             */
/*   Updated: 2025/10/08 19:13:39 by devjorginho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	sort_two(t_stacks *stacks)
{
	if (stacks->len_stack_a < 2)
		return ;
	if (stacks->stack_a[0] > stacks->stack_a[1])
		sa(stacks);
}

void	sort_three(t_stacks *stack)
{
	int	a;
	int	b;
	int	c;

	a = stack->stack_a[0];
	b = stack->stack_a[1];
	c = stack->stack_a[2];
	if (a > b && b < c && a < c)
		sa(stack);
	else if (a > b && b < c && a > c)
		ra(stack);
	else if (a < b && b > c && a < c)
	{
		sa(stack);
		ra(stack);
	}
	else if (a < b && b > c && a > c)
		rra(stack);
	else if (a > b && b > c)
	{
		sa(stack);
		rra(stack);
	}
}
void	real_four_five_sort(t_stacks *stacks)
{
	if (stacks->len_stack_a == 5)
		pb(stacks);
	pb(stacks);
	sort_three(stacks);
	while (stacks->len_stack_b > 0)
	{
		if (stacks->stack_b[0] < stacks->stack_a[0])
			pa(stacks);
		else if (stacks->stack_b[0] < stacks->stack_a[1])
			(ra(stacks), pa(stacks), rra(stacks));
		else if (stacks->stack_b[0] < stacks->stack_a[2])
		{
			if (stacks->len_stack_a == 4)
				rra(stacks);
			(rra(stacks), pa(stacks), ra(stacks), ra(stacks));
			if (stacks->len_stack_a == 5)
				ra(stacks);
		}
		else if (stacks->len_stack_a == 4
			&& stacks->stack_b[0] < stacks->stack_a[3])
			(rra(stacks), pa(stacks), ra(stacks), ra(stacks));
		else
			(pa(stacks), ra(stacks));
	}
}

void	sort_four(t_stacks *stacks)
{
	real_four_five_sort(stacks);
}

void	sort_five(t_stacks *stacks)
{
	real_four_five_sort(stacks);
}

void	radix_sort(t_stacks *stacks)
{
	int	i;
	int	j;
	int	max;
	int len;

	len = stacks->len_stack_a;
	normalize_stack(stacks);
	max = max_index(stacks);
	while ((max >> stacks->max_bits) != 0)
		stacks->max_bits++;
	j = 0;
	while (j < stacks->max_bits)
	{
		i = 0;
		while (i < len)
		{
			if (((stacks->normalized_a[0] >> j) & 1) == 0)
				pb(stacks);
			else
				ra(stacks);
			i++;
		}
		while (stacks->len_stack_b > 0)
			pa(stacks);
		j++;
	}
}
