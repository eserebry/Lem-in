# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eserebry <eserebry@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/06 22:47:44 by eserebry          #+#    #+#              #
#    Updated: 2017/11/26 01:56:34 by eserebry         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem_in

FLAGS = -Wall -Wextra -Werror -Ofast
CC = gcc

SRC =	main.c \
		display_management.c \
		ft_free.c \
		ft_solve.c \
		ft_ants.c \
		ft_doors.c \
		ft_input.c \
		ft_links.c \
		ft_path.c \
		ft_rooms.c \
		ft_solution.c \

LIBFT = libft/libft.a
FT_PRINTF = libft/ft_printf/libftprintf.a

OBJ = $(SRCS:.c=.o)

SRCDIR = srcs
OBJDIR = objs

SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJS = $(addprefix $(OBJDIR)/, $(OBJ))

HEADER = lem_in.h

RM = rm -rf

GREEN = \033[32m
RED = \033[31m

all : $(NAME)

$(NAME): $(OBJ)
	@make re -C libft
	@make -C libft/ft_printf
	@$(CC) -o $(NAME) $(SRCS) $(FLAG) $(LIBFT) $(FT_PRINTF)
	@echo "$(GREEN)lem_in: creating object files"

clean:
	@/bin/$(RM) $(OBJ)
	@make -C libft clean
	@make -C libft/ft_printf clean

fclean: clean
	@make -C libft clean
	@make -C libft/ft_printf clean
	@/bin/$(RM) $(NAME)
	@echo "$(RED)lem_in: deleting object files"

re: fclean all

.PHONY: all clean fclean re
