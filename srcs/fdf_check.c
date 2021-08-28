/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 12:00:36 by ksoulard          #+#    #+#             */
/*   Updated: 2016/06/06 17:37:07 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		print_error(char *error)
{
	ft_putstr("mlx: ");
	ft_putendl(error);
	ft_putendl("Usage: ./fdf <file>");
	exit(EXIT_FAILURE);
}

int			check_arg(int ac, char **av, t_i *map)
{
	char	*line;
	int		i;
	int		ret;

	i = 0;
	if (ac != 2)
		print_error("invalid arg");
	if ((map->fd = open(av[1], O_RDONLY)) == -1)
		print_error("invalid file");
	while ((ret = get_next_line(map->fd, &line)) > 0)
	{
		if (i == 2147483647)
			break ;
		i++;
	}
	if (ret == -1)
		print_error("Undefined error");
	close(map->fd);
	return (i);
}

void		create_lines(int i, char *av, t_i *map)
{
	char	*line;
	int		j;
	int		ret;

	if ((map->tab = (int **)malloc(sizeof(int *) * i + 1)) == NULL)
		print_error("memory was not allocated");
	if ((map->fd = open(av, O_RDONLY)) == -1)
		print_error("invalid file");
	j = 0;
	while ((ret = get_next_line(map->fd, &line) > 0) && j < i)
	{
		if ((map->tab[j++] = create_line(line)) == NULL)
		{
			ft_free_tab((void **)map->tab);
			print_error("memory was not allocated");
		}
	}
	if (ret == -1)
		print_error("Undefined error");
	map->tab[j] = NULL;
	close(map->fd);
}

int			*create_line(char *line)
{
	int		j;
	int		*tab;
	char	**tmp;

	j = 0;
	tmp = ft_strsplit(line, ' ');
	while (tmp[j])
		j++;
	if ((tab = (int *)malloc(sizeof(int) * j + 2)) == NULL)
		return (NULL);
	tab[0] = j;
	j = 1;
	while (tmp[j - 1])
	{
		tab[j] = ft_atoi(tmp[j - 1]);
		j++;
	}
	ft_free_tab((void **)tmp);
	return (tab);
}
