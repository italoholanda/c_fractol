# UTILS FUNCTIONS
UTILS = utils/mlibx.c

# FRACTOL MAIN FUNCTION
FRACTOL = fractol.c

# SOURCE CODE
SOURCE = $(UTILS)$(FRACTOL)

# BIN FILES
BIN = $(SOURCE:.c=.o)

# STATIC FRACTOL LIB
NAME = fractol.a

# DEFAULT COMPILER
COMPILER = gcc

# DEFAULT COMPILER FLAGS
DFLAGS = -Wall -Wextra -Werror

# LIBX AND MATH COMPILER FLAGS
XFLAGS = -lX11 -lXext -lmlx -lm

# COMPILE AND BUILD STATIC LIB
$(NAME):
		$(COMPILER) -c  $(UTILS) $(DFLAGS) $(XFLAGS)
		mv *.o ./utils/
		$(COMPILER) -c  $(FRACTOL) $(DFLAGS) $(XFLAGS)
		mv *.o ./
		ar rcs $(NAME) $(BIN)

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
