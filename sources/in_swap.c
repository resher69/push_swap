/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardet <agardet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 23:09:35 by kali              #+#    #+#             */
/*   Updated: 2021/09/11 05:02:15 by agardet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

//swap top 2 numbers
void	swap(int *stack, char *display)
{
	int	tmp;

	tmp = stack[0];
	stack[0] = stack[1];
	stack[1] = tmp;
	write(1, display, 3);
}

void	swap_both(int *a_stack, int *b_stack)
{
	swap(a_stack, NULL);
	swap(b_stack, NULL);
	write(1, "ss\n", 3);
}
