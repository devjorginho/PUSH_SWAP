/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devjorginho <devjorginho@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 17:07:54 by jde-carv          #+#    #+#             */
/*   Updated: 2025/10/08 19:13:36 by devjorginho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ft_perror(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
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

