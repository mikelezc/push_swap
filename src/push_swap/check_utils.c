/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:00:52 by mlezcano          #+#    #+#             */
/*   Updated: 2024/02/01 13:06:32 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ps_error_msg(int *stack)
{
	free(stack);
	write(2, "Error\n", 6);
	exit (1);
}

int	ps_all_zeros(char *nbr)
{
	while (*nbr)
	{
		if (*nbr >= '1' && *nbr <= '9')
			return (0);
		nbr++;
	}
	return (1);
}

int	ps_get_nbr(char *nbr, int *stack)
{
	int	num;

	num = 0;
	while (*nbr)
	{
		if (*nbr < '0' || *nbr > '9')
			ps_error_msg(stack);
		num = (*nbr - '0') + (num * 10);
		nbr++;
	}
	return (num);
}
