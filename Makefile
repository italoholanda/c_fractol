## GENERAL ##
NAME:= fractol
CC:= gcc
SFLAGS:= -Wall -Wextra -Werror
XFLAGS:= -lm -lbsd -lmlx -lXext -lX11

## DOCUMENT ##
STATIC:= fractol.a
MAIN:= main.c
SRC:= mandelbrot.c mlibx.c complex.c
BIN:= ${SRC:.c=.o}

## MAKE NAME ##
$(NAME): ${STATIC}
	${CC} ${SFLAGS} -I -c -O3 -fsanitize=leak ${MAIN} ${STATIC} ${XFLAGS} -o ${NAME}

## MAKE STATIC ##
$(STATIC): ${BIN}
	ar rcs ${STATIC} ${BIN}

## MAKE BIN ##
$(BIN):
	${CC} ${SFLAGS} -c -O3 ${SRC} ${XFLAGS}


## REMOVE BIN ##
clean:
	rm -rf ${BIN}

## REMOVE ALL ##
fclean: clean
	rm -rf ${STATIC}
	rm -rf ${NAME}

## REMAKE ALL ##
re: fclean ${NAME}
