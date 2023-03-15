# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mhaan <mhaan@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/27 16:14:12 by mhaan         #+#    #+#                  #
#    Updated: 2023/03/15 11:46:27 by mhaan         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

AR = ar -crs
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = /bin/rm -rf

INCLUDES = -I./includes

SRC_DIR = ./src
SRC =	ft_printf.c helpers.c

OBJ_DIR = ./obj
OBJS = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

LIBFT_DIR = ../libft
LIBFT_AR = ../libft/libft.a

all: $(NAME)

clean:
		$(RM) $(OBJ_DIR)
		make clean -C $(LIBFT_DIR)

fclean: clean
		$(RM) $(NAME)
		$(RM) $(LIBFT_AR)

re:
		$(MAKE) fclean
		$(MAKE) all

$(NAME): $(OBJS)
		make bonus -C $(LIBFT_DIR)
		mv $(LIBFT_AR) ./$(NAME)
		$(AR) $(NAME) $(OBJS)


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		@mkdir -p $(OBJ_DIR)
		$(CC) $(INCLUDES) $(CFLAGS) -c -o $@ $<

.PHONY:
		all clean fclean re