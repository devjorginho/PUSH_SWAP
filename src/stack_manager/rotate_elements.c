/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_elements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devjorginho <devjorginho@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:49:58 by jde-carv          #+#    #+#             */
/*   Updated: 2025/10/08 19:34:52 by devjorginho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	rotate_elements(int *stack, int stack_size)
{
	int	first;
	int	i;

	if (!stack || stack_size < 2)
		return ;
	first = stack[0];
	i = 0;
	while (i < stack_size - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[stack_size - 1] = first;
}

void	ra(t_stacks *stack)
{
	rotate_elements(stack->stack_a, stack->len_stack_a);
	write(1, "ra\n", 3);
}

void	rb(t_stacks *stack)
{
	rotate_elements(stack->stack_b, stack->len_stack_b);
	write(1, "rb\n", 3);
}

void	rr(t_stacks *stack)
{
	rotate_elements(stack->stack_a, stack->len_stack_a);
	rotate_elements(stack->stack_b, stack->len_stack_b);
	write(1, "rr\n", 3);
}
