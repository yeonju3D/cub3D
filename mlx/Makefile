#
#

NOM=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
SRC+= mlx_png.c mlx_mouse.m
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2

# ---------------------------------------------------------------------------- #
#    Define the variables for progress bar                                     #
# ---------------------------------------------------------------------------- #

TOTAL_FILES			:=	$(shell echo $(SRC) | wc -w)
COMPILED_FILES		:=	0
STEP				:=	100

# add to match string put with X11 in size and position
CFLAGS+= -DSTRINGPUTX11

all: $(NOM)

$(NOM):	$(OBJ)
	@ar -r $(NOM) $(OBJ)
	@ranlib $(NOM)
	@printf "\n$(MAGENTA)[$(NOM)] Linking Success\n$(DEF_COLOR)"

%.o: %.m
	@$(CC) $(CFLAGS) -c $< -o $@
	@$(eval COMPILED_FILES = $(shell expr $(COMPILED_FILES) + 1))
	@$(eval PROGRESS = $(shell expr $(COMPILED_FILES) "*" $(STEP) / $(TOTAL_FILES)))
	@printf "                                                                                                   \r"
	@printf "$(YELLOW)[$(NOM)] [%02d/%02d] ( %3d %%) Compiling $<\r$(DEF_COLOR)" $(COMPILED_FILES) $(TOTAL_FILES) $(PROGRESS)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@$(eval COMPILED_FILES = $(shell expr $(COMPILED_FILES) + 1))
	@$(eval PROGRESS = $(shell expr $(COMPILED_FILES) "*" $(STEP) / $(TOTAL_FILES)))
	@printf "                                                                                                   \r"
	@printf "$(YELLOW)[$(NOM)] [%02d/%02d] ( %3d %%) Compiling $<\r$(DEF_COLOR)" $(COMPILED_FILES) $(TOTAL_FILES) $(PROGRESS)

clean:
	@$(RM) -f $(NOM) $(OBJ) *~
	@$(RM) -f mlx_app
	@printf "$(BLUE)[LIBMLX] obj. files$(DEF_COLOR)$(GREEN)	=> Cleaned!\n$(DEF_COLOR)"

fclean: clean
	@$(RM) -f mlx_app
	@printf "$(CYAN)[LIBMLX] exec. files$(DEF_COLOR)$(GREEN)	=> Cleaned!\n$(DEF_COLOR)"

re: clean all

# ---------------------------------------------------------------------------- #
#    Define the colors                                                         #
# ---------------------------------------------------------------------------- #

DEF_COLOR	=	\033[1;39m
GRAY		=	\033[1;90m
RED			=	\033[1;91m
GREEN		=	\033[1;92m
YELLOW		=	\033[1;93m
BLUE		=	\033[1;94m
MAGENTA		=	\033[1;95m
CYAN		=	\033[1;96m
WHITE		=	\033[1;97m
