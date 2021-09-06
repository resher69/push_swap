/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 05:05:40 by agardet           #+#    #+#             */
/*   Updated: 2021/09/05 23:14:02 by kali             ###   ########lyon.fr   */
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
void	ft_error(int *a_stack, int *b_stack);
int		*ft_parsing(int argc, char **argv, t_data *data);
int		*ft_argv_to_tab(int argc, char **argv, t_data *data);
void	ft_get_NbsQty(char **list, t_data *data);
void	ft_check_a_stack_error(int argc, char **argv, \
			int *a_stack, char **list);	
long	ft_modified_atoi(char **argv, int *a_stack, int i, int count_qty);
int		*ft_sort_list(int *a_stack,t_data *data);
int		*ft_sort_list2(int tab[], t_data *data, int *a_stack);
void	switch_value(int *ranked_stack_i, int rang, int *searcher, int stack_a);

//instructions
void    push(int *a_stack, int *b_stack, t_data *data, char *display);
void    rotate(int *stack, t_data *data, char *display);
void    rotate_both(int *a_stack, int *b_stack, t_data *data);
void    reverse_rotate(int *stack, t_data *data, char *display);
void    reverse_rotate_both(int *a_stack, int *b_stack, t_data *data);
void    swap(int *stack, char *display);
void    swap_both(int *a_stack, int *b_stack);

#endif