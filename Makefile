# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrocca <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/24 01:29:56 by lrocca            #+#    #+#              #
#    Updated: 2021/07/02 19:06:45 by lrocca           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc
CFLAGS	?=	-g -Wall -Wextra -Werror
IFLAGS	=	-I$(INCDIR) -I$(LIBDIR)
LDFLAGS	+=	-lreadline

NAME	=	minishell

FILES	=	main.c error.c prompt.c exec.c env.c path.c signal.c fd.c \
			builtin/cd.c \
			builtin/echo.c \
			builtin/env.c \
			builtin/exit.c \
			builtin/export.c \
			builtin/pwd.c \
			builtin/unset.c \
			parsing/interpolation.c \
			parsing/lexer.c \
			parsing/redirection.c \
			utils/cmd.c \
			utils/env.c \
			utils/ft_ismeta.c \
			utils/ft_isname_start.c \
			utils/line_to_name.c \
			utils/list_to_array.c \
			utils/redir.c

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
