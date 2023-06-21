# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/07 17:00:59 by yeongo            #+#    #+#              #
#    Updated: 2023/06/16 22:13:18 by yeongo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:=	libft.a

CC				:=	cc
CFLAGS			:=	-Wall -Wextra -Werror
CPPFLAGS		:=
MJFLAGS			 =	-MJ $@.part.json

AR				:=	ar
ARFLAGS			:=	rcus
RM				:=	rm -rf

HEADER			:=	./include/
SRC_DIR			:=	./srcs/
OBJ_DIR			:=	./.obj/
CACHE_DIR		:=	./.cache/

SRC_FILES		:=	$(addsuffix .c,				\
						ft_issep				\
						ft_issign				\
						ft_isalpha				\
						ft_isdigit				\
						ft_isalnum				\
						ft_isascii				\
						ft_isprint				\
						ft_toupper				\
						ft_tolower				\
						ft_atoi					\
						ft_itoa					\
						ft_putchar_fd			\
						ft_putstr_fd			\
						ft_putnbr_fd			\
						ft_putendl_fd			\
						ft_strlen				\
						ft_strcmp				\
						ft_strncmp				\
						ft_strlcpy				\
						ft_strlcat				\
						ft_strchr				\
						ft_strrchr				\
						ft_strnstr				\
						ft_strdup				\
						ft_strjoin				\
						ft_substr				\
						ft_strtrim				\
						ft_strmapi				\
						ft_striteri				\
						ft_str_append			\
						ft_split				\
						ft_split_set			\
						ft_calloc				\
						ft_bzero				\
						ft_memset				\
						ft_memcpy				\
						ft_memmove				\
						ft_memcmp				\
						ft_memchr				\
						ft_free					\
						check_leaks				\
						ft_lstnew				\
						ft_lstsize				\
						ft_lstlast				\
						ft_lstadd_front			\
						ft_lstadd_back			\
						ft_lstdelone			\
						ft_lstclear				\
						ft_lstiter				\
						ft_lstmap				\
						get_next_line_utils		\
						get_next_line			\
						print_number			\
						print_text				\
						ft_printf				\
						ft_abs					\
					)
OBJ_FILES		:=	$(SRC_FILES:.c=.o)
JSON_FILES		:=	compile_commands.json
SRC				:=	$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ				:=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))

CPPFLAGS		+=	-I$(HEADER)
SRC_FOLDER		:=	$(SRC_DIR)
OBJ_FOLDER		:=	$(OBJ_DIR)
OBJS			:=	$(OBJ)
PRINT			:=	LIBFT

.PHONY	:	all
all		:	$(OBJ_FOLDER) $(NAME)

$(OBJ_FOLDER)	:
	@if [ ! -d $(OBJ_FOLDER) ]; then \
		mkdir -p $(OBJ_FOLDER); \
	fi

$(NAME)	:	$(OBJS)
	@$(AR) $(ARFLAGS) $@ $^
	@(printf [ && find . -name "*.part.json" | xargs cat && printf ]) > $(JSON_FILES);
	@echo "\033[01;32m       LFT_SUCCESS!      \033[0m"

$(OBJ_FOLDER)%.o	:	$(SRC_FOLDER)%.c
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(MJFLAGS) -c -o $@ $<

.PHONY	:	clean
clean	:
	@$(RM) $(OBJ_DIR) $(CACHE_DIR)
	@echo "\033[91m    REMOVE LFT_OBJECT    \033[0m"

.PHONY	:	fclean
fclean	:	clean
	@$(RM) $(NAME)
	@echo "\033[91m     LFT_FCLEAN DONE     \033[0m"

.PHONY	:	re
re		:	fclean
	@make all
