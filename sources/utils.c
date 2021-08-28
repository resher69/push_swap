/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardet <agardet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 02:53:19 by agardet           #+#    #+#             */
/*   Updated: 2021/08/28 06:29:16 by agardet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

//write Error in stdin and exit program
void	ft_error(void)
{
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}

long	ft_modified_atoi(char **argv, int *a_stack, int i, int count_qty)
{
	long	nb;
	int		roam;
	int		j;

	nb = 0;
	roam = 0;
	j = 0;
	if (argv[i][roam] == '-')
		roam++;
	while (argv[i][roam] && argv[i][roam] >= '0' && argv[i][roam] <= '9')
	{
		nb = nb * 10 + argv[i][roam] - '0';
		roam++;
	}
	if (argv[i][0] == '-')
		nb *= -1;
	if (nb < INT_MIN || nb > INT_MAX)
		ft_error();
	while (++j < count_qty)
	{
		if (a_stack[i] == nb)
			ft_error();
	}
	return (nb);
}
