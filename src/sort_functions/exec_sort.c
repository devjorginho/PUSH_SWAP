/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-carv <jde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 21:13:30 by jde-carv          #+#    #+#             */
/*   Updated: 2025/10/06 21:22:30 by jde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	exec_sort(t_stacks *stacks)
{
	if (stacks->len_stack_a == 2)
		sort_two(stacks);
	else if (stacks->len_stack_a == 3)
		sort_three(stacks);
	else if (stacks->len_stack_a == 4)
		sort_four(stacks);
	else if (stacks->len_stack_a == 5)
		sort_five(stacks);
	else
		radix_sort(stacks);
}
