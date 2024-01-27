/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 11:08:58 by mlezcano          #+#    #+#             */
/*   Updated: 2024/01/27 12:18:37 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/inc/libft.h"
# include "../libft/inc/ft_printf.h"
# include "../libft/inc/get_next_line.h"
# include <stdlib.h>

typedef struct s_stacks
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
}	t_stacks;

# define ASCENDING 0
# define DESCENDING 1
# define OPT 0
# define STACK 1

//Push_swap(main)
void	push_swap(char **argv);

//Check
int		ps_arr_len(char **argv);
void	ps_error(int *stack);
int		ps_atoi_lim(char *str, int *stack);
void	ps_is_repeat(int *stack, int size);
int		ps_is_sorted(int *pile, int size, int order);

//Sortage
int		ps_sort(t_stacks *stack, int size);
void	ps_sort_three_a(t_stacks *s);
void	ps_bubble_sort(int *tmp_stack, int size);
int		ps_push(t_stacks *stack, int len, int operation);

//Quicksort
int		ps_quick_sort_a(t_stacks *stack, int size, int counter);
int		ps_quick_sort_b(t_stacks *stack, int len, int counter);
void	ft_quicksort_3(t_stacks *stack, int len);
int		ft_sort_small_b(t_stacks *stack, int len);
int		ps_find_pivot(int *pivot, int *stack, int size);

//Operations
void	sa(t_stacks *stack, int print);
void	sb(t_stacks *stack, int print);
void	ss(t_stacks *stack, int print);
void	ra(t_stacks *stack, int print);
void	rb(t_stacks *stack, int print);
void	rr(t_stacks *stack, int print);
void	rra(t_stacks *stack, int print);
void	rrb(t_stacks *stack, int print);
void	rrr(t_stacks *stack, int print);
void	pb(t_stacks *stack, int print);
void	pa(t_stacks *stack, int print);

//Bonus
int		*ft_check_errors(char **argv);
void	ft_checker_instructions(t_stacks *stack);
void	ft_checker_start(t_stacks *stack);
char	*get_next_line(int fd);
void	ft_checker(t_stacks *stack);
int		ft_check_opt(char *opt, t_stacks *stack);
void	ft_opt(t_stacks *stack, char *opt);
void	ft_print_stacks(t_stacks *stack);

#endif