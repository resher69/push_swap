/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardet <agardet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 05:05:40 by agardet           #+#    #+#             */
/*   Updated: 2021/09/11 04:56:08 by agardet          ###   ########lyon.fr   */
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

//parsing 11 files 
int		*ft_parsing(int argc, char **argv, t_data *data);
int		*ft_argv_to_tab(int argc, char **argv, t_data *data);
void	ft_get_Nbsqty(char **list, t_data *data);
void	ft_check_a_stack_error(char **argv, int *a_stack, char **list);	
long	ft_modified_atoi(char **argv, int *a_stack, int i, int count_qty);
int		*ft_sort_list(int *a_stack, t_data *data);
int		*ft_sort_list2(int tab[], t_data *data, int *a_stack);
void	switch_value(int *ranked_stack_i, int rang, int *searcher, int stack_a);
void	ft_choose_algo(int *a_stack, int *b_stack, t_data *data);
int		ft_is_sorted(int *a_stack, t_data *data);
void	ft_error(int *a_stack, int *b_stack);

//instructions 7 files
void	push(int *a_stack, int *b_stack, t_data *data, char *display);
void	rotate(int *stack, t_data *data, char *display);
void	rotate_both(int *a_stack, int *b_stack, t_data *data);
void	reverse_rotate(int *stack, t_data *data, char *display);
void	reverse_rotate_both(int *a_stack, int *b_stack, t_data *data);
void	swap(int *stack, char *display);
void	swap_both(int *a_stack, int *b_stack);

//algo_utils 4 files
int		ft_put_nb_on_top(int *stack, int i, int j, t_data *data);
void	ft_get_num_to_push(int *stack, t_data *data, int chunk);
void	ft_where_in_b_stack(int *a_stack, int *b_stack, t_data *data);
void	ft_push_in_a_stack(int *a_stack, int *b_stack, t_data *data);

//algo 7 files
int		ft_last_number(int *stack, t_data *data);
void	two_nums(int *a_stack);
void	three_ints(int *a_stack, t_data *data);
void	four_ints(int *a_stack, int *b_stack, t_data *data);
void	five_ints(int *a_stack, int *b_stack, t_data *data);
void	five_ints_2(int *a_stack, int *b_stack, t_data *data);
void	x_ints(int *a_stack, int *b_stack, t_data *data);
//29 files in total

#endif