## GENERAL ##
NAME:= fractol
CC:= gcc
SFLAGS:= -Wall -Wextra -Werror
XFLAGS:= -lm -lbsd -lmlx -lXext -lX11

## DOCUMENT ##
STATIC:= fractol.a
MAIN:= src/main.c
SRC:= src/set_mandelbrot.c src/mlibx_utils.c src/complex_utils.c src/get_fractal.c
BIN:= bin/set_mandelbrot.o bin/mlibx_utils.o bin/complex_utils.o bin/get_fractal.o

## MAKE NAME ##
$(NAME): ${STATIC}
	${CC} ${SFLAGS} -I -c -O3 -fsanitize=leak ${MAIN} ${STATIC} ${XFLAGS} -o ${NAME}

## MAKE STATIC ##
$(STATIC): ${BIN}
	ar rcs ${STATIC} ${BIN}

## MAKE BIN ##
$(BIN):
	mkdir -p bin
	${CC} ${SFLAGS} -c -O3 ${SRC} ${XFLAGS}
	mv *.o bin/

## REMOVE BIN ##
clean:
	rm -rf ${BIN}

## REMOVE ALL ##
fclean: clean
	rm -rf ${STATIC}
	rm -rf ${NAME}

## REMAKE ALL ##
re: fclean ${NAME}
