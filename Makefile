# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mhaan <mhaan@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/27 16:14:12 by mhaan         #+#    #+#                  #
#    Updated: 2023/03/03 16:33:40 by mhaan         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

AR = ar -crs
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = /bin/rm -rf

SRC_DIR = ./ft_printf
SRC = 	ft_printf.c helpers.c

OBJ_DIR = ./obj
OBJS = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

all: $(NAME)

clean:
		$(RM) $(OBJ_DIR)
		make clean -C libft

fclean: clean
		$(RM) $(NAME)
		$(RM) libft/libft.a

re:
		$(MAKE) fclean
		$(MAKE) all


$(NAME): $(OBJ_DIR) $(OBJS)
		make bonus -C libft
		cp libft/libft.a ./$(NAME)
		$(AR) $(NAME) $(OBJS)

$(OBJ_DIR):
		mkdir -p $(OBJ_DIR)
		
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		$(CC) $(CFLAGS) -c $< -o $@

.PHONY:
		all clean fclean re