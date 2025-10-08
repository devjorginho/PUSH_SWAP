/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-carv <jde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 17:07:54 by jde-carv          #+#    #+#             */
/*   Updated: 2025/10/07 18:12:36 by jde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ft_perror(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	move_min_to_top(t_stacks *stacks, int min_index)
{
	if (min_index <= stacks->len_stack_a / 2)
	{
		while (min_index-- > 0)
			ra(stacks);
	}
	else
	{
		min_index = stacks->len_stack_a - min_index;
		while (min_index-- > 0)
			rra(stacks);
	}
}


int	find_min_index(int *stack, int len)
{
	int	min;
	int	i;

	min = stack[0];
	if (stack[1] < min)
	{
		i = 1;
		min = stack[1];
	}
	if (stack[2] < min)
	{
		i = 2;
		min = stack[2];
	}
	if (stack[3] < min)
	{
		i = 3;
		min = stack[3];
	}
	if (len == 5 && stack[4] < min)
	{
		i = 4;
		min = stack[4];
	}
	return (i);
}

int	max_index(t_stacks *stack)
{
	int	i;
	int	max;

	max = stack->normalized_a[0];
	for (i = 1; i < stack->len_stack_a; i++)
	{
		if (stack->normalized_a[i] > max)
			max = stack->normalized_a[i];
	}
	return (max);
}

void	normalize_stack(t_stacks *stack)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while (i < stack->len_stack_a)
	{
		count = 0;
		j = 0;
		while (j < stack->len_stack_a)
		{
			if (stack->stack_a[i] > stack->stack_a[j])
				count++;
			j++;
		}
		stack->normalized_a[i] = count;
		i++;
	}
}

