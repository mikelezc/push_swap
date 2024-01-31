/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 11:13:26 by mlezcano          #+#    #+#             */
/*   Updated: 2024/01/31 13:32:51 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	pb(t_stacks *stack)
{
	int	i;

	if (stack->a_len)
	{
		stack->b_len++;
		i = stack->b_len;
		while (--i > 0)
			stack->b[i] = stack->b[i - 1];
		stack->b[0] = stack->a[0];
		i = -1;
		stack->a_len--;
		while (++i < stack->a_len)
			stack->a[i] = stack->a[i + 1];
		ft_printf("pb\n");
	}
}

void	pa(t_stacks *stack)
{
	int	i;

	if (stack->b_len)
	{
		stack->a_len++;
		i = stack->a_len;
		while (--i > 0)
			stack->a[i] = stack->a[i - 1];
		stack->a[0] = stack->b[0];
		i = -1;
		stack->b_len--;
		while (++i < stack->b_len)
			stack->b[i] = stack->b[i + 1];
		ft_printf("pa\n");
	}
}
