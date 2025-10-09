/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devjorginho <devjorginho@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 18:11:29 by jde-carv          #+#    #+#             */
/*   Updated: 2025/10/09 12:54:54 by devjorginho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void init_stacks(t_stacks *stack, int ac, char **argv)
{
    int i;
    int j;
    int total_count;
    char **split;

    total_count = 0;
    i = 1;
    while (i < ac)
    {
        split = ft_split(argv[i], ' ');
        j = 0;
        while (split[j])
        {
            total_count++;
            j++;
        }
        free_string(split);
        i++;
    }
    stack->stack_a = ft_calloc(total_count, sizeof(int));
    stack->stack_b = ft_calloc(total_count, sizeof(int));
    stack->normalized_a = ft_calloc(total_count, sizeof(int));
    stack->len_stack_a = total_count;
    stack->len_stack_b = 0;
}

void populate_stack(t_stacks *stack, int ac, char **argv)
{
    int i;
    int j;
    int idx;
    char **split;

    idx = 0;
    i = 1;
    while (i < ac)
    {
        split = ft_split(argv[i], ' ');
        j = 0;
        while (split[j])
        {
            stack->stack_a[idx++] = ft_atoi(split[j]);
            j++;
        }
        free_string(split);
        i++;
    }
}

