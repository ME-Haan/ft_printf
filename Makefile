# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mhaan <mhaan@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/27 16:14:12 by mhaan         #+#    #+#                  #
#    Updated: 2022/11/07 10:55:57 by mhaan         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
AR = -crs
CFLAGS = -Wall -Wextra -Werror
RM = /bin/rm -f 

SRC_DIR = src/
SRC = 	ft_printf.c helpers.c switch.c

OBJ_DIR = obj/
OBS = $(addprefix $(OBJ_DIR),$(SRC:.c=.o)

BONUS = 	
BOBS = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBS)
		@make -C libft
		@cp libft/libft.a ./$(NAME)
		@ar $(AR) $(NAME) $(OBS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
		@$(CC) -c $(CFLAGS) $< -o $@

$(OBJF):
		@mkdir -p $(OBJ_DIR)

bonus: $(OBS) $(BOBS)
		ar $(AR) $(NAME) $(OBS) $(BOBS)

clean:
		@$(RM) $(OBJ_DIR)$(OBS)

fclean: clean
		$(RM) $(NAME)

re:
		$(MAKE) fclean
		$(MAKE) all

.PHONY:
		all bonus clean fclean re