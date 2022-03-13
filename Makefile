# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: igomes-h <italogholanda@gmail.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/04 10:36:08 by igomes-h          #+#    #+#              #
#    Updated: 2022/03/13 18:04:15 by igomes-h         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## GENERAL ##
NAME:= fractol
CC:= gcc
SFLAGS:= -Wall -Wextra -Werror
XFLAGS:= -lm -lbsd -lmlx -lXext -lX11

## DOCUMENT ##
STATIC:= fractol.a
MAIN:= src/main.c
SRC = \
	src/get_fractal.c src/utils_mlibx.c src/utils_complex.c src/utils_errors.c \
	src/utils_libft.c src/put_mandelbrot.c src/put_julia.c src/utils_colors.c
BIN = \
	bin/get_fractal.o bin/utils_mlibx.o bin/utils_complex.o bin/utils_errors.o \
	bin/utils_libft.o bin/put_mandelbrot.o bin/put_julia.o bin/utils_colors.o

## MAKE NAME ##
$(NAME): ${STATIC}
	${CC} ${SFLAGS} -I -c -O3 -fsanitize=leak \
	${MAIN} ${STATIC} ${XFLAGS} -o ${NAME}

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
