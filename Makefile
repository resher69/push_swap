# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/11 13:44:49 by ksoulard          #+#    #+#              #
#    Updated: 2018/01/20 15:03:06 by ksoulard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		fdf

CC =		gcc

EXT =		.c

FLAGS =		-Wall -Wextra -Werror

FLAGS_MLX =	-lmlx -framework OpenGL -framework AppKit -Llibft -lft

FILE =		fdf_main	fdf_function	fdf_init	fdf_check	fdf_hook

SOURCE = 	srcs/

INCLUDE =	includes/

HEADER = 	fdf.h

FILES =		$(addprefix $(SOURCE), $(addsuffix $(EXT), $(FILE)))

OBJ = $(FILES:$(EXT)=.o)

LIB_DIR =	libft

FDF_DIR =	fdf

EXEC=		$(LIB_DIR)/$(LIB_DIR).a

C_W=		\033[0m
C_R=		\033[38;5;124m
C_Y=		\033[38;5;214m
C_B=		\033[38;5;97m
C_N=		\033[38;5;200m
C_G=		\033[38;5;190m

all: 	$(EXEC) $(NAME) #norme

$(EXEC):
		@make -C libft
		@echo "$(C_Y)$(LIB_DIR) $(C_R)		is done !$(C_W)"

$(NAME): $(OBJ)
		@$(CC) $(FLAGS) $(FLAGS_MLX) -o $(NAME) $(OBJ) $(EXEC)
		@echo "\n$(C_Y)$(NAME) $(C_R)		is done !$(C_W)"

%.o:	%$(EXT) $(INCLUDE)
		@$(CC) $(FLAGS) -c $< -o $@ -I libft -I minilibx_macos
		@printf "\033[32m.$(C_W)"

clean:
		@rm -rf $(OBJ)
		@echo "$(C_B)$(NAME)$(C_R)		All obj are cleaned$(C_W)"
		@(cd $(LIB_DIR) && $(MAKE) $@)
		@echo "$(C_B)$(LIB_DIR)$(C_R)		All obj are cleaned$(C_W)"

fclean: clean
		@rm -rf $(NAME)
		@echo "\n$(C_G)$(NAME)$(C_R)		is clean$(C_W)"
		@(cd $(LIB_DIR) && $(MAKE) $@)
		@echo "$(C_G)$(EXEC)$(C_R)	is clean$(C_W)\n"

norme:
	@echo "\nSource:$(C_N)"
	@norminette $(FILES)
	@echo "\n$(C_W)Header:$(C_N)"
	@norminette $(INCLUDE)$(HEADER)
	@echo "$(C_W)"
re: fclean all
