# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrocca <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/24 01:29:56 by lrocca            #+#    #+#              #
#    Updated: 2021/07/05 23:36:28 by lrocca           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc
CFLAGS	?=	-g -Wall -Wextra -Werror
IFLAGS	+=	-I$(INCDIR) -I$(LIBDIR)
LDFLAGS	+=	-lreadline

NAME	=	minishell

FILES	=	main.c \
			env.c \
			exec.c \
			fd.c \
			pipeline.c \
			prompt.c \
			signal.c \
			builtin/cd.c \
			builtin/echo.c \
			builtin/env.c \
			builtin/exit.c \
			builtin/export.c \
			builtin/pwd.c \
			builtin/unset.c \
			lib/cmd.c \
			lib/env.c \
			lib/error.c \
			lib/path.c \
			lib/redir.c \
			parsing/buffer.c \
			parsing/interpolation.c \
			parsing/lexer.c \
			parsing/line.c \
			parsing/redirection.c \
			utils/ft_isbuiltin.c \
			utils/ft_ismeta.c \
			utils/ft_isname_start.c \
			utils/list_to_array.c \

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
