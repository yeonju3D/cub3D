# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/07 17:00:59 by yeongo            #+#    #+#              #
#    Updated: 2023/01/13 08:22:30 by yeongo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:=	libft.a

CC				:=	cc
CFLAGS			:=	-Wall -Wextra -Werror
CPPFLAGS		:=

AR				:=	ar
ARFLAGS			:=	rcus
RM				:=	rm -rf

HEADER			:=	./include/
SRC_DIR			:=	./src/
OBJ_DIR			:=	./.obj/

SRC_FILES		:=	$(addsuffix .c,			\
					ft_isalpha				\
					ft_isdigit				\
					ft_issign				\
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
SRC				:=	$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ				:=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))

CPPFLAGS		+=	-I$(HEADER)
SRC_FOLDER		:=	$(SRC_DIR)
OBJ_FOLDER		:=	$(OBJ_DIR)
OBJS			:=	$(OBJ)
PRINT			:=	LIBFT

ifdef MANDA_FILE
		MANDA_NAME		:=	$(addprefix \", $(addsuffix \", $(MANDA_FILE)))
		CPPFLAGS 		+=	-D MANDA_NAME=$(MANDA_NAME)
endif

ifdef BONUS_FILE
		BONUS_NAME		:=	$(addprefix \", $(addsuffix \", $(BONUS_FILE)))
		CPPFLAGS 		+=	-D BONUS_NAME=$(BONUS_NAME)
endif

.PHONY	:	all
all		:	$(OBJ_FOLDER) $(NAME)

$(OBJ_FOLDER)	:
	@if [ ! -d $(OBJ_FOLDER) ]; then \
		mkdir -p $(OBJ_FOLDER); \
	fi

$(NAME)	:	$(OBJS)
	@$(AR) $(ARFLAGS) $@ $^
	@echo "\033[01;32m       LFT_SUCCESS!      \033[0m"

$(OBJ_FOLDER)%.o	:	$(SRC_FOLDER)%.c
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

.PHONY	:	clean
clean	:
	@$(RM) $(OBJ_DIR)
	@echo "\033[91m    REMOVE LFT_OBJECT    \033[0m"

.PHONY	:	fclean
fclean	:	clean
	@$(RM) $(NAME)
	@echo "\033[91m     LFT_FCLEAN DONE     \033[0m"

.PHONY	:	re
re		:	fclean
	@make all
