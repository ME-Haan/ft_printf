# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mhaan <mhaan@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/27 16:14:12 by mhaan         #+#    #+#                  #
#    Updated: 2022/11/05 14:22:17 by mhaan         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = 	

OBS = $(SRC:.c=.o)

BONUS = 	

BOBS = $(BONUS:.c=.o)

CC = gcc
ARFLAGS = -crs
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBS)
		ar $(ARFLAGS) $(NAME) $(OBS)

%.o: %.c
		$(CC) -c $(CFLAGS) $^ -o $@

bonus: $(OBS) $(BOBS)
		ar $(ARFLAGS) $(NAME) $(OBS) $(BOBS)

clean:
		/bin/rm -f $(OBS) $(BOBS)

fclean: clean
		/bin/rm -f $(NAME)

re:
		$(MAKE) fclean
		$(MAKE) all

.PHONY:
		all bonus clean fclean re