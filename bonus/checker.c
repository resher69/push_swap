/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardet <agardet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 06:18:55 by agardet           #+#    #+#             */
/*   Updated: 2021/09/13 00:38:37 by agardet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	do_commands2(char *line, int *a_stack, int *b_stack, t_data *data)
{
	if (!(ft_strncmp(line, "rb", 3)))
		rotate(b_stack, data, NULL);
	else if (!(ft_strncmp(line, "rr", 3)))
		rotate_both(a_stack, b_stack, data);
	else if (!(ft_strncmp(line, "exit\n", 4)) || !(ft_strncmp(line, "stop\n", 4)))
		return (0);
	else
		write(1, "command not found\n", 22);
	return (1);
}

int	do_commands(char *line, int *a_stack, int *b_stack, t_data *data)
{
	if (!(ft_strncmp(line, "sa", 3)))
		swap(a_stack, NULL);
	else if (!(ft_strncmp(line, "sb", 3)))
		swap(b_stack, NULL);
	else if (!(ft_strncmp(line, "ss", 3)))
		swap_both(a_stack, b_stack);
	else if (!(ft_strncmp(line, "pa", 3)))
		push(b_stack, a_stack, data, NULL);
	else if (!(ft_strncmp(line, "pb", 3)))
		push(a_stack, b_stack, data, NULL);
	else if (!(ft_strncmp(line, "rra", 4)))
		reverse_rotate(a_stack, data, NULL);
	else if (!(ft_strncmp(line, "rrb", 4)))
		reverse_rotate(b_stack, data, NULL);
	else if (!(ft_strncmp(line, "rrr", 4)))
		reverse_rotate_both(a_stack, b_stack, data);
	else if (!(ft_strncmp(line, "ra", 3)))
		rotate(a_stack, data, NULL);
	else if (do_commands2(line, a_stack, b_stack, data) == 0)
		return (0);
	return (1);
}

void	end_checker(int *a_stack, int *b_stack, t_data *data)
{
	if (ft_is_sorted(a_stack, data) && b_stack[0] == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free(a_stack);
	free(b_stack);
}

int	main(int ac, char **av)
{
	int		*a_stack;
	int		*b_stack;
	t_data	data;
	char	*line;

	a_stack = ft_parsing(ac, av, &data);
	b_stack = ft_calloc(sizeof(int), data.nbsqty + 1);
	if (!b_stack)
		ft_error(a_stack, NULL);
	while (get_next_line(0, &line) > 0)
	{
		if (!(do_commands(line, a_stack, b_stack, &data)))
			break ;
		free(line);
	}
	end_checker(a_stack, b_stack, &data);
	free(line);
	return (0);
}
