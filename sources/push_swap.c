/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 02:35:37 by agardet           #+#    #+#             */
/*   Updated: 2021/09/05 21:52:13 by kali             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	main(int argc, char **argv)
{
	t_data	data;
	int		*a_stack;
	int		*b_stack;

	a_stack = ft_parsing(argc, argv, &data);
	b_stack = ft_calloc(sizeof(int), data.nbsqty + 1);
	if (!b_stack)
		ft_error(a_stack, NULL);

	free(a_stack);
	free(b_stack);
	return (0);
}
