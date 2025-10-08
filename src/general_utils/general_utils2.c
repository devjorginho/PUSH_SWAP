/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-carv <jde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 17:07:54 by jde-carv          #+#    #+#             */
/*   Updated: 2025/10/08 17:37:45 by jde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ft_perror(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
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

