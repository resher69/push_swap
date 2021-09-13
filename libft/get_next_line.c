/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardet <agardet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 11:07:16 by agardet           #+#    #+#             */
/*   Updated: 2021/09/13 00:50:24 by agardet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_get_line(char *save)
{
	char	*line;
	ssize_t	i;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	line[i] = 0;
	while (--i >= 0)
		line[i] = save[i];
	return (line);
}

static int	ft_error_handler(char *save, char *buf)
{
	if (save)
		free(save);
	if (buf)
		free(buf);
	return (-1);
}

static char	*ft_rest_line(char *save)
{
	char	*rest;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!save)
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == 0)
	{
		free(save);
		return (NULL);
	}
	rest = malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (!rest)
		return (NULL);
	i++;
	while (save[i])
		rest[j++] = save[i++];
	rest[j] = 0;
	free(save);
	return (rest);
}

char	*xdlanorm(void)
{
	char	*buf;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		exit(-1);
	return (buf);
}

int	get_next_line(int fd, char **line)
{
	static char	*save;
	char		*buf;
	int			ret;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	buf = xdlanorm();
	ret = 1;
	while ((ft_check_new_line(save) != 0) && (ret != 0))
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret < 0)
			return (ft_error_handler(save, buf));
		buf[ret] = 0;
		save = ft_sstrjoin(save, buf);
	}
	free(buf);
	*line = ft_get_line(save);
	if (!*line)
		return (-1);
	save = ft_rest_line(save);
	if (ret != 0)
		return (1);
	free(save);
	return (0);
}
