#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/12 17:20:35 by rbaum             #+#    #+#              #
#    Updated: 2015/10/11 18:42:41 by rbaum            ###   ########.fr        #
#                                                                              #
#******************************************************************************#


.PHONY:			all, libft, clean, fclean, re

CC =			gcc

CFLAG =			-Wall -Wextra -Werror

NAME =			ft_select

SRC_PATH =		./src/

OBJ_PATH =		./obj/

LIBFT_PATH =	./libft/

INC_PATH =		./inc/

SRC_NAME =		main.c				print_list.c			short_func.c\
				key_events.c		modif_term.c			ft_init.c\
				signal.c			move.c\

OBJ_NAME =		$(SRC_NAME:.c=.o)

LIBFT_NAME =	libft.a

INC_NAME =		select.h

SRC =			$(addprefix $(SRC_PATH),$(SRC_NAME))

OBJ =			$(addprefix $(OBJ_PATH),$(OBJ_NAME))

LIBFT =			$(addprefix $(LIBFT_PATH),$(LIBFT_NAME))

INC =			$(addprefix $(INC_PATH),$(INC_NAME))

INCLIBFT = 		$(LIBFT_PATH)inc

SELECT_FLAG =	-ltermcap

LIBFT_FLAG = 	-L$(LIBFT_PATH) -lft

all:			libft $(NAME) 

$(NAME):		$(OBJ)
				@$(CC) $(LIBFT_FLAG) $(SELECT_FLAG) -o $@ $^
				@echo "Select created"

$(OBJ_PATH)%.o:	$(SRC_PATH)%.c $(INC)
				@mkdir -p $(OBJ_PATH)
				@$(CC) $(CFLAG) -I$(INC_PATH) -I$(INCLIBFT) -o $@ -c $<

libft:			$(LIBFT)

$(LIBFT):		$(LIBFT_PATH)
				@make -C $(LIBFT_PATH)

clean:
				@make -C $(LIBFT_PATH) clean
				@rm -f $(OBJ)

fclean:			
				@rm -f $(OBJ)
				@make -C $(LIBFT_PATH) fclean
				@rm -f $(NAME)

re: 			fclean all
