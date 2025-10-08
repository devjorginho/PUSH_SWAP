/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-carv <jde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:50:03 by jde-carv          #+#    #+#             */
/*   Updated: 2025/10/06 21:34:03 by jde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	swap_elements(int *stack, int stack_size)
{
	int	swap;

	if (!stack || !*stack)
		return ;
	if (stack_size < 2)
		return ;
	swap = stack[0];
	stack[0] = stack[1];
	stack[1] = swap;
}

void	sa(t_stacks *stack)
{
	swap_elements(stack->stack_a, stack->len_stack_a);
	write(1, "sa\n", 3);
}

void	sb(t_stacks *stack)
{
	swap_elements(stack->stack_b, stack->len_stack_b);
	write(1, "sb\n", 3);
}

void	ss(t_stacks *stack)
{
	swap_elements(stack->stack_a, stack->len_stack_a);
	swap_elements(stack->stack_b, stack->len_stack_b);
	write(1, "ss\n", 3);
}
