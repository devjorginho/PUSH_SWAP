/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-carv <jde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 18:14:31 by jde-carv          #+#    #+#             */
/*   Updated: 2025/10/07 18:13:10 by jde-carv         ###   ########.fr       */
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

void	sort_four(t_stacks *stacks)
{
	int min_index;

	min_index = find_min_index(stacks->stack_a, stacks->len_stack_a);
	move_min_to_top(stacks, min_index);
	pb(stacks);
	sort_three(stacks);
	pa(stacks);
}

void	sort_five(t_stacks *stacks)
{
	int min_index;

	min_index = find_min_index(stacks->stack_a, stacks->len_stack_a);
	move_min_to_top(stacks, min_index);
	pb(stacks);
	min_index = find_min_index(stacks->stack_a, stacks->len_stack_a);
	move_min_to_top(stacks, min_index);
	pb(stacks);
	sort_three(stacks);
	pa(stacks);
	pa(stacks);
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
