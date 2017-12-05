# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eserebry <eserebry@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/11 21:47:23 by eserebry          #+#    #+#              #
#    Updated: 2017/11/24 06:01:41 by eserebry         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Wextra -Werror -c -I -fsanitize=address

INCLUDES =	"includes"

FUNCTION = atoi bzero isdigit isprint memalloc memdel memcmp memcpy memmove \
memset strchr strdel strdup strjoin strlen strclen strsub strnew strcat \
strncat strcpy strsplit strstr strcpy_int strjoin_free get_next_line putendl \
putchar putnbr putstr strcmp space\

FT_FUNCTION = $(addprefix ft_, $(FUNCTION))
SRC = $(addsuffix .c, $(FT_FUNCTION))

OBJ = $(SRC:.c=.o)

RM = rm -f

GREEN = \033[32m
RED = \033[31m

all: $(NAME)

$(NAME): 
		@gcc $(FLAGS) $(SRC)
		@ar rc $(NAME) $(OBJ)
		@ranlib $(NAME)
		@echo "$(GREEN)libft: creating object files"


$(COMPILED): @%.o: %.c
		@$(CC) $(FLAGS) $< -o $@ -I $(INCLUDES)

clean:
		@/bin/$(RM) $(OBJ)

fclean: clean
		@/bin/$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re