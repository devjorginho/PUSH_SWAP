/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-carv <jde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 12:56:51 by jde-carv          #+#    #+#             */
/*   Updated: 2025/10/07 17:49:36 by jde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int ac, char **av)
{
	t_stacks		stacks;
	static t_verify	verify;

	init_stacks(&stacks, ac, av);
	populate_stack(&stacks, ac, av);
	validate_arguments(&stacks, &verify);
	exec_sort(&stacks);
	free_stacks(&stacks);
	return (0);
}
