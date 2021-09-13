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

// save the smallest and biggest number and their index in tab
int	*ft_sort_list(int *a_stack, t_data *data)
{
	int	i;
	int	tab[4];

	i = -1;
	tab[0] = a_stack[0];
	tab[1] = a_stack[0];
	tab[2] = 0;
	tab[3] = 0;
	while (++i < data->nbsqty)
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

// transform the input in a sorted list from 1 to nbs_qty
int	*ft_sort_list2(int tab[], t_data *data, int *a_stack)
{
	int	*ret;
	int	rank;
	int	i;
	int	search;

	rank = 1;
	ret = ft_calloc(sizeof(int), data->nbsqty);
	if (!ret)
		return (NULL);
	while (++rank < data->nbsqty)
	{
		i = -1;
		search = tab[1];
		while (++i < data->nbsqty)
		{
			if (a_stack[i] < search && a_stack[i] > tab[0])
				switch_value(&ret[i], rank, &search, a_stack[i]);
		}
		tab[0] = search;
	}
	ret[tab[2]] = 1;
	ret[tab[3]] = data->nbsqty;
	free(a_stack);
	return (ret);
}

//change value
void	switch_value(int *ranked_stack_i, int rank, int *searcher, int a_stack)
{
	(*ranked_stack_i) = rank;
	(*searcher) = a_stack;
}
