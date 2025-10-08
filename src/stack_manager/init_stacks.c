/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-carv <jde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 18:11:29 by jde-carv          #+#    #+#             */
/*   Updated: 2025/10/08 17:41:55 by jde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	init_stacks(t_stacks *stack, int ac, char **argv, t_verify *verify)
{
	if (ac == 2)
	{
		verify->is_a_list = 1;
		stack->arguments_to_split = ft_split(argv[1], ' ');
		stack->len_stack_a = 0;
		while (stack->arguments_to_split[stack->len_stack_a])
			stack->len_stack_a++;
	}
	else
		stack->len_stack_a = ac - 1;
	stack->stack_a = ft_calloc(stack->len_stack_a, sizeof(int));
	stack->normalized_a = ft_calloc(stack->len_stack_a, sizeof(int));
	stack->stack_b = ft_calloc(stack->len_stack_a, sizeof(int));
	stack->len_stack_b = 0;
	if (!stack->stack_a || !stack->stack_b || !stack->normalized_a)
		return ;
}

void	populate_stack(t_stacks *stack, int ac, char **argv)
{
	int	i;

	i = 0;
	while (i < stack->len_stack_a)
	{
		if (ac == 2)
			stack->stack_a[i] = ft_atoi(stack->arguments_to_split[i]);
		else
			stack->stack_a[i] = ft_atoi(argv[i + 1]);
		i++;
	}
}
