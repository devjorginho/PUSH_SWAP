/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-carv <jde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 10:47:31 by devjorginho       #+#    #+#             */
/*   Updated: 2025/10/06 17:16:38 by jde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	check_overflow(long result, int sign)
{
	if (result * sign > INT_MAX || result * sign < INT_MIN)
		ft_perror();
}

static void	check_invalid_char(const char *str)
{
	if (*str < '0' || *str > '9')
		ft_perror();
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}

int	ft_atoi(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*(str + 1) < '0' || *(str + 1) > '9')
			ft_perror();
		if (*str == '-')
			sign = -1;
		str++;
	}
	check_invalid_char(str);
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		check_overflow(result, sign);
		str++;
	}
	if (*str != '\0')
		ft_perror();
	return ((int)(result * sign));
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*alloc;
	size_t			full_s;

	if (!nmemb || !size)
	{
		alloc = malloc(0);
		if (!alloc)
			return (NULL);
		return (alloc);
	}
	full_s = nmemb * size;
	if (nmemb != full_s / size)
		return (NULL);
	alloc = malloc(full_s);
	if (!alloc)
		return (NULL);
	ft_bzero(alloc, full_s);
	return ((void *)alloc);
}
