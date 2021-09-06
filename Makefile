# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kali <kali@student.42lyon.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/28 02:34:44 by agardet           #+#    #+#              #
#    Updated: 2021/09/05 23:10:53 by kali             ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

.PHONY: clean, fclean, re
.SUFFIXES: .c .o .h .a
EXEC = push_swap
EXEC_LIBFT = libft/libft.a
SRCS = push_swap.c	utils.c parsing.c parsing_utils.c	in_push_rotate.c	in_swap.c
OBJS = $(SRCS:.c=.o)
OBJDIR = objects/
SRCDIR = sources/
LIBDIR = libft/
INCDIR = includes/
CFLAGS = -Wall -Wextra -Werror
LIBS =  -lft
VPATH = sources/:includes/:objects/

all: $(EXEC_LIBFT) $(EXEC)


$(EXEC_LIBFT):
	make -C $(LIBDIR)
$(EXEC): $(OBJS)
	cc $(CFLAGS) $(addprefix $(OBJDIR), $(notdir $^)) -L $(LIBDIR)  $(LIBS) -o $(EXEC)
%.o: %.c
	cc -c $(CFLAGS) $< -I $(INCDIR) -I $(LIBDIR) -o $(addprefix $(OBJDIR), $@)
clean:
	make -C $(LIBDIR) clean
	$(RM) $(addprefix $(OBJDIR), $(OBJS))
fclean:
	make -C $(LIBDIR) fclean
	$(RM) $(addprefix $(OBJDIR), $(OBJS))
	$(RM) $(EXEC)
re: fclean all