/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_elements.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-carv <jde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:49:49 by jde-carv          #+#    #+#             */
/*   Updated: 2025/10/07 17:01:20 by jde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	reverse_rotate_elements(int *stack, int stack_size)
{
	int	last;
	int	i;

	i = stack_size - 1;
	last = stack[stack_size - 1];
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[0] = last;
}

void	rra(t_stacks *stack)
{
	reverse_rotate_elements(stack->stack_a, stack->len_stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_stacks *stack)
{
	reverse_rotate_elements(stack->stack_b, stack->len_stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stacks *stack)
{
	reverse_rotate_elements(stack->stack_a, stack->len_stack_a);
	reverse_rotate_elements(stack->stack_b, stack->len_stack_b);
	write(1, "rrr\n", 4);
}
