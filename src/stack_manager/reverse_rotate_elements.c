/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_elements.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devjorginho <devjorginho@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:49:49 by jde-carv          #+#    #+#             */
/*   Updated: 2025/10/08 19:35:10 by devjorginho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	reverse_rotate_elements(int *stack, int stack_size)
{
	int	last;
	int	i;

	if (!stack || stack_size < 2)
		return ;
	last = stack[stack_size - 1];
	i = stack_size - 1;
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
