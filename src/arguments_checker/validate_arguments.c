/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-carv <jde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:58:00 by jde-carv          #+#    #+#             */
/*   Updated: 2025/10/07 17:12:06 by jde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	check_repeated(t_stacks *stack, t_verify *verify)
{
	int	i;
	int	j;

	verify->has_repeated = 0;
	i = 0;
	while (i < stack->len_stack_a)
	{
		j = i + 1;
		while (j < stack->len_stack_a)
		{
			if (stack->stack_a[i] == stack->stack_a[j])
				verify->has_repeated = 1;
			j++;
		}
		i++;
	}
}

static void	check_sorted(t_stacks *stack, t_verify *verify)
{
	int	i;

	verify->is_sorted = 1;
	i = 0;
	while (i < stack->len_stack_a - 1)
	{
		if (stack->stack_a[i] > stack->stack_a[i + 1])
		{
			verify->is_sorted = 0;
			return ;
		}
		i++;
	}
}

void	validate_arguments(t_stacks *stack, t_verify *verify)
{
	check_repeated(stack, verify);
	check_sorted(stack, verify);
	if (verify->has_repeated)
		ft_perror();
	if (verify->is_sorted)
		exit(0);
}
