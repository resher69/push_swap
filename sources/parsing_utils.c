/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 19:24:56 by kali              #+#    #+#             */
/*   Updated: 2021/09/02 19:24:56 by kali+###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

//get nb as an int and check for errors
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
		ft_error(a_stack, NULL);
	while (++j < count_qty)
	{
		if (a_stack[i] == nb)
			ft_error(a_stack, NULL);
	}
	return (nb);
}
// ???
int	*ft_sort_list(int *a_stack,t_data *data)
{
	int	i;
	int tab[4];

	i = 0;
	tab[0] = a_stack[0];
	tab[1] = a_stack[0];
	tab[2] = 0;
	tab[3] = 0;
	// ?
	while (i < data->nbsqty)
	{
		if (a_stack[i] <= tab[0])
		{
			tab[0] = a_stack[i];
			tab[2] = i;
		}
		if (a_stack[i] >= tab[1])
		{
			tab[1] = a_stack[i];
			tab[3] = i;
		}
	}
	return (ft_sort_list2(tab, data, a_stack));
}

int	*ft_sort_list2(int tab[], t_data *data, int *a_stack)
{
	int	*ret;
	int	rang;
	int	i;
	int	search;

	rang = 1;
	ret = ft_calloc(sizeof(int), data->nbsqty);
	if (!ret)
		return (NULL);
	while (++rang < data->nbsqty)
	{
		i = -1;
		search = tab[1];
		while (++i < data->nbsqty)
		{
			if (a_stack[i] < search && a_stack[i] > tab[0])
				switch_value(&ret[i], rang, &search, a_stack[i]);
		}
		tab[0] = search;
	}
	ret[tab[2]] = 1;
	ret[tab[3]] = data->nbsqty;
	free(a_stack);
	return (ret);
	
	
}

void	switch_value(int *ranked_stack_i, int rang, int *searcher, int stack_a)
{
	(*ranked_stack_i) = rang;
	(*searcher) = stack_a;
}