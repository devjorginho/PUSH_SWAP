/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-carv <jde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 17:31:51 by jde-carv          #+#    #+#             */
/*   Updated: 2025/10/07 17:52:16 by jde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stacks
{
	int		*stack_a;
	int		*stack_b;
	int		len_stack_a;
	int		len_stack_b;
	int		*normalized_a;
	int		normalized_len;
	int		max_bits;
	char	**arguments_to_split;
}		t_stacks;

typedef struct s_verify
{
	unsigned char	has_repeated : 1;
	unsigned char	is_sorted : 1;
}		t_verify;

// general utils
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_perror(void);
int		ft_atoi(const char *str);
void	move_min_to_top(t_stacks *stacks, int min_index);
int		find_min_index(int *stack, int len);
void	normalize_stack(t_stacks *stack);
int		max_index(t_stacks *stack);
char	**ft_split(const char *s, char c);
void	free_string(char **str);

// Checking flags
void	setup_verifications(t_verify *verify);
void	validate_arguments(t_stacks *stack, t_verify *verify);
void	index_management(t_stacks *stack);

// Sort functions
void	sort_two(t_stacks *stacks);
void	sort_three(t_stacks *stack);
void	sort_four(t_stacks *stacks);
void	sort_five(t_stacks *stacks);
void	radix_sort(t_stacks *stacks);
void	exec_sort(t_stacks *stacks);

// Manage stack functions
void	init_stacks(t_stacks *stack, int ac, char **argv);
void	populate_stack(t_stacks *stack, int ac, char **argv);
void	free_stacks(t_stacks *stack);
void	sa(t_stacks *stack);
void	sb(t_stacks *stack);
void	ss(t_stacks *stack);
void	pa(t_stacks *stacks);
void	pb(t_stacks *stacks);
void	ra(t_stacks *stack);
void	rb(t_stacks *stack);
void	rr(t_stacks *stack);
void	rra(t_stacks *stack);
void	rrb(t_stacks *stack);
void	rrr(t_stacks *stack);

#endif