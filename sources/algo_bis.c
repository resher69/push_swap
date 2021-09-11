/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_bis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardet <agardet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 01:57:57 by agardet           #+#    #+#             */
/*   Updated: 2021/09/11 05:02:16 by agardet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

//count how many operations need ot be done then put nb i and j on top
int	ft_put_nb_on_top(int *stack, int i, int j, t_data *data)
{
	if (j == ft_last_number(stack, data))
		j = 0;
	else
		j = ft_last_number(stack, data) - j;
	if (j < 0 && i <= 0)
		return (0);
	if (i < j)
		while (i-- > 0)
			rotate(stack, data, "ra\n");
	else
	{
		while (j-- >= 0)
			reverse_rotate(stack, data, "rra\n");
	}
	return (1);
}

//check if the number is higher than the chunk 
void	ft_get_num_to_push(int *stack, t_data *data, int chunk)
{
	int	i;
	int	j;

	i = 0;
	while (stack[i] != 0 && stack[i] > chunk)
		i++;
	j = ft_last_number(stack, data);
	while (stack[j] > chunk)
		j--;
	if (i != 0)
		ft_put_nb_on_top(stack, i, j, data);
}

//sort b_stack a little bit
void	ft_where_in_b_stack(int *a_stack, int *b_stack, t_data *data)
{
	push(a_stack, b_stack, data, "pb\n");
	if (b_stack[1] == 0 || b_stack[0] > b_stack[1])
		return ;
	if (b_stack[0] < b_stack[ft_last_number(b_stack, data)])
		rotate(b_stack, data, "rb\n");
	else
		swap(b_stack, "sb\n");
}

//push all numbers in order to a_stack depending on their position in the stack 
//to minimize operations
void	ft_push_in_a_stack(int *a_stack, int *b_stack, t_data *data)
{
	int	i;
	int	j;
	int	nbs_qty;

	nbs_qty = data->nbsqty;
	while (b_stack[0] != 0)
	{
		i = 0;
		while (b_stack[i] != nbs_qty)
			i++;
		if (i > ft_last_number(b_stack, data) / 2)
		{
			j = ft_last_number(b_stack, data) - i;
			while (j-- >= 0)
				reverse_rotate(b_stack, data, "rrb\n");
		}
		else
			while (i-- > 0)
				rotate(b_stack, data, "rb\n");
		nbs_qty--;
		push(b_stack, a_stack, data, "pa\n");
	}
}

//divides the stack with chunks
void	x_ints(int *a_stack, int *b_stack, t_data *data)
{
	int	i;
	int	j;
	int	chunk;
	int	chunk_qty;

	i = 0;
	while (i * i <= data->nbsqty)
		i++;
	chunk_qty = i / 2;
	chunk = data->nbsqty / chunk_qty;
	i = 0;
	while (i <= chunk_qty)
	{
		j = 0;
		while (j < data->nbsqty / chunk_qty && a_stack[0] != 0)
		{
			ft_get_num_to_push(a_stack, data, chunk);
			ft_where_in_b_stack(a_stack, b_stack, data);
			j++;
		}
		chunk += (data->nbsqty / chunk_qty);
		i++;
	}
	ft_push_in_a_stack(a_stack, b_stack, data);
}
