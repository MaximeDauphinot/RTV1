# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdauphin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/10 22:45:44 by mdauphin          #+#    #+#              #
#    Updated: 2018/01/09 11:47:54 by mdauphin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	RTV1
SHEL		=	/bin/bash

CC			=	gcc
CFLAGS		=

LIBFT_DIR	=	libft/
MLX_DIR		=	minilibx_macos/
SRCS_DIR	=	srcs/
SRCS_LIST	=	rtv1.c \
				init.c \
				keyhook.c \
				raytracer.c \
				draw.c \
				sphere.c \
				opvector.c \
				help_window.c \
				parse.c \
				get_value.c

SRCS		=	$(addprefix $(SRCS_DIR), $(SRCS_LIST))
OBJS_DIR	=	objs/
OBJS_LIST	=	$(patsubst %.c, %.o, $(SRCS_LIST))
OBJS		=	$(addprefix $(OBJS_DIR), $(OBJS_LIST))
HEADERS		=	-I./libft -I./includes
LIBS		=	-framework OpenGl -framework AppKit -L./libft -L./minilibx_macos libft/libft.a minilibx_macos/libmlx.a

all : $(NAME)

$(NAME) : $(OBJS)
	@make --no-print-directory -C $(LIBFT_DIR)
	@make --no-print-directory -C $(MLX_DIR)
	@echo "\033[32mLinking...\033[0m"
	@$(CC) $(CFLAGS) $^ $(LIBS) -o $@
	@echo "\033[32mBinary \033[1;32m$(NAME)\033[1;0m\033[32m created.\033[0m"

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@
	@echo "\033[34mCompilation of \033[36m$(notdir $<)\033[34m done.\033[0m"

norme :
	@norminette $(SRCS)

clean :
	@make clean --no-print-directory -C $(MLX_DIR)
	@rm -rf $(OBJS_DIR)
	@echo "\033[31mObjects files \033[1;31m$(OBJS_LIST)\033[1;0m\033[31m removed.\033[0m"

fclean : clean
	@make fclean --no-print-directory -C $(LIBFT_DIR)
	@rm -rf $(NAME)	
	@echo "\033[31mBin \033[1;31m$(NAME)\033[1;0m\033[31m removed.\033[0m"

re : fclean all
.PHONY : all clean
