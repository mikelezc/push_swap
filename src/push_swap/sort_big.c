/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 11:11:31 by mlezcano          #+#    #+#             */
/*   Updated: 2024/01/29 10:14:48 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ps_quick_sort_b(t_stacks *stack, int len, int counter)
{
	int	pivot;
	int	items;

	items = len;
	if (counter == 0 && ps_is_sorted(stack->b, len, DES) == 1)
		while (len--)
			pa(stack);
	if (len <= 3)
	{
		ps_sort_small_b(stack, len);
		return (1);
	}
	if (!ps_find_pivot(&pivot, stack->b, len))
		return (0);
	while (len != items / 2)
	{
		if (stack->b[0] >= pivot && len--)
			pa(stack);
		else if (++counter)
			rb(stack);
	}
	while (items / 2 != stack->b_len && counter--)
		rrb(stack);
	return (ps_quick_sort_a(stack, items / 2 + items % 2, 0)
		&& ps_quick_sort_b(stack, items / 2, 0));
}

int	ps_quick_sort_a(t_stacks *stack, int len, int counter)
{
	int	pivot;
	int	items;

	items = len;
	if (ps_is_sorted(stack->a, len, ASC) == 1)
		return (1);
	if (len <= 3)
	{
		ps_sort_small_a(stack, len);
		return (1);
	}
	if (counter == 0 && !ps_find_pivot(&pivot, stack->a, len))
		return (0);
	while (len != items / 2 + items % 2)
	{
		if (stack->a[0] < pivot && (len--))
			pb(stack);
		else if (++counter)
			ra(stack);
	}
	while (items / 2 + items % 2 != stack->a_len && counter--)
		rra(stack);
	ps_quick_sort_a(stack, items / 2 + items % 2, 0);
	ps_quick_sort_b(stack, items / 2, 0);
	return (1);
}
