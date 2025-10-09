/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devjorginho <devjorginho@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 17:51:56 by jde-carv          #+#    #+#             */
/*   Updated: 2025/10/09 12:56:18 by devjorginho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ft_perror(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
void	free_string(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
int find_min_index(int *stack, int len)
{
    int i;
    int min_index;

    i = 1;
    min_index = 0;
    while (i < len)
    {
        if (stack[i] < stack[min_index])
            min_index = i;
        i++;
    }
    return min_index;
}

void push_min_to_b(t_stacks *stacks)
{
    int min_index;

    min_index = find_min_index(stacks->stack_a, stacks->len_stack_a);
    if (min_index <= stacks->len_stack_a / 2)
    {
        while (min_index-- > 0)
            ra(stacks);
    }
    else
    {
        min_index = stacks->len_stack_a - min_index;
        while (min_index-- > 0)
            rra(stacks);
    }
    pb(stacks);
}
