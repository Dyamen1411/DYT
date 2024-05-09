# **************************************************************************** #
#                                                                              #
#    Makefile                                                                  #
#                                                                              #
#    By: Antoine Massias <massias.antoine.pro@gmail.com>                       #
#                                                                              #
#    Created: 2024/05/09 15:19:22 by Antoine Massias                           #
#    Updated: 2024/05/09 15:21:50 by Antoine Massias                           #
#                                                                              #
# **************************************************************************** #

COL_RED		=	\x1b[1;31m
COL_GREEN	=	\x1b[1;32m
COL_RESET	=	\x1b[1;0m

SRC_DIR :=	src
INC_DIR :=	include
OBJ_DIR	:=	build

CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra -g
LFLAGS		=	

FILES		=				\
	main

SRCS		=	$(addprefix $(SRC_DIR)/, $(addsuffix .c,$(FILES)))
OBJS		=	$(addprefix $(OBJ_DIR)/, $(addsuffix .o,$(FILES)))

NAME		=	dyt

.PHONY: all bonus clean fclean re

all: $(NAME)

bonus: all

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

$(NAME): $(OBJS)
	$(CC) $^ -o $@ $(LFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) -c $< -o $@ -I$(INC_DIR) $(CFLAGS)
