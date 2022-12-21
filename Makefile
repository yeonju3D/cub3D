# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/07 17:00:59 by yeongo            #+#    #+#              #
#    Updated: 2022/12/21 12:39:29 by yeongo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:=		libft.a
CC				:=		cc
CFLAGS			:=		-Wall -Wextra -Werror
AR				:=		ar
ARFLAGS			:=		rcus
RM				:=		rm -rf

HEADER			:=		./include/
SRC_DIR			:=		./src/
OBJ_DIR			:=		./.obj/
SRC_FILES		:=		$(addsuffix .c,			\
						ft_isalpha				\
						ft_isdigit				\
						ft_issign				\
						ft_isalnum				\
						ft_isascii				\
						ft_isprint				\
						ft_strlen				\
						ft_memset				\
						ft_bzero				\
						ft_memcpy				\
						ft_memmove				\
						ft_strlcpy				\
						ft_strlcat				\
						ft_toupper				\
						ft_tolower				\
						ft_strchr				\
						ft_strrchr				\
						ft_strncmp				\
						ft_memchr				\
						ft_memcmp				\
						ft_strnstr				\
						ft_atoi					\
						ft_calloc				\
						ft_strdup				\
						ft_substr				\
						ft_strjoin				\
						ft_strtrim				\
						ft_split				\
						ft_itoa					\
						ft_strmapi				\
						ft_striteri				\
						ft_putchar_fd			\
						ft_putstr_fd			\
						ft_putendl_fd			\
						ft_putnbr_fd			\
						ft_lstnew				\
						ft_lstadd_front			\
						ft_lstsize				\
						ft_lstlast				\
						ft_lstadd_back			\
						ft_lstdelone			\
						ft_lstclear				\
						ft_lstiter				\
						ft_lstmap				\
						get_next_line			\
						get_next_line_utils		\
						ft_printf				\
						print_number			\
						print_text				\
						ft_free					\
						check_leaks)
OBJ_FILES		:=		$(SRC_FILES:.c=.o)
SRC				:=		$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ				:=		$(addprefix $(OBJ_DIR), $(OBJ_FILES))

INCLUDE			:=		$(HEADER)
SRC_FOLDER		:=		$(SRC_DIR)
OBJ_FOLDER		:=		$(OBJ_DIR)
OBJS			:=		$(OBJ)
PRINT			:=		LIBFT

.PHONY	:	all
all		:	$(OBJ_FOLDER) $(NAME)

$(NAME)	:	$(OBJS)
	$(AR) $(ARFLAGS) $@ $^

$(OBJ_FOLDER)%.o	:	$(SRC_FOLDER)%.c
	@$(CC) $(CFLAGS) -I$(INCLUDE) -c -o $@ $<

$(OBJ_FOLDER)	:
	@if [ ! -d $(OBJ_FOLDER) ]; then \
		mkdir -p $(OBJ_FOLDER); \
	fi

.PHONY	:	clean
clean	:
	@$(RM) $(OBJ_DIR)

.PHONY	:	fclean
fclean	:	clean
	@$(RM) $(NAME)

.PHONY	:	re
re		:	fclean
	@make all
