# UTILS FUNCTIONS
UTILS = \
	utils/mlibx.c \
	utils/complex.c

# FRACTOL FUNCTION
FRACTOL = fractol.c

# MAIN
MAIN = main.c

# SOURCE CODE
SOURCE = $(MAIN) $(UTILS) $(FRACTOL)

# STATIC FRACTOL LIB
NAME = fractol

# DEFAULT COMPILER
COMPILER = gcc

# DEFAULT COMPILER FLAGS
DFLAGS = -Wall -Wextra -Werror

# LIBX AND MATH COMPILER FLAGS
XFLAGS = -lX11 -lXext -lmlx -lm

# COMPILE AND BUILD STATIC LIB
$(NAME):
		$(COMPILER) -o $(NAME) $(SOURCE) $(DFLAGS) $(XFLAGS)

# VERIFY DEPS
all:	$(NAME)

# REMOVE ALL BIN FILES
clean:
		rm -rf $(BIN)

# REMOVE STATIC FRACTOL LIB
fclean:	clean
		rm -rf $(NAME)

# REBUILD
re:		fclean all
