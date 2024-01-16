NAME = fdf
MOULINETTE = -Wall -Wextra -Werror
SRC = src/
INC = inc/
HEADERS = -I mlx/
CC_FLAGS = cc -c -I $(INC)
FDF_C = $(SRC)main.c $(SRC)handle_map.c $(SRC)utils.c $(SRC)drawing.c $(SRC)draw_x.c $(SRC)draw_y.c
FDF_O = fdf.o

LIBFT_A = libft/libft.a
FT_PRINTF_A = ft_printf/libftprintf.a

.PHONY: all clean fclean re
all: $(NAME)

%.o: %.c
$(NAME): $(SRC)
				$(MAKE) -C libft/ re
				$(MAKE) -C ft_printf/ re
				cc $(MOULINETTE) $(HEADERS) $(FDF_C) -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(LIBFT_A) $(FT_PRINTF_A)
clean:
				$(MAKE) -C libft clean
				$(MAKE) -C ft_printf clean
fclean: clean
				rm -f $(NAME)
				$(MAKE) -C libft fclean
				$(MAKE) -C ft_printf fclean
re: fclean all