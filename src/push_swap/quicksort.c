/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 11:11:31 by mlezcano          #+#    #+#             */
/*   Updated: 2024/01/27 12:40:39 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_quicksort_3(t_stacks *stack, int len)
{
	if (len == 3 && stack->size_a == 3)
		ps_sort_three_a(stack);
	else if (len == 2)
	{
		if (stack->a[0] > stack->a[1])
			sa(stack, OPT);
	}
	else if (len == 3)
	{
		while (len != 3 || !(stack->a[0] < stack->a[1]
				&& stack->a[1] < stack->a[2]))
		{
			if (len == 3 && stack->a[0] > stack->a[1] && stack->a[2])
				sa(stack, OPT);
			else if (len == 3 && !(stack->a[2] > stack->a[0]
					&& stack->a[2] > stack->a[1]))
				len = ps_push(stack, len, 0);
			else if (stack->a[0] > stack->a[1])
				sa(stack, OPT);
			else if (len++)
				pa(stack, OPT);
		}
	}
}

int	ft_sort_small_b(t_stacks *s, int len)
{
	if (len == 1)
		pa(s, OPT);
	else if (len == 2)
	{
		if (s->b[0] < s->b[1])
			sb(s, OPT);
		while (len--)
			pa(s, OPT);
	}
	else if (len == 3)
	{
		while (len || !(s->a[0] < s->a[1] && s->a[1] < s->a[2]))
		{
			if (len == 1 && s->a[0] > s->a[1])
				sa(s, OPT);
			else if (len == 1 || (len >= 2 && s->b[0] > s->b[1])
				|| (len == 3 && s->b[0] > s->b[2]))
				len = ps_push(s, len, 1);
			else
				sb(s, OPT);
		}
	}
	return (0);
}

int	ps_find_pivot(int *pivot, int *stack, int len)
{
	int		*tmp_stack;
	int		i;

	tmp_stack = (int *)malloc(len * sizeof(int));
	if (!tmp_stack)
		return (0);
	i = 0;
	while (i < len)
	{
		tmp_stack[i] = stack[i];
		i++;
	}
	ps_bubble_sort(tmp_stack, len);
	*pivot = tmp_stack[len / 2];
	free(tmp_stack);
	return (1);
}

int	ps_quick_sort_b(t_stacks *stack, int len, int counter)
{
	int	pivot;
	int	items;

	if (counter == 0 && ps_is_sorted(stack->b, len, DESCENDING) == 1)
		while (len--)
			pa(stack, OPT);
	if (len <= 3)
	{
		ft_sort_small_b(stack, len);
		return (1);
	}
	items = len;
	if (!ps_find_pivot(&pivot, stack->b, len))
		return (0);
	while (len != items / 2)
	{
		if (stack->b[0] >= pivot && len--)
			pa(stack, OPT);
		else if (++counter)
			rb(stack, OPT);
	}
	while (items / 2 != stack->size_b && counter--)
		rrb(stack, OPT);
	return (ps_quick_sort_a(stack, items / 2 + items % 2, 0)
		&& ps_quick_sort_b(stack, items / 2, 0));
}

int	ps_quick_sort_a(t_stacks *stack, int len, int counter)
{
	int	pivot;
	int	items;

	if (ps_is_sorted(stack->a, len, ASCENDING) == 1)
		return (1);
	items = len;
	if (len <= 3)
	{
		ft_quicksort_3(stack, len);
		return (1);
	}
	if (counter == 0 && !ps_find_pivot(&pivot, stack->a, len))
		return (0);
	while (len != items / 2 + items % 2)
	{
		if (stack->a[0] < pivot && (len--))
			pb(stack, OPT);
		else if (++counter)
			ra(stack, OPT);
	}
	while (items / 2 + items % 2 != stack->size_a && counter--)
		rra(stack, OPT);
	return (ps_quick_sort_a(stack, items / 2 + items % 2, 0)
		&& ps_quick_sort_b(stack, items / 2, 0));
	return (1);
}
