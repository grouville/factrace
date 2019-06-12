# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: fleonard <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/05/17 15:25:39 by fleonard     #+#   ##    ##    #+#        #
#    Updated: 2019/05/17 15:25:41 by fleonard    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME	:= factrace

CC = gcc

SOURCES = 	src/fact.c \
			src/main.c
CPPFLAGS := -Iinclude -L lib -l gmp 
CFLAGS	:= -Wall -Wextra -O3 -march=native -Wl,-no_pie


OBJECTS = $(SOURCES:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CPPFLAGS) $(CFLAGS)  -o $@ $^

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
