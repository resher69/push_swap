/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 02:53:19 by agardet           #+#    #+#             */
/*   Updated: 2021/09/09 22:33:33 by kali             ###   ########lyon.fr   */
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

int	ft_is_sorted(int *a_stack, t_data *data)
{
	int	i;

	i = 1;
	while (i < data->nbsqty && a_stack[i - 1] < a_stack[i])
		i++;
	if (i == data->nbsqty || a_stack[i] == 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}