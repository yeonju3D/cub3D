# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/08 10:26:53 by yeongo            #+#    #+#              #
#    Updated: 2023/06/27 20:44:09 by juwkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				:=	cub3D
PROJECT_NAME		:=	CUB3D

HEADER				:=	./mandatory/include/
SRC_DIR				:=	./mandatory/srcs/
OBJ_DIR				:=	./mandatory/.obj/

HEADER_BONUS		:=	./bonus/include/
SRC_B_DIR			:=	./bonus/srcs/
OBJ_B_DIR			:=	./bonus/.obj/
CACHE_DIR			:=	./.cache/

LIBFT_DIR			:=	./libft/
LIBFT_HEADER		:=	./libft/include/
LIBFT				:=	$(LIBFT_DIR)libft.a
LIBMLX_DIR			:=	./libmlx/
LIBMLX				:=	$(LIBMLX_DIR)libmlx.a
LDFLAGS				:=	-L$(LIBFT_DIR) -lft -L$(LIBMLX_DIR) -lmlx

SRC_FILES			:=	$(addsuffix .c,				\
							main					\
							ft_mlx					\
							parse					\
						)
OBJ_FILES			:=	$(SRC_FILES:.c=.o)
SRC					:=	$(addprefix $(SRC_DIR),		$(SRC_FILES))
OBJ					:=	$(addprefix $(OBJ_DIR),		$(OBJ_FILES))

SRC_B_FILES			:=	$(addsuffix .c,				\
							main_bonus				\
						)
OBJ_B_FILES			:=	$(SRC_B_FILES:.c=.o)
SRC_BONUS			:=	$(addprefix $(SRC_B_DIR),	$(SRC_B_FILES))
OBJ_BONUS			:=	$(addprefix $(OBJ_B_DIR),	$(OBJ_B_FILES))

JSON_FILES			:=	compile_commands
JSON				:=	$(addsuffix .json,			$(JSON_FILES))

ifdef BONUS
		INCLUDE				:=	$(HEADER_BONUS)
		SRC_FOLDER			:=	$(SRC_B_DIR)
		OBJ_FOLDER			:=	$(OBJ_B_DIR)
		OBJS				:=	$(OBJ_BONUS)
		PRINT				:=	$(addsuffix _BONUS,		$(PROJECT_NAME))
else
		INCLUDE				:=	$(HEADER)
		SRC_FOLDER			:=	$(SRC_DIR)
		OBJ_FOLDER			:=	$(OBJ_DIR)
		OBJS				:=	$(OBJ)
		PRINT				:=	$(PROJECT_NAME)
endif

ifdef	DEBUG
		DBFLAGS		:=	-g -fsanitize=address
		PRINT		:=	$(addsuffix _DEBUG, $(PRINT))
endif

CC					:=	cc
CFLAGS				:=	-Wall -Wextra -Werror
CPPFLAGS			:=	-I$(INCLUDE) -I$(LIBFT_HEADER) -I$(LIBMLX_DIR)
FRAMEWORK			:=	-framework OpenGL -framework Appkit
MJFLAGS				 =	-MJ $@.part.json
RM					:=	rm -rf

.PHONY	:	all
all		:	$(OBJ_FOLDER) $(NAME)

$(OBJ_FOLDER)		:
	@if [ ! -d $(OBJ_FOLDER) ]; then \
		mkdir -p $(OBJ_FOLDER); \
	fi

$(NAME)			:	$(LIBFT) $(LIBMLX) $(OBJS)
	@$(CC) $(CFLAGS) $(LDFLAGS) $(DBFLAGS) -o $@ $^
	@(printf [ && find . -name "*.part.json" | xargs cat && printf ]) > $(JSON);
	@echo "\033[01;32m         SUCCESS!        \033[0m"

$(LIBFT)		:
	@make -s -C $(LIBFT_DIR) all

$(LIBMLX)		:
	@make -s -C $(LIBMLX_DIR) all 2> /dev/null

$(OBJ_DIR)%.o	:	$(SRC_DIR)%.c
	@$(CC) $(CFLAGS) $(DBFLAGS) $(CPPFLAGS) $(MJFLAGS) -c -o $@ $<

.PHONY	:	test
test	:
	@make TEST=1 all

.PHONY	:	debug
debug	:
	@make DEBUG=1 all

.PHONY	:	bonus
bonus	:
	@make BONUS=1 all

.PHONY	:	clean
clean	:
	@make -s -C $(LIBFT_DIR) clean
	@make -s -C $(LIBMLX_DIR) clean
	@$(RM) $(OBJ_DIR) $(OBJ_B_DIR) $(CACHE_DIR)
	@echo "\033[91m      REMOVE OBJECT      \033[0m"

.PHONY	:	fclean
fclean	:	clean
	@$(RM) $(LIBFT)
	@$(RM) $(NAME)
	@echo "\033[91m       FCLEAN DONE       \033[0m"

.PHONY	:	re
re		:	fclean
	@make all
