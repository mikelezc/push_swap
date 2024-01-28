/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 11:11:53 by mlezcano          #+#    #+#             */
/*   Updated: 2024/01/28 13:53:29 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ps_sort_three_a(t_stacks *stack)
{
	if (stack->a[0] > stack->a[1] && stack->a[0]
		< stack->a[2] && stack->a[1] < stack->a[2])
		sa(stack);
	if (stack->a[0] > stack->a[1] && stack->a[0]
		> stack->a[2] && stack->a[1] > stack->a[2])
	{
		sa(stack);
		rra(stack);
	}
	if (stack->a[0] > stack->a[1] && stack->a[0]
		> stack->a[2] && stack->a[1] < stack->a[2])
		ra(stack);
	if (stack->a[0] < stack->a[1] && stack->a[0]
		< stack->a[2] && stack->a[1] > stack->a[2])
	{
		sa(stack);
		ra(stack);
	}
	if (stack->a[0] < stack->a[1] && stack->a[0]
		> stack->a[2] && stack->a[1] > stack->a[2])
		rra(stack);
}

int	ps_sort(t_stacks *stack, int len)
{
	if (ps_is_sorted(stack->a, stack->a_len, ASC) == 0)
	{
		if (len == 2)
			sa(stack);
		else if (len == 3)
			ps_sort_three_a(stack);
		else
			ps_quick_sort_a(stack, len, 0);
	}
	return (0);
}
