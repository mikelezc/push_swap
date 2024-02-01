/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 19:48:29 by mlezcano          #+#    #+#             */
/*   Updated: 2024/02/01 13:02:58 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ps_is_sorted(int *stack, int len, int direction)
{
	int	i;

	i = 1;

	while (i < len)
	{
		if ((direction == ASC && stack[i - 1] > stack[i])
			|| (direction == DES && stack[i - 1] < stack[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ps_is_repeat(int *stack, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (stack[i] == stack[j])
				ps_error_msg(stack);
			j++;
		}
		i++;
	}
}

int	ps_atoi_lim(char *str, int *stack)
{
	int				i;
	int				sign;
	unsigned int	num;
	int				plus;

	i = 0;
	num = 0;
	sign = 1;
	plus = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+')
		plus = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (plus == 1 && ps_all_zeros(&str[i]))
		ps_error_msg(stack);
	num = ps_get_nbr(&str[i], stack);
	if ((num > 2147483648 && sign == -1) || (num > 2147483647 && sign == 1)
		|| (num == 0 && sign == -1))
		ps_error_msg(stack);
	return (num * sign);
}

int	ps_arr_len(char **argv)
{
	int	i;

	i = 0;
	while (*argv)
	{
		argv++;
		i++;
	}
	return (i);
}
