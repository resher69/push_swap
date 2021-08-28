/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardet <agardet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 05:05:40 by agardet           #+#    #+#             */
/*   Updated: 2021/08/28 06:29:52 by agardet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "stdio.h"
# include "string.h"
# include "errno.h"
# include "limits.h"

typedef struct s_data
{
	int	nbsqty;
	int	min;
	int	max;
}		t_data;

//parsing
void	ft_error(void);
int		*ft_parsing(int argc, char **argv, t_data *data);
int		*ft_argv_to_tab(int argc, char **argv, t_data *data);
void	ft_get_NbsQty(char **list, t_data *data);
void	ft_check_a_stack_error(int argc, char **argv, \
			int *a_stack, char **list);

#endif