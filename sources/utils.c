/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 02:53:19 by agardet           #+#    #+#             */
/*   Updated: 2021/09/02 20:04:37 by kali             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

//write Error in stdin and exit program
void	ft_error(void)
{
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}
