/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardet <agardet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 12:31:17 by agardet           #+#    #+#             */
/*   Updated: 2021/09/13 00:46:41 by agardet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_check_new_line(char *buf)
{
	size_t	i;

	if (!buf)
		return (-1);
	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (0);
		i++;
	}
	return (-1);
}

char	*ft_sstrjoin(char *s1, char *s2)
{
	size_t	total_len;
	char	*res;

	if (!s2)
		return (NULL);
	total_len = ft_strlen(s1) + ft_strlen(s2);
	res = malloc(sizeof(char) * (total_len + 1));
	if (!res)
		return (NULL);
	*res = 0;
	ft_sstrcat(res, (char *)s1);
	ft_sstrcat(res, (char *)s2);
	res[total_len] = 0;
	free(s1);
	return (res);
}

char	*ft_sstrcat(char *dst, const char *src)
{
	int		i;
	int		j;
	char	*src_cpy;

	if (!dst)
		return (NULL);
	if (!src)
		return (dst);
	i = 0;
	j = 0;
	src_cpy = (char *)src;
	while (dst[i])
		i++;
	while (src_cpy[j])
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = 0;
	return (dst);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
