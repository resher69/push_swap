/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_push_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardet <agardet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 21:40:31 by kali              #+#    #+#             */
/*   Updated: 2021/09/11 05:02:15 by agardet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

//send top of X stack into top of Y stack
void	push(int *a_stack, int *b_stack, t_data *data, char *display)
{
	int	tmp;
	int	i;
	int	j;

	if (a_stack[0] == 0)
		return ;
	i = 0;
	j = 1;
	tmp = a_stack[0];
	while (j < data->nbsqty && a_stack[j] != 0)
	{
		a_stack[i] = a_stack[j];
		i++;
		j++;
	}
	a_stack[i] = 0;
	i = data->nbsqty - 1;
	while (i > 0)
	{
		b_stack[i] = b_stack[i - 1];
		i--;
	}
	b_stack[0] = tmp;
	write(1, display, 3);
}

//top number goes to bottom
void	rotate(int *stack, t_data *data, char *display)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = stack[0];
	while (stack[i] != 0 && i < data->nbsqty)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[i - 1] = tmp;
	write(1, display, 3);
}

//bottom number goes to top
void	reverse_rotate(int *stack, t_data *data, char *display)
{
	int	tmp;
	int	i;

	i = data->nbsqty - 1;
	while (stack[i] == 0)
		i--;
	tmp = stack[i];
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[i] = tmp;
	write(1, display, 4);
}

void	reverse_rotate_both(int *a_stack, int *b_stack, t_data *data)
{
	reverse_rotate(a_stack, data, NULL);
	reverse_rotate(b_stack, data, NULL);
}

void	rotate_both(int *a_stack, int *b_stack, t_data *data)
{
	rotate(a_stack, data, NULL);
	rotate(b_stack, data, NULL);
}
