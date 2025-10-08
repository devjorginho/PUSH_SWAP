/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devjorginho <devjorginho@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 21:13:30 by jde-carv          #+#    #+#             */
/*   Updated: 2025/10/08 19:50:56 by devjorginho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	exec_sort(t_stacks *stacks)
{
	if (stacks->len_stack_a == 2)
		sa(stacks);
	else if (stacks->len_stack_a == 3)
		sort_three(stacks);
	else if (stacks->len_stack_a == 4)
		sort_four(stacks);
	else if (stacks->len_stack_a == 5)
		sort_five(stacks);
	else
		radix_sort(stacks);
}
