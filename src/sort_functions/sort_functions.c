/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devjorginho <devjorginho@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 18:14:31 by jde-carv          #+#    #+#             */
/*   Updated: 2025/10/08 21:18:23 by devjorginho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void sort_three(t_stacks *stacks)
{
    int a = stacks->stack_a[0];
    int b = stacks->stack_a[1];
    int c = stacks->stack_a[2];

    if (a > b && b < c && a < c)
        sa(stacks);
    else if (a > b && b > c)
    {
        sa(stacks);
        rra(stacks);
    }
    else if (a > b && b < c && a > c)
        ra(stacks);
    else if (a < b && b > c && a < c)
    {
        sa(stacks);
        ra(stacks);
    }
    else if (a < b && b > c && a > c)
        rra(stacks);
}
void sort_four(t_stacks *stacks)
{
    push_min_to_b(stacks);
    sort_three(stacks);
    pa(stacks);
}
void sort_five(t_stacks *stacks)
{
    if (stacks->len_stack_a == 2)
    {
        if (stacks->stack_a[0] > stacks->stack_a[1])
            sa(stacks);
        return;
    }
    else if (stacks->len_stack_a == 3)
    {
        sort_three(stacks);
        return;
    }
    else
    {
        push_min_to_b(stacks);
        push_min_to_b(stacks);
        sort_three(stacks);
        pa(stacks);
        pa(stacks);
    }
}
void radix_sort(t_stacks *stacks)
{
    t_radix_counters setup;

    setup_radix_counters(stacks, &setup);
    setup.j = 0;
    while (setup.j < setup.max_bits)
    {
        setup.i = 0;
        while (setup.i < setup.len)
        {
            if (((stacks->stack_a[0] >> setup.j) & 1) == 0)
                pb(stacks);
            else
                ra(stacks);
            setup.i++;
        }
        while (stacks->len_stack_b > 0)
            pa(stacks);
        setup.j++;
    }
}

