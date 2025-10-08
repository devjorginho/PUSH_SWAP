/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-carv <jde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 21:23:53 by jde-carv          #+#    #+#             */
/*   Updated: 2025/10/08 17:43:33 by jde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	free_stacks(t_stacks *stack, t_verify *verify)
{
	if (stack->stack_a)
		free(stack->stack_a);
	if (stack->stack_b)
		free(stack->stack_b);
	if (stack->normalized_a)
		free(stack->normalized_a);
	if (verify->is_a_list)
		free(stack->arguments_to_split);
}
