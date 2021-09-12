/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardet <agardet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 06:18:55 by agardet           #+#    #+#             */
/*   Updated: 2021/09/12 06:20:06 by agardet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	do_commands2(char *line, int *stack_a, int *stack_b, t_data *data)
{
	if (!(ft_strncmp(line, "rb", 3)))
		R(stack_b, data, NULL);
	else if (!(ft_strncmp(line, "rr", 3)))
		Rr(stack_a, stack_b, data);
	else if (!(ft_strncmp(line, "exit\n", 4)) || !(ft_strncmp(line, "stop\n", 4)))
		return (0);
	else
		write(1, "commande non reconnue\n", 22);
	return (1);
}

int	do_commands(char *line, int *stack_a, int *stack_b, t_data *data)
{
	if (!(ft_strncmp(line, "sa", 3)))
		s(stack_a, NULL);
	else if (!(ft_strncmp(line, "sb", 3)))
		s(stack_b, NULL);
	else if (!(ft_strncmp(line, "ss", 3)))
		ss(stack_a, stack_b);
	else if (!(ft_strncmp(line, "pa", 3)))
		P(stack_b, stack_a, data, NULL);
	else if (!(ft_strncmp(line, "pb", 3)))
		P(stack_a, stack_b, data, NULL);
	else if (!(ft_strncmp(line, "rra", 4)))
		Reverse_r(stack_a, data, NULL);
	else if (!(ft_strncmp(line, "rrb", 4)))
		Reverse_r(stack_b, data, NULL);
	else if (!(ft_strncmp(line, "rrr", 4)))
		rrr(stack_a, stack_b, data);
	else if (!(ft_strncmp(line, "ra", 3)))
		R(stack_a, data, NULL);
	else if (do_commands2(line, stack_a, stack_b, data) == 0)
		return (0);
	return (1);
}

void	end_checker(int *stack_a, int *stack_b, t_data *data)
{
	if (is_sorted(stack_a, data) && stack_b[0] == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free(stack_a);
	free(stack_b);
}

int	main(int ac, char **av)
{
	int		*stack_a;
	int		*stack_b;
	t_data	data;
	char	*line;

	stack_a = parsing(ac, av, &data);
	stack_b = ft_calloc(sizeof(int), data.nbsqty + 1);
	if (!stack_b)
	{
		free(stack_a);
		exit(-1);
	}
	while (get_next_line(0, &line) > 0)
	{
		if (!(do_commands(line, stack_a, stack_b, &data)))
			break ;
		free(line);
	}
	end_checker(stack_a, stack_b, &data);
	free(line);
	return (0);
}
