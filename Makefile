# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrocca <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/24 01:29:56 by lrocca            #+#    #+#              #
#    Updated: 2021/06/24 02:39:18 by lrocca           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

NAME	=	minishell

FILES	=	main.c

SRCDIR	=	./src
OBJDIR	=	./obj
INCDIR	=	./inc

SRC	=	$(addprefix $(SRCDIR)/, $(FILES))
OBJ	=	$(patsubst $(SRCDIR)%, $(OBJDIR)%, $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir $(@D)
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	$(RM) $(OBJ)
	$(RM) -r $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all
