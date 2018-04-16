# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msicot <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 14:13:34 by msicot            #+#    #+#              #
#    Updated: 2018/04/16 11:23:25 by msicot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_NAME = main.c ft_board.c ft_clear_tab.c ft_check_lines.c ft_prepa_algo.c ft_int_len.c ft_algo.c ft_place.c ft_score.c
OBJ_NAME = $(SRC_NAME:.c=.o)

SRC_PATH = ./src/
OBJ_PATH = ./obj/
INC_PATH = ./inc/

MN_NAME = msicot.filler
complete = @echo "\033[92mComplete\033[0m"
cleaning = @echo "Project building...\n\033[92mCleaning complete\033[0m"


CC = gcc
CFLAGS = -Werror -Wextra -Wall
NAME = msicot.filler
		
SRC = $(addprefix $(SRC_PATH), $(SRC_NAME)) 
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./libft
	@gcc $(CFLGAS) $(OBJ) -L./libft/ -lft -o $(MN_NAME)
	$(complete)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean :
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATHJ) 2> /dev/null || true
	@make clean -C ./libft
	@echo "Filler's objects have been removed"
	$(cleaning)

fclean : clean
	@rm -f $(NAME)
	@make fclean -C ./libft
	@echo "Filler has been removed"

re : fclean all
