/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 02:45:30 by agardet           #+#    #+#             */
/*   Updated: 2021/09/02 20:04:39 by kali             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

//check if list(input) is correct and count NbsQty
void	ft_get_nbsqty(char **list, t_data *data)
{
	int	i;
	int	roam;

	i = 0;
	while (list[i])
	{
		roam = 0;
		if (list[i][roam] == '-' && list[i][roam] >= '0' \
				&& list[i][roam] <= '9')
			roam++;
		if (list[i][roam] >= '0' && list[i][roam] <= '9')
		{
			while (list[i][roam] >= '0' && list[i][roam] <= '9')
				roam++;
			data->nbsqty++;
		}
		else
			if (list[i][roam])
				ft_error();
	}
}

//count how many numbers in the list
void	ft_check_a_stack_error(int argc, char **argv, int *a_stack, char **list)
{
	int	i;
	int	count_qty;

	i = 0;
	while (list[i])
	{
		if (list[i][0] == '-' || (list[i][0] >= '0' && list[i][0] <= '9'))
		{
			a_stack[count_qty] = ft_modified_atoi(argv, a_stack, i, count_qty);
			count_qty++;
		}
		i++;
	}

}

//put the input in char **list and verify if input is correct
int	*ft_argv_to_tab(int argc, char **argv, t_data *data)
{
	int		*a_stack;
	int		i;
	char	**list;

	i = 1;
	while (i < argc)
	{
		list = ft_split(argv[i], ' ');
		if (!list)
			ft_error();
		ft_get_nbsqty(list, data);
		free_tab(list);
	}
	a_stack = malloc(sizeof(int) * data->nbsqty);
	if (!a_stack)
		ft_error();
	ft_check_a_stack_error(argc, argv, a_stack, list);
	return (a_stack);
}

//creates the A stack then sort the numbers inside it
int	*ft_parsing(int argc, char **argv, t_data *data)
{
	int	*a_stack;

	if (argc < 2)
		ft_error();
	a_stack = ft_argv_to_tab(argc, argv, data);
	if (!a_stack)
		ft_error();
	a_stack = ft_sort_list(a_stack, data);
		if (!a_stack)
		ft_error();
	return (a_stack);
}
