/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 11:11:53 by mlezcano          #+#    #+#             */
/*   Updated: 2024/01/27 13:37:04 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ps_bubble_sort(int *tmp_stack, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tmp_stack[i] > tmp_stack[j])
			{
				tmp = tmp_stack[i];
				tmp_stack[i] = tmp_stack[j];
				tmp_stack[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	ps_push(t_stacks *stack, int len, int operation)
{
	if (operation == 0)
		pb(stack, OPT);
	else
		pa(stack, OPT);
	len--;
	return (len);
}

void	ps_sort_three_a(t_stacks *s)
{
	if (s->a[0] > s->a[1] && s->a[0] < s->a[2] && s->a[1] < s->a[2])
		sa(s, OPT);
	if (s->a[0] > s->a[1] && s->a[0] > s->a[2] && s->a[1] > s->a[2])
	{
		sa(s, OPT);
		rra(s, OPT);
	}
	if (s->a[0] > s->a[1] && s->a[0] > s->a[2] && s->a[1] < s->a[2])
		ra(s, OPT);
	if (s->a[0] < s->a[1] && s->a[0] < s->a[2] && s->a[1] > s->a[2])
	{
		sa(s, OPT);
		ra(s, OPT);
	}
	if (s->a[0] < s->a[1] && s->a[0] > s->a[2] && s->a[1] > s->a[2])
		rra(s, OPT);
}

int	ps_sort(t_stacks *stack, int len)
{
	if (ps_is_sorted(stack->a, stack->size_a, ASC) == 0)
	{
		if (len == 2)
			sa(stack, OPT);
		else if (len == 3)
			ps_sort_three_a(stack);
		else
			ps_quick_sort_a(stack, len, 0);
	}
	return (0);
}
