/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardet <agardet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 02:45:30 by agardet           #+#    #+#             */
/*   Updated: 2021/09/13 03:09:27 by agardet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

//check if list(input) is correct and count NbsQty
void	ft_get_nbsqty(char **list, t_data *data)
{
	int	i;
	int	roam;

	i = -1;
	while (list[++i])
	{
		roam = 0;
		if (list[i][roam] == '-' && list[i][roam + 1] >= '0' \
				&& list[i][roam + 1] <= '9')
			roam++;
		if (list[i][roam] >= '0' && list[i][roam] <= '9')
		{
			while (list[i][roam] >= '0' && list[i][roam] <= '9')
				roam++;
			data->nbsqty++;
		}
		if (list[i][roam] && !(list[i][roam] >= '0' && list[i][roam] <= '9'))
			ft_error(NULL, NULL);
	}
}

//get nb as an int and check for errors
long	ft_modified_atoi(char **argv, int *a_stack, int i, int count_qty)
{
	long	nb;
	int		roam;
	int		j;

	nb = 0;
	roam = 0;
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
	j = -1;
	while (++j < count_qty)
		if (a_stack[j] == nb)
			ft_error(a_stack, NULL);
	return ((int)nb);
}

//count how many numbers in the list
void	ft_check_a_stack_error(int argc, char **argv, int *a_stack)
{
	int		count_qty;
	char	**list;
	int		index;
	int		i;

	index = 0;
	count_qty = 0;
	while (++index < argc)
	{
		list = ft_split(argv[index], ' ');
		if (!list)
			exit (-1);
		i = -1;
		while (list[++i])
		{
			if (('0' <= list[i][0] && list[i][0] <= '9') || list[i][0] == '-')
			{
				a_stack[count_qty] = \
					ft_modified_atoi(list, a_stack, i, count_qty);
				count_qty++;
			}
		}
		free_tab(list);
	}
}

//put the input in char **list and malloc
int	*ft_argv_to_tab(int argc, char **argv, t_data *data)
{
	int		*a_stack;
	int		i;
	char	**list;

	i = 0;
	while (++i < argc)
	{
		list = ft_split(argv[i], ' ');
		if (!list)
			ft_error(NULL, NULL);
		ft_get_nbsqty(list, data);
	}
	a_stack = malloc(sizeof(int) * data->nbsqty);
	if (!a_stack)
		ft_error(NULL, NULL);
	ft_check_a_stack_error(argc, argv, a_stack);
	return (a_stack);
}

//creates the A stack then sort the numbers inside it
int	*ft_parsing(int argc, char **argv, t_data *data)
{
	int	*a_stack;

	if (argc < 2)
		ft_error(NULL, NULL);
	a_stack = ft_argv_to_tab(argc, argv, data);
	if (!a_stack)
		ft_error(a_stack, NULL);
	a_stack = ft_sort_list(a_stack, data);
	if (!a_stack)
		ft_error(a_stack, NULL);
	return (a_stack);
}
