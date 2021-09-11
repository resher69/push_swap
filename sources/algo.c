/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardet <agardet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 23:29:25 by kali              #+#    #+#             */
/*   Updated: 2021/09/11 05:35:01 by agardet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	two_nums(int *a_stack)
{
	if (a_stack[0] == 2)
		swap(a_stack, "sa\n");
}

void	three_ints(int *a_stack, t_data *data)
{
	if (a_stack[0] < a_stack[1] && a_stack[0] < a_stack[2])
	{
		swap(a_stack, "sa\n");
		rotate(a_stack, data, "ra\n");
	}
	else if (a_stack[0] > a_stack[1] && a_stack[0] > a_stack[2])
	{
		if (a_stack[1] < a_stack[2])
			rotate(a_stack, data, "ra\n");
		else
		{
			swap(a_stack, "sa\n");
			reverse_rotate(a_stack, data, "rra\n");
		}
	}
	else
	{
		if (a_stack[1] < a_stack[2])
			swap(a_stack, "sa\n");
		else
			reverse_rotate(a_stack, data, "rra\n");
	}
}

void	four_ints(int *a_stack, int *b_stack, t_data *data)
{
	if (a_stack[3] == 1)
		reverse_rotate(a_stack, data, "rra\n");
	else
		while (a_stack[0] != 1)
			rotate(a_stack, data, "ra\n");
	push(a_stack, b_stack, data, "pb\n");
	if (ft_is_sorted(a_stack, data) == EXIT_FAILURE)
		three_ints(a_stack, data);
	push(b_stack, a_stack, data, "pa\n");
}

void	five_ints(int *a_stack, int *b_stack, t_data *data)
{
	int	i;
	int	end;

	i = 0;
	end = 4;
	while (i < 2)
	{
		if (a_stack[end] == 1 || a_stack[end] == 5)
			reverse_rotate(a_stack, data, "rra\n");
		else if (a_stack[end - 1] == 1 || a_stack[end - 1] == 5)
		{
			reverse_rotate(a_stack, data, "rra\n");
			reverse_rotate(a_stack, data, "rra\n");
		}
		else
			while (a_stack[0] != 5 && a_stack[0] != 1)
				rotate(a_stack, data, "ra\n");
		push(a_stack, b_stack, data, "pb\n");
		end --;
		i++;
	}
}

void	five_ints_2(int *a_stack, int *b_stack, t_data *data)
{
	if (ft_is_sorted(a_stack, data) == EXIT_FAILURE)
		three_ints(a_stack, data);
	push(b_stack, a_stack, data, "pa\n");
	if (a_stack[0] > a_stack[1])
		rotate(a_stack, data, "ra\n");
	push(b_stack, a_stack, data, "pa\n");
	if (a_stack[0] > a_stack[1])
		rotate(a_stack, data, "ra\n");
}
