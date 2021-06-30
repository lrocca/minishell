# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrocca <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/24 01:29:56 by lrocca            #+#    #+#              #
#    Updated: 2021/06/30 06:06:18 by lrocca           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc
CFLAGS	?=	-g -Wall -Wextra -Werror
IFLAGS	=	-I$(INCDIR) -I$(LIBDIR)
LDFLAGS	+=	-lreadline

NAME	=	minishell

FILES	=	main.c error.c prompt.c exec.c env.c path.c \
			parse/lexer.c \
			parse/redirection.c \
			utils/cmd.c \
			utils/ft_ismeta.c \
			utils/getenv.c \
			builtin/env.c \
			builtin/exit.c \
			builtin/export.c \
			builtin/pwd.c \
			builtin/unset.c

SRCDIR	=	./src
OBJDIR	=	./obj
INCDIR	=	./inc
LIBDIR	=	./libft

LIBFT	=	$(LIBDIR)/libft.a

SRC	=	$(addprefix $(SRCDIR)/, $(FILES))
OBJ	=	$(patsubst $(SRCDIR)%, $(OBJDIR)%, $(SRC:.c=.o))

all: $(NAME)
	./minishell

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(IFLAGS) -c $^ -o $@

$(LIBFT):
	$(MAKE) -C $(LIBDIR)

clean:
	$(RM) $(OBJ)
	$(RM) -r $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all
