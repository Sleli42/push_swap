# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/06/24 00:57:49 by lubaujar          #+#    #+#              #
#    Updated: 2015/08/24 00:22:24 by lubaujar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
RM = rm -rf
FLAGS = -g -Wall -Wextra -Werror
LDFLAGS = -I./include/ -I./libft/include/

SRC = main.c \
	init.c \
	list.c \
	error.c \
	display.c \
	r_op.c \
	p_op.c \
	s_op.c \
	tools.c \
	sort.c

OBJ = $(SRC:.c=.o)
	SRCDIR	= ./srcs/
	OBJDIR	= ./objs/
	INCDIR	= ./include/
	SRCS	= $(addprefix $(SRCDIR), $(SRC))
	OBJS	= $(addprefix $(OBJDIR), $(OBJ))
	INCS	= $(addprefix $(INCDIR), $(INC))

all: $(NAME)

$(NAME): $(OBJS) $(INCS)
	@gcc $(FLAGS) -o $@ $^ -L./libft/ -lft
	@echo "\t \033[32mcompilation ..\033[0m"

$(OBJS): $(SRCS)
	make -C libft/
	@gcc $(FLAGS) -c $(SRCS) $(LDFLAGS)
	@echo "\\033[1;34mPUSH PUSH PUSH\n\tSWAP SWAP SWAP"
	@echo "\\033[1;34m\t\tPUSH SWAP in progress ...\\033[0;39m"
	@mkdir -p $(OBJDIR)
	@mv $(OBJ) $(OBJDIR)

clean:
	@echo "\nRM *.o.. \t      \033[32mDELETE!\033[0m"
	@$(RM) $(OBJS)
	@$(RM) *.o

fclean: clean
	make fclean -C libft/
	@echo "RM ./ft_minishell..   \033[32mDELETE!\033[0m"
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
