/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devjorginho <devjorginho@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 12:56:51 by jde-carv          #+#    #+#             */
/*   Updated: 2025/10/08 19:14:45 by devjorginho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int ac, char **av)
{
	t_stacks		stacks;
	static t_verify	verify;

	init_stacks(&stacks, ac, av, &verify);
	populate_stack(&stacks, ac, av);
	validate_arguments(&stacks, &verify);
	exec_sort(&stacks);
	free_stacks(&stacks, &verify);
	return (0);
}
