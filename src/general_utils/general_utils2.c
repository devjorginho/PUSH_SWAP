/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devjorginho <devjorginho@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 17:07:54 by jde-carv          #+#    #+#             */
/*   Updated: 2025/10/09 12:56:01 by devjorginho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int max_index(t_stacks *stack)
{
    int i;
    int max;

    max = stack->normalized_a[0];
    i = 1;
    while (i < stack->len_stack_a)
    {
        if (stack->normalized_a[i] > max)
            max = stack->normalized_a[i];
        i++;
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
void setup_radix_counters(t_stacks *stacks, t_radix_counters *setup)
{
    setup->len = stacks->len_stack_a;
    normalize_stack(stacks);
    setup->i = 0;
    while (setup->i < setup->len)
    {
        stacks->stack_a[setup->i] = stacks->normalized_a[setup->i];
        setup->i++;
    }
    setup->max = max_index(stacks);
    setup->max_bits = 0;
    while ((setup->max >> setup->max_bits) != 0)
        setup->max_bits++;
}

