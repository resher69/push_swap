/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardet <agardet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 02:53:19 by agardet           #+#    #+#             */
/*   Updated: 2021/09/11 05:16:28 by agardet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

//write Error in stdin and exit program
void	ft_error(int *a_stack, int *b_stack)
{
	if (a_stack)
		free(a_stack);
	if (b_stack)
		free(b_stack);
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}

//check if the stack is sorted or not
int	ft_is_sorted(int *a_stack, t_data *data)
{
	int	i;

	i = 1;
	while (i < data->nbsqty && a_stack[i - 1] < a_stack[i])
		i++;
	if (i == data->nbsqty || a_stack[i] == 0)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

//decides which algo to choose depending on nbsqty
void	ft_choose_algo(int *a_stack, int *b_stack, t_data *data)
{
	if (data->nbsqty == 2)
		two_nums(a_stack);
	else if (data->nbsqty == 3)
		three_ints(a_stack, data);
	else if (data->nbsqty == 4)
		four_ints(a_stack, b_stack, data);
	else if (data->nbsqty == 5)
	{
		five_ints(a_stack, b_stack, data);
		five_ints_2(a_stack, b_stack, data);
	}
	else
		x_ints (a_stack, b_stack, data);
}

//get last number while skipping voids (0)
int	ft_last_number(int *stack, t_data *data)
{
	int	i;

	i = data->nbsqty - 1;
	while (stack[i] == 0 && i > 0)
		i--;
	return (i);
}
